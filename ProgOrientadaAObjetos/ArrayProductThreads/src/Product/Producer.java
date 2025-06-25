package Product;

public class Producer extends Thread{
	private QueueProduct qP;
    public static final long MAX_SLEEP_TIME = 5000;

	Producer(QueueProduct qP){
		this.qP = qP;	
	}
	
	@Override
	public void run() {
		for (int i = 0; i < this.qP.getMaxSize(); i++) {
			Product p = new Product();
			this.qP.addProduct(p);			
			try {
				this.sleep((long)Math.random()*MAX_SLEEP_TIME);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.println("Finished Producing...");
	}
}
