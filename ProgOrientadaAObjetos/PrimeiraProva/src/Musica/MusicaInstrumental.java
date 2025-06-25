package Musica;

import javax.xml.crypto.Data;

public class MusicaInstrumental extends Musica {
	private String nomeArqPartitura;
	
	MusicaInstrumental(int identificador, String titulo, Duracao duracao, String autores, Data data, String genero, String nomeArqPartitura){
		super(identificador, titulo, duracao, autores, data, genero);
		this.nomeArqPartitura = nomeArqPartitura;
	}

	public String getNomeArqPartitura() {
		return nomeArqPartitura;
	}

	public void setNomeArqPartitura(String nomeArqPartitura) {
		this.nomeArqPartitura = nomeArqPartitura;
	}

	@Override
	public String toString() {
		return "MusicaInstrumental [nomeArqPartitura=" + nomeArqPartitura + "]";
	}

	

	
	
}