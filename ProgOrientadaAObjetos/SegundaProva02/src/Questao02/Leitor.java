package Questao02;

public class Leitor extends Thread{
	private Contador contador;
	private int k;
	
	Leitor(Contador contador, int k){
		this.contador = contador;
		this.k = k;
	}
	
	@Override
	public void run() {
		for (int i =0; i < this.k;i++) {
			System.out.println("Lendo: " + contador.getValor());
		}
		System.out.println("Fim do LEITOR");
	}
}
