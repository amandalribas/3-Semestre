package Exemplo;


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class IO {
    
    public static ListaBicicletas lerBicicletas(String nomeArq){
        ListaBicicletas lb = null;
        
        FileReader fr = null;
        BufferedReader br = null;
        
        try{
            fr = new FileReader(nomeArq);
            br = new BufferedReader(fr);
            lb = new ListaBicicletas(100);
            boolean eof = false;
            do{
                String linha = br.readLine();
                if (linha!=null){
                    //System.out.println(linha);
                    String[] campos = linha.split(" ");
                    int id = Integer.parseInt(campos[0]);
                    int patrimonio = Integer.parseInt(campos[1]);
                    int tipo = Integer.parseInt(campos[2]);
                    Bicicleta bicicleta;
                    if (tipo == 0){
                        bicicleta = new Bicicleta(id,patrimonio);
                    }
                    else{
                        bicicleta = new BicicletaGPS(id,patrimonio, "XYZ");
                    }
                    lb.append(bicicleta);
                    
                }
                else{
                    eof = true;
                }
            }while (eof!=true);
            
        }catch(FileNotFoundException e){
            System.out.println(e);
        }catch(IOException e){
            System.out.println(e);
        }finally{
            try{
                if (fr != null) fr.close();
                if (br != null) br.close();
            }catch(IOException e){
                e.printStackTrace();
            }
        }
        
        return lb;
        
    }
    


    public static ListaEstacoes lerEstacoes(String nomeArq){
        ListaEstacoes les = null;
        
        /* Implementar o método que lê os dados das estações*/
        
        return les;
        
    }
    
    public static void lerLocalizacaoBicicletas(String nomeArq, ListaBicicletas lb, ListaEstacoes les){
        
        /* Implementar o método que lê a localização das bicicletas.
           Ele deve vincular uma bicicleta a uma estacao e estacionar a bicicleta na devida estação.
        */
        
    }
    
}


