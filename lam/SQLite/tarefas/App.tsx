import React, { useEffect, useState } from "react";
import * as SQLite from "expo-sqlite";
import { View, Text, TextInput, Button, FlatList, StyleSheet } from "react-native";


export default function App() {
  type Tarefa = {
  	id: number;
   	descricao: string;
  };
  const [db, setDb] = useState<SQLite.SQLiteDatabase | null>(null);
  const [descricao, setDescricao] = useState("");
  const [tarefas, setTarefas] = useState<Tarefa[]>([]);
  useEffect(() => {
    const initDb = async () => {
      const database: SQLite.SQLiteDatabase = await SQLite.openDatabaseAsync("tarefas.db");
      setDb(database);
      await database.execAsync(`
        CREATE TABLE IF NOT EXISTS tarefas (
          id INTEGER PRIMARY KEY AUTOINCREMENT,
          descricao TEXT
        );
      `);
    };
    initDb();
    if (db) {
      carregarTarefas();
    }
  }, [db]);
  const carregarTarefas = async () => {
    if (!db) return;
    const result = await db.getAllAsync<Tarefa>("SELECT * FROM tarefas;");
    setTarefas(result);
  };
  const atualizarTarefa = async (id: number, novaDescricao: string) => {
    if (!db) return;
    await db.runAsync("UPDATE tarefas SET descricao = ? WHERE id = ?;", [novaDescricao, id]);
    carregarTarefas();
  };
  const deletarTarefa = async (id: number) => {
    if (!db) return;
    await db.runAsync("DELETE FROM tarefas WHERE id = ?;", [id]);
    carregarTarefas();
  };
  const adicionarTarefa = async () => {
    if (!db) return;
    if (descricao.trim() === "") return;
    await db.runAsync("INSERT INTO tarefas (descricao) VALUES (?);", [descricao]);
    setDescricao("");
    carregarTarefas();
  };
  return (
    <View style={styles.container}>
      <Text style={styles.titulo}>Minhas Tarefas</Text>
      <TextInput
        placeholder="Digite uma tarefa..."
        value={descricao}
        onChangeText={setDescricao}
        style={styles.texto}
      />
      <Button title="Adicionar" onPress={adicionarTarefa} />

      <FlatList
        data={tarefas}
        keyExtractor={(item) => item.id.toString()}
        renderItem={({ item }) => (
          <View style={styles.lista}>
            <Text>{item.descricao}</Text>
            <View style={{ flexDirection: "row", gap: 10 }}>
              <Button title="Editar" onPress={() => atualizarTarefa(item.id, "Novo texto")} />
              <Button title="Excluir" onPress={() => deletarTarefa(item.id)} />
            </View>
          </View>
        )}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 20,
  },
  titulo: {
    fontSize: 20,
    marginBottom: 30,
    marginTop: 20,
  },
  lista: {
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center",
    padding: 10,
    borderBottomWidth: 1,
    borderBottomColor: "#ddd",
  },
  texto: {
    borderWidth: 1,
    borderColor: "#ccc",
    padding: 8,
    marginBottom: 10,
    borderRadius: 5,
  }
});