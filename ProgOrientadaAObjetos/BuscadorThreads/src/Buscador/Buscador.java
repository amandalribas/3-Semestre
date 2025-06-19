package Buscador;

/*
 *  Considere um array de inteiros v não ordenado (não é possível usar busca binária). 
 *  Escreva um programa,que dado um inteiro x, e usando K Threads, 
 *  efetue a busca de x em v. Considere que v e k sejam potencias de 2
 */
public class Buscador implements Runnable{

	private static volatile boolean encontrado = false;

	
	private int vetor[];
	private int valor;
	private int inicio;
	private int fim;
	private int pos;
	private int id;
	private String nome;
	
	Buscador(int id, int vetor[], int inicio, int fim, int valor){
		this.id = id;
		this.nome = "Thread"+id;
		this.vetor = vetor;
		this.inicio = inicio;
		this.fim = fim;
		this.valor = valor;
		this.pos = -1;
	}
	
	
	
	public int getPos() {
		return pos;
	}

	public void setPos(int pos) {
		this.pos = pos;
	}

	@Override
	public void run() {
		for (int i = this.inicio; i < this.fim; i++) {
			if (encontrado) {
				System.out.println(this.nome + " Encerrando..."); 
				return;
			}
			
			System.out.println(this.nome + " percorrendo posicao " + i + " valor: " + this.vetor[i]);
			if (this.vetor[i] == this.valor) {
				setPos(i);
				System.out.println("Encontrado " + this.valor + " na " + nome);
				encontrado = true;
				return;
			}try {
				Thread.sleep(1000);
			}catch(Exception e ) {
				System.out.println(e);
			}
		}
	}
}
