package Product;

public class Test {
	public static void main(String[] args) {
		
		Product product = new Product();
		
		Producer p0 = new Producer(product);
		
		Consumer c0 = new Consumer(product);
		
		p0.start();

		c0.start();
	}
}
