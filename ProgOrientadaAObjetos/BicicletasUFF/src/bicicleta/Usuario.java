package bicicleta;

public class Usuario {
	private int id;
	private int matricula;
	private Bicicleta bicicleta;
	private String nome;
	
	Usuario(int id, int matricula, String nome){
		this.id = id;
		this.matricula = matricula;
		this.nome = nome;
		this.bicicleta = null;
	}
	
	@Override
	public String toString() {
		return "Usuario = [ ID: " + id +
						", Matricula: " + matricula + 
						", Nome: " + nome + "]";
	}
	
	//getters e setters
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public int getMatricula() {
		return matricula;
	}
	
	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}
	
	public Bicicleta getBicicleta() {
		return bicicleta;
	}
	
	public void setBicicleta(Bicicleta bicicleta) {
		this.bicicleta = bicicleta;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
}
