package Bicicleta;

public class ListaBicicletas {

	private Bicicleta[] elementos;
	private int max;
	private int n;
	
	ListaBicicletas(int max){
		this.n = 0;
		this.max = max;
		this.elementos = new Bicicleta[max];
	}
	
	public void append(Bicicleta b) {
		try {
			this.elementos[this.n++] = b;
		}catch (ArrayIndexOutOfBoundsException e) {
			this.n--;
			System.out.println(e);
		}
	}
	
	public void imprimir() {
		System.out.println("[ ");
		for (int i = 0;i<this.n;i++) {
			System.out.println(this.elementos[i] + " ");
		}
		System.out.println(" ]\n");
	}
	
	public int length() {
		return this.n;
	}

	public Bicicleta getBicicleta(int i) {
		Bicicleta b = null;
		try {
			System.out.println(this.elementos[i]);
		}catch (Exception e) {
			System.out.println(e);
		}
		return b;
	}
	
}
