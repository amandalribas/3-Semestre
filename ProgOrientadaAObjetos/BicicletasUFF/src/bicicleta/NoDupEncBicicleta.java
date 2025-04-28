package bicicleta;

public class NoDupEncBicicleta {
	private Bicicleta bicicleta;
	private NoDupEncBicicleta proximoNo;
	private NoDupEncBicicleta anteriorNo;
	
	public NoDupEncBicicleta(Bicicleta bicicleta) {
		this.bicicleta = bicicleta;
		this.anteriorNo = null;
		this.proximoNo = null;
	}
	
	public NoDupEncBicicleta(Bicicleta bicicleta, NoDupEncBicicleta proximoNo, NoDupEncBicicleta anteriorNo) {
		this.bicicleta = bicicleta;
		this.proximoNo = proximoNo;
		this.anteriorNo = anteriorNo;
	}
	
	public Bicicleta getBicicleta() {
		return bicicleta;
	}
	
	public void setBicicleta(Bicicleta bicicleta) {
		this.bicicleta = bicicleta;
	}
	
	public NoDupEncBicicleta getProximoNo() {
		return proximoNo;
	}
	
	public void setProximoNo(NoDupEncBicicleta proximoNo) {
		this.proximoNo = proximoNo;
	}
	
	public NoDupEncBicicleta getAnteriorNo() {
		return anteriorNo;
	}
	
	public void setAnteriorNo(NoDupEncBicicleta anteriorNo) {
		this.anteriorNo = anteriorNo;
	}
	
	
}