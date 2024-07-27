package com.pitchy

import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReadableArray

class PitchyModule(reactContext: ReactApplicationContext) :
  ReactContextBaseJavaModule(reactContext) {

  override fun getName(): String {
    return NAME
  }

  @ReactMethod
  fun autoCorrelate(buf: ReadableArray, sampleRate: Double, promise: Promise) {
    val bufArray = buf.toArrayList().map { it as Double }.toDoubleArray()
    val pitch = nativeAutoCorrelate(bufArray, sampleRate)
    promise.resolve(pitch)
  }

  @ReactMethod
  fun calculateVolume(buf: ReadableArray, promise: Promise) {
    val bufArray = buf.toArrayList().map { it as Double }.toDoubleArray()
    val volume = nativeCalculateVolume(bufArray)
    promise.resolve(volume)
  }

  private external fun nativeAutoCorrelate(buf: DoubleArray, sampleRate: Double): Double
  private external fun nativeCalculateVolume(buf: DoubleArray): Double

  companion object {
    const val NAME = "Pitchy"
    init {
      System.loadLibrary("react-native-pitchy")
    }
  }
}