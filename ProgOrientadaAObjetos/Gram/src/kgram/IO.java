package kgram;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class IO {
	public static String leArquivo(String nomeArquivo) {
		String texto = "";
		FileReader fr = null;
		BufferedReader br = null;
		boolean eof = false;
		try {
			fr = new FileReader(nomeArquivo);
			br = new BufferedReader(fr);
			do {
				String linha = br.readLine();
				if (linha!=null && !linha.trim().isEmpty()) {
					texto += linha + "\n";
				}else if (linha == null) eof = true;
			}while (!eof);
		}catch(IOException e) {
			System.out.println(e);
		}finally {
			try {
				if(fr!=null) fr.close();
				if (br!=null) br.close();	 
			}catch(Exception e) {
				System.out.println(e);
			}
		}
		
		return texto;
	}
}
