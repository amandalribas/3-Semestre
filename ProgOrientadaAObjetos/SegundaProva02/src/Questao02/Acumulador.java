package Questao02;


public class Acumulador extends Thread{
	private Contador contador;
	private int k;
	
	Acumulador(Contador contador, int k){
		this.contador = contador;
		this.k = k;
	}
	@Override
	public void run() {
		for (int i =0; i < this.k;i++) {
			contador.incrementaValor(i);
			System.out.println("Acumulando +" + i + "...");
		}
		System.out.println("Fim do ACUMULADOR");
	}
}
