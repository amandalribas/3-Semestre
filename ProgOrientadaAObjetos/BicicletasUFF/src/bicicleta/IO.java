package bicicleta;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.util.Scanner;

import bicicleta.Bicicleta.TIPO;

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
		System.out.println("LENDO BICICLETAS DE ARQUIVO...");

		try {
			//String nomeArquivo = leNomeArquivo();
			String nomeArquivo = "bicicletas.txt";
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
					if (tipo == 0) {
						b = new Bicicleta(id, numPatrimonio);
						b.setTipo(TIPO.COMUM);
					}
					else {
						b = new BicicletaGPS(id,numPatrimonio, "XYZ");
						b.setTipo(TIPO.GPS);
					}
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
		System.out.println("LENDO ESTACOES DE ARQUIVO...");
		try {
			//String nomeArquivo = leNomeArquivo();
			String nomeArquivo = "estacoes.txt";
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
	
	TERMINAR:::
	*/
	public static void lerLocalizacaoBicicletas(ListaBicicletas lb, ListaEstacoes les) {
		System.out.println("LENDO LOCALIZACAO DE ARQUIVO...");
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
	
	/*Implemente na classe IO um método para carregar dados de usuários de um arquivo texto.*/
	public static ListaUsuarios lerUsuariosArquivo(String nomeArquivo) {
		System.out.println("LENDO USUARIOS DE ARQUIVO...");
		//String nomeArquivo = leNomeArquivo();
		//String nomeArquivo = "usuarios.txt";
		FileReader fr = null;
		BufferedReader br = null;
		ListaUsuarios lus = null;
		try {
			fr = new FileReader(nomeArquivo);
			br = new BufferedReader(fr);
			boolean eof = false;
			lus = new ListaUsuarios(100);
			do {
				String linha = br.readLine();
				if (linha != null) {
					String[] campos = linha.split(" ");
					int id = Integer.parseInt(campos[0]);
					int matricula = Integer.parseInt(campos[1]);
					String nome = campos[2];
					String endereco = campos[3];
					String telefone = campos[4];
					String email = campos[5]; 
					lus.append(new Usuario(id,matricula,nome,endereco,telefone,email));
				}else eof = true;
			
			}while (!eof);
		}catch(FileNotFoundException e) {
			System.out.println(e);
		}catch (IOException e) {
			System.out.println(e);
		}finally {
			try {
				if (fr != null) fr.close();
				if (br != null) br.close();
			}catch (IOException e) {
				e.printStackTrace();
			}
		}
		return lus;
	}
	
	public static void cadastrarUsuarioArquivo(Usuario u, String nomeArquivo) {
		//String nomeArquivo = "usuarios.txt";
		FileWriter fw = null;
		BufferedWriter bw = null;
		try {
			fw = new FileWriter(nomeArquivo, true);
			bw = new BufferedWriter(fw);
			String idString = Integer.toString(u.getId());
			String matriculaString = Integer.toString(u.getMatricula());
			bw.write(idString + " " + matriculaString + " " + u.getNome() + " " + u.getEndereco() + " " + u.getTelefone() + " " + u.getEmail() + "\n");
		}catch(IOException e) {
			System.out.println(e);
		}finally {
			try {
				if (bw!=null) bw.close();
				if (fw!=null) fw.close();
			}catch(IOException e) {
				System.out.println(e);
			}
		}
	}
	
	/*12) Implemente na classe IO um método para recuperar a senha e o login de um usuário.*/
	public static void recuperarSenha(String nomeArquivo) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("==============================================");
		System.out.println("               RECUPERANDO SENHA...           ");
		System.out.println("==============================================");
		System.out.println("[LOGIN]: ");
		String login = keyboard.next();
		//String nomeArquivo = "login.bin";
		try {
			FileInputStream fi = new FileInputStream(nomeArquivo);
			DataInputStream di = new DataInputStream(fi);
			
			boolean eof = false;
			do {
				byte[] b = new byte[10]; //le a string Login
				if (di.read(b,0,10) != -1) {
					int senha = di.readInt();
					String log = new String(b).trim();
					if (log.equals(login)) {
						System.out.println("LOGIN: " + log + " SENHA: " + senha);
						return;
					}
				}else eof = true;
			}while(!eof);
		}catch(IOException e) {
			System.out.println(e);
		}
	}

	
}
