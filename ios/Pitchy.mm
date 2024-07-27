#import "Pitchy.h"

@implementation Pitchy
RCT_EXPORT_MODULE()

// Example method
// See // https://reactnative.dev/docs/native-modules-ios
RCT_EXPORT_METHOD(multiply:(double)a
                  b:(double)b
                  resolve:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject)
{
    NSNumber *result = @(pitchy::multiply(a, b));

    resolve(result);
}

// Method to expose autoCorrelate
RCT_EXPORT_METHOD(autoCorrelate:(NSArray<NSNumber *> *)buf
                  sampleRate:(double)sampleRate
                  resolve:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject)
{
    // Convert NSArray<NSNumber *> to std::vector<double>
    std::vector<double> cBuf;
    for (NSNumber *num in buf) {
        cBuf.push_back([num doubleValue]);
    }

    // Call the autoCorrelate function
    double result = pitchy::autoCorrelate(cBuf, sampleRate);
    
    if (result < 0) {
        reject(@"autoCorrelate_error", @"Not enough signal", nil);
    } else {
        NSNumber *resultNumber = @(result);
        resolve(resultNumber);
    }
}


@end
