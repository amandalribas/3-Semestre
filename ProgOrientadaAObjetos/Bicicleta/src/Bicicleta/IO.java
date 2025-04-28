package Bicicleta;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import Exemplo.ListaEstacoes;


public class IO {
	
	public static ListaEstacoes lerEstacoes(String nomeArq){
        ListaEstacoes les = null;
        
        /* Implementar o método que lê os dados das estações*/
        
        return les;
        
    }
	
	/*
	public ListaBicicletas lerBicicletasArquivo() { // Adiciona a Lista de Bicicletas 
		ListaBicicletas lb = null;
		FileReader fr = null;
		BufferedReader br = null;
		try {
			Sistema si = new Sistema();
			String nomeArquivo = si.leNomeArquivo();
			fr = new FileReader(nomeArquivo);
			br = new BufferedReader(fr);
			lb = new ListaBicicletas(100);
			boolean eof = false;
			do {
				String linha = br.readLine();
				if (linha != null) {
					String Campos[] = linha.split(" ");
					int id = Integer.parseInt(Campos[0]);
					int numPatrimonio = Integer.parseInt(Campos[1]);
					Bicicleta b = new Bicicleta(id, numPatrimonio);
					lb.append(b);
				}else {
					eof = true;
				}
			}while (!eof);
		}catch (IOException e) {
			System.out.println(e);
		}finally {
			try {
				if (fr!=null) fr.close();
				if (br!=null) br.close();
			}catch (IOException e) {
				System.out.println(e);
			}
		}
		return lb;
	}*/
	
	public void consultaBicicletasArquivo() {
		FileReader fr = null;
		BufferedReader br = null;
		try {
			Sistema si = new Sistema();
			String nomeArquivo = si.leNomeArquivo();
			fr = new FileReader(nomeArquivo);
			br = new BufferedReader(fr);
			boolean eof = false;
			do {
				String linha = br.readLine();
				if (linha!=null) {
					System.out.println(linha);
				}else eof = true;
			}while(!eof);
		}catch(IOException e) {
			System.out.print(e);
		}finally {
			try {
				if (fr != null) fr.close();
				if (br!=null) br.close();	
			}catch (IOException e) {
				System.out.println(e);
			}
		}
	}
	
	
	public void escreverBicicletasArquivo() {
		
		FileWriter fw = null;
		BufferedWriter bw = null;
		Scanner keyboard;
		try {
			Sistema si = new Sistema();
			String nomeArquivo = si.leNomeArquivo();
			fw = new FileWriter(nomeArquivo);
			bw = new BufferedWriter(fw);
			keyboard = new Scanner(System.in);
			System.out.println("Quantas Bicicletas quer Cadastrar?");
			int total = keyboard.nextInt();
			int pos;
			String id, numPatrimonio;
			for (int i = 0; i < total; i++){
				pos = i+1;
				System.out.println("Digite ID e Numero de Patrimonio da " + pos + "a. Bicicleta: ");
				id = keyboard.next();
				numPatrimonio = keyboard.next();
				try {
					bw.write(id + " " + numPatrimonio + "\n");
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}finally {
			try {
				if (bw!=null) bw.close();
				if (fw!=null) fw.close();
			}catch (IOException e){
				e.printStackTrace();
			}	
		}
	}

	public void adicionarBicicletasArquivo() {
		FileWriter fw = null;
		BufferedWriter bw = null;
		Scanner keyboard = null;
		try {
			Sistema si = new Sistema();
			String nomeArquivo = si.leNomeArquivo();
			keyboard = new Scanner(System.in);
			fw = new FileWriter(nomeArquivo, true);
			bw = new BufferedWriter(fw);
			System.out.println("Quantas Biciletas Quer Adicionar? ");
			int total = keyboard.nextInt();
			String id, numPatrimonio;
			int pos;
			for (int i = 0; i < total; i++) {
				pos = i+1;
				System.out.println("Digite ID e Numero de Patrimonio da " + pos + "a. Bicicleta: ");
				id = keyboard.next();
				numPatrimonio = keyboard.next();
				try {
					bw.write(id + " " + numPatrimonio + "\n");
				}catch (IOException e) {
					e.printStackTrace();
				}
			}
		}catch (IOException e) {
			e.printStackTrace();
		}finally {
			try {
				if (bw!=null) bw.close();
				if (fw!=null) fw.close();
			}catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
