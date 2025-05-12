package bicicleta;

public class ListaBicicletasEnc {
	
	private class NoEncBicicleta {
		public Bicicleta bicicleta;
		public NoEncBicicleta proximoNo;
		
		public NoEncBicicleta(Bicicleta bicicleta) {
			this.bicicleta = bicicleta;
			this.proximoNo = null;
		}
	}	
	
	private NoEncBicicleta inicio;
	private NoEncBicicleta fim;
	private int tamanho;
	
	
	public void append(Bicicleta b) {
		
		NoEncBicicleta novoNo = new NoEncBicicleta(b);
		this.tamanho++;
		/*LISTA VAZIA:*/
		if (this.inicio == null) {
			this.inicio = novoNo;
			this.fim = novoNo;
			return;
		}
		/*SENAO: APPEND NO FINAL)*/
		this.fim.proximoNo = novoNo;
		this.fim = novoNo;
		
	}
	
	public void imprimir() {
		NoEncBicicleta atual = this.inicio;
		while (atual != null) {
			System.out.println(atual.bicicleta);
			atual = atual.proximoNo;		
		}
	}
	
	public Bicicleta getId(int id) {
		NoEncBicicleta atual = this.inicio;
		while (atual != null) {
			if (atual.bicicleta.getId() == id) {
				return atual.bicicleta;
			}
			atual = atual.proximoNo;
		}
		System.out.println("BICICLETA NAO ENCONTRADA!");
		return null;
	}
	
	public void removerId(int id) {
		NoEncBicicleta atual = this.inicio;
		if (atual.bicicleta.getId() == id) {
			this.inicio = atual.proximoNo;
			this.tamanho--;
			return;
		}
		while (atual.proximoNo!=null) {
			if (atual.proximoNo.bicicleta.getId() == id) {
				atual.proximoNo = atual.proximoNo.proximoNo;
				this.tamanho--;
				return;
			}
			atual = atual.proximoNo;
		}
		System.out.println("ID NAO encontrado!");
	}
	
	public void ordenarId() {
        /* Implemente um metodo que ordene as bicicletas por id */

	}
	
	public int length(){
        return this.tamanho;
    }
	
	public NoEncBicicleta getInicio() {
		return inicio;
	}
	public void setInicio(NoEncBicicleta inicio) {
		this.inicio = inicio;
	}
	public NoEncBicicleta getFim() {
		return fim;
	}
	public void setFim(NoEncBicicleta fim) {
		this.fim = fim;
	}
	public int getTamanho() {
		return tamanho;
	}
	public void setTamanho(int tamanho) {
		this.tamanho = tamanho;
	}
	
	
}
