#include <jni.h>
#include "react-native-pitchy.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_pitchy_PitchyModule_nativeAutoCorrelate(JNIEnv *env, jclass type, jdoubleArray buf, jdouble sampleRate) {
    jsize len = env->GetArrayLength(buf);
    jdouble *bufArray = env->GetDoubleArrayElements(buf, 0);
    std::vector<double> bufVector(bufArray, bufArray + len);
    env->ReleaseDoubleArrayElements(buf, bufArray, 0);
    return pitchy::autoCorrelate(bufVector, sampleRate);
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_pitchy_PitchyModule_nativeCalculateVolume(JNIEnv *env, jclass type, jdoubleArray buf) {
    jsize len = env->GetArrayLength(buf);
    jdouble *bufArray = env->GetDoubleArrayElements(buf, 0);
    std::vector<double> bufVector(bufArray, bufArray + len);
    env->ReleaseDoubleArrayElements(buf, bufArray, 0);
    return pitchy::calculateVolume(bufVector);
}