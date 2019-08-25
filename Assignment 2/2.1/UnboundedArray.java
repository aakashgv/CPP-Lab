//package threads.array;

public class UnboundedArray {

	private int[] array;
	private int size; // number of elements

	public UnboundedArray(int initialCapacity) {

		array = new int[initialCapacity];
		size = 0;
	}

	public void insert(int value) {
		if (size == array.length)
			System.out.println("Array is full");
		else {
			array[size++] = value;
			adjust();
		}

	}
	
	public int getSize(){
		return size;
	}

	public int getCapacity() {
		return array.length;
	}

	public String toString() {
		// TODO Auto-generated method stub
		String s = "";
		for (int i = 0; i < size; i++) {
			s += array[i] + " ";
		}
		return s;
	}

	/**
	 * Deletes the first element in the array
	 * 
	 */
	public void delete() {
		if (size == 0) {
			System.out.println("Array is empty!");
			return;
		}
		for (int i = 1; i < size; i++) {
			array[i - 1] = array[i];
		}
		size--;
		adjust();
	}

	/**
	 * Deletes the element at a specific index in the array
	 * 
	 * @param index
	 *            of the element to be deleted
	 */
	public void delete(int index) {
		if (size == 0) {
			System.out.println("Array is empty!");
			return;
		} 
		else if(index<0||index>=size){
			System.out.println("Invalid index!");
			return;
		}
		System.out.println("Deleted Element = "+array[index]);
		for (int i = index + 1; i < size; i++) {
			array[i - 1] = array[i];
		}
		
		size--;
		adjust();
	}
	
	/** Deletes the elements from startIndex to endIndex both inclusive from the array
	 * @param startIndex
	 * @param endIndex
	 */
	public void delete(int startIndex, int endIndex) {
		if (size == 0) {
			System.out.println("Array is empty!");
			return;
		}
		else if(startIndex<0||startIndex>=size){
			System.out.println("Invalid start index!");
			return;
		}
		else if(endIndex<startIndex||endIndex>=size) {
			System.out.println("Invalid end index!");
			return;
		}
		int replace = startIndex;
		for (int i = endIndex + 1; i < size; i++) {
			array[replace++] = array[i];
		}
		//System.out.println(array);
		
		size-=(endIndex-startIndex+1);
		adjust();
	}
	
	/**
	 * Replaces the element at a specific index in the array with the element specified
	 * @param index of the element to be replaced 
	 * @param element to be replaced with
	 */
	public void modify(int index, int element) {
		if (size == 0) {
			System.out.println("Array is empty!");
		} else if(index<0||index>=size){
			System.out.println("Invalid index!");
		}
		
		array[index] = element;
	}


	private void adjust() {
		if(size>=(array.length*0.75)){
			int[] newArray = new int[array.length*2];
			for(int i=0;i<size;i++) {
				newArray[i] = array[i];
			}
			array = newArray;
		} else if(size<=(array.length*0.25)) {
			int[] newArray = new int[array.length/2];
			for(int i=0;i<size;i++) {
				newArray[i] = array[i];

			}
			array = newArray;
		}

	}

	public static void main(String[] args) {
		UnboundedArray myArray = new UnboundedArray(1);
		System.out.println(myArray);
		for (int i = 1; i <= 10; i++) {
			myArray.insert(i);
		}
		System.out.println(myArray);
		
		for (int i = 1; i <= 5; i++) {
			myArray.delete();
		}
		System.out.println(myArray);
		System.out.println(myArray.getCapacity());
		myArray.delete(2);
		System.out.println(myArray);
		System.out.println(myArray.getCapacity());

		myArray.delete(1, 2);
		System.out.println(myArray);
		System.out.println(myArray.getCapacity());

		myArray.modify(0, 10);
		System.out.println(myArray);
		System.out.println(myArray.getCapacity());
		
	}
}
