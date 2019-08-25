//package threads.array;

public class DeleteRangeThread extends Thread{
	private UnboundedArray array;
	
	public DeleteRangeThread(String name, UnboundedArray array) {
		// TODO Auto-generated constructor stub
		super(name);
		this.array = array;
	}
	
	public static int generate(int min, int max) {
		return min + (int) (Math.random() * ((max - min) + 1));
	}
	
	public void run(){
		//DeleteRangeThread
		while(true){
			int size=array.getSize();
			array.delete(size/4, 3*size/4);
			System.out.println("Lower Range:  "+size/4);
			System.out.println("Upper Range:  "+3*size/4);
			System.out.println("Deleted in range");
			System.out.println("Current Array: "+array);
			System.out.println();	
			
			try{
				sleep(3000);
			}
			catch(InterruptedException e){
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
