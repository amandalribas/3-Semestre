package bicicleta;

public class ListaEstacoesDupEnc {
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
		this.fim.setProximoNo(novoNo);
		novoNo.setAnteriorNo(this.fim);
		this.fim = novoNo;
		this.tamanho++;
	}
	
	public void imprimir() {
		NoDupEncEstacao atual = this.inicio;
		while (atual != null) {
			System.out.println(atual.getEstacao());
			atual = atual.getProximoNo();		}
	}
	
	public Estacao getId(int id) {
		NoDupEncEstacao atual = this.inicio;
		while (atual != null) {
			if (atual.getEstacao().getId() == id) {
				return atual.getEstacao();
			}
			atual = atual.getProximoNo();
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
		if (atual.getEstacao().getId() == id) {
			this.inicio = atual.getProximoNo();
			this.inicio.setAnteriorNo(null);
			this.tamanho--;
			return;
		}
		/*REMOVE do FINAL*/
		if (this.fim.getEstacao().getId() == id) {
			this.fim.getAnteriorNo().setProximoNo(null);
			this.tamanho--;
			return;
		}
		NoDupEncEstacao proximo = atual.getProximoNo();
		/*SENAO*/
		while (proximo != null) {
			if (proximo.getEstacao().getId() == id) {
				atual.setProximoNo(proximo.getProximoNo());
				proximo.getProximoNo().setAnteriorNo(atual);
				this.tamanho--;
				return;
			}
			atual = proximo;
			proximo = proximo.getProximoNo();
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
