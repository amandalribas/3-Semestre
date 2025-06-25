package Questao01;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

/*1) Considere uma coleção c de objetos que sejam subtipos da classe abstrata Forma, que
implementa a interface Desenhavel. Considere como exemplos de forma os objetos das classes
Circulo, Triangulo, e Rectangulo. Escreva um método genérico que percorre a coleção c e execute
a operação void desenhar() sobre os elementos de c (3.0 pontos).

interface Desenhavel{
	void desenhar();

}*/

public class Questao01 {
	
	public static <T extends Forma> void executando(Collection<T> c){
		for (Iterator<T> it = c.iterator(); it.hasNext();) {
			T elemento = it.next();
			elemento.desenhar();
		}
	}
	
	
	public static void main(String[] args) {
		Collection<Forma> cf = new ArrayList<>();
		cf.add(new Circulo());
		cf.add(new Retangulo());
		cf.add(new Triangulo());
		executando(cf);
	}
}
