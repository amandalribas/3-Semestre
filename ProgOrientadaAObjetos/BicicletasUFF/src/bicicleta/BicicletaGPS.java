package bicicleta;


public class BicicletaGPS extends Bicicleta{
	private GPS gps;
	
	public BicicletaGPS(int id, int numPatrimonio, String modeloGPS) {
		super(id,numPatrimonio);
		this.gps = new GPS(id,modeloGPS);
	}
	
	
    /* Modifique este metodo para retornar  a posicao via o GPS */
	public Ponto2D getPosicao(){
		return gps.getPosicao();
    }
	
	
}
