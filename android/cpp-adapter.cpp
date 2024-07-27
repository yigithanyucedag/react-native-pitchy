#include <jni.h>
#include "react-native-pitchy.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits>

extern "C" JNIEXPORT jdouble JNICALL
Java_com_pitchy_PitchyModule_nativeAutoCorrelate(JNIEnv *env, jobject /* this */, jdoubleArray buf, jdouble sampleRate)
{
    jsize len = env->GetArrayLength(buf);
    jdouble *bufArray = env->GetDoubleArrayElements(buf, 0);
    std::vector<double> vec(bufArray, bufArray + len);
    env->ReleaseDoubleArrayElements(buf, bufArray, 0);
    return pitchy::autoCorrelate(vec, sampleRate);
}

extern "C" JNIEXPORT jdouble JNICALL
Java_com_pitchy_PitchyModule_nativeCalculateVolume(JNIEnv *env, jobject /* this */, jdoubleArray buf)
{
    jsize len = env->GetArrayLength(buf);
    jdouble *bufArray = env->GetDoubleArrayElements(buf, 0);
    std::vector<double> vec(bufArray, bufArray + len);
    env->ReleaseDoubleArrayElements(buf, bufArray, 0);
    return pitchy::calculateVolume(vec);
}