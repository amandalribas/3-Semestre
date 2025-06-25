package Exemplo;

public abstract class Figura implements Comparable<Figura> {
    public int id;
    public float posX;
    public float posY;

    public Figura(int id) {
        this.id = id;
    }
    
    public abstract float calcularArea();
    public abstract void desenhar();

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getPosX() {
        return posX;
    }

    public void setPosX(float posX) {
        this.posX = posX;
    }

    public float getPosY() {
        return posY;
    }

    public void setPosY(float posY) {
        this.posY = posY;
    }

    
    
    @Override
    public String toString() {
        return "Figura{" + "id=" + id + '}';
    }

    @Override
    public int compareTo(Figura fig) {
        float minhaArea = this.calcularArea();
        float areaObj = fig.calcularArea();
        
        if (minhaArea>areaObj){
            return 1;
        }
        else if (minhaArea<areaObj){
            return -1;
        }
        else{
            return 0;
        }
    }
     
}
