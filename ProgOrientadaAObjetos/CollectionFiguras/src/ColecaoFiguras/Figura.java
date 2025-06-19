package ColecaoFiguras;

public abstract class Figura {
	private int id;
	
	Figura(int id){
		this.id = id;
	}
	
	public abstract float calcularArea();
	
	public abstract void desenhar();
	
}
