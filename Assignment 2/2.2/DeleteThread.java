//package threads.array;

public class DeleteThread extends Thread{
	private UnboundedArray array;
	
	public DeleteThread(String name, UnboundedArray array) {
		// TODO Auto-generated constructor stub
		super(name);
		this.array = array;
	}
	
	public static int generate(int min, int max) {
		return min + (int) (Math.random() * ((max - min) + 1));
	}
	
	public void run() {
		//Delete Thread
		while(true){
			for(int i=0; i<2; i++){
				int index=generate(0, array.getSize()-1);			
				array.delete(index);
				System.out.println("Deleted two elements");
				System.out.println("Current Array: "+array);
				System.out.println();				
			}
			try{
				sleep(3000);
			}
			catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
			
	
