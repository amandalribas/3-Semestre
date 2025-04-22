package Bicicleta;

public class Estacao {
	private static int MAXBICICLETAS = 5;
	
	private int id;
	private String nome;
	private String localidade;
	private ListaBicicletas bicicletas;

	//Construtor
	Estacao(int id, String nome, String localidade){
		this.id = id;
		this.nome = nome;
		this.localidade = localidade;
		this.bicicletas = new ListaBicicletas(MAXBICICLETAS);
	}
	
	@Override
	public String toString() {
		return "\nEstacao: { id = " + this.id +
				";\nnome = " + this.nome +
				";\nlocalidade = " + this.localidade +
				";\nbicicletas = " + this.bicicletas + "}";
	}
	
	/*GETTERS E SETTERS*/
	public void setId(int id) {
		this.id = id;
	}
	
	public int getId() {
		return this.id;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setLocalidade(String localidade) {
		this.localidade = localidade;
	}
	
	public String getLocalidade() {
		return this.localidade;
	}
	
	
}
