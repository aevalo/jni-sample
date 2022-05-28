#include <jni.h>
#include <cstring>
#include <sample_native.hpp>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     org_example_java_Sample1
 * Method:    intMethod
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_example_java_Sample1_intMethod(JNIEnv* env, jobject obj, jint num) {
  return square(num);
}

/*
 * Class:     org_example_java_Sample1
 * Method:    booleanMethod
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_example_java_Sample1_booleanMethod(JNIEnv* env, jobject obj, jboolean boolean) {
  return invert(boolean);
}

/*
 * Class:     org_example_java_Sample1
 * Method:    stringMethod
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_example_java_Sample1_stringMethod(JNIEnv* env, jobject obj, jstring string) {
  const char* str = env->GetStringUTFChars(string, 0);
  char cap[128];
  strcpy(cap, str);
  env->ReleaseStringUTFChars(string, str);
  uppercase(cap);
  return env->NewStringUTF(cap);
}

/*
 * Class:     org_example_java_Sample1
 * Method:    intArrayMethod
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_org_example_java_Sample1_intArrayMethod(JNIEnv* env, jobject obj, jintArray array) {
  jsize len = env->GetArrayLength(array);
  jint* body = env->GetIntArrayElements(array, 0);
  int sum = array_sum(body, len);
  env->ReleaseIntArrayElements(array, body, 0);
  return sum;
}

#ifdef __cplusplus
}
#endif
