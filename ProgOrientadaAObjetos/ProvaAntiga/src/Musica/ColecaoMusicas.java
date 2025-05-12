package Musica;

public abstract class ColecaoMusicas {
	private int numMusicas;
	public ColecaoMusicas(){ numMusicas = 0;}
	public int getNumMusicas() { return numMusicas;}
	
	public void setNumMusicas(int numMusicas) { this.numMusicas = numMusicas;}

	public abstract void adicionar(Musica musica);
	public abstract Musica buscar(String titulo);
	public abstract Musica remover(String titulo);
	public abstract void imprimir();
}
