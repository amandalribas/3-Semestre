package bicicleta;

public class NoEncBicicleta {
	private Bicicleta bicicleta;
	private NoEncBicicleta proximoNo;
	
	public NoEncBicicleta(Bicicleta bicicleta) {
		this.bicicleta = bicicleta;
		this.proximoNo = null;
	}
	
	public NoEncBicicleta(Bicicleta bicicleta, NoEncBicicleta proximoNo) {
		this.bicicleta = bicicleta;
		this.proximoNo = proximoNo;
	}
	
	@Override
	public String toString() {
		return bicicleta.toString();
	}
	
	public Bicicleta getBicicleta() {
		return bicicleta;
	}
	public void setBicicleta(Bicicleta bicicleta) {
		this.bicicleta = bicicleta;
	}
	public NoEncBicicleta getProximoNo() {
		return proximoNo;
	}
	public void setProximoNo(NoEncBicicleta proximoNo) {
		this.proximoNo = proximoNo;
	}
	
	
	
}
