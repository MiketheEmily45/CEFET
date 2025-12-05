// ...existing code...
(function(){
    const canvas = document.getElementById('gameCanvas');
    const ctx = canvas.getContext('2d');

    // fixed CSS size in px (viewport)
    const CSS_WIDTH = 1000;
    const CSS_HEIGHT = 500;

    // level width (will be set per level)
    let levelWidth = 3000;

    // handle device pixel ratio for crisp rendering (fixed size)
    function setupCanvas() {
        const ratio = window.devicePixelRatio || 1;
        canvas.style.width = CSS_WIDTH + 'px';
        canvas.style.height = CSS_HEIGHT + 'px';
        canvas.width = Math.round(CSS_WIDTH * ratio);
        canvas.height = Math.round(CSS_HEIGHT * ratio);
        ctx.setTransform(ratio, 0, 0, ratio, 0, 0);
    }
    setupCanvas();

    // player state (world coordinates)
    const player = {
        x: 80,
        y: 0,
        w: 48,
        h: 64,
        vx: 0,
        vy: 0,
        speed: 180, // px/s
        jumpStrength: -550,
        onGround: false,
        facing: 1,
        punching: 0 // timer for punch animation
    };

    const keys = {};
    window.addEventListener('keydown', e => { 
        if (document.activeElement === canvas) e.preventDefault(); 
        keys[e.key.toLowerCase()] = true; 
    });
    window.addEventListener('keyup', e => { 
        if (document.activeElement === canvas) e.preventDefault();
        keys[e.key.toLowerCase()] = false; 
    });

    // platforms in world coordinates (x,y = top-left), y measured from top of canvas
    const groundY = 380;

    // ending block (160px wide) will be set per world
    let endBlock = null;

    // runtime flags
    let levelComplete = false;
    let levelState = 'world'; // 'world' or 'boss'
    let currentWorldIndex = 0; // 0..2 for three worlds

    // enemy defaults — change these to adjust all enemies easily
    const enemyDefaults = {
        w: 48,
        h: 48,
        vx: 80,     // patrol speed
        hp: 3,      // default health
        alive: true
    };

    function createEnemy(cfg) {
        const e = Object.assign({}, enemyDefaults, cfg);
        if (e.x === undefined) e.x = 0;
        if (e.minX === undefined) e.minX = Math.max(0, e.x - 200);
        if (e.maxX === undefined) e.maxX = Math.min(levelWidth - (e.w || 48), e.x + 200);
        return e;
    }

    // projectiles (used for Puss and bosses) in world coords
    const projectiles = [];

    // camera (viewport) position in world coords (left)
    let cameraX = 0;

    // specials
    const specials = {
        donkey: { key: 'e', cooldownMax: 15.0, cooldown: 0, duration: 1.0, activeTime: 0, active: false, x: 0, y: 0 },
        puss:   { key: 'r', cooldownMax: 20.0, cooldown: 0, duration: 2.0, activeTime: 0, active: false, x: 0, y: 0 },
        gingy:  { key: 'x', cooldownMax: 35.0, cooldown: 0, duration: 2.0, activeTime: 0, active: false, usedThisLevel: false, x: 0, y: 0 }
    };

    // simple level definitions (3 worlds + bosses)
    const worlds = [
        // world 0
        {
            width: 3000,
            platforms: [
                { x: 0, y: groundY, w: 3000, h: CSS_HEIGHT - groundY },
                { x: 800, y: 200, w: 160, h: 20},
                { x: 1300, y: 270, w: 200, h: 130},
                { x: 1600, y: 270, w: 500, h: 20}
            ],
            enemies: function(){ // returns array
                return [
                    createEnemy({ x: 200, y: groundY - enemyDefaults.h, minX: 50, maxX: 400, hp: 1 }),
                    createEnemy({ x: 820, y: groundY - enemyDefaults.h, minX: 720, maxX: 960, hp: 3 }),
                    createEnemy({ x: 1200, y: groundY - enemyDefaults.h, minX: 1000, maxX: 1280, hp: 2 }),
                    createEnemy({ x: 1300 + 30, y: 270 - enemyDefaults.h, minX: 1300, maxX: 1300 + 200 - enemyDefaults.w, hp: 3 }),
                    createEnemy({ x: 1300 + 110, y: 270 - enemyDefaults.h, minX: 1300, maxX: 1300 + 200 - enemyDefaults.w, hp: 3 }),
                    createEnemy({ x: 1600 + Math.floor(500/2) - Math.floor(enemyDefaults.w/2), y: 270 - enemyDefaults.h, minX: 1600, maxX: 1600 + 500 - enemyDefaults.w, hp: 4 })
                ];
            },
            boss: {
                hp: 30,
                x: 2400,
                y: groundY - 160,
                w: 160,
                h: 160,
                shootInterval: 2.0,
                projSpeed: 300,
                move: 'stationary'
            }
        },

        // world 1 (slightly different layout)
        {
            width: 3600,
            platforms: [
                { x: 0, y: groundY, w: 3600, h: CSS_HEIGHT - groundY },
                { x: 600, y: 240, w: 180, h: 20},
                { x: 1400, y: 230, w: 220, h: 20},
                { x: 2200, y: 300, w: 400, h: 20}
            ],
            enemies: function(){
                return [
                    createEnemy({ x: 150, y: groundY - enemyDefaults.h, minX: 50, maxX: 350, hp: 2 }),
                    createEnemy({ x: 640, y: groundY - enemyDefaults.h, minX: 560, maxX: 820, hp: 3 }),
                    createEnemy({ x: 1350, y: groundY - enemyDefaults.h, minX: 1200, maxX: 1500, hp: 2 }),
                    createEnemy({ x: 1400 + 40, y: 230 - enemyDefaults.h, minX: 1400, maxX: 1400 + 220 - enemyDefaults.w, hp: 3 }),
                    createEnemy({ x: 1400 + 120, y: 230 - enemyDefaults.h, minX: 1400, maxX: 1400 + 220 - enemyDefaults.w, hp: 3 }),
                    createEnemy({ x: 2200 + 100, y: 300 - enemyDefaults.h, minX: 2200, maxX: 2200 + 400 - enemyDefaults.w, hp: 5 })
                ];
            },
            boss: {
                hp: 45,
                x: 3000,
                y: groundY - 160,
                w: 160,
                h: 160,
                shootInterval: 1.5, // faster DPS
                projSpeed: 420,
                move: 'stationary'
            }
        },

        // world 2 (final world)
        {
            width: 5000,
            platforms: [
                { x: 0, y: groundY, w: 5000, h: CSS_HEIGHT - groundY },
                { x: 900, y: 220, w: 200, h: 20},
                { x: 2000, y: 200, w: 300, h: 20},
                { x: 3200, y: 260, w: 360, h: 20}
            ],
            enemies: function(){
                return [
                    createEnemy({ x: 250, y: groundY - enemyDefaults.h, minX: 100, maxX: 420, hp: 2 }),
                    createEnemy({ x: 920, y: groundY - enemyDefaults.h, minX: 820, maxX: 1100, hp: 3 }),
                    createEnemy({ x: 1990, y: groundY - enemyDefaults.h, minX: 1800, maxX: 2200, hp: 2 }),
                    createEnemy({ x: 2000 + 40, y: 200 - enemyDefaults.h, minX: 2000, maxX: 2000 + 300 - enemyDefaults.w, hp: 3 }),
                    createEnemy({ x: 2000 + 160, y: 200 - enemyDefaults.h, minX: 2000, maxX: 2000 + 300 - enemyDefaults.w, hp: 3 }),
                    createEnemy({ x: 3200 + 160, y: 260 - enemyDefaults.h, minX: 3200, maxX: 3200 + 360 - enemyDefaults.w, hp: 6 })
                ];
            },
            boss: {
                hp: 70,
                x: 4200,
                y: groundY - 160,
                w: 160,
                h: 160,
                shootInterval: 1.0, // faster DPS
                projSpeed: 520,
                move: 'vertical', // final boss moves up and down
                moveRange: { minY: groundY - 320, maxY: groundY - 100 },
                moveSpeed: 120 // px/s up/down
            }
        }
    ];

    // current platforms/enemies
    let platforms = [];
    let enemies = [];
    let pendingWorldIndex = null;
    // helper utilities
    function clamp(v, a, b) { return Math.max(a, Math.min(b, v)); }
    function rectIntersect(x1,y1,w1,h1, x2,y2,w2,h2) {
        return x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2;
    }

    // damage handler
    function damageEnemy(e, dmg) {
        if (!e.alive) return;
        e.hp = (e.hp || 1) - dmg;
        if (e.hp <= 0) {
            e.alive = false;
            // if boss died, schedule advance to next world (defer actual load)
            if (e.isBoss) {
                onBossDefeated();
            }
            if (e.isBoss) {
                pendingWorldIndex = currentWorldIndex + 1;
            }
        }
    }

    // spawn specials
    function spawnDonkey() {
        specials.donkey.active = true;
        specials.donkey.activeTime = specials.donkey.duration;
        specials.donkey.cooldown = specials.donkey.cooldownMax;
        specials.donkey.x = clamp(player.x + (player.facing * 60), 10, levelWidth - 80);
        specials.donkey.y = clamp(player.y, 0, CSS_HEIGHT - 56);
        // damage nearby enemies
        for (const en of enemies) {
            if (!en.alive) continue;
            if (rectIntersect(specials.donkey.x - 20, specials.donkey.y - 20, 100, 100, en.x, en.y, en.w, en.h)) {
                damageEnemy(en, 3);
            }
        }
    }

    function spawnPuss() {
        specials.puss.active = true;
        specials.puss.activeTime = specials.puss.duration;
        specials.puss.cooldown = specials.puss.cooldownMax;
        specials.puss.x = clamp(player.x + (player.facing * 60), 10, levelWidth - 50);
        specials.puss.y = clamp(player.y, 0, CSS_HEIGHT - 48);
        projectiles.push({
            x: specials.puss.x + 20 * player.facing,
            y: specials.puss.y + 8,
            vx: 420 * player.facing,
            vy: 0,
            life: 1.5,
            damage: 3,
            owner: 'puss'
        });
    }

    function spawnGingy() {
    specials.gingy.active = true;
    specials.gingy.cooldown = specials.gingy.cooldownMax;
    specials.gingy.usedThisLevel = true;
    specials.gingy.x = Math.max(-200 + cameraX, cameraX - 220);
    specials.gingy.y = clamp(player.y - 20, 0, CSS_HEIGHT - 120);
    specials.gingy.vx = 700;
    specials.gingy.activeTime = Infinity;
    // eliminate any enemy currently on screen using damageEnemy (so boss death is handled properly)
    for (const e of enemies) {
        if (!e.alive) continue;
        if (e.x + e.w >= cameraX && e.x <= cameraX + CSS_WIDTH) {
            damageEnemy(e, 9999);
        }
    }
}

    // level loader
    function loadWorld(index) {
        const w = worlds[index];
        currentWorldIndex = index;
        levelWidth = w.width;
        platforms = JSON.parse(JSON.stringify(w.platforms)); // simple copy
        endBlock = { x: levelWidth - 160, y: groundY - 160, w: 160, h: 160 };
        platforms.push(endBlock);
        enemies = w.enemies();
        // reset player into start area
        player.x = 80;
        player.y = 0;
        player.vx = player.vy = 0;
        player.onGround = false;
        levelState = 'world';
        cameraX = 0;
        specials.gingy.usedThisLevel = false;
    }

    function loadBossForCurrentWorld() {
        const bossCfg = worlds[currentWorldIndex].boss;
        levelState = 'boss';
        // small boss arena width
        levelWidth = Math.max(1200, bossCfg.x + 300);
        platforms = [
            { x: 0, y: groundY, w: levelWidth, h: CSS_HEIGHT - groundY },
            { x: Math.floor(levelWidth/3) - 100, y: groundY - 120, w: 200, h: 16 },
            { x: Math.floor(2*levelWidth/3) - 100, y: groundY - 120, w: 200, h: 16 }
        ];
        endBlock = { x: levelWidth - 160, y: groundY - 160, w: 160, h: 160 };
        platforms.push(endBlock);

        // create boss enemy
        const boss = {
            x: bossCfg.x,
            y: bossCfg.y,
            w: bossCfg.w,
            h: bossCfg.h,
            vx: 0,
            vy: 0,
            minX: bossCfg.x - 100,
            maxX: bossCfg.x + 100,
            alive: true,
            hp: bossCfg.hp,
            isBoss: true,
            shootInterval: bossCfg.shootInterval,
            shootTimer: bossCfg.shootInterval,
            projSpeed: bossCfg.projSpeed,
            moveType: bossCfg.move,
            moveRange: bossCfg.moveRange || null,
            moveSpeed: bossCfg.moveSpeed || 0
        };
        enemies = [ boss ];

        // place player
        player.x = 80;
        player.y = groundY - player.h;
        player.vx = player.vy = 0;
        player.onGround = true;
        cameraX = 0;
        specials.gingy.usedThisLevel = false;
    }

    function onBossDefeated() {
        // if more worlds remain, load next world; else mark game complete
        if (currentWorldIndex < worlds.length - 1) {
            loadWorld(currentWorldIndex + 1);
        } else {
            levelComplete = true; // final boss defeated -> game end
        }
    }

    // initial load
    loadWorld(0);

    // robust finish-block test
    function isTouchingEndBlock() {
        if (!endBlock) return false;
        const pad = 6; // tolerance in pixels
        return rectIntersect(
            player.x, player.y, player.w, player.h,
            endBlock.x - pad, endBlock.y - pad, endBlock.w + pad * 2, endBlock.h + pad * 2
        );
    }

    // player attack
    function doPunchAttack() {
        const range = 48;
        const attackBox = {
            x: player.facing > 0 ? player.x + player.w : player.x - range,
            y: player.y + 8,
            w: range,
            h: player.h - 16
        };
        for (const e of enemies) {
            if (!e.alive) continue;
            if (rectIntersect(attackBox.x, attackBox.y, attackBox.w, attackBox.h, e.x, e.y, e.w, e.h)) {
                // normal punch; specials already use different damage
                damageEnemy(e, 1);
                if (e.vx !== undefined) e.vx = (player.facing > 0 ? 80 : -80);
            }
        }
    }

    let last = performance.now();

    function update(dt) {
        // cooldown reduce
        for (const k of Object.keys(specials)) {
            if (specials[k].cooldown > 0) specials[k].cooldown = Math.max(0, specials[k].cooldown - dt);
            if (specials[k].active && k !== 'gingy') {
                specials[k].activeTime -= dt;
                if (specials[k].activeTime <= 0) specials[k].active = false;
            }
        }

        const prevX = player.x, prevY = player.y;

        if (!levelComplete) {
            // player input
            let moveX = 0;
            if (keys['a']) moveX -= 1;
            if (keys['d']) moveX += 1;
            player.vx = moveX * player.speed;
            if (moveX !== 0) player.facing = moveX > 0 ? 1 : -1;

            if (keys[' '] || keys['space']) {
                if (player.onGround) {
                    player.vy = player.jumpStrength;
                    player.onGround = false;
                }
            }

            if (keys['q'] && player.punching <= 0) {
                player.punching = 0.25;
                doPunchAttack();
            }

            if (keys['e'] && specials.donkey.cooldown <= 0) spawnDonkey();
            if (keys['r'] && specials.puss.cooldown <= 0) spawnPuss();
            if (keys['x'] && specials.gingy.cooldown <= 0 && !specials.gingy.usedThisLevel) spawnGingy();
        } else {
            player.vx = 0;
            player.vy = 0;
        }

        // physics
        player.vy += 1100 * dt;
        player.x += player.vx * dt;
        player.y += player.vy * dt;

        // platform collision
        player.onGround = false;
        for (const plat of platforms) {
            if (rectIntersect(player.x, player.y, player.w, player.h, plat.x, plat.y, plat.w, plat.h)) {
                if (prevY + player.h <= plat.y) {
                    player.y = plat.y - player.h;
                    player.vy = 0;
                    player.onGround = true;
                } else if (prevY >= plat.y + plat.h) {
                    player.y = plat.y + plat.h;
                    player.vy = 0;
                } else if (prevX + player.w <= plat.x) {
                    player.x = plat.x - player.w;
                    player.vx = 0;
                } else if (prevX >= plat.x + plat.w) {
                    player.x = plat.x + plat.w;
                    player.vx = 0;
                } else {
                    player.y = plat.y - player.h;
                    player.vy = 0;
                    player.onGround = true;
                }
            }
        }

        // clamp to level
        player.x = clamp(player.x, 0, levelWidth - player.w);
        if (player.y > CSS_HEIGHT + 400) {
            player.x = 80;
            player.y = 0;
            player.vy = 0;
        }

        if (player.punching > 0) player.punching -= dt;

        // update projectiles (puss or boss)
        for (let i = projectiles.length - 1; i >= 0; i--) {
            const p = projectiles[i];
            p.x += (p.vx || 0) * dt;
            p.y += (p.vy || 0) * dt;
            p.life -= dt;

            // collision with enemies (for player projectiles)
            if (p.owner === 'puss') {
                for (const en of enemies) {
                    if (!en.alive) continue;
                    if (rectIntersect(p.x - 6, p.y - 3, 12, 6, en.x, en.y, en.w, en.h)) {
                        damageEnemy(en, p.damage || 1);
                        projectiles.splice(i,1);
                        break;
                    }
                }
                if (!projectiles[i]) continue;
            }

            // collision with player (boss projectiles)
            if (p.owner === 'boss') {
                if (rectIntersect(player.x, player.y, player.w, player.h, p.x - 6, p.y - 3, 12, 6)) {
                    // hit player -> respawn simple
                    player.x = 80;
                    player.y = 0;
                    player.vx = player.vy = 0;
                    projectiles.splice(i,1);
                    continue;
                }
            }

            if (projectiles[i] && (p.life <= 0 || p.x < -200 || p.x > levelWidth + 200 || p.y < -200 || p.y > CSS_HEIGHT + 200)) {
                projectiles.splice(i,1);
            }
        }

        // boss shooting & movement
        for (const b of enemies) {
            if (!b.alive) continue;
            // boss movement patterns
            if (b.isBoss) {
                if (b.moveType === 'vertical' && b.moveRange) {
                    // move up/down between moveRange
                    if (!b._dir) b._dir = -1; // -1 up, 1 down
                    b.y += b._dir * (b.moveSpeed || 80) * dt;
                    if (b.y < b.moveRange.minY) { b.y = b.moveRange.minY; b._dir = 1; }
                    if (b.y > b.moveRange.maxY) { b.y = b.moveRange.maxY; b._dir = -1; }
                }
                // shooting timer
                b.shootTimer -= dt;
                if (b.shootTimer <= 0) {
                    b.shootTimer = b.shootInterval;
                    // spawn projectile towards player (normalized)
                    const bx = b.x + b.w/2;
                    const by = b.y + b.h/2;
                    const px = player.x + player.w/2;
                    const py = player.y + player.h/2;
                    const dx = px - bx, dy = py - by;
                    const dist = Math.max(1, Math.hypot(dx,dy));
                    const speed = b.projSpeed || 300;
                    const vx = dx / dist * speed;
                    const vy = dy / dist * speed;
                    projectiles.push({
                        x: bx,
                        y: by,
                        vx, vy,
                        life: 6,
                        damage: 1,
                        owner: 'boss'
                    });
                }
            } else {
                // regular enemy patrol
                b.x += (b.vx || 0) * dt;
                if (b.x < b.minX) { b.x = b.minX; b.vx *= -1; }
                if (b.x > b.maxX) { b.x = b.maxX; b.vx *= -1; }
            }

            // collision with player (stomp or hurt)
            if (rectIntersect(player.x, player.y, player.w, player.h, b.x, b.y, b.w, b.h)) {
                if (prevY + player.h <= b.y + 6) {
                    damageEnemy(b, 1);
                    player.vy = player.jumpStrength * 0.6;
                    player.onGround = false;
                } else if (player.punching > 0) {
                    // punching while colliding - do damage already applied in doPunchAttack
                } else {
                    // hurt player
                    player.x = 80;
                    player.y = 0;
                    player.vx = player.vy = 0;
                }
            }
        }

        // check finish block touch (only in world state)
        if (levelState === 'world' && isTouchingEndBlock()) {
            // enter boss for this world
            loadBossForCurrentWorld();
        }

        // update camera
        cameraX = clamp(player.x + player.w/2 - CSS_WIDTH / 2, 0, Math.max(0, levelWidth - CSS_WIDTH));

       // apply pending world transition (deferred to avoid reentrancy during enemy loop)
       if (pendingWorldIndex !== null) {
           const idx = pendingWorldIndex;
           pendingWorldIndex = null;
           if (idx < worlds.length) {
               loadWorld(idx);
           } else {
               levelComplete = true;
           }
       }
    }
    function specialFillTime(v) { return Math.ceil(v); }

    function draw() {
        ctx.clearRect(0,0,CSS_WIDTH, CSS_HEIGHT);
        ctx.save();
        ctx.translate(-cameraX, 0);

        // background
        ctx.fillStyle = '#8fd3a6';
        ctx.fillRect(cameraX,0, CSS_WIDTH, CSS_HEIGHT);

        // draw platforms
        for (const plat of platforms) {
            ctx.fillStyle = (endBlock && plat === endBlock) ? '#ffd700' : '#6b8a3e';
            ctx.fillRect(plat.x, plat.y, plat.w, plat.h);
        }

        // draw end label
        if (levelState === 'world' && endBlock) {
            ctx.fillStyle = '#000';
            ctx.font = '16px sans-serif';
            ctx.fillText('FINISH', endBlock.x + 18, endBlock.y + 90);
        }

        // draw specials
        if (specials.donkey.active) {
            ctx.fillStyle = '#8b5a2b';
            ctx.fillRect(specials.donkey.x, specials.donkey.y, 64, 56);
            ctx.fillStyle = '#fff'; ctx.font = '12px sans-serif';
            ctx.fillText('Donkey', specials.donkey.x + 6, specials.donkey.y + 34);
        }
        if (specials.puss.active) {
            ctx.fillStyle = '#c08c4a';
            ctx.fillRect(specials.puss.x, specials.puss.y, 48, 48);
            ctx.fillStyle = '#000'; ctx.font = '12px sans-serif';
            ctx.fillText('Puss', specials.puss.x + 6, specials.puss.y + 30);
        }
        if (specials.gingy.active) {
            ctx.fillStyle = '#f4a261';
            ctx.fillRect(specials.gingy.x, specials.gingy.y, 120, 120);
            ctx.fillStyle = '#000'; ctx.font = '16px sans-serif';
            ctx.fillText('Giant', specials.gingy.x + 10, specials.gingy.y + 50);
            ctx.fillText('Gingy', specials.gingy.x + 10, specials.gingy.y + 74);
            ctx.fillStyle = 'rgba(255,255,255,0.12)';
            ctx.fillRect(cameraX,0, CSS_WIDTH, CSS_HEIGHT);
        }

        // draw enemies (including boss)
        for (const e of enemies) {
            if (!e.alive) continue;
            ctx.fillStyle = e.isBoss ? '#800000' : '#b22222';
            ctx.fillRect(e.x, e.y, e.w, e.h);
            ctx.fillStyle = '#fff'; ctx.font = '12px sans-serif';
            ctx.fillText(e.isBoss ? 'BOSS' : 'Enemy', e.x - 2, e.y - 6);
            ctx.fillStyle = '#000'; ctx.font = '10px sans-serif';
            ctx.fillText(`HP:${e.hp}`, e.x, e.y - 18);
        }

        // draw projectiles
        for (const p of projectiles) {
            ctx.fillStyle = (p.owner === 'boss') ? '#000' : '#d1d1d1';
            ctx.fillRect(p.x - 6, p.y - 3, 12, 6);
        }

        // draw player
        ctx.save();
        ctx.translate(player.x + player.w/2, player.y + player.h/2);
        ctx.fillStyle = '#3b7a2b';
        ctx.fillRect(-player.w/2, -player.h/2, player.w, player.h);
        ctx.fillStyle = '#fff';
        ctx.fillRect(player.facing*6 - 6, -player.h/4, 8, 8);
        if (player.punching > 0) {
            ctx.fillStyle = 'rgba(255,200,0,0.9)';
            ctx.fillRect(player.facing*player.w/2, -12, player.facing*24, 12);
        }
        ctx.restore();

        ctx.restore();

        // HUD
        ctx.fillStyle = '#000'; ctx.font = '14px sans-serif';
        ctx.fillText('WASD: move  |  Space: jump  |  Q: punch', 10, 20);

        if (levelState === 'boss') {
            ctx.fillStyle = '#900'; ctx.font = '18px sans-serif';
            ctx.fillText('BOSS FIGHT', CSS_WIDTH/2 - 60, 28);
        }

        // specials HUD
        ctx.font = '12px sans-serif';
        ctx.fillStyle = specials.donkey.cooldown > 0 ? '#a00' : '#060';
        ctx.fillText(`E - Donkey: ${specials.donkey.active ? 'ACTIVE' : (specials.donkey.cooldown>0? specialFillTime(specials.donkey.cooldown) + 's' : 'ready')}`, 10, 40);
        ctx.fillStyle = specials.puss.cooldown > 0 ? '#a00' : '#060';
        ctx.fillText(`R - Puss: ${specials.puss.active ? 'ACTIVE' : (specials.puss.cooldown>0? specialFillTime(specials.puss.cooldown) + 's' : 'ready')}`, 10, 56);
        ctx.fillStyle = (specials.gingy.cooldown > 0 || specials.gingy.usedThisLevel) ? '#a00' : '#060';
        const gingyText = specials.gingy.active ? 'ACTIVE' : (specials.gingy.usedThisLevel ? 'used' : (specials.gingy.cooldown>0? specialFillTime(specials.gingy.cooldown) + 's' : 'ready'));
        ctx.fillText(`X - Giant Gingy: ${gingyText}`, 10, 72);

        // progress bar
        const barX = 10, barY = CSS_HEIGHT - 18, barW = 240, barH = 8;
        ctx.fillStyle = '#ddd';
        ctx.fillRect(barX, barY, barW, barH);
        const progress = clamp((player.x + player.w/2) / levelWidth, 0, 1);
        ctx.fillStyle = '#3b7a2b';
        ctx.fillRect(barX, barY, barW * progress, barH);
        ctx.strokeStyle = '#000';
        ctx.strokeRect(barX, barY, barW, barH);

        // final game complete
        if (levelComplete) {
            ctx.fillStyle = 'rgba(0,0,0,0.6)';
            ctx.fillRect(CSS_WIDTH/2 - 160, CSS_HEIGHT/2 - 40, 320, 80);
            ctx.fillStyle = '#fff';
            ctx.font = '20px sans-serif';
            ctx.fillText('You beat the game!', CSS_WIDTH/2 - 120, CSS_HEIGHT/2);
            ctx.font = '12px sans-serif';
            ctx.fillText('Press F5 to restart', CSS_WIDTH/2 - 50, CSS_HEIGHT/2 + 24);
        }
    }

    function loop(ts) {
        const dt = Math.min(0.033, (ts - last) / 1000);
        last = ts;
        update(dt);
        draw();
        requestAnimationFrame(loop);
    }
    requestAnimationFrame(loop);

    // allow canvas to receive keyboard events when clicked
    canvas.addEventListener('click', () => canvas.focus());
})();