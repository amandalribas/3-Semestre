package Questao01;

public class ImprimeMensagem extends Processo{
	private String mensagem;
	
	public ImprimeMensagem(String nome, int id, int prioridade, String mensagem) {
		super(nome, id, prioridade);
		this.mensagem = mensagem;
	}
	
	
	
	@Override
	public void executar() {
		System.out.println(this);
		System.out.println(mensagem);
	}
}
