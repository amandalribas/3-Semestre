package Questao03;

/*3) Considere uma matriz de inteiros com n x n elementos. Escreva um programa em Java que utilize
4 threads para determinar o maior elemento, onde cada thread é responsável por achar o maior
elemento nas submatrizes A0, A1, A2 e A3, conforme a figura abaixo. (3.0 pontos).*/

public class Matriz extends Thread{
	private int n;
	private int[][] m;
	private int maior;
	private int id;
	

	
	Matriz(int id, int n, int m[][]) {
		this.id = id;
		this.n = n;
		this.m = m;
		maior = 0;
	}
	
	@Override
	public void run() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.println("Buscando " + this.m[i][j] + " na Matriz " + this.id);
				if (this.m[i][j] > this.maior) this.maior = this.m[i][j];
			}
		}
		System.out.println("Maior Elemento da Matriz " + this.id + " :" + this.maior);
	}
}
