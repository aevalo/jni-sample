import org.testng.annotations.*;
import static org.testng.Assert.*;

public class Sample1Test {
  @Test
  public void intMethodTest() {
    Sample1 sample = new Sample1();
    assertEquals(sample.intMethod(5), 25, "intMethod should return input value squared");
  }

  @Test
  public void booleanMethodTest() {
    Sample1 sample = new Sample1();
    assertEquals(sample.booleanMethod(true), false, "booleanMethod should return input value inverted");
  }

  @Test
  public void stringMethodTest() {
    Sample1 sample = new Sample1();
    assertEquals(sample.stringMethod("java"), "JAVA", "stringMethod should return input value uppercased");
  }

  @Test
  public void intArrayMethodTest() {
    Sample1 sample = new Sample1();
    assertEquals(sample.intArrayMethod(new int[] {1, 1, 2, 3, 5, 8, 13}), 33, "intArrayMethod should return input value summed");
  }
}
