package Mapa;

public class ListaEstados {
	private Mapa[] estados;
	private int max;
	private int tamanho;
	
	ListaEstados(int max) {
		this.estados = new Mapa[max];
		this.tamanho = -1;
	}
	
	public void append(Mapa mapa) {
		if (lenght() < this.max) {
			this.tamanho++;
			this.estados[this.tamanho] = mapa;
		}
	}
	
	
	public Mapa[] getEstados() {
		return estados;
	}



	public void setEstaods(Mapa[] estados) {
		this.estados = estados;
	}



	public int getMax() {
		return max;
	}



	public void setMax(int max) {
		this.max = max;
	}



	public int getTamanho() {
		return tamanho;
	}



	public void setTamanho(int tamanho) {
		this.tamanho = tamanho;
	}



	public int lenght() {
		return this.getTamanho();
	}
	
}
