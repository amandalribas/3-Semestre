package bicicleta;

public class ListaBicicletasDupEnc {
	

	private class NoDupEncBicicleta{
		public Bicicleta bicicleta;
		public NoDupEncBicicleta proximoNo;
		public NoDupEncBicicleta anteriorNo;
		
		public NoDupEncBicicleta(Bicicleta bicicleta) {
			this.bicicleta = bicicleta;
			this.anteriorNo = null;
			this.proximoNo = null;
		}
	}
	
	private NoDupEncBicicleta inicio;
	private NoDupEncBicicleta fim;
	private int tamanho;
	
	
	public void append(Bicicleta b) {
		NoDupEncBicicleta novoNo = new NoDupEncBicicleta(b);
		this.tamanho++;
		/*SE VAZIA INSERE NO INICIO E FIM*/
		if(this.inicio == null) {
			this.inicio = novoNo;
			this.fim = novoNo;
			return;
		}
		/*INSERE NO FINAL*/
		this.fim.proximoNo = novoNo;
		novoNo.anteriorNo = this.fim;
		this.fim = novoNo;
	}
	
	public void imprimir() {
		NoDupEncBicicleta atual = this.inicio;
		while (atual != null) {
			System.out.println(atual.bicicleta);
			atual = atual.proximoNo;		}
	}
	
	public Bicicleta getId(int id) {
		NoDupEncBicicleta atual = this.inicio;
		while (atual != null) {
			if (atual.bicicleta.getId() == id) {
				return atual.bicicleta;
			}
			atual = atual.proximoNo;
		}
		System.out.println("BICICLETA NAO ENCONTRADA!");
		return null;
	}
	
	public void ordenarId() {
        /* Implemente um metodo que ordene as bicicletas por id */

	}
	
	public void removerId(int id) {
		NoDupEncBicicleta atual = this.inicio;
		/*REMOVE do INICIO*/
		if (atual.bicicleta.getId() == id) {
			this.inicio = atual.proximoNo;
			this.inicio.anteriorNo =null;
			this.tamanho--;
			return;
		}
		/*REMOVE do FINAL*/
		if (this.fim.bicicleta.getId() == id) {
			this.fim.anteriorNo.proximoNo = null;
			this.tamanho--;
			return;
		}
		NoDupEncBicicleta proximo = atual.proximoNo;
		/*SENAO*/
		while (proximo != null) {
			if (proximo.bicicleta.getId() == id) {
				atual.proximoNo = proximo.proximoNo;
				proximo.proximoNo.anteriorNo = atual;
				this.tamanho--;
				return;
			}
			atual = proximo;
			proximo = proximo.proximoNo;
		}
		
		System.out.println("ID NAO encontrado!");
	}
	
	
	public int lenght() {
		return this.tamanho;
	}
	
	public NoDupEncBicicleta getInicio() {
		return inicio;
	}

	public void setInicio(NoDupEncBicicleta inicio) {
		this.inicio = inicio;
	}

	public NoDupEncBicicleta getFim() {
		return fim;
	}

	public void setFim(NoDupEncBicicleta fim) {
		this.fim = fim;
	}

	public int getTamanho() {
		return tamanho;
	}

	public void setTamanho(int tamanho) {
		this.tamanho = tamanho;
	}

	
	
	
}
