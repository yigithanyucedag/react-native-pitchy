#include <jni.h>
#include "react-native-pitchy.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_pitchy_PitchyModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return pitchy::multiply(a, b);
}
