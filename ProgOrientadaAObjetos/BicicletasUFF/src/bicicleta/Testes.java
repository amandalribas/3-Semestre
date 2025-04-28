package bicicleta;

public class Testes {
	
	public void mergeSort(ListaBicicletas array){
        //MERGE SORT
		int tamanho = array.length();
		if (tamanho < 2) // sorted
			return;
		
		int metadeTamanho = tamanho/2;
		ListaBicicletas esquerdaArray = new ListaBicicletas(metadeTamanho); 
		ListaBicicletas direitaArray = new ListaBicicletas(tamanho - metadeTamanho);
		
		//PREENCHENDO ARRAYS
		for (int i = 0; i < metadeTamanho ; i++) esquerdaArray.append(array.get(i));
		for (int i = metadeTamanho; i < tamanho; i++) direitaArray.append(array.get(i));
		
		mergeSort(esquerdaArray);
		mergeSort(direitaArray);
	}
	
	private static void merge(ListaBicicletas array, ListaBicicletas esquerdaArray, ListaBicicletas direitaArray) {
		int tamanhoEsquerda = esquerdaArray.length();
		int tamanhoDireita = direitaArray.length();
		array.limpaLista();
		int i = 0, j = 0, k = 0;
		while (i<tamanhoEsquerda && j<tamanhoDireita) {
			
		}
	}
	
	public void limpaLista() {
		for (int i = 0;i<this.length();i++) this.elementos[i] = null;
	}
}
