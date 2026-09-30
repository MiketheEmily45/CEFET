import React, { useState } from "react";
import {
  Alert,
  FlatList,
  Pressable,
  SafeAreaView,
  StyleSheet,
  Text,
  TextInput,
  View,
} from "react-native";
import { db } from "./src/services/firebaseConfig";
import { atualizarMensagem } from "./src/services/updateDoc";
import { deletarMensagem } from "./src/services/deleteDoc";
import { useMensagens } from "./src/services/onSnapshot";
import { addDoc, collection } from "firebase/firestore";


export default function App() {
 const mensagens = useMensagens();
 const [novoTexto, setNovoTexto] = useState("");
 const [editandoId, setEditandoId] = useState<string | null>(null);
 const [textoEditado, setTextoEditado] = useState("");

 const adicionarMensagem = async () => {
   if (novoTexto.trim() === "") return;
   try {
     await addDoc(collection(db, "mensagens"), {
       texto: novoTexto.trim(),
       data: new Date().toISOString(),
     });
     setNovoTexto("");
   } catch {
     Alert.alert("Erro", "Não foi possível adicionar a tarefa.");
   }
 };

 const iniciarEdicao = (id: string, texto: string) => {
   setEditandoId(id);
   setTextoEditado(texto);
 };

 const salvarEdicao = async () => {
   if (!editandoId || textoEditado.trim() === "") return;
   await atualizarMensagem(editandoId, textoEditado.trim());
   setEditandoId(null);
   setTextoEditado("");
 };

 const confirmarExclusao = (id: string) => {
   Alert.alert("Excluir tarefa", "Deseja remover esta tarefa?", [
     { text: "Cancelar", style: "cancel" },
     { text: "Excluir", style: "destructive", onPress: () => deletarMensagem(id) },
   ]);
 };

 return (
   <SafeAreaView style={styles.safeArea}>
     <View style={styles.container}>
       <Text style={styles.title}>App de Tarefas 📝</Text>
       <TextInput
         placeholder="Digite uma mensagem"
         placeholderTextColor="#8a8f98"
         value={novoTexto}
         onChangeText={setNovoTexto}
         onSubmitEditing={adicionarMensagem}
         returnKeyType="done"
         style={styles.input}
       />
       <Pressable style={styles.addButton} onPress={adicionarMensagem}>
         <Text style={styles.addButtonText}>ADICIONAR</Text>
       </Pressable>

       <FlatList
         data={mensagens}
         keyExtractor={(item) => item.id}
         contentContainerStyle={styles.list}
         ListEmptyComponent={<Text style={styles.emptyText}>Nenhuma tarefa ainda.</Text>}
         renderItem={({ item }) => (
           <View style={styles.taskRow}>
             {editandoId === item.id ? (
               <TextInput
                 value={textoEditado}
                 onChangeText={setTextoEditado}
                 onSubmitEditing={salvarEdicao}
                 autoFocus
                 style={styles.editInput}
               />
             ) : (
               <Text style={styles.taskText}>{item.texto}</Text>
             )}
             <View style={styles.actions}>
               <Pressable
                 style={styles.actionButton}
                 onPress={editandoId === item.id ? salvarEdicao : () => iniciarEdicao(item.id, item.texto)}
                 accessibilityLabel={editandoId === item.id ? "Salvar tarefa" : "Editar tarefa"}
               >
                 <Text style={styles.actionIcon}>{editandoId === item.id ? "✓" : "✎"}</Text>
               </Pressable>
               <Pressable
                 style={styles.actionButton}
                 onPress={() => confirmarExclusao(item.id)}
                 accessibilityLabel="Excluir tarefa"
               >
                 <Text style={styles.actionIcon}>🗑</Text>
               </Pressable>
             </View>
           </View>
         )}
       />
     </View>
   </SafeAreaView>
 );
}

const styles = StyleSheet.create({
 safeArea: { flex: 1, backgroundColor: "#ffffff" },
 container: { flex: 1, paddingHorizontal: 24, paddingTop: 18 },
 title: { color: "#202124", fontSize: 20, fontWeight: "700", marginBottom: 16 },
 input: {
   borderColor: "#4b4b4b",
   borderRadius: 5,
   borderWidth: 1,
   color: "#202124",
   fontSize: 16,
   height: 38,
   paddingHorizontal: 10,
 },
 addButton: {
   alignItems: "center",
   backgroundColor: "#2f86eb",
   borderRadius: 2,
   elevation: 2,
   justifyContent: "center",
   marginTop: 10,
   minHeight: 36,
 },
 addButtonText: { color: "#ffffff", fontSize: 14, fontWeight: "700" },
 list: { paddingTop: 9 },
 taskRow: {
   alignItems: "center",
   borderBottomColor: "#8d8d8d",
   borderBottomWidth: 1.5,
   flexDirection: "row",
   minHeight: 55,
   paddingVertical: 8,
 },
 taskText: { color: "#333333", flex: 1, fontSize: 15, paddingHorizontal: 10 },
 editInput: {
   borderColor: "#2f86eb",
   borderRadius: 3,
   borderWidth: 1,
   color: "#333333",
   flex: 1,
   fontSize: 15,
   marginHorizontal: 5,
   paddingHorizontal: 6,
 },
 actions: { flexDirection: "row", gap: 10 },
 actionButton: {
   alignItems: "center",
   backgroundColor: "#2f86eb",
   borderRadius: 2,
   elevation: 2,
   height: 35,
   justifyContent: "center",
   width: 35,
 },
 actionIcon: { color: "#ffffff", fontSize: 20 },
 emptyText: { color: "#777777", paddingTop: 24, textAlign: "center" },
});
