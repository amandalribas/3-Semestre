package Product;

public class Consumer extends Thread{
	public static final int MAX_PRODUCTS = 10;
	public static final long MAX_SLEEP_TIME = 5000;
	
	private Product product;
	Consumer(Product product){
		this.product = product;
	}
	
	
	
	@Override
	public void run() {
		for (int i = 0; i < MAX_PRODUCTS; i++) {
			System.out.println("Consumindo " + product.getId() + "...");
			try {
				this.sleep((long)Math.random()*MAX_SLEEP_TIME);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.println("Fim do Consumidor");
	}
	
	
	
	
}
