import { useEffect, useState } from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { autoCorrelate } from 'react-native-pitchy';

export default function App() {
  const [result, setResult] = useState<number | undefined>();

  useEffect(() => {
    const data = new Array(2048)
      .fill(0)
      .map((_, i) => Math.sin((i / 2048) * Math.PI * 2 * 440));
    autoCorrelate(data, 44100).then(setResult);
  }, []);

  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
