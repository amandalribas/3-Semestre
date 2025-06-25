package Exemplo;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Set;

public class Exemplo {
	
	public static <E> Set<E> removeDups(Collection<E> c) {
		return new LinkedHashSet<E>(c);
	}

	public static <E> void printaColecao(Collection<E> c) {
		for (Iterator<E> it = c.iterator(); it.hasNext();) {
			E atual = it.next();
			System.out.println(atual);
		}
	}
	
	public static void main(String[] args) {
		
		Collection<String> colecao = new ArrayList<>();
		colecao.add("Amanda");
		colecao.add("Diogo");
		
		Collection<String> colecao2 = new ArrayList<>();
		colecao2.add("Lais");
		colecao2.add("Madu");
		
		colecao.addAll(colecao2);
		colecao.add("Amanda");
		
		//Collection<int>
	
		System.out.println("Colecao: ");
		printaColecao(colecao);
		
		Set<String> set = removeDups(colecao);
		System.out.println("Set: ");
		printaColecao(set);
	}
}
