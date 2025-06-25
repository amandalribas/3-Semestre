package Product;

public class Product{
	private int id;
	private float value;
	
	Product(){
		this.id = (int) (Math.random()*50);
		this.value = Math.round((float)Math.random()*100000)/100f;
	}
	
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public float getValue() {
		return value;
	}

	public void setValue(float value) {
		this.value = value;
	}

	@Override
	public String toString() {
		return "Product [id=" + id + ", value=" + value + "]";
	}
	 

}
