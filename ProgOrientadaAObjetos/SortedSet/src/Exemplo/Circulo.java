package Exemplo;

public class Circulo extends Figura{
	private float raio;
    private float cx,cy;

    public Circulo(int id,float raio, float cx, float cy) {
        super(id);
        this.raio = raio;
        this.cx = cx;
        this.cy = cy;
        this.posX = cx;
        this.posY = cy;

    }
    
    

    @Override
    public float calcularArea() {
        return (float)Math.PI*raio*raio;
    }

    @Override
    public void desenhar() {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return "Circulo{" + "id=" + id + "raio=" + raio + ", cx=" + cx + ", cy=" + cy + '}';
    }
}
