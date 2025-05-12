package Musica;

import java.io.BufferedReader;
import java.io.FileReader;

public class Letra {
	private String nomeArqLetra;
	private String letra;
	
	Letra(String nomeArqLetra){
		this.nomeArqLetra = nomeArqLetra;
		this.letra = "";
		FileReader fr = null;
		BufferedReader br = null;
		try {
			fr = new FileReader(nomeArqLetra);
			br = new BufferedReader(fr);
			boolean eof = false;
			do {
				String linha = br.readLine();
				if (linha != null) {
					this.letra += linha;
				}else {
					eof = true;
				}
			}while (!eof);
		}catch(Exception e) {
			System.out.println(e);
		}finally {
			try {
				if (fr!=null) fr.close();
				if (br!= null) br.close();
			}catch(Exception e) {
				System.out.println(e);
			}
		}
	}
}
