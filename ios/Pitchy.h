#ifdef __cplusplus
#import "react-native-pitchy.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNPitchySpec.h"

@interface Pitchy : NSObject <NativePitchySpec>
#else
#import <React/RCTBridgeModule.h>

@interface Pitchy : NSObject <RCTBridgeModule>
#endif

@end
