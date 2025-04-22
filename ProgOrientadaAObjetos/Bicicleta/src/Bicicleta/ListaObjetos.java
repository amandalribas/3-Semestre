package Bicicleta;

//obs: Estudar como implementar depois com lista encadeada
public class ListaObjetos {
	private Object[] elementos;
	private int max;
	private int n;
	
	ListaObjetos(int max){
		this.n = 0;
		this.max = max;
		this.elementos = new Object[max];
	}
	
	public void append(Object o) {
		try {
			this.elementos[this.n++] = o;
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

}

