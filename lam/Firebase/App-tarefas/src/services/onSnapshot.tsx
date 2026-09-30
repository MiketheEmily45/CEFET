import { collection, onSnapshot, orderBy, query } from "firebase/firestore";
import { useEffect, useState } from "react";
import { db } from "./firebaseConfig";

export type Mensagem = {
    id: string;
    texto: string;
    data?: string;
};

export const useMensagens = () => {
    const [mensagens, setMensagens] = useState<Mensagem[]>([]);

    useEffect(() => {
        const mensagensQuery = query(
            collection(db, "mensagens"),
            orderBy("data", "desc"),
        );
        const unsubscribe = onSnapshot(mensagensQuery, (snapshot) => {
            setMensagens(
                snapshot.docs.map((documento) => ({
                    id: documento.id,
                    ...(documento.data() as Omit<Mensagem, "id">),
                })),
            );
        });

        return unsubscribe;
    }, []);

    return mensagens;
};