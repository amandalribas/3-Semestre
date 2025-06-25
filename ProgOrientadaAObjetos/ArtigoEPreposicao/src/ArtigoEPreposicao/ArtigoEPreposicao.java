package ArtigoEPreposicao;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.function.Predicate;

/*
 * 1) Escreva um programa em Java que leia um paragráfo na forma de uma String e remova todos os artigos e preposições.
 * Considere os seguintes elementos da Língua Portuguesa: 'a', 'o', 'as','aos', 'os', 'de', 'do', 'da', 'dos', das', 'com'.
 * 
 * 2) Com Base no Exercício anterior, escreva uma solução em Java que determina as palavras em comum entre dois pargráfos sem as preposiçoes e artigos.
 * */


public class ArtigoEPreposicao {
	

	
	public static Collection<String> removeSelecionados(String[] p, Predicate<String> condicao){
		Collection<String> resultado = new ArrayList<String>();
		for (String atual: p) {
			if (condicao.test(atual)) // if !removiveis.cointains(p.toLowerCase()) //if colecao2.contains(c1.toLowerCase())
				resultado.add(atual);
		}
		return resultado;
	}
	
	
	public static void printaCollectionString(Collection<String> p) {
		for (String atual: p) 
			System.out.print(atual + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		
		Collection<String> removiveis = new HashSet<String>();
		removiveis.addAll(Arrays.asList("a", "o", "as", "aos", "de", "do", "de", "dos", "das", "com"));

		Predicate<String> cond = s -> !removiveis.contains(s.toLowerCase());
		
		
		String paragrafo = "A frase.";
		String[] p1 = paragrafo.split(" ");
		Collection<String> r1 = removeSelecionados(p1, cond);
		
		printaCollectionString(r1);
		
		paragrafo = "A outra frase.";
		String[] p2 = paragrafo.split(" ");
		Collection<String> r2 = removeSelecionados(p2,cond);
		
		printaCollectionString(r2);
		
		
		String[] p3 = r2.toArray(new String[r2.size()]);
	
		Collection<String> p4 = new HashSet<String>();
		for (String atual : p1) {
			p4.add(atual);
		}
		
		Collection<String> r = removeSelecionados(p3, 
				s-> p4.contains(s));
		printaCollectionString(r);
	}
	
	
}
