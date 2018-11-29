package basics;

public class AccessTypeTest {
	public static void main( String args[] ) {
		Level0 l = new Level1();
		l.printAll();
	}
}

class Level0 {
	public void pubFunc(){
		System.out.println( this.getClass() + ": " + 
				new Object(){}.getClass().getEnclosingMethod().getName());
	}
	void pkgProFunc(){
		System.out.println( this.getClass() + ": " + 
				new Object(){}.getClass().getEnclosingMethod().getName());
	}
	protected void protFunc(){
		System.out.println( this.getClass() + ": " + 
				new Object(){}.getClass().getEnclosingMethod().getName());
	}
	private void priFunc(){
		System.out.println( this.getClass() + ": " + 
				new Object(){}.getClass().getEnclosingMethod().getName());
	}
	
	public void printAll(){
		pubFunc();
		pkgProFunc();
		protFunc();
		priFunc();
	}
}

class Level1 extends Level0 {
	public void printAll(){
		pubFunc();
		pkgProFunc();
		protFunc();
		//priFunc();
	}
}
