package Musica;

import javax.xml.crypto.Data;

public class Musica {
	private int identificador;
	private String titulo;
	private Duracao duracao;
	private String autores;
	private Data data;
	private String genero;

	Musica (int identificador, String titulo, Duracao duracao, String autores, Data data, String genero){
		this.identificador = identificador;
		this.titulo = titulo;
		this.duracao = duracao;
		this.autores = autores;
		this.data = data;
		this.genero = genero;
	}

	@Override
	public String toString() {
		return "Musica [identificador=" + identificador + ", titulo=" + titulo + ", duracao=" + duracao + ", autores="
				+ autores + ", data=" + data + ", genero=" + genero + "]";
	}

	public int getIdentificador() {
		return identificador;
	}

	public void setIdentificador(int identificador) {
		this.identificador = identificador;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public Duracao getDuracao() {
		return duracao;
	}

	public void setDuracao(Duracao duracao) {
		this.duracao = duracao;
	}

	public String getAutores() {
		return autores;
	}

	public void setAutores(String autores) {
		this.autores = autores;
	}

	public Data getData() {
		return data;
	}

	public void setData(Data data) {
		this.data = data;
	}

	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		this.genero = genero;
	}
	
	
}
