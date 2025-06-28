package Questao02;

public class Questao02 {
	public static void main(String[] args) {
		Contador c = new Contador(10);
		
		int k = 10;
		Thread a = new Acumulador(c,k);
		Thread l = new Leitor(c,k);
		
		a.start();
		l.start();
		try {
			a.join();
			l.join();

		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
