package listaEncadeada;

import bicicleta.Bicicleta;

public class ListaEncadeadaBicicletas {
	private NoBicicleta inicio;
	private NoBicicleta ultimo;
	private int tamanho = 0;
	private static int NAO_ENCONTRADO = -1;
	
	public void adiciona(Bicicleta elemento) {
		NoBicicleta celula = new NoBicicleta(elemento);
		if (tamanho == 0) {
			this.inicio = celula;
		} else {
			this.ultimo.setProximo(celula);
		}
		this.ultimo = celula;
		this.tamanho++;
	}
	

	public void limpa() { //limpa lista inteira
		for (NoBicicleta atual = this.inicio; atual != null;) {
			NoBicicleta proximo = atual.getProximo();
			atual.setElemento(null);
			atual.setProximo(null);
			atual = proximo;
		}
		/*this.inicio = null;
		 this.ultimo = null;
		 this.tamanho = 0;
		 */
	}
	

	public int busca(Bicicleta bicicleta) { // busca por elemento
		NoBicicleta atual = this.inicio;
		int pos = 0;
		while (atual!=null) {
			if (atual.getElemento().equals(bicicleta)) {
				return pos;
			}pos++;
			atual = atual.getProximo();
		}
		return NAO_ENCONTRADO;
	}
	
	public NoBicicleta getId(int id) {
		NoBicicleta atual = this.inicio;
		while (atual != null) {
			if (atual.getElemento().getId() == id)
				return atual;
			atual = atual.getProximo();
		}
		return null;
	}

	
    /* Implemente o método para remover uma bicicleta dada seu id */
	public Bicicleta removerId(int id){
		NoBicicleta atual = this.inicio;
		NoBicicleta proximo = atual.getProximo();
		while (proximo!=null) {
			if (proximo.getElemento().getId() == id) {
				atual.setProximo(proximo.getProximo());;
				this.tamanho--;
				return proximo.getElemento();
			}
			atual = atual.getProximo();
			proximo = atual.getProximo();	
		}
		System.out.println("ID NAO ENCONTRADO!");
		return null;
    }

	
    /* Implemente um metodo que ordene as bicicletas por id */
    public void ordenarId(){
    	// BUBBLE SORT
    	NoBicicleta atual = this.inicio;
    	NoBicicleta proximo = this.inicio.getProximo();
    }
	
	public int getTamanho() {
		return this.tamanho;
	}
	
	@Override
	public String toString() {
		if (this.tamanho == 0)
				return "[]";

		StringBuilder sb = new StringBuilder();
		NoBicicleta atual = this.inicio;
		
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
