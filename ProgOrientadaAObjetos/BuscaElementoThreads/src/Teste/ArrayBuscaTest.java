package Teste;

import java.util.Collection;
import java.util.LinkedList;

public class ArrayBuscaTest {
	
	public static int[] divideVetor(int[] vetor, int inicio, int fim, int k) {
		int[] subvetor = new int[vetor.length/k];

		for (int i = inicio; i <fim; i++) {
			subvetor[i-inicio] = vetor[i];
		}
		
		return subvetor;
	}
	
	public static void imprimeVetor(int[] vetor) {
		for (int i = 0; i < vetor.length; i++) {
			System.out.print(vetor[i] + "\t");
		}
	}
	
	public static void main(String[] args) {
		int[] vetor = {0,2,3,4,1,5,2,7,4,9,2,2,11,14,8,2};
		int k = 4; //numero de sublistas / threads;
		
		
		
		Collection<ArrayBusca> cthr = new LinkedList<>();
		
		int lengthSub = vetor.length/k;
		for (int i = 0; i < k; i++) {
			
			int[] subvetor = divideVetor(vetor,i*(lengthSub), i*(lengthSub)+lengthSub, k);
			cthr.add(new ArrayBusca(i, subvetor,2));
		
		}
		
		for (Thread t: cthr) {
			t.start();
		}
		
		for (Thread t: cthr) {
			try {
				t.join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		for (ArrayBusca t: cthr) {
			System.out.println("\nElemento " + t.getElemento_busca() + " na pos: " + t.getPosicao() + " do vetor: ");
			imprimeVetor(t.getVetor());
		}	
		
	}
}
