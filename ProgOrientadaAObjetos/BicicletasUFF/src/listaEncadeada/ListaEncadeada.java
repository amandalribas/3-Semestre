package listaEncadeada;


public class ListaEncadeada<T> {
	private No<T> inicio;
	private No<T> ultimo;
	private int tamanho = 0;
	private static int NAO_ENCONTRADO = -1;
	
	public void adiciona(T elemento) {
		No<T> celula = new No(elemento);
		if (tamanho == 0) {
			this.inicio = celula;
		} else {
			this.ultimo.setProximo(celula);
		}
		this.ultimo = celula;
		this.tamanho++;
	}
	
	public void adicionaInicio(T elemento) {
		No<T> celula = new No<T>(elemento);
		if (tamanho == 0) {
			this.inicio = celula;
			this.ultimo = celula;
		}else {
			celula.setProximo(this.inicio);
			this.inicio = celula;
		}
			
		this.tamanho++;
	}
	
	public void adiciona(T elemento, int posicao) { //adiciona elemento na posicao desejada
		if (posicao == 0 || posicao > this.tamanho) //
			throw new IllegalArgumentException("Posicao Invalida!");
		
		if (posicao == 0) adicionaInicio(elemento);
		else if (posicao == this.tamanho) adiciona(elemento);
		else {
			No<T> noAnterior = this.busca(posicao);
			No<T> noProximo = noAnterior.getProximo();
			No<T> atual = new No<>(elemento, noProximo);
			noAnterior.setProximo(atual);
			this.tamanho++;
		}
	}
	
	public void limpa() { //limpa lista inteira
		for (No<T> atual = this.inicio; atual != null;) {
			No<T> proximo = atual.getProximo();
			atual.setElemento(null);
			atual.setProximo(null);
			atual = proximo;
		}
		/*this.inicio = null;
		 this.ultimo = null;
		 this.tamanho = 0;
		 */
	}
	
	public No<T> busca(int posicao) { //busca por posicao
		if (!(posicao > 0 && posicao <= this.tamanho)) {
			throw new IllegalArgumentException("Posicao Nao Existe!");
		}
		No<T> atual = this.inicio;
		for (int i = 0; i <= posicao;i++) atual = atual.getProximo();
		return atual;
	}
	
	public int busca(T elemento) { // busca por elemento
		No<T> atual = this.inicio;
		int pos = 0;
		while (atual!=null) {
			if (atual.getElemento().equals(elemento)) {
				return pos;
			}pos++;
			atual = atual.getProximo();
		}
		return NAO_ENCONTRADO;
	}
	
	
	public void removeInicio() {
		if (this.tamanho == 0)
			throw new RuntimeException("A Lista está vazia!");
		this.inicio = this.inicio.getProximo();
		this.tamanho--;
		if (this.tamanho == 0)
			this.ultimo = null;
	}

	public void removeFinal() {
		if (this.tamanho == 0)
			throw new RuntimeException("A Lista esta Vazia!");
		if (this.tamanho == 1)
			removeInicio();
		No<T> penultimoNo = this.busca(this.tamanho-2);
		penultimoNo.setProximo(null);
		this.ultimo = penultimoNo;
		this.tamanho--;
	}
	
	public void remove(int pos) {
		if (posicaoNaoExiste(pos))
			throw new IllegalArgumentException("Posicao Inexistente!");
		if (pos == 0) {
			this.removeInicio();
			return;
		}
		if (pos == this.tamanho-1) {
			this.removeFinal();
			return;
		}
		No<T> anterior = this.busca(pos-1);
		No<T> atual = anterior.getProximo();
		No<T> proximo = atual.getProximo();
		anterior.setProximo(proximo);
		atual.setProximo(null);
		this.tamanho--;
	}
	
	public boolean posicaoNaoExiste(int pos) {
		return !(pos > 0 && pos < this.getTamanho());
	}
	
	public int getTamanho() {
		return this.tamanho;
	}
	
	
	@Override
	public String toString() {
		if (this.tamanho == 0)
				return "[]";

		StringBuilder sb = new StringBuilder();
		No<T> atual = this.inicio;
		
		//sb.append(atual.getElemento()).append(", ");
		
		for (int i = 0; i < this.tamanho; i++) {
			sb.append(atual.getElemento()).append("\n ");
			atual = atual.getProximo();
		}
		/*
		while (atual.getProximo() != null) {
			atual = atual.getProximo();
			System.out.println(atual);
			sb.append(atual.getElemento()).append(", ");
		}*/
		return sb.toString();
	}
	
	
}
