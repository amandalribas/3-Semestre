package kgram;

import java.util.HashMap;
import java.util.Map;

/*divide e conta a quantidade de K caracteres iguais*/
public class KGram {
	
	public static Map<String, Integer> kGram(String texto,int k){
		Map<String, Integer> conjunto = new HashMap<>();
		for (int i = 0; i <= texto.length()-k;i++) {
			String atual = texto.substring(i,i+k);
			atual = atual.toLowerCase().replaceAll("[^\\p{L}]", "");
			if (!atual.equals("")) {
				Integer frequencia = conjunto.get(atual);
				if (frequencia == null) frequencia = 1;
				else frequencia++;
				conjunto.put(atual,frequencia);
			}			
		}
		return conjunto;
	}	
	
	
	/*Contando a quantidade de palavras sem contar o tamanho --CONCERTAR QUE NAO CONSIDERA LETRAS MINUSCULAS,MAIUSCULAS...*/
	
	public static Map<String, Integer> quantidadePalavras(String texto) {
		String[] palavras = texto.split("\\s+");
		Map<String, Integer> conjunto = new HashMap<>();
		
		for (String palavra: palavras) {
			palavra = palavra.toLowerCase().replaceAll("[^\\p{L}]", ""); 
			if (!palavra.equals("")) {
				Integer frequencia = conjunto.get(palavra);
				if (frequencia == null) frequencia = 1;
				else frequencia++;
				conjunto.put(palavra, frequencia);	
			}	
		}
		return conjunto;
	}
	
	/*
	public static void main(String[] args) {
		String texto = "Amanda se chama Amanda e o maior problema da Amanda é a amanda.";
		Map<String, Integer> m = quantidadePalavras(texto);
		System.out.println(m);
		
		Map<String, Integer> m2 = kGram(texto,2);
		System.out.println(m2);
	}*/
}
