package Contador;

public class Contador implements Runnable{
	private int id;
	private String nome;
	private int pausa;
	
	Contador(int id, int pausa){
		this.id = id;
		this.nome = "Thread" + id;
		this.pausa = pausa;
	}
	
	@Override
	public void run() {
		for (int i = 0; i < 10; i++) {
			System.out.println("Thread: " + nome + " Contando: " + i);
			try {
				Thread.sleep(pausa);
			}catch(Exception e ) {
				System.out.println(e);
			}
		}
	}
}
