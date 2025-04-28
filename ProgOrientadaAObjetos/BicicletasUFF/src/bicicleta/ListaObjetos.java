package bicicleta;

public class ListaObjetos {
	 private Object[] elementos;
	    private int max;
	    private int n;
	    
	    ListaObjetos(int max){
	        this.n = 0;
	        this.max = max;
	        this.elementos = new Object[max];
	    }
	    
	    public void append(Object o){
	        /*if (this.n < this.max){
	            this.elementos[this.n++] = o;
	        }
	        else{
	     
	            System.out.println("Erro:Lista esta cheia.");
	        }*/
	      
	        try{
	            this.elementos[this.n++] = o;
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
	    
	    public Object get(int i){
	        Object o = null;
	        try{
	            o = this.elementos[i];
	        }
	        catch(Exception e){
	            System.out.println(e);
	        }   
	        return o;
	    }
	    
	    public int length(){
	        return this.n;
	    }
}
