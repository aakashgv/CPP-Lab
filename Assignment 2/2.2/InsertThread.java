//package threads.array;

public class InsertThread extends Thread {
	private UnboundedArray array;

	public InsertThread(String name, UnboundedArray array) {
		// TODO Auto-generated constructor stub
		super(name);
		this.array = array;
	}

	public static int generate(int min, int max) {
		return min + (int) (Math.random() * ((max - min) + 1));
	}

	public void run() {
		// Write your code to implement the job of insert thread
		while(true) {
			for(int i = 1; i<= 3; i++) {
				int element = generate(1, 100);
				array.insert(element);
				System.out.println("Element inserted: "+element);
				System.out.println("Current Array: "+array);
				System.out.println();	
			}
			
			try {
				sleep(10000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
