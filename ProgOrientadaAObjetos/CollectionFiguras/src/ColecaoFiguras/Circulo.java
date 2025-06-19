package ColecaoFiguras;

public class Circulo extends Figura{
	private float raio;
	private float cx;
	private float cy;
	
	Circulo(int id, float raio, float cx, float cy){
		super(id);
		this.raio = raio;
		this.cx = cx;
		this.cy = cy;
	}
	
	public float calcularArea() {
		return (float)Math.PI * raio * raio;
	}

	public void desenhar() {
		System.out.println(this);
	}
	
	@Override
	public String toString() {
		return "Circulo [raio=" + raio + "]";
	}
	
}
