package bicicleta;

public class Bicicleta {
	public static enum TIPO{COMUM, GPS};
	public static enum ESTADO{ALUGADA, PARADA, MANUTENCAO};
	private int id;
	private int numPatrimonio;
	private Usuario usuario;
	private TIPO tipo; 
	private ESTADO estado;
	private Estacao estacao;
	
	public Bicicleta(int id, int numPatrimonio) {
		this.id = id;
		this.numPatrimonio = numPatrimonio;
		this.tipo = TIPO.COMUM;
		this.estado = ESTADO.PARADA;
		this.usuario = null;
	}
	
	public void vincularUsuario(Usuario usuario) {
		this.estado = ESTADO.ALUGADA;
		this.usuario = usuario;
	}
	
	public void estacionar(Estacao estacao){
		if (this.estacao != null)
			this.estacao.removerBicicleta(this.getId());
		estacao.adicionarBicicleta(this);
		this.estacao = estacao;
		this.estado = ESTADO.PARADA;
	}
	
	/*
	public ponto2D getPosicao(){
		-- a implementar
		return null;
	 */
	
	public static String estadoToString(ESTADO estado) {
		String s = "";
		switch (estado) {
		case ALUGADA: s = "Alugada"; break;
		case PARADA: s = "Parada"; break;
		case MANUTENCAO: s = "Manutencao"; break;
		}
		return s;
	}
	
	public static String tipoToString(TIPO tipo) {
		String s = "";
		switch (tipo) {
		case COMUM: s = "Comum"; break;
		case GPS: s = "GPS"; break;
		}
		return s;
	}
	
	
	public static String usuarioToString(Usuario usuario){
        
        String s = "";
        if (usuario!=null) s += usuario.getId();
        return s;
    }
	
	@Override
	public String toString() {
		String nomeEstacao = "Nao Alocada";
		if (estacao != null) nomeEstacao = estacao.getNome();
		return "Bicicleta = [ ID: " + id +
							", Numero de Patrimonio: " + numPatrimonio +
							", Tipo: " + tipoToString(this.tipo) + 
							", Estado: " + estado + 
							", Usuario: " + usuarioToString(this.usuario)  +
							", Estacao: " + estacao + "]";
		
	}
	
	
	
	//getters e setters
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public int getNumPatrimonio() {
		return numPatrimonio;
	}
	
	public void setNumPatrimonio(int numPatrimonio) {
		this.numPatrimonio = numPatrimonio;
	}
	
	public Usuario getUsuario() {
		return usuario;
	}
	
	public void setUsuario(Usuario usuario) {
		this.usuario = usuario;
	}
	
	public TIPO getTipo() {
		return tipo;
	}
	
	public void setTipo(TIPO tipo) {
		this.tipo = tipo;
	}
	
	public ESTADO getEstado() {
		return estado;
	}
	
	public void setEstado(ESTADO estado) {
		this.estado = estado;
	}
	
	public Estacao getEstacao() {
		return estacao;
	}
	
	public void setEstacao(Estacao estacao) {
		this.estacao = estacao;
	}
	
	
}
