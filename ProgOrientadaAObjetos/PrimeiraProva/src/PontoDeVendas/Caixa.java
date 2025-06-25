package PontoDeVendas;

import java.util.Scanner;

public class Caixa {
	private NoVenda cabeca;
	
	
	private class NoVenda{
		public NoVenda proximo;
		public Venda venda;
			
		NoVenda(Venda venda){
			this.proximo = null;
			this.venda = venda;
		}
		
		NoVenda(NoVenda proximo, Venda venda){
			this.proximo = proximo;
			this.venda = venda;
		}
	}
	
	public void append(Venda venda) {
		if (this.cabeca == null) {
			this.cabeca = new NoVenda(venda);
			return;
		}
		NoVenda atual = new NoVenda(this.cabeca, venda);
		this.cabeca = atual;
	}
	
	public NoVenda buscaVenda(int codVenda) {
		NoVenda atual = this.cabeca;
		while (atual != null) {
			if (atual.venda.getCodigoVenda() == codVenda) {
				return atual;
			}
			atual = atual.proximo;
		}
		return null;
	}
	
	public void registrarItemVenda(int codVenda, int codProduto, int quantidade) {
		NoVenda atual = buscaVenda(codVenda);
		if (atual != null) {
			atual.venda.append(new ItemVenda(codProduto, quantidade));
		}
	}
	
	
	public void iniciarVenda(int codVenda, String cpfCliente) {
		Venda venda = new Venda(codVenda, cpfCliente);
		
		Scanner keyboard = new Scanner(System.in);
		String resp;
		do {
			System.out.println("Digite o Codigo do Produto: ");
			int codProduto = keyboard.nextInt();
			System.out.println("Digite a Quantidade do Produto: ");
			int quantidade = keyboard.nextInt();
			registrarItemVenda(codVenda, codProduto, quantidade);
			System.out.println("Registrar mais um item? [s/n] ");
			resp = keyboard.next();
		}while (resp.toLowerCase().equals("s"));
		venda.calcularTotal();
		this.append(venda);
		System.out.println(venda.getTotal());
		venda.imprime();
	}

}
