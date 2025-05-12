package bicicleta;

public class BicicletaEletrica extends BicicletaGPS{
	private int cargaBateria;
	
	public BicicletaEletrica(int id, int numPatrimonio, String modeloGPS, int cargaBateria) {
		super(id,numPatrimonio,modeloGPS);
		this.cargaBateria = cargaBateria;
	}
	
	public void setCargaBateria(int cargaBateria) {
		this.cargaBateria = cargaBateria;
	}
	
	public int getCargaBateria() {
		return this.cargaBateria;
	}
}
