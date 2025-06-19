package ColecaoFiguras;
import java.util.LinkedList;
import java.util.Collection;

public interface Figuras{
	
	public static void processarFiguras(Collection<? extends Figura> cf) {
		for (Figura f:cf) {
			f.desenhar();
			System.out.println(f.calcularArea());
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		
		Collection<Figura> cf = new LinkedList<>(); 
		
		Collection<Circulo> cc = new LinkedList<>(); 

		cf.add(new Circulo(0, 3.4f, 0.0f, 0.0f));
		cf.add(new Retangulo(1, 1.0f, 2.3f));
		cf.add(new Retangulo(2, 2.4f, 4.2f));
		
		cc.add(new Circulo(3, 2.7f, 0.7f, 0.1f));
		cc.add(new Circulo(4, 4.4f, 2.2f, 1.0f));
		cc.add(new Circulo(5, 9.4f, 3.2f, 1.1f));
		
		System.out.println("Colecao contendo Figuras (mistura) somente \n----------------");
		processarFiguras(cf);
		
		System.out.println("Colecao contendo Circulos Somente \n----------------");
		processarFiguras(cc);
		
		System.out.println("Colecao Total de Figuras: \n----------------");
		Collection<Figura> ct = new LinkedList<>();
		
		ct.addAll(cf);
		ct.addAll(cc);
		
		processarFiguras(ct);
		
		
		//processarFiguras(cc); NAO PODE na Collection<Figura>, POIS NEM TODA FIGURA É UM CÍRCULO
		//Colection<?> Coleção de Indeterminados/ Desconhecidos / Coringas -- wildcard
		
		/*
		 * Quando usar vaiavel declarada como wildcard  nao pode usar o metodo adicionar;
		 * EX: em um metodo <? extends Figura>, poderia ser passado um circulo, mas dentro do método poderia ter um add retangulo, o que não é válido.
		*/
		
	}

}
