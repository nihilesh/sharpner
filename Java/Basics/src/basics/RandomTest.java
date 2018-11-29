package basics;

import java.util.Random;

public class RandomTest{
	public static void main ( String args[] ) {
		MyRandom r = new MyRandom();
		for( int i = 0; i < 5 ; i++){
			System.out.println(" next(0) : " + r.next(0));
			System.out.println(" next(1) : " + r.next(1));
			System.out.println(" next(2) : " + r.next(2));
			System.out.println(" next(3) : " + r.next(3));
		}
	}
}

class MyRandom extends Random{
	private static final long serialVersionUID = 1L;

	public int next(int bits){
		return super.next(bits);
	}
}