package PontoDeVendas;

public class ItemVenda {
	private int codItem;
	private float preco;
	private int quantidade;
	
	ItemVenda(int codItem, int quantidade){
		this.codItem = codItem;
		this.preco = 5; // valor arbitrário
		this.quantidade = quantidade;
	}

	public float calcularPreco() {
		return this.preco * quantidade;
	}


	public float getPreco() {
		return preco;
	}

	public void setPreco(float preco) {
		this.preco = preco;
	}

	public int getQuantidade() {
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}
	
}
