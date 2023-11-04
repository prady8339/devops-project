import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class MyClassTest {
   @Test
   public void testMyMethod() {
       MyClass myClass = new MyClass();
       int result = myClass.myMethod();
       assertEquals(1, result);
   }
}
