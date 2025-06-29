package Questao03;

import java.util.HashMap;
import java.util.Map;

/*3) Implemente um programa em Java que resolva o problema de determinar a sequência de
Fibonacci através da técnica de memoização (memoization). Nesta técnica, uma vez calculado um
valor intermediário de uma função, ele é armazenado para posterior consulta, evitando o recalculo
redundante de operações. Utilize a interface apropriada para resolver tal problema (4.0 pontos).*/


public class Fibonnaci {
	private Map<Integer, Integer> data;
	
	Fibonnaci(){
		data = new HashMap<>();
		data.put(0, 0);
		data.put(1, 1);
		data.put(2, 1);
	}
	public Integer calculaFibonnaci(int i) {
		Integer n = this.data.get(i);
		if (n!=null) return n;
		n = calculaFibonnaci(i-1) + this.calculaFibonnaci(i-2);
		this.data.put(i, n);
		return n;
	}
	
	public static void main(String[] args) {
		Fibonnaci fib = new Fibonnaci();	
		for (int i = 0; i < 30; i++) {
			Integer n = fib.calculaFibonnaci(i);
			System.out.println(n);
		}
		
	}
}
