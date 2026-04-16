import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';
import { styles } from './HomeStyle';
import Rodape from '../../components/rodape/Rodape';

export default function Home() {
  return (
    <View style={styles.container}>
      <Text>Criador de senhas!</Text>
      <StatusBar style="auto" />
      <Rodape />
    </View>
  );
}