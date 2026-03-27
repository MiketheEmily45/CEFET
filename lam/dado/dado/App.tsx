import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View, Image, TouchableOpacity } from 'react-native';
import { useState } from 'react';

export default function App() {
  const [number, setNumber] = useState<number | null>(null);

  const handlePress = () => {
    const randomNumber = Math.floor(Math.random() * 6) + 1;
    setNumber(randomNumber);
  };

  return (
    <View style={styles.container}>
      <TouchableOpacity onPress={handlePress}>
        <Image source={require('./assets/dado.png')} style={{ width: 200, height: 200 }} />
      </TouchableOpacity>
      <Text>toque no dado para girar!</Text>
      {number !== null && <Text style={styles.numberText}>{number}</Text>}
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
  numberText: {
    fontSize: 48,
    fontWeight: 'bold',
    color: '#333',
    marginTop: 20,
  },
});
