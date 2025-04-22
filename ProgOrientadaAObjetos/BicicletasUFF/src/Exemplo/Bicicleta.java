package Exemplo;

public class Bicicleta {
    public static enum TIPO{COMUM, GPS};
    public static enum ESTADO{ALUGADA, PARADA, MANUTENCAO};
    private static int numBicicletas;   
    private int id;
    private int numPatrimonio;
    private Usuario usuario;
    private TIPO tipo; 
    private ESTADO estado;
    private Estacao estacao;
    
   
    Bicicleta(int id, int numPat){
        this.id = id;
        this.numPatrimonio = numPat;
        this.tipo = TIPO.COMUM;
        this.estado = ESTADO.PARADA; 
        this.usuario = null;
    }
    
    public void vincular(Usuario usuario){
        this.estado = ESTADO.ALUGADA;
        this.usuario = usuario;
    }
    
    public void estacionar(Estacao estacao){
        Estacao estacaoAntiga = this.estacao;
        if (estacaoAntiga!=null){
            estacaoAntiga.removerBicicleta(id);
        }
        this.estacao = estacao;
        estacao.adicionarBicicleta(this);
    }
    
    public void estacionar(){
        this.usuario = null;
        this.estado = ESTADO.PARADA;
    }

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

    public ESTADO getEstado() {
        return estado;
    }

    public void setEstado(ESTADO estado) {
        this.estado = estado;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public Estacao getEstacao() {
        return estacao;
    }

    public void setEstacao(Estacao estacao) {
        this.estacao = estacao;
    }
    

    
    public static String estadoToString(ESTADO estado){
        String s="";
        switch(estado){
            case ALUGADA: s = "alugada";break;
            case PARADA: s = "parada";break;
            case MANUTENCAO: s = "manutencao";break;
        }
        return s;
    }
    
    public static String tipoToString(TIPO tipo){
        String s="";
        switch(tipo){
            case COMUM: s = "comum";break;
            case GPS: s = "gps";break;
        }
        return s;
    }

    
    
    @Override
    public String toString(){
        String nomeEstacao = "Nao alocada";
        if (estacao != null){
            nomeEstacao = estacao.getNome();
        }
        
        return "Bicicleta = [ id = " + id +
                              ",numero de patrimonio = " + numPatrimonio +
                              ",tipo = " + tipoToString(tipo) +
                              ",estado = " + estadoToString(estado) +
                              ",estacao = " + nomeEstacao +
                              ",usuario = " + usuario +
                            "]";  
    }
    
    public Ponto2D getPosicao(){
        return null;
    }
    
    
}
