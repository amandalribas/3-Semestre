package listaEncadeada;

import bicicleta.Bicicleta;

public class NoBicicleta {
	private Bicicleta elemento;
	private NoBicicleta proximo;
	
	
	public NoBicicleta(Bicicleta elemento) {
		this.elemento = elemento;
		this.proximo = null;
	}
	
	public NoBicicleta(Bicicleta elemento, NoBicicleta proximo) {
		this.elemento = elemento;
		this.proximo = proximo;
	}
	
	
	@Override
	public String toString() {
		return "No [elemento=" + elemento + "]";
	}


	public Bicicleta getElemento() {
		return elemento;
	}
	
	public void setElemento(Bicicleta elemento) {
		this.elemento = elemento;
	}
	
	public NoBicicleta getProximo() {
		return proximo;
	}
	
	public void setProximo(NoBicicleta proximo) {
		this.proximo = proximo;
	}
	
}
