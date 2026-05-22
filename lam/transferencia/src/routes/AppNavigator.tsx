import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import ListaProdutos from '../screens/ListaProdutos';
import Detalhe from '../screens/Detalhe';

const Stack = createStackNavigator();

export default function AppNavigator() {
    return (
        <NavigationContainer>
            <Stack.Navigator initialRouteName='pag-lista'>
                <Stack.Screen name='pag-lista' component={ListaProdutos} options={{ title: 'Lista de Produtos', headerTitleAlign: 'center', headerStyle: {backgroundColor: 'gray'}}} />
                <Stack.Screen name='pag-detalhe' component={Detalhe} options={{ title: 'Detalhes do Livro', headerTitleAlign: 'center', headerStyle: {backgroundColor: 'gray'}}} />
            </Stack.Navigator>
        </NavigationContainer>
    );
}