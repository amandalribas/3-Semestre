package Questao02;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

/*
Escreva um programa em Java que receba uma lista de notas e usando um objeto que implementa
a interface Map, construa um histograma das notas, que armazena a frequência de cada uma delas
nos estratos (“A” ,”B”,”C”,”D”,”E”). Considere os seguintes intervalos de valores reais para a
definição dos estratos (3.5 pontos).
“A” – nota >= 9.0
“B” - 8.0 <= nota < 9.0
“C” - 7.0 <= nota < 8.0
“D” - 6.0 <= nota < 7.0
“E” - nota < 6.0*/


public class Questao02 {
	public static Map<String,Integer> histograma(Collection<Float> lista) {
		Map<String, Integer> map = new HashMap<>();
		for (Iterator<Float> it = lista.iterator();it.hasNext();) {
			Float nota_atual = it.next();
			String letra = "";
			
			if (nota_atual >= 9.0f) letra = "A";
			else if (nota_atual < 9.0f && nota_atual>= 8.0f) letra = "B";
			else if (nota_atual < 8.0f && nota_atual >= 7.0f) letra = "C";
			else if (nota_atual < 7.0f && nota_atual >= 6) letra = "D";
			else letra = "E";
			
			Integer frequencia = map.get(letra);
			if (frequencia == null) frequencia = 1;
			else frequencia++;
			map.put(letra,frequencia);
		}
		return map;
	}
	
	public static void main(String[] args) {
		Collection<Float> lista_notas = new ArrayList<Float>();
		lista_notas.add(6.7f);
		lista_notas.add(7.9f);
		lista_notas.add(10.0f);
		lista_notas.add(2.4f);
		lista_notas.add(8.7f);
		lista_notas.add(5.4f);
		lista_notas.add(7.2f);
		Map<String, Integer> map = histograma(lista_notas);
		System.out.println(map);
		
	}
}
  