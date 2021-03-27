import org.scalatest.funsuite.AnyFunSuite
import org.junit.runner.RunWith
import org.scalatestplus.junit.JUnitRunner

@RunWith(classOf[JUnitRunner])
class Sample1Suite extends AnyFunSuite {
  test("intMethod should return input value squared") {
    val sample = new Sample1();
    assert(sample.intMethod(5) == 25)
  }

  test("booleanMethod should return input value inverted") {
    val sample = new Sample1();
    assert(sample.booleanMethod(true) == false)
  }

  test("stringMethod should return input value uppercased") {
    val sample = new Sample1();
    assert(sample.stringMethod("java") == "JAVA")
  }

  test("intArrayMethod should return input value summed") {
    val sample = new Sample1();
    assert(sample.intArrayMethod(Array(1, 1, 2, 3, 5, 8, 13)) == 33)
  }
}
