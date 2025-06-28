package Teste;

import java.util.ArrayList;

public class ArrayBusca extends Thread{
	private int[] vetor;
	private ArrayList<Integer> posicao;
	private int elemento_busca;
	private int id;
	
	ArrayBusca(int id, int[] vetor, int elemento){
		this.vetor = vetor;
		this.elemento_busca = elemento;
		this.posicao = new ArrayList<>();
		this.id = id;
	}
	
	public void run() {
		for (int i = 0; i < vetor.length; i++) {
			System.out.println("Thread" + id + " percorrendo " + vetor[i]);
			if (vetor[i] == elemento_busca) this.posicao.add(i);
			try {
				this.sleep((int) (Math.random()*1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.println("FIM da Busca na Thread" + id);
	}

	public ArrayList<Integer> getPosicao() {
		return posicao;
	}

	public void setPosicao(ArrayList<Integer> posicao) {
		this.posicao = posicao;
	}

	public int[] getVetor() {
		return vetor;
	}

	public void setVetor(int[] vetor) {
		this.vetor = vetor;
	}

	public int getElemento_busca() {
		return elemento_busca;
	}

	public void setElemento_busca(int elemento_busca) {
		this.elemento_busca = elemento_busca;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
	
	
}
