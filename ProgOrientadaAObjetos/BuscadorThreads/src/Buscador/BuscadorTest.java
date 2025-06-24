package Buscador;

import java.util.ArrayList;
import java.util.List;

public class BuscadorTest {
	public static void main(String[] args) {
		int K = 8;

		int vetor[] = {
			    87, 29, 49, 15, 70, 61, 91, 47,
			    34, 76, 20, 89, 10, 37, 58, 25,
			    67, 48, 33, 79, 52, 17, 92, 41,
			    68, 83, 26, 99, 14, 55, 30, 72,
			    19, 61, 43, 80, 27, 90, 16, 32,
			    49, 31, 75, 84, 23, 57, 69, 13,
			    60, 28, 79, 37, 13, 50, 86, 24,
			    91, 36, 47, 72, 19, 58, 43, 68
			};

		int tamVThr = vetor.length/K;
		
		List<Thread> threads = new ArrayList<Thread>();
		List<Buscador> buscadores = new ArrayList<Buscador>();
		
		for (int i = 0; i <K; i++) {
			int inicio = i * tamVThr;
			int fim = inicio + tamVThr;
			Buscador b = new Buscador(i,vetor, inicio, fim, 14);
			Thread t = new Thread(b);
			threads.add(t);
			buscadores.add(b);
			t.start();

		}
		for (Thread t: threads) {
			try {
				t.join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	
	}
}
