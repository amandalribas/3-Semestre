package Questao01;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class MetodoGenericoProcesso {
	/*
	Escreva um método genérico que receba um coleção de objetos que sejam subtipos de Processo e
	invoque sobre cada um deles o método executar, caso a sua prioridade seja maior que um valor
	inteiro x passado como parâmetro. O método deve retornar ao final uma lista contendo os processos
	executados (3.5 pontos).*/
	/* implementar o metodo executarColecaoProcessos */
	
	public static <T extends Processo> Collection<T> executarColecaoProcessos(Collection<T> cp, int x){ 
		Collection<T> ecp = new ArrayList<>(); //ProcessosExecutados
		for (Iterator<T> it = cp.iterator(); it.hasNext();) {
			T p = it.next();
			if (p.getPrioridade()>x) {
				p.executar();
				ecp.add(p);
			}
		}
		return ecp;
	}
	
	public static void main(String[] args) {
		Collection<ImprimeMensagem> cp = new ArrayList<>();
		
		cp.add(new ImprimeMensagem("Processo A",1,10,"Ola, tudo bem?"));
		cp.add(new ImprimeMensagem("Processo B",2,5,"Como vai?"));
		cp.add(new ImprimeMensagem("Processo C",3,3,"Eu estou bem"));
		cp.add(new ImprimeMensagem("Processo D",4,8,"Beleza!"));
		
		Collection<ImprimeMensagem> ecp = executarColecaoProcessos(cp,7);
		
	}
}
