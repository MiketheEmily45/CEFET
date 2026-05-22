import React from 'react';
import { View, Text, Button, StyleSheet } from 'react-native';

export default function Detalhe({route, navigation}: any) {
    const { idlivro, titulolivro, autorlivro, anolivro } = route.params;
    return (
        <View style={styles.container}>
            <Text style={styles.text}>Detalhes do Livro</Text>
            <Text>ID: {idlivro}</Text>
            <Text>Título: {titulolivro}</Text>
            <Text>Autor: {autorlivro}</Text>
            <Text>Ano: {anolivro}</Text>
            <Button title='Voltar para lista' onPress={() => navigation.goBack()}/>
        </View>
    );
}
const styles = StyleSheet.create({
    container: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
        backgroundColor: 'lightblue',
    },
    text: {
        fontSize: 20,
        fontWeight: 'bold',
    }
});