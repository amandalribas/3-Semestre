package Product;

public class Product {
	private int id;
	private float value;
	Product(){
		this.id = (int) Math.random();
		this.value = (float)Math.random()*1000;
	}
	
}
