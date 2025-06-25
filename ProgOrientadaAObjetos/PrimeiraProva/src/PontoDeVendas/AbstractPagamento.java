package PontoDeVendas;

public abstract class AbstractPagamento {
	protected float total;
	protected String formaPagamento;
	protected String detalhamento;

	public AbstractPagamento(){
		
	};
	
	
	public abstract void efetuarPagamento(Venda venda, String dadoPagamento);

	public void imprimir(){
		System.out.println("Valor a pagar:"+total);
		System.out.println("Forma de Pagamento:"+formaPagamento);
		System.out.println("Detalhamento:"+detalhamento);
	}
}
