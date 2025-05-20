package ColecaoFiguras;

public class Retangulo extends Figura{
	private float x;
	private float y;
	
	Retangulo(int id, float x, float y){
		super(id);
		this.x = x;
		this.y = y;
	}
	
	public float calcularArea() {
		return x * y;
	}
	
	@Override
	public void desenhar() {
		System.out.println(this);
	}
	
	@Override
	public String toString() {
		return "Retangulo [x=" + x + ", y=" + y + "]";
	};

	
	
}
