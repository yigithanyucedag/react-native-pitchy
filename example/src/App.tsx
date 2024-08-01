import { useEffect, useState } from 'react';
import { StyleSheet, Text, View } from 'react-native';
import Pitchy from 'react-native-pitchy';

import { useMicrophonePermission } from './hooks/use-microphone-permission';

export default function App() {
  const permissionGranted = useMicrophonePermission();

  const [frequency, setFrequency] = useState<number | undefined>();

  useEffect(() => {
    Pitchy.init({
      minVolume: -45,
    });
    Pitchy.addListener((data) => {
      setFrequency(data.pitch);
    });
  }, []);

  useEffect(() => {
    if (!permissionGranted) return;

    Pitchy.start();

    return () => {
      Pitchy.stop();
    };
  }, [permissionGranted]);

  return (
    <View style={styles.container}>
      <Text>Frequency: {frequency}</Text>
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
