package Mapa;

public class MapaPais extends Mapa{
	private ListaEstados estados;
	
	MapaPais(int r, int g, int b){
		super(r,g,b);
		this.estados = new ListaEstados(100);
	}
	
}
