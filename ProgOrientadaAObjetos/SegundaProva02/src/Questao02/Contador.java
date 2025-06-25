package Questao02;

/*Escreva um programa em Java que contenha uma classe Contador, que armazena um inteiro, e
que é manipulada por duas threads associadas as classes Acumulador e Leitor, que
respectivamente, são capazes de incrementar e ler o valor inteiro na instância de Contador. Assuma
que as instâncias de Acumulador e Leitor incrementem e leiam o valor em Contador k vezes (3.0
pontos).*/

public class Contador {
	private int valor;
	
	Contador(int valor){
		this.valor = valor;
		
	}
}
