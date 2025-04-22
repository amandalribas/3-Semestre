package bicicleta;


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
		for (int i = 0; i < this.n; i++) {
			System.out.println(this.elementos[i] + " ");
		}
		System.out.println("]");
	}
	
	public Bicicleta get(int i) { //Pega a Bicicleta no Indice i
		Bicicleta b = null;
		try {
			b = this.elementos[i];
		}catch (Exception e) {
			System.out.println(e);
		}
		return b;
	}
	
	public Bicicleta getId(int id) {
		for (Bicicleta b: elementos) {
			if(b.getId() == id) return b;
		}
		return null;
	}
	
	public void removerId(int id){	
		for (int i=0;i<this.n;i++){
			if (this.elementos[i].getId() == id){
				for (int j = i; j<this.n; j ++){
					this.elementos[j] = this.elementos[j+1];
		        }
				this.n--;
		        return;
		    }
		}
    }
	
	public void ordenarId(){
        /* Implemente um metodo que ordene as bicicletas por id */
        
    }
    
    public int length(){
        return this.n;
    }
    
}
