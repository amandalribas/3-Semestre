package Bicicleta;

public class Usuario {
	private int cpf;
	private int matricula;
	private String nome;
	private Bicicleta bicicleta;

	//Construtor:
	Usuario(int cpf, int matricula, String nome){
		this.cpf = cpf;
		this.matricula = matricula;
		this.nome = nome;
		this.bicicleta = null;
	}
	
	public void vinculaBicicleta(Bicicleta bicicleta) {
		this.bicicleta = bicicleta;
		this.bicicleta.setEstado(0);
	}
	
	//GETTERS E SETTERS:
	public void setCpf(int cpf) {
		this.cpf = cpf;
	}
	
	public int getCpf() {
		return this.cpf;
	}
	
	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}

	public int getMatricula() {
		return this.matricula;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getNome() {
		return this.nome;
	}

	public Bicicleta getBicicleta() {
		return this.bicicleta;
	}
	
	@Override
	public String toString() {
		return "[cpf = " + this.cpf +
				";\nmatricula = " + this.matricula +
				";\nnome = " + this.nome +  "]";
	}

}

