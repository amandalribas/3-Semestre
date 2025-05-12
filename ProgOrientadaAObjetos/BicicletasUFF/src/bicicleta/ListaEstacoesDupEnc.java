package bicicleta;

public class ListaEstacoesDupEnc {
	

	private class NoDupEncEstacao {
		public Estacao estacao;
		public NoDupEncEstacao anteriorNo;
		public NoDupEncEstacao proximoNo;
	
		NoDupEncEstacao(Estacao estacao){
			this.estacao = estacao;
			this.anteriorNo = null;
			this.proximoNo = null;
		}
	}
	
	private NoDupEncEstacao inicio;
	private NoDupEncEstacao fim;
	private int tamanho;
	
	public void append(Estacao e) {
		NoDupEncEstacao novoNo = new NoDupEncEstacao(e);
		this.tamanho++;
		if (inicio == null) {
			this.inicio = novoNo;
			this.fim = novoNo;
			return;
		}
		/*SENAO APPEND NO FINAL*/
		this.fim.proximoNo = novoNo;
		novoNo.anteriorNo = this.fim;
		this.fim = novoNo;
		this.tamanho++;
	}
	
	public void imprimir() {
		NoDupEncEstacao atual = this.inicio;
		while (atual != null) {
			System.out.println(atual.estacao);
			atual = atual.proximoNo;		}
	}
	
	public Estacao getId(int id) {
		NoDupEncEstacao atual = this.inicio;
		while (atual != null) {
			if (atual.estacao.getId() == id) {
				return atual.estacao;
			}
			atual = atual.proximoNo;
		}
		System.out.println("BICICLETA NAO ENCONTRADA!");
		return null;
	}
	
	public void ordenarId() {
        /* Implemente um metodo que ordene as bicicletas por id */

	}
	
	public void removerId(int id) {
		NoDupEncEstacao atual = this.inicio;
		/*REMOVE do INICIO*/
		if (atual.estacao.getId() == id) {
			this.inicio = atual.proximoNo;
			this.inicio.anteriorNo = null;
			this.tamanho--;
			return;
		}
		/*REMOVE do FINAL*/
		if (this.fim.estacao.getId() == id) {
			this.fim.anteriorNo.proximoNo = null;
			this.tamanho--;
			return;
		}
		NoDupEncEstacao proximo = atual.proximoNo;
		/*SENAO*/
		while (proximo != null) {
			if (proximo.estacao.getId() == id) {
				atual.proximoNo = proximo.proximoNo;
				proximo.proximoNo.anteriorNo = atual;
				this.tamanho--;
				return;
			}
			atual = proximo;
			proximo = proximo.proximoNo;
		}
		
		System.out.println("ID NAO encontrado!");
	}
	
	
	public int lenght() {
		return this.tamanho;
	}

	public NoDupEncEstacao getInicio() {
		return inicio;
	}

	public void setInicio(NoDupEncEstacao inicio) {
		this.inicio = inicio;
	}

	public NoDupEncEstacao getFim() {
		return fim;
	}

	public void setFim(NoDupEncEstacao fim) {
		this.fim = fim;
	}

	public int getTamanho() {
		return tamanho;
	}

	public void setTamanho(int tamanho) {
		this.tamanho = tamanho;
	}
	
	
	
}
