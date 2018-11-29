package basics;
import junit.framework.*;

import java.util.ArrayList;
import java.util.List;

public class ImmutableTest {
	public static void main( String arg[] ) {
		String s = "Atul";
		foo( s );
		TestCase.assertEquals( "Atul" , s);
		Integer i = 5;
		foo (i);
		TestCase.assertEquals(new Integer(5), i);
		List<Integer> l = new ArrayList<>();
		l.add(5);
		foo(l);
		TestCase.assertEquals(2, l.size());
		System.out.println("Done");	
	}
	private static void foo(List<Integer> l) {
		l.add(6);
	}

	private static void foo(Integer i) {
		i++;
	}

	private static void foo(String s) {
		s = s.substring(1);
	}
}
