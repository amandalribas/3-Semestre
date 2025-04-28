package bicicleta;

public class Estacao {
	//private static final int MAXBICICLETAS = 20;
	private int maxBicicletas = 20;
	private int id;
	private String nome;
	private String localidade;
	private ListaBicicletas bicicletas;
	
	Estacao(int id, String nome, String localidade){
		this.id = id;
		this.nome = nome;
		this.localidade = localidade;
		this.bicicletas = new ListaBicicletas(this.maxBicicletas);
	}
	
	Estacao(int id, String nome, String localidade, int maxBicicletas){
		this.id = id;
		this.nome = nome;
		this.localidade = localidade;
		this.bicicletas = new ListaBicicletas(maxBicicletas);
	}
	
	public void adicionarBicicleta(Bicicleta b){
		if (this.bicicletas.length() > this.maxBicicletas) {
			System.out.println("CAPACIDADE MAXIMA ATINGIDA!");
			return;
		}
        this.bicicletas.append(b);
    }
    
    public void removerBicicleta(int id){
       bicicletas.removerId(id);
    }
   
    public String bicicletasToString(){
        
        /* Modifique este metodo para que ele retorne uma string contendo os ids das bicicletas */
        String s = "[";
        
        
        s+="]";
        
        return s;
    }

    @Override
    public String toString() {
        return "Estacao{" + "id = " + id + ", nome = " + nome + ", localidade = " + localidade + ", bicicletas = " + bicicletasToString() + '}';
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
    
    public int getMaxBicicletas() {
    	return maxBicicletas;
    }
    
    public void setMaxBicicletas(int maxBicicletas) {
    	this.maxBicicletas = maxBicicletas;
    }
}
