package Mapa;

public class ListaPontos {
	private Ponto[] ListaPontos;
	private int tamanho;
	private int max;
	
	ListaPontos(int max){
		ListaPontos = new Ponto[max];
		this.tamanho = -1;
	}
	
	public void append(float x, float y) {
		if (lenght() < this.max) {
			this.tamanho++;
			this.ListaPontos[tamanho] = new Ponto(x,y);
		}
	}

	public int lenght() {
		return this.tamanho;
	}

}
