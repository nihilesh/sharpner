package basics;

import java.util.Random;

public class JoinThreadTest {

	public static Random random = null;

	/*
	 * There is a task to be done -- 
	 *    Task is done when countA + countB is more than 10.
	 *    I will start multiple workers to do the job.
	 *    I will give them the task.
	 *    This class is me.
	 */
	public static void main( String arg[] ) throws InterruptedException{
		long randSeed = (System.getenv("RandomSeed") != null) ?
				Long.valueOf(System.getenv("RandomSeed")) : 
					new Random().nextLong();

		System.out.println("Using randSeed: "+ randSeed);	
		JoinThreadTest.random = new Random(randSeed);

		Worker[] workers = new Worker[3];

		for ( int i = 0; i < 3; i++) {
			Task task = new Task();

			for ( int j = 0; j < 3; j++) {
				workers[j] = new Worker();
			}
			
			for(Worker worker:workers) {
				worker.setTask(task);
				worker.start();
			}

			for (Worker worker:workers){
				if (worker.isAlive()) {
					worker.join();
				}
			}
		}

		System.out.println( "Completed my worldly responsibilities, dieing now... ");

	}
}

class Worker extends Thread {
	private Task t = null;

	public Worker() {
		//setDaemon(true);
		System.out.println("I am created");
	}

	public void setTask(Task t){
		this.t = t;
	}

	@Override
	public void run() {
		System.out.println( Thread.currentThread() + ": Running");
		Thread th = Thread.currentThread();
		while (t.sum < 100){
			synchronized(t){
				if ( t.sum > 100 ) {
					System.out.println(th.getName() + " says, Task already done... thanks!");
					break;
				}
				t.countA += JoinThreadTest.random .nextInt(10);
				t.countB += JoinThreadTest.random.nextInt(10);
				t.sum = ( t.countA + t.countB );
				t.sum = t.sum > 100 ? 100: t.sum;

				System.out.println( th.getName() + " says, task is : " + (t.sum*100/100) + "% done." );
				System.out.flush();
			}

			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println( Thread.currentThread() + ": Exiting");
	}
}

class Task{
	public int countA;
	public int countB;
	public int sum;
	public Task(){
		countA = countB = sum = 0;
	}
}