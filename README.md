# react-native-pitchy

A real-time pitch detection library for React Native.

## Installation

1. Install the library using a package manager of your choice:

```sh
npm install react-native-pitchy
```

2. **Linking (iOS only):**

```sh
npx pod-install
```

3. **Rebuild your app** after installing the package.

> On iOS simulators, pitch detection may not work as expected due to the **lack of microphone support**. Make sure to test on a real device.

## Permissions

Microphone permissions are **required for pitch detection** to work. Make sure to request the necessary permissions before starting pitch detection. You can use a library like [react-native-permissions](https://github.com/zoontek/react-native-permissions) to request permissions.

### iOS

`Microphone`

### Android

`RECORD_AUDIO`

## Usage

1. Import the library:

```tsx
import Pitchy, { PitchyConfig, PitchyEventCallback } from 'react-native-pitchy';
```

2. **(Optional)** Configure Pitchy before initialization:

```tsx
const config: PitchyConfig = {
  bufferSize: 4096, // Adjust buffer size for performance vs accuracy
  minVolume: -60, // Minimum volume threshold for pitch detection (in dB)
};
```

3. Initialize Pitchy with the optional configuration:

```tsx
Pitchy.init(config);
```

4. Start pitch detection:

```tsx
Pitchy.start().then(() => {
  console.log('Pitch detection started!');
});
```

5. Listen to pitch events:

```tsx
const handlePitchDetected: PitchyEventCallback = (data) => {
  console.log('Pitch detected:', data.pitch);
};

const subscription = Pitchy.addListener(handlePitchDetected);

// Remember to unsubscribe later to avoid memory leaks
subscription.remove();
```

6. Stop pitch detection:

```tsx
Pitchy.stop().then(() => {
  console.log('Pitch detection stopped!');
});
```

7. Check if pitch detection is running:

```tsx
Pitchy.isRecording().then((isRecording) => {
  console.log('Pitch detection is recording:', isRecording);
});
```

## API

### Types

- `PitchyAlgorithm`: String representing the pitch detection algorithm (currently only supports `"ACF2+"`)
- `PitchyConfig`: Configuration object for Pitchy.init
  - `bufferSize`: (optional) Number representing the audio buffer size (default: 4096)
  - `minVolume`: (optional) Number representing the minimum volume threshold (default: -60)
  - `algorithm`: (optional) `PitchyAlgorithm` used for detection (default: "ACF2+")
- `PitchyEventCallback`: Function called when pitch is detected. Receives an object with a `pitch` property (number)

### Methods

- `Pitchy.init(config?: PitchyConfig)`: Initializes Pitchy with an optional configuration.
- `Pitchy.start()`: Starts pitch detection and returns a Promise.
- `Pitchy.stop()`: Stops pitch detection and returns a Promise.
- `Pitchy.isRecording()`: Checks if pitch detection is currently running and returns a Promise resolving to a boolean.
- `Pitchy.addListener(callback: PitchyEventCallback)`: Adds a listener for the `onPitchDetected` event.

## Roadmap

- [ ] Fix example app (permissions issue related to builder-bob)
- [ ] Add FFT for ACF2+ algorithm (currently uses a naive implementation)
- [ ] Add more pitch detection algorithms

## Examples

Check out the [example app](example) for a simple implementation of pitch detection using Pitchy.

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT
