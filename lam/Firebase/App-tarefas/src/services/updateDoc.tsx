import { doc, updateDoc } from "firebase/firestore";
import { db } from "./firebaseConfig";


export const atualizarMensagem = async (id: string, texto = "Mensagem atualizada!") => {
 try {
   const docRef = doc(db, "mensagens", id);
   await updateDoc(docRef, {
    texto,
   });
   console.log("Mensagem atualizada!");
 } catch (error) {
   console.log("Erro ao atualizar:", error);
 }
};