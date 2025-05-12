package bicicleta;

public class ListaUsuarios {
	private Usuario[] usuarios;
	private int max;
	private int n;
	
	ListaUsuarios(int max){
		this.n = 0;
		this.max = max;
		this.usuarios = new Usuario[max];
	}
	
	public void append(Usuario u) {
		try {
			this.usuarios[this.n++] = u;
		}catch (ArrayIndexOutOfBoundsException e) {
			this.n--;
			System.out.println(e);
		}
	}
	
	public void imprimir() {
		System.out.println("[");
		for (int i = 0; i < this.n; i++) {
			System.out.println(this.usuarios[i] + " ");
		}
		System.out.println("]");
	}
	
	public Usuario get(int i) {
		Usuario u = null;
		try {
			u = this.usuarios[i];
		}catch (Exception e) {
			System.out.println(e);
		}
		return u;
	}
	
	public Usuario getId(int id) {
		for (Usuario u: usuarios) {
			if (u.getId() == id ) return u;
		}
		return null;
	}
	
	public void removerId(int id) {
		for (int i = 0; i<this.n;i++) {
			if (this.usuarios[i].getId() == id) {
				for (int j = i; j < this.n; j++) {
					this.usuarios[j] = this.usuarios[j+1];
				}
				this.n--;
				return;
			}
		}
	}
	
	public void ordenarId() {
        /* Implemente um metodo que ordene as bicicletas por id */

	}

	public int length(){
        return this.n;
    }
    
	
}
