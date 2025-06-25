package Product;

public class Consumer extends Thread{
	private QueueProduct qP;
    public static final long MAX_SLEEP_TIME = 5000;

	Consumer(QueueProduct qP){
		this.qP = qP;	
	}
	
	@Override
	public void run() {
		for (int i = 0; i < this.qP.getMaxSize(); i++) {
			this.qP.getProduct();
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
