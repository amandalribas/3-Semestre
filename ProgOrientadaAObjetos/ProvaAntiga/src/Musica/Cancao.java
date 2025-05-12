package Musica;

import javax.xml.crypto.Data;

public class Cancao extends Musica{
	private Letra letra;
	
	Cancao(int identificador, String titulo, Duracao duracao, String autores, Data data, String genero, String nomeArqLetra){
		super(identificador, titulo, duracao, autores, data, genero);
		this.letra = new Letra(nomeArqLetra);
	}

	public Letra getLetra() {
		return letra;
	}

	public void setLetra(Letra letra) {
		this.letra = letra;
	}

	@Override
	public String toString() {
		return "Cancao [letra=" + letra + ", toString()=" + super.toString();
	}


	
	
	
}
