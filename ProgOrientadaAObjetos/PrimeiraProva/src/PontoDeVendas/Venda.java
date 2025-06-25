package PontoDeVendas;

public class Venda {
	private int codigoVenda;
	private String cpfCliente;
	private NoItem cabeca;
	private float total = 0;
	
	Venda(int codigoVenda, String cpfCliente){
		this.codigoVenda = codigoVenda;
		this.cpfCliente = cpfCliente;
	}
	
	private class NoItem{
		public NoItem proximo;
		public ItemVenda itemVenda;
		
		NoItem(ItemVenda item){
			this.proximo = null;
			this.itemVenda = item;
		}
		
		NoItem(NoItem proximo, ItemVenda item){
			this.proximo = proximo;
			this.itemVenda = item;
		}
	}
	
	public void calcularTotal() {
		NoItem atual =	this.cabeca;
		while (atual!=null) {
			this.total += atual.itemVenda.calcularPreco();
			atual = atual.proximo;
		}
	}
	
	/*Insere No Inicio*/
	public void append(ItemVenda item) {
		if (this.cabeca == null) {
			this.cabeca = new NoItem(item);
			return;
		}
		NoItem novoItem = new NoItem(this.cabeca, item);
		this.cabeca = novoItem;
	}
	
	public void imprime() {
		NoItem atual = this.cabeca;
		while (atual != null) {
			System.out.println(atual);
			atual = atual.proximo;
		}
	}
	
	public int getCodigoVenda() {
		return codigoVenda;
	}

	public void setCodigoVenda(int codigoVenda) {
		this.codigoVenda = codigoVenda;
	}

	public String getCpfCliente() {
		return cpfCliente;
	}

	public void setCpfCliente(String cpfCliente) {
		this.cpfCliente = cpfCliente;
	}

	public float getTotal() {
		return total;
	}

	public void setTotal(float total) {
		this.total = total;
	}
	
	
}
