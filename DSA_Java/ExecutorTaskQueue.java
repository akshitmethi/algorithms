import java.util.Arrays;

/**
 * This class is used to calculate the total wall time for a spark stage for a given task duration list and
 *  available cores.
 * */
public class ExecutorTaskQueue {
	private long[] internalArr;
	private int size;

	public ExecutorTaskQueue(int size){
		internalArr = new long[size+1]; 
		this.size = 0;
	}

	private int left(int root){
		return root*2;
	}

	private int right(int root){
		return root*2;
	}

	private int parent(int child){
		return child/2;
	}

	public void heapifyUp(){
		int curr = size;
		while(curr != 0){
			int p = parent(curr);
			if(internalArr[curr] < internalArr[p]){
				long tmp = internalArr[curr];
				internalArr[curr] = internalArr[p];
				internalArr[p] = tmp;
			}
			curr = p;
		}
	}

	public void heapifyDown(){
		int curr =1;
		while(curr<=size){
			int l = left(curr);
			int r = right(curr);
			if(r>size)
				r=l;
			if(l>size)
				return;
			if(internalArr[l]<internalArr[r]){
				if(internalArr[curr] > internalArr[l]){
					long tmp = internalArr[curr];
					internalArr[curr] = internalArr[l];
					internalArr[l] = tmp;
				}
				curr = l;
			} else {
				if(internalArr[curr] > internalArr[r]){
					long tmp = internalArr[curr];
					internalArr[curr] = internalArr[r];
					internalArr[r] = tmp;
				}
				curr = r;
			}
		}
	}

	public boolean add(long value){
		if(size == 0){
			internalArr[size+1] = value;
			size++;
			return true;
		}
		internalArr[size+1] = value;
		size++;
		heapifyUp();
		return true;
	}

	public long poll(){
		long toReturn = internalArr[1];
		internalArr[1] = internalArr[size--];
		heapifyDown();
		
		return toReturn;
	}

	public long pollWithReduction(){
		long toReturn = poll();
		for(int i=1; i<getSize();i++){
			internalArr[i] -= toReturn;
		}
		while(peek() <= 0)
			poll();
		System.out.println("item polled"+String.valueOf(toReturn));
		return toReturn;
	}

	public long peek(){
		return internalArr[1];
	}

	public int getSize(){
		return size;
	}

	public long runTaskOnCores(long[] taskDurations, int availableCores){
		int i=0;
		long wallTime=0;
		while(i<taskDurations.length){
			while(getSize()<=availableCores){
				this.add(taskDurations[i++]);
			}
			wallTime += pollWithReduction();
		}
		while(getSize() > 0)
			wallTime += pollWithReduction();
		return wallTime;
	}

	public static void main(String[] args) {
		ExecutorTaskQueue taskQueue = new ExecutorTaskQueue(7);
		System.out.println(taskQueue.runTaskOnCores(new long[]{5L,10L,12L,16L,7L,9L,20L},3));
		//1+2+7 = 10
	}
}