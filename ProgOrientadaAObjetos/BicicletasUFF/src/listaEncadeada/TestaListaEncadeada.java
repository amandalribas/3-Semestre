package listaEncadeada;

import bicicleta.Bicicleta;

public class TestaListaEncadeada {
	public static void main(String[] args) {
		Bicicleta b0 = new Bicicleta(3, 1111);
		ListaEncadeadaBicicletas lista = new ListaEncadeadaBicicletas();
		lista.adiciona(b0);
		System.out.println("Tamanho = " + lista.getTamanho());
		
		Bicicleta b1 = new Bicicleta(7, 2222);
		lista.adiciona(b1);
		Bicicleta b2 = new Bicicleta(1,3333);
		lista.adiciona(b2);
		Bicicleta b3 = new Bicicleta(4,4444);
		lista.adiciona(b3);
		
		System.out.println("Tamanho = " + lista.getTamanho());
		
		//System.out.println(lista.getId(4));
		
		
		//b2 = lista.removerId(3);
		//System.out.println("Removido: " + b2);
		System.out.println("LISTA: " + lista);
		lista.ordenarId();
		System.out.println("Lista ORDENADA: " + lista);
	}
	
}
