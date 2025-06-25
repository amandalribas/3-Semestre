package Exemplo;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class Lista {

	public static void main(String[] args) {
	
		
		List<Integer> lista = new ArrayList<>();
		lista.add(5);
		lista.add(1);
		lista.add(2);
		lista.add(3);
		lista.add(4);
		
		for (ListIterator<Integer> it = lista.listIterator(lista.size()); it.hasPrevious(); ) {
				Integer atual = it.previous();
				System.out.println("Atual : " + atual);
				if (atual == 5) System.out.println("achou");
		}

	}


}
