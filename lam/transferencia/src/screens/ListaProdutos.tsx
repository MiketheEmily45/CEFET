import React from 'react';
import { View, Text, Button, StyleSheet } from 'react-native';

export default function ListaProdutos({navigation}: any) {
    const Livro = {
        id: 1,
        titulo: 'O Senhor dos Anéis',
        autor: 'J.R.R. Tolkien',
        ano: 1954,
    };

    const handleVerDetalhe = () => {
        navigation.navigate('pag-detalhe', { idlivro: Livro.id, titulolivro: Livro.titulo, autorlivro: Livro.autor, anolivro: Livro.ano });
    };
    return (
        <View style={styles.container}>
            <Text style={styles.text}>Lista de Produtos</Text>
            <Button title='Ver detalhes do livro' onPress={handleVerDetalhe}/>
        </View>
    );
}
const styles = StyleSheet.create({
    container: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
        backgroundColor: 'yellow',
    },
    text: {
        fontSize: 20,
        fontWeight: 'bold',
    }
}); 