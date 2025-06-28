package Questao03;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/*3) Considere uma matriz de inteiros com n x n elementos. Escreva um programa em Java que utilize
4 threads para determinar o maior elemento, onde cada thread é responsável por achar o maior
elemento nas submatrizes A0, A1, A2 e A3, conforme a figura abaixo. (3.0 pontos)*/

public class Questao03 {
	
	public static int[][] divideMatriz(int m[][], int inicio_linha, int fim_linha, int inicio_coluna, int fim_coluna, int n){
		int submatriz[][] = new int[n][n];
	
		for (int i = inicio_linha;i<fim_linha;i++) {
			for (int j = inicio_coluna; j < fim_coluna;j++) {
				submatriz[i-inicio_linha][j-inicio_coluna] = m[i][j];
			}
		}
		return submatriz;
	}
	
	public static void printaMatriz(int m[][]) {
		int n = m.length;
		for(int i = 0; i<n;i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(m[i][j] + " ");
			}
			System.out.println("");
		}
	}
	
	
	public static void main(String[] args) {
		int n = 8;
		int m[][] = new int[n][n];

		/*Cria Matriz Aleatoria n x n*/
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				m[i][j] = (int) (Math.random()*100);
			}
		}
		System.out.println("Matriz Inicial");
		printaMatriz(m);
		
		
		
		List<Thread> thrList = new ArrayList<>();
		int qntd_matrizes = 4;
		int novo_n = n/(qntd_matrizes/2);
		
		int contadorMatrizes = 0;
		
		for (int i = 0; i < (qntd_matrizes/2);i++) {
			for (int j = 0; j < (qntd_matrizes/2);j++) {
				int submatriz[][] = divideMatriz(m, i*novo_n, (i*novo_n)+novo_n, j*novo_n, (j*novo_n) + novo_n, novo_n);
				System.out.println("\nMatriz " + contadorMatrizes + ":");
				printaMatriz(submatriz);
				
				Thread t = new Matriz(contadorMatrizes, novo_n,submatriz);
				contadorMatrizes++;
				thrList.add(t);
			}
		}
		
		
		System.out.println("");

		for (Iterator<Thread> it = thrList.iterator();it.hasNext();) {
			it.next().start();
		}
		
		
		for (Iterator<Thread> it = thrList.iterator();it.hasNext();) {
			try {
				it.next().join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
	


/*int m[][] = {
{87, 29, 49, 15, 70, 61, 91, 47},
{34, 76, 20, 89, 10, 37, 58, 25},
{67, 48, 33, 79, 52, 17, 92, 41},
{68, 83, 26, 99, 14, 55, 30, 72},
{19, 61, 43, 80, 27, 90, 16, 32},
{49, 31, 75, 84, 23, 57, 69, 13},
{60, 28, 79, 37, 13, 50, 86, 24},
{91, 36, 47, 72, 19, 58, 43, 68}
};
*/
