package bicicleta;

public class GPS {
	private int id;
	private String modelo;
	
	public GPS(int id, String modelo) {
		this.id = id;
		this.modelo = modelo;
	}
	
	
	 public Ponto2D getPosicao(){
	        /* Modifique este método para que gere um número aleatório entre [0,1000] */
	        return new Ponto2D((float)(Math.random()*1000),(float)(Math.random()*1000));
	    }
	  
	
}
