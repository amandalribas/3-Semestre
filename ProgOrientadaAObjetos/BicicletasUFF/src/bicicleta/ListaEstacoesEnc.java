package bicicleta;

public class ListaEstacoesEnc {
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
		this.fim.setProximoNo(novoNo);
		this.fim = novoNo;
	}
	
	public void imprimir() {
		NoEncEstacao atual = this.inicio;
		while (atual != null) {
			System.out.println(atual.getEstacao());
			atual = atual.getProximoNo();		}
	}
	
	public Estacao getId(int id) {
		NoEncEstacao atual = this.inicio;
		while (atual != null) {
			if (atual.getEstacao().getId() == id) {
				return atual.getEstacao();
			}
			atual = atual.getProximoNo();
		}
		System.out.println("BICICLETA NAO ENCONTRADA!");
		return null;
	}
	
	public void removerId(int id) {
		NoEncEstacao atual = this.inicio;
		if (atual.getEstacao().getId() == id) {
			this.inicio = atual.getProximoNo();
			this.tamanho--;
			return;
		}
		while (atual.getProximoNo()!=null) {
			if (atual.getProximoNo().getEstacao().getId() == id) {
				atual.setProximoNo(atual.getProximoNo().getProximoNo());
				this.tamanho--;
				return;
			}
			atual = atual.getProximoNo();
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
