# react-native-pitchy

A simple pitch detection module for React Native

## Installation

```sh
npm install react-native-pitchy
```

## Usage

### Get pitch (Hz)

```js
import { autoCorrelate } from 'react-native-pitchy';

const audioBuffer = new Float32Array(4096); // Dummy audio buffer
const sampleRate = 44100;
const pitch = await autoCorrelate(audioBuffer, sampleRate); // returns the pitch in Hz
```

### Get volume (dB)

```js
import { getVolume } from 'react-native-pitchy';

const audioBuffer = new Float32Array(4096); // Dummy audio buffer
const volume = await getVolume(audioBuffer); // returns the volume in dB
```

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT
