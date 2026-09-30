import { collection, addDoc, onSnapshot } from "firebase/firestore";
import { db } from "./firebaseConfig";

const adicionarMensagem = async () => {
 try {
   await addDoc(collection(db, "mensagens"), {
     texto: "Minha primeira mensagem!",
     autor: "Aluno",
     data: new Date().toISOString(),
   });
   console.log("Mensagem adicionada com sucesso!");
 } catch (error) {
   console.log("Erro ao adicionar:", error);
 }
};