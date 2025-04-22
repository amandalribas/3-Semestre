package bicicleta;

public class Estacao {
	private static final int MAXBICICLETAS = 20;
	private int id;
	private String nome;
	private String localidade;
	private ListaBicicletas bicicletas;
	
	Estacao(int id, String nome, String localidade){
		this.id = id;
		this.nome = nome;
		this.localidade = localidade;
		this.bicicletas = new ListaBicicletas(MAXBICICLETAS);
	}
	
	public void adicionarBicicleta(Bicicleta b){
        this.bicicletas.append(b);
    }
    
    public void removerBicicleta(int id){
       bicicletas.removerId(id);
    }
   
	//getters e setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getLocalidade() {
        return localidade;
    }

    public void setLocalidade(String localidade) {
        this.localidade = localidade;
    }

    public ListaBicicletas getBicicletas() {
        return bicicletas;
    }

    public void setBicicletas(ListaBicicletas bicicletas) {
        this.bicicletas = bicicletas;
    }
}
