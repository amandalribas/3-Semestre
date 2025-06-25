package Exemplo;

import java.util.Comparator;
import java.util.SortedSet;
import java.util.TreeSet;


public class ExemploSortedSet {
	public static void main(String[] args) {
        SortedSet<Figura> TreeSet;
        SortedSet<Figura> conjFiguras = new TreeSet<>();
        
        conjFiguras.add(new Circulo(1,10.0f,5.0f,0.0f));
        conjFiguras.add(new Circulo(2,6.0f,10.0f,1.0f));
        conjFiguras.add(new Circulo(3,2.0f,-3.0f,2.0f));
        
        System.out.println("Ordenacao por raio");
        for (Figura fig:conjFiguras){
            System.out.println(fig);
        }
        
        Comparator<Figura> compX = new ComparadorFigurasAbscissas();
        SortedSet<Figura> conjFigurasOrdX = new TreeSet<>(compX);
        
        conjFigurasOrdX.add(new Circulo(1,10.0f,5.0f,0.0f));
        conjFigurasOrdX.add(new Circulo(2,6.0f,10.0f,1.0f));
        conjFigurasOrdX.add(new Circulo(3,2.0f,-3.0f,2.0f));
        
        System.out.println("\nOrdenacao por coord X");
        for (Figura fig:conjFigurasOrdX){
            System.out.println(fig);
        }
  /*      
        Comparator<Figura> compY = new Comparator<>(){
            @Override
            public int compare(Figura o1, Figura o2) {
                if (o1.posY > o2.posY){
                    return 1;
                }
                else if (o1.posY<o2.posY){
                    return -1;
                }
                else{
                    return 0;
                }   
            }
        };
    */    
        Comparator<Figura> compY = (Figura o1, Figura o2) -> {
            if (o1.posY > o2.posY){
                return 1;
            }
            else if (o1.posY<o2.posY){
                return -1;
            }
            else{
                return 0;   
            }
        };
        
        SortedSet<Figura> conjFigurasOrdY = new TreeSet<>(compY);
        
        conjFigurasOrdY.add(new Circulo(1,10.0f,5.0f,0.0f));
        conjFigurasOrdY.add(new Circulo(2,6.0f,10.0f,1.0f));
        conjFigurasOrdY.add(new Circulo(3,2.0f,-3.0f,2.0f));
        
        System.out.println("\nOrdenacao por coord Y");
        for (Figura fig:conjFigurasOrdY){
            System.out.println(fig);
        }
    }
}
