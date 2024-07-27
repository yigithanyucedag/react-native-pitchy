#import "Pitchy.h"

@implementation Pitchy
RCT_EXPORT_MODULE()

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

    resolve([NSNumber numberWithDouble:result]);
}

// Method to expose calculateVolume
RCT_EXPORT_METHOD(calculateVolume:(NSArray<NSNumber *> *)buf
                  resolve:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject)
{
    // Convert NSArray<NSNumber *> to std::vector<double>
    std::vector<double> cBuf;
    for (NSNumber *num in buf) {
        cBuf.push_back([num doubleValue]);
    }

    // Call the calculateVolume function
    double result = pitchy::calculateVolume(cBuf);

    resolve([NSNumber numberWithDouble:result]);
}

@end
