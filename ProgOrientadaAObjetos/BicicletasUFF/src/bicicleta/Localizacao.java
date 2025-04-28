package bicicleta;

public class Localizacao {
	private Ponto2D posicao;
	private String descricao;
	
	public Localizacao(float x, float y, String descricao) {
		this.posicao = new Ponto2D(x,y);
		this.descricao = descricao;
	}

	public Ponto2D getPosicao() {
		return posicao;
	}

	public void setPosicao(Ponto2D posicao) {
		this.posicao = posicao;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	@Override
	public String toString() {
		return "Localizacao{" + "posicao=" + posicao + ", descricao=" + descricao + '}';
	}
	
	
}
