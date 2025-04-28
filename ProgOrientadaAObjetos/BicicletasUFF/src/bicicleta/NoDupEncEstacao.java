package bicicleta;

public class NoDupEncEstacao {
	private Estacao estacao;
	private NoDupEncEstacao anteriorNo;
	private NoDupEncEstacao proximoNo;
	
	NoDupEncEstacao(Estacao estacao){
		this.estacao = estacao;
		this.anteriorNo = null;
		this.proximoNo = null;
	}
	
	NoDupEncEstacao(Estacao estacao, NoDupEncEstacao anteriorNo, NoDupEncEstacao proximoNo){
		this.estacao = estacao;
		this.anteriorNo = anteriorNo;
		this.proximoNo = proximoNo;
	}

	public Estacao getEstacao() {
		return estacao;
	}

	public void setEstacao(Estacao estacao) {
		this.estacao = estacao;
	}

	public NoDupEncEstacao getAnteriorNo() {
		return anteriorNo;
	}

	public void setAnteriorNo(NoDupEncEstacao anteriorNo) {
		this.anteriorNo = anteriorNo;
	}

	public NoDupEncEstacao getProximoNo() {
		return proximoNo;
	}

	public void setProximoNo(NoDupEncEstacao proximoNo) {
		this.proximoNo = proximoNo;
	}

	
}
