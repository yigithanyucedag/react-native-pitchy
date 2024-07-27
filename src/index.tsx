import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package 'react-native-pitchy' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

const Pitchy = NativeModules.Pitchy
  ? NativeModules.Pitchy
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
        },
      }
    );

/**
 * Detects the pitch of the audio data in the buffer.
 * @param buf The audio data buffer.
 * @param sampleRate The sample rate of the audio data.
 * @returns A promise that resolves to the detected pitch in Hz.
 */
export function autoCorrelate(
  buf: ArrayLike<number>,
  sampleRate: number
): Promise<number> {
  return Pitchy.autoCorrelate(buf, sampleRate);
}

/**
 * Calculates the volume of the audio data in the buffer.
 * @param buf The audio data buffer.
 * @returns A promise that resolves to the calculated volume in dB.
 */
export function calculateVolume(buf: ArrayLike<number>): Promise<number> {
  return Pitchy.calculateVolume(buf);
}
