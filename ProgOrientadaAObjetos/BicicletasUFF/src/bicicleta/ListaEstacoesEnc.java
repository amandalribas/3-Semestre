package bicicleta;

public class ListaEstacoesEnc {
	
	private class NoEncEstacao {
		public Estacao estacao;
		public NoEncEstacao proximoNo;
		
		NoEncEstacao(Estacao estacao){
			this.estacao = estacao;
			this.proximoNo = null;
		}
	}
	
	private NoEncEstacao inicio;
	private NoEncEstacao fim;
	private int tamanho;
	
	public void append(Estacao e) {
		NoEncEstacao novoNo = new NoEncEstacao(e);
		this.tamanho++;
		/*LISTA VAZIA:*/
		if (this.inicio == null) {
			this.inicio = novoNo;
			this.fim = novoNo;
			return;
		}
		/*SENAO: APPEND NO FINAL)*/
		this.fim.proximoNo = novoNo;
		this.fim = novoNo;
	}
	
	public void imprimir() {
		NoEncEstacao atual = this.inicio;
		while (atual != null) {
			System.out.println(atual.estacao);
			atual = atual.proximoNo;		}
	}
	
	public Estacao getId(int id) {
		NoEncEstacao atual = this.inicio;
		while (atual != null) {
			if (atual.estacao.getId() == id) {
				return atual.estacao;
			}
			atual = atual.proximoNo;
		}
		System.out.println("BICICLETA NAO ENCONTRADA!");
		return null;
	}
	
	public void removerId(int id) {
		NoEncEstacao atual = this.inicio;
		if (atual.estacao.getId() == id) {
			this.inicio = atual.proximoNo;
			this.tamanho--;
			return;
		}
		while (atual.proximoNo !=null) {
			if (atual.proximoNo.estacao.getId() == id) {
				atual.proximoNo = atual.proximoNo.proximoNo;
				this.tamanho--;
				return;
			}
			atual = atual.proximoNo;
		}
		System.out.println("ID NAO encontrado!");
	}
	
	public void ordenarId() {
        /* Implemente um metodo que ordene as bicicletas por id */
	}
	
	public int lenght() {
		return this.tamanho;
	}
	
	public NoEncEstacao getInicio() {
		return inicio;
	}
	public void setInicio(NoEncEstacao inicio) {
		this.inicio = inicio;
	}
	public NoEncEstacao getFim() {
		return fim;
	}
	public void setFim(NoEncEstacao fim) {
		this.fim = fim;
	}
	public int getTamanho() {
		return tamanho;
	}
	public void setTamanho(int tamanho) {
		this.tamanho = tamanho;
	}
	
	
}
