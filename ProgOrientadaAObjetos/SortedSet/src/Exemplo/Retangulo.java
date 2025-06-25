package Exemplo;

public class Retangulo extends Figura{
	public float a;
    public float b;

    public Retangulo(int id,float a, float b, float posX, float posY) {
        super(id);
        this.a = a;
        this.b = b;
        this.posX = posX;
        this.posY = posY;
    }
    
    

    @Override
    public float calcularArea() {
        return a*b;
    }

    @Override
    public String toString() {
        return "Retangulo{"  + "id=" + id + "a=" + a + ", b=" + b + '}';
    }

    
    @Override
    public void desenhar() {
        System.out.println(this);
    }
    
}
