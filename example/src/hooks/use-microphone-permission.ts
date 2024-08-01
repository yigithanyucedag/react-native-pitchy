import { useEffect, useState } from 'react';
import { Platform } from 'react-native';
import { type Permission, request } from 'react-native-permissions';

export const useMicrophonePermission = () => {
  const [hasPermission, setHasPermission] = useState(false);

  useEffect(() => {
    const permission = Platform.select({
      ios: 'ios.permission.MICROPHONE',
      android: 'android.permission.RECORD_AUDIO',
    });
    if (!permission) {
      return;
    }
    request(permission as Permission).then((result) => {
      setHasPermission(result === 'granted');
    });
  }, []);
  return hasPermission;
};
