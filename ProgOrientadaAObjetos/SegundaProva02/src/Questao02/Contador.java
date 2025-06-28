package Questao02;

/*Escreva um programa em Java que contenha uma classe Contador, que armazena um inteiro, e
que é manipulada por duas threads associadas as classes Acumulador e Leitor, que
respectivamente, são capazes de incrementar e ler o valor inteiro na instância de Contador. Assuma
que as instâncias de Acumulador e Leitor incrementem e leiam o valor em Contador k vezes (3.0
pontos).*/

public class Contador {
	private int valor;
	private boolean writeable;
	
	Contador(int valor){
		this.valor = valor;
		writeable = true;
	}

	public synchronized int getValor() {
		while(writeable) {
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		this.notify();
		writeable = true;
		return valor;
	
	}

	public void setValor(int valor) {
		this.valor = valor;
	
	}
	
	public synchronized void incrementaValor(int aumento) {
		while (!writeable) {
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		this.notify(); //multiplas threads: this.notifyAll();
		this.valor += aumento;
		writeable = false;
	}

	public boolean isWriteable() {
		return writeable;
	}

	public void setWriteable(boolean writeable) {
		this.writeable = writeable;
	}
	
	
}
