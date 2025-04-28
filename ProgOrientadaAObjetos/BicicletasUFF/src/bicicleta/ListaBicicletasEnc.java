package bicicleta;

public class ListaBicicletasEnc {
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
		this.fim.setProximoNo(novoNo);
		this.fim = novoNo;
		
	}
	
	public void imprimir() {
		NoEncBicicleta atual = this.inicio;
		while (atual != null) {
			System.out.println(atual.getBicicleta());
			atual = atual.getProximoNo();		}
	}
	
	public Bicicleta getId(int id) {
		NoEncBicicleta atual = this.inicio;
		while (atual != null) {
			if (atual.getBicicleta().getId() == id) {
				return atual.getBicicleta();
			}
			atual = atual.getProximoNo();
		}
		System.out.println("BICICLETA NAO ENCONTRADA!");
		return null;
	}
	
	public void removerId(int id) {
		NoEncBicicleta atual = this.inicio;
		if (atual.getBicicleta().getId() == id) {
			this.inicio = atual.getProximoNo();
			this.tamanho--;
			return;
		}
		while (atual.getProximoNo()!=null) {
			if (atual.getProximoNo().getBicicleta().getId() == id) {
				atual.setProximoNo(atual.getProximoNo().getProximoNo());
				this.tamanho--;
				return;
			}
			atual = atual.getProximoNo();
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
