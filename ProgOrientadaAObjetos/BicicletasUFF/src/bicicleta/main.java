package bicicleta;

public class main {
	public static void main(String[] args) {
		Bicicleta b0 = new Bicicleta(1,1111);
		ListaBicicletas lista = new ListaBicicletas(10);
		lista.append(b0);
		Bicicleta b1 = new Bicicleta(2,2222);
		lista.append(b1);
		Bicicleta b2 = new Bicicleta(3,3333);
		lista.append(b2);
		lista.imprimir();
		lista.removerId(2);
		lista.imprimir();
	}
	
}
