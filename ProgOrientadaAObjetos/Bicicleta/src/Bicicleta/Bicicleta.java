package Bicicleta;

public class Bicicleta {
	static final int ALUGADA = 0;
	static final int PARADA = 1;
	static final int MANUTENCAO = 2;
	
	private int id;
	private int numPatrimonio;
	private int estado;
	private Usuario usuario;
	//private lista historico;
	
	//Construtor
	Bicicleta(int id, int numPatrimonio){
		this.id = id;
		this.numPatrimonio = numPatrimonio;
		this.estado = PARADA;
		this.usuario = null;
	}
	
	public void vincularUsuario(Usuario usuario) {
		this.usuario = usuario;
		this.estado = ALUGADA;
	}
	
	public void estacionar() {
		this.usuario = null;
		this.estado = PARADA;
	}
	
	
	@Override
	public String toString() {
		return "\nBicicleta: { id = " + this.id +
				";\nnumPatrimonio = " + this.numPatrimonio +
				";\nestado = " + this.estado +
				";\nusuario = " + this.usuario + "}";
	}
	
	//GETTERS E SETTERS
	public void setId(int id) {
		this.id = id;
	}
	
	public int getId() {
		return this.id;
	}
	
	public void setNumPatrimonio(int numPatrimonio) {
		this.numPatrimonio = numPatrimonio;
	}
	
	public int getNumPatrimonio() {
		return this.numPatrimonio;
	}
	
	public void setEstado(int estado) {
		this.estado = estado;
	}
	
	public int getEstado() {
		return this.estado;
	}
	
	
	//String to String:
	
	
}
