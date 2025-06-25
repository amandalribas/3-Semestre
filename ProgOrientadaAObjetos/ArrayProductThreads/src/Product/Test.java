package Product;

public class Test {
	public static void main(String[] args) {
		
		//Product p = new Product();
		//System.out.println("Product ID: "+ p.getId() + " VALUE: "+ p.getValue());
		QueueProduct qP = new QueueProduct(10);
		//qP.addRandomProduct();
		Producer p = new Producer(qP);
		Consumer c = new Consumer(qP);
		p.start();
		c.start();
		//System.out.println(qP);
	}
}
