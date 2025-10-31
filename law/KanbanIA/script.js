document.addEventListener('DOMContentLoaded', () => {
    let taskIdCounter = 2; // Começa em 2 porque já temos uma tarefa de exemplo com id=1

    // --- Funcionalidade de Adicionar Tarefa (Modal) ---
    const modal = document.getElementById('add-task-modal');
    const closeBtn = document.querySelector('.close-btn');
    const saveTaskBtn = document.getElementById('save-task-btn');
    const newTaskInput = document.getElementById('new-task-input');
    const addTaskButtons = document.querySelectorAll('.add-task-btn');
    let targetTaskListId = ''; // Para saber em qual lista adicionar a tarefa

    // Abrir o modal
    addTaskButtons.forEach(button => {
        button.addEventListener('click', (e) => {
            targetTaskListId = e.target.getAttribute('data-column');
            modal.style.display = 'block';
            newTaskInput.value = ''; // Limpar o input
            newTaskInput.focus();
        });
    });

    // Fechar o modal
    closeBtn.addEventListener('click', () => {
        modal.style.display = 'none';
    });

    // Fechar o modal ao clicar fora
    window.addEventListener('click', (e) => {
        if (e.target === modal) {
            modal.style.display = 'none';
        }
    });

    // Adicionar a tarefa
    saveTaskBtn.addEventListener('click', () => {
        const taskText = newTaskInput.value.trim();
        if (taskText) {
            addTaskToColumn(taskText, targetTaskListId);
            modal.style.display = 'none';
        } else {
            alert('Por favor, insira a descrição da tarefa.');
        }
    });

    // Função para criar e adicionar a tarefa
    function addTaskToColumn(text, listId) {
        const taskList = document.getElementById(listId);
        const newTask = document.createElement('div');
        newTask.classList.add('kanban-task');
        newTask.setAttribute('draggable', 'true');
        newTask.setAttribute('id', `task-${taskIdCounter++}`);
        
        // Conteúdo da tarefa: texto e botão de exclusão
        const taskContent = document.createElement('span');
        taskContent.textContent = text;
        
        const deleteButton = document.createElement('button');
        deleteButton.classList.add('delete-task-btn');
        deleteButton.textContent = 'X';
        deleteButton.addEventListener('click', deleteTask);

        newTask.appendChild(taskContent);
        newTask.appendChild(deleteButton);
        
        // Adicionar os event listeners de drag-and-drop à nova tarefa
        addDragListeners(newTask);

        taskList.appendChild(newTask);
    }

    // Função para excluir a tarefa
    function deleteTask(e) {
        // O botão está dentro da div.kanban-task
        const task = e.target.closest('.kanban-task');
        if (task) {
            task.remove();
        }
    }

    // --- Funcionalidade de Drag and Drop ---

    let draggedTask = null;

    // Função para adicionar os listeners de drag a uma tarefa
    function addDragListeners(task) {
        task.addEventListener('dragstart', dragStart);
        task.addEventListener('dragend', dragEnd);
    }

    // Adicionar listeners a todas as tarefas existentes (tarefa de exemplo) e adicionar botão de exclusão
    document.querySelectorAll('.kanban-task').forEach(task => {
        // Adicionar botão de exclusão à tarefa de exemplo
        const deleteButton = document.createElement('button');
        deleteButton.classList.add('delete-task-btn');
        deleteButton.textContent = 'X';
        deleteButton.addEventListener('click', deleteTask);
        
        // Envolver o texto existente em um span para melhor controle de layout
        const taskText = document.createElement('span');
        taskText.textContent = task.textContent.trim();
        task.textContent = ''; // Limpa o conteúdo original
        task.appendChild(taskText);
        task.appendChild(deleteButton);
        
        addDragListeners(task);
    });

    // Eventos de Drag
    function dragStart() {
        draggedTask = this;
        setTimeout(() => this.classList.add('dragging'), 0);
    }

    function dragEnd() {
        this.classList.remove('dragging');
        draggedTask = null;
    }

    // Eventos de Drop (nas listas de tarefas)
    const taskLists = document.querySelectorAll('.task-list');

    taskLists.forEach(list => {
        list.addEventListener('dragover', dragOver);
        list.addEventListener('dragenter', dragEnter);
        list.addEventListener('dragleave', dragLeave);
        list.addEventListener('drop', drop);
    });

    function dragOver(e) {
        e.preventDefault(); // Necessário para permitir o drop
        const afterElement = getDragAfterElement(this, e.clientY);
        const draggable = document.querySelector('.dragging');

        if (!draggable) return;

        // Adicionar feedback visual de drag-over na lista
        this.classList.add('drag-over');

        if (afterElement == null) {
            this.appendChild(draggable);
        } else {
            this.insertBefore(draggable, afterElement);
        }
    }

    function dragEnter(e) {
        e.preventDefault();
        // Não adicionamos a classe drag-over aqui, apenas no dragOver para evitar flickering
    }

    function dragLeave() {
        // Remover feedback visual de drag-over
        this.classList.remove('drag-over');
    }

    function drop() {
        // Remover feedback visual de drag-over
        this.classList.remove('drag-over');
        // O elemento já foi movido no dragOver, o drop apenas finaliza
    }

    // Função auxiliar para determinar onde inserir o elemento (para reordenar)
    function getDragAfterElement(container, y) {
        // Filtra todos os elementos que não estão sendo arrastados
        const draggableElements = [...container.querySelectorAll('.kanban-task:not(.dragging)')];

        return draggableElements.reduce((closest, child) => {
            const box = child.getBoundingClientRect();
            const offset = y - box.top - box.height / 2; // Calcula a distância do centro
            
            // Se o offset for negativo e mais próximo de zero (ou seja, acima do centro)
            if (offset < 0 && offset > closest.offset) {
                return { offset: offset, element: child };
            } else {
                return closest;
            }
        }, { offset: Number.NEGATIVE_INFINITY }).element; // Começa com o valor mais negativo
    }

    // Inicializar o contador de tarefas para a tarefa de exemplo
    if (document.getElementById('task-1')) {
        // A tarefa de exemplo já foi processada acima, então o contador está correto.
    }
});
