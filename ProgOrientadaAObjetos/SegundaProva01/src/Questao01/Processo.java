package Questao01;

public abstract class Processo implements Executavel{
	private String nome;
	private int id;
	private int prioridade;
	
	public Processo(String nome, int id, int prioridade) {
		this.nome = nome;
		this.id = id;
		this.prioridade = prioridade;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getPrioridade() {
		return prioridade;
	}

	public void setPrioridade(int prioridade) {
		this.prioridade = prioridade;
	}
	
	
}
