import { doc, deleteDoc } from "firebase/firestore";
import { db } from "./firebaseConfig";

export const deletarMensagem = async (id: string) => {
 try {
   await deleteDoc(doc(db, "mensagens", id));
   console.log("Mensagem deletada!");
 } catch (error) {
   console.log("Erro ao deletar:", error);
 }
};