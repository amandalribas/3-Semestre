package bicicleta;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class IO {

	public static String leNomeArquivo() {
		Scanner teclado = new Scanner(System.in);
		System.out.println("Digite o nome do Arquivo: ");
		String arquivo = teclado.next();
		return arquivo;
	}
	
	// Adiciona Bicicletas de Arquivo para Lista de Bicicletas
	public static ListaBicicletas lerBicicletasArquivo() { 
		ListaBicicletas lb = null;
		FileReader fr = null;
		BufferedReader br = null;
		System.out.println("=======================================================================================");
		System.out.println("LENDO BICICLETAS DE ARQUIVO...");
		System.out.println("=======================================================================================");
		try {
			String nomeArquivo = leNomeArquivo();
			fr = new FileReader(nomeArquivo);
			br = new BufferedReader(fr);
			lb = new ListaBicicletas(100);
			boolean eof = false;
			
			do {
				String linha = br.readLine();
				if (linha != null) {
					String campos[] = linha.split(" ");
					int id = Integer.parseInt(campos[0]);
					int numPatrimonio = Integer.parseInt(campos[1]);
					int tipo = Integer.parseInt(campos[2]);
					Bicicleta b;
					if (tipo == 0) b = new Bicicleta(id, numPatrimonio);
					else b = new BicicletaGPS(id,numPatrimonio, "XYZ");
					lb.append(b);
				}else {
					eof = true;
				}
			}while (!eof);
		
		}catch(FileNotFoundException e) {
			System.out.println(e);
		}catch (IOException e) {
			System.out.println(e);
		}finally {
			try {
				if (fr!=null) fr.close();
				if (br!=null) br.close();
			}catch (IOException e) {
				e.printStackTrace();
			}
		}
		return lb;
	}
	
    /* Implementar o método que lê os dados das estações*/
	public static ListaEstacoes lerEstacoesArquivo() {
		ListaEstacoes les = null;
		FileReader fr = null;
		BufferedReader br = null;
		System.out.println("=======================================================================================");
		System.out.println("LENDO ESTACOES DE ARQUIVO...");
		System.out.println("======================================================================================="); 
		try {
			String nomeArquivo = leNomeArquivo();
			fr = new FileReader(nomeArquivo);
			br = new BufferedReader(fr);
			les = new ListaEstacoes(100);
			boolean eof = false;
			do {
				String linha = br.readLine();
				if (linha!=null) {
					String campos[] = linha.split(" ");
					int id = Integer.parseInt(campos[0]);
					String nome = campos[1];
					String localidade = campos[2];
					int maxBicicletas = Integer.parseInt(campos[3]);
					Estacao es = new Estacao(id, nome, localidade, maxBicicletas);
					les.append(es);
				}else eof = true;
			}while(eof != true);
		
		}catch(FileNotFoundException e) {
			System.out.println(e);
		}catch (IOException e) {
			System.out.println(e);
		}finally {
			try {
				if (fr!=null) fr.close();
				if (br!=null) br.close();
			}catch(IOException e) {
				e.printStackTrace();
			}
		}
		return les;
	}
	
	/* Implementar o método que lê a localização das bicicletas.
	Ele deve vincular uma bicicleta a uma estacao e estacionar a bicicleta na
	devida estação.
	*/
	public static void lerLocalizacaoBicicletas(ListaBicicletas lb, ListaEstacoes les) {
		System.out.println("=======================================================================================");
		System.out.println("LENDO LOCALIZACAO DE ARQUIVO...");
		System.out.println("======================================================================================="); 
		String nomeArquivo = leNomeArquivo();
		
		FileReader fr = null;
		BufferedReader br = null;
		try {
			fr = new FileReader(nomeArquivo);
			br = new BufferedReader(fr);
			boolean eof = false;
			do { //LENDO O ARQUIVO
				String linha = br.readLine();
				String[] campos = linha.split(" ");
				float x = Float.parseFloat(campos[0]);
				float y = Float.parseFloat(campos[1]);
				Ponto2D ponto = new Ponto2D(x,y);
				
			}while (!eof);
		}catch(FileNotFoundException e) {
			System.out.println(e);
		}catch (IOException e) {
			System.out.println(e);
		}finally {
			try {
				if (fr!=null) fr.close();
				if (br!=null) br.close();
			}catch(IOException e) {
				e.printStackTrace();
			}
		}
		
	}
	
}
