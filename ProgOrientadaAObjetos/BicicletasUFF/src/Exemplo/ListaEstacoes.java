package Exemplo;


public class ListaEstacoes {
    private Estacao[] elementos;
    private int max;
    private int n;
    
    ListaEstacoes(int max){
        this.n = 0;
        this.max = max;
        this.elementos = new Estacao[max];
    }
    
    public void append(Estacao es){
        /*if (this.n < this.max){
            this.elementos[this.n++] = o;
        }
        else{
     
            System.out.println("Erro:Lista esta cheia.");
        }*/
        
        try{
            this.elementos[this.n++] = es;
        }
        catch(ArrayIndexOutOfBoundsException e){
            this.n--;
            System.out.println(e);
        }
    }

    public void imprimir() {
        System.out.println("[ ");
        for (int i = 0;i<this.n;i++){
            System.out.println(this.elementos[i]+" ");
            
        }
        System.out.println("]");
    }
    
    public Estacao get(int i){
        Estacao es = null;
        try{
            es = this.elementos[i];
        }
        catch(Exception e){
            System.out.println(e);
        }   
        return es;
    }
    
    public Estacao getId(int id){
        /* A implementar */
        for (Estacao es:elementos){
            if (es.getId()==id){
                return es;
            }
        }
        return null;
    }

    public void removerId(){
        /* A implementar */
    }
    
    public void ordenarId(){
        /* A implementar */
        
    }
    
    public int length(){
        return this.n;
    }
    
}


