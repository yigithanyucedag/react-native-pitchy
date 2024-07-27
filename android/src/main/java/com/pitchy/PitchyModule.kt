package com.pitchy

import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.Promise

class PitchyModule(reactContext: ReactApplicationContext) :
  ReactContextBaseJavaModule(reactContext) {

  override fun getName(): String {
    return NAME
  }

  @ReactMethod
  fun nativeAutoCorrelate(buf: DoubleArray, sampleRate: Double, promise: Promise) {
    // Call native method
    val result = autoCorrelate(buf, sampleRate)

    // Resolve promise
    promise.resolve(result)
  }

  @ReactMethod
  fun calculateVolume(buf: DoubleArray, promise: Promise) {
    // Call native method
    val result = calculateVolume(buf)

    // Resolve promise
    promise.resolve(result)
  }


  companion object {
    const val NAME = "Pitchy"
  }
}
