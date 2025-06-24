package Product;


public class Producer extends Thread{
	
	public static final int MAX_PRODUCTS = 10;
	public static final long MAX_SLEEP_TIME = 5000;
	
	private Product product;
	
	Producer(Product product){
		this.product = product;
	}
	
	
	
	
	
	@Override
	public void run() {
		for (int i = 0; i < MAX_PRODUCTS; i++) {
			product.setId(i);
			System.out.println("Produzindo " + i + "...");
			try {
				this.sleep((long)Math.random()*MAX_SLEEP_TIME);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.println("Fim da Producao");
	}
	
	
}
