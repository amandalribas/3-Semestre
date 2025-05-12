package Musica;

public abstract class ColecaoMusicasArray extends ColecaoMusicas{
	private Musica[] musicas;
	private int max;
	
	ColecaoMusicasArray(int max){
		this.max = max;
		this.musicas = new Musica[max];
	}
	
	public void adicionar(Musica musica) {
		if (super.getNumMusicas()< this.max) {
			super.setNumMusicas(super.getNumMusicas()+1);
			this.musicas[super.getNumMusicas()-1] = musica;
		}
	}
	
	public Musica buscar(String titulo) {
		if (super.getNumMusicas() < this.max) {
			for (int i = 0; i < super.getNumMusicas(); i++) {
				if (musicas[i].getTitulo().equals(titulo))
					return musicas[i];
			}
		}
		return null;
	}
	
	public Musica remover(String titulo) {
		for (int i = 0; i < super.getNumMusicas();i++) {
			if (musicas[i].getTitulo().equals(titulo)) {
				for (int j = i; j < super.getNumMusicas()-1; j++) {
					this.musicas[j] = this.musicas[j+1];
				}
				return this.musicas[i];
			}
		}
		return null;
	}
	
	public void imprimir() {
		for (int i = 0; i < super.getNumMusicas(); i++)
			System.out.println(this.musicas[i]);
	}
}
