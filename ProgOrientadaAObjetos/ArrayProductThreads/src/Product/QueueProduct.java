package Product;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class QueueProduct {
	private int maxSize;
	private Queue<Product> queue;
	private boolean writeable;
	
	QueueProduct(int size){
		this.maxSize = size;
		queue = new LinkedList<Product>();
		this.writeable = false;
	}
	
	/*public void addRandomProduct() {
		for (int i = 0; i < this.maxSize;i++) {
			queue.add(new Product());
		}
	}*/
	
	public synchronized void addProduct(Product p) {
		while (writeable) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		if (this.queue.size() < this.maxSize) {
			this.notifyAll();
			this.queue.add(p);
			this.writeable = true;
			System.out.println("Added " + p);
			
		}
	}
	
	public synchronized void getProduct() {
		while (!writeable) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		Iterator<Product> it = this.queue.iterator();
		Product p = null;
		if (it.hasNext()) {
			this.notifyAll();
			p = it.next();
			this.writeable = false;
			System.out.println("Getting " + p);
			queue.remove();
		}
	}

	@Override
	public String toString() {
		String str = "QueueProduct= { maxSize= " + this.maxSize + " Queue= [";
		for (Iterator<Product> it = this.queue.iterator(); it.hasNext();) {
			if (!it.hasNext()) str += it.next();
			else str += "\n" + it.next();
		}
		str += " ] } ";
		return str;
	}

	public int getMaxSize() {
		return maxSize;
	}

	public void setMaxSize(int maxSize) {
		this.maxSize = maxSize;
	}
	
	
	
}
