package bicicleta;

public class NoEncEstacao {
	private Estacao estacao;
	private NoEncEstacao proximoNo;
	
	NoEncEstacao(Estacao estacao){
		this.estacao = estacao;
		this.proximoNo = null;
	}
	
	NoEncEstacao(Estacao estacao, NoEncEstacao proximoNo){
		this.estacao = estacao;
		this.proximoNo = proximoNo;
	}

	public Estacao getEstacao() {
		return estacao;
	}

	public void setEstacao(Estacao estacao) {
		this.estacao = estacao;
	}

	public NoEncEstacao getProximoNo() {
		return proximoNo;
	}

	public void setProximoNo(NoEncEstacao proximoNo) {
		this.proximoNo = proximoNo;
	}
	
	
}
