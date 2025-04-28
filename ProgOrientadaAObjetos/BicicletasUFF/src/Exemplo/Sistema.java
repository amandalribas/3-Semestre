package Exemplo;

import java.util.Scanner;

public class Sistema {
    private ListaBicicletas bicicletas;
    private ListaEstacoes estacoes;
    private boolean finalizar;
    
    public Sistema(){
        this.finalizar = false;
    }
    
    public void inicializar(){
        this.bicicletas = IO.lerBicicletas("bicicletas.txt");
        this.estacoes = IO.lerEstacoes("estacoes.txt");
        IO.lerLocalizacaoBicicletas("localizacao.txt", bicicletas, estacoes);
        
    }
    
    public void cadastrarBicicletas(){
        Scanner teclado = new Scanner(System.in);
        
        System.out.println("Digite o numero de bicicletas a cadastrar");
        int numBicicletas = teclado.nextInt();
        
        for (int i = 0; i<numBicicletas; i++){
            System.out.println("Digite o id, o num. de patrimonio (seis digitos) e o tipo (0-COMUM,1-GPS)");
            int id = teclado.nextInt();
            int patr = teclado.nextInt();
            int tipo = teclado.nextInt();
            Bicicleta  b;
            if (tipo == 0){
                b = new Bicicleta(id,patr);
            }
            else{
                System.out.println("Digite o modelo do GPS");
                String modelo = teclado.next();
                b = new BicicletaGPS(id,patr,modelo);
            }
            System.out.println("Deseja alocar a bicicleta a uma estacao (s/n)?");
            String s = teclado.next();
            
            if (s.toLowerCase().charAt(0) =='s'){
                this.consultarEstacoes();
                System.out.println("Digite o identificador da estacao desejada");
                int idEst = teclado.nextInt();
                Estacao estacao = estacoes.getId(idEst);
                if (estacao!=null){
                    b.estacionar(estacao);
                }
                else{
                    System.out.println("Estacao invalida");
                }
            }
            this.bicicletas.append(b);
        } 
    }


    
    public void consultarBicicletas(){
        System.out.println("________________________________________________________________________________________________________________");
        System.out.println("Bicicletas cadastradas no sistema");
        for (int i=0;i<bicicletas.length();i++){
                System.out.println(bicicletas.get(i));
        }
        System.out.println("________________________________________________________________________________________________________________");
    }

    public void cadastrarEstacoes(){
        
        /* Implemente o método para cadastrar estacoes */ 
        System.out.println("Não implementado");
    }
    
    public void consultarEstacoes(){
        /* Implemente o metodo para consultar estacoes */
        System.out.println("Não implementado");
    }
    
    public void estacionarBicicleta(){
       /* Implemente o metodo para mover uma bicicleta de uma estacao para outra */
       System.out.println("Não implementado");   
            
    }
    
    public void exibeMenuPrincipal(){
        System.out.println(" ______________________________________________________________________________________________________________ ");
        System.out.println("|                                                  BICICLETAS UFF                                              |");
        System.out.println("|______________________________________________________________________________________________________________|");
        
        System.out.println("B - Cadastrar bicicletas   ");
        System.out.println("b - Consultar bicicletas   ");
        System.out.println("E - Cadastrar estacoes     ");
        System.out.println("e - Consultar estacoes     ");
        System.out.println("m - Estacionar bicicleta   ");
        System.out.println("s - sair do sistema        ");
        System.out.println(" ______________________________________________________________________________________________________________ ");
        System.out.println("|______________________________________________________________________________________________________________|");
    }
    
    public void processarInteracao(){
        Scanner teclado = new Scanner(System.in);
        char c = teclado.next().charAt(0);
        
        switch(c){
            case 'B':this.cadastrarBicicletas();break;
            case 'b':this.consultarBicicletas();break;
            case 'E':this.cadastrarEstacoes();break;
            case 'e':this.consultarEstacoes();break;
            case 'm':this.estacionarBicicleta();break;
            case 's':this.finalizar = true;
                                
        }
               
    }
    
    public void iniciar(){
        boolean finalizar = false;
        do{
            this.exibeMenuPrincipal();
            this.processarInteracao();
            
            
        }while(this.finalizar != true);
    }
    
    
}
