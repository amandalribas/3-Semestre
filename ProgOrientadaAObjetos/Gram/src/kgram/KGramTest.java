package kgram;

import java.util.Map;

public class KGramTest {
	
	public static void main(String[] args) {		
		String texto = IO.leArquivo("TheAdventuresOfSherlockHolmes.txt");
		System.out.println(texto);
		Map<String,Integer> freqPalavras = KGram.quantidadePalavras(texto);
		
		System.out.println("Frequencia de Palavras:");
		for (Map.Entry<String, Integer> e : freqPalavras.entrySet())
			System.out.println(e.getKey() + ": " + e.getValue());
	}
}
