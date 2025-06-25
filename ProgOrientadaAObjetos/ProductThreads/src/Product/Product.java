package Product;

public class Product{	
	private int id;
	private boolean writeable;
	
	Product(){
		this.id = 0;
		writeable = false;
	}

	public synchronized int getId() {
		while (!isWriteable()) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		this.notifyAll();
		this.writeable = false;
		return id;
	}

	public synchronized void setId(int id) {
		while (isWriteable()) {
			try {
				wait();
			}catch(InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		this.notifyAll();
		this.writeable = true;
		this.id = id;
	}

	
	public boolean isWriteable() {
		return writeable;
	}

	public void setWriteable(boolean writeable) {
		this.writeable = writeable;
	}

	@Override
	public String toString() {
		return "Product [id=" + id + ", writeable=" + writeable + "]";
	}


	
	
}
