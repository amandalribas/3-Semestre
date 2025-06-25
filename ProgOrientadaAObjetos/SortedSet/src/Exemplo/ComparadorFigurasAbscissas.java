package Exemplo;

import java.util.Comparator;

public class ComparadorFigurasAbscissas implements Comparator<Figura> {
	@Override
    public int compare(Figura o1, Figura o2) {
        if (o1.posX > o2.posX){
            return 1;
        }
        else if (o1.posX<o2.posX){
            return -1;
        }
        else{
            return 0;
        }
    }
    
}
