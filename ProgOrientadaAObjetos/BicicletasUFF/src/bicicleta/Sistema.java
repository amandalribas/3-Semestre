package bicicleta;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.Scanner;
import bicicleta.Bicicleta.ESTADO;

public class Sistema {
	public static enum TIPO_USUARIO{COMUM, ADMINISTRADOR};

	private ListaBicicletas bicicletas;
	private ListaEstacoes estacoes;
	private ListaUsuarios usuarios;
	private ListaBicicletas bicicletasManutencao;
	private boolean finalizar;
	private boolean logado;
	private Usuario usuario;
	private String arquivoUsuario;
	private String arquivoUsuarioBin;
	private TIPO_USUARIO tipoUsuario;
	
    public Sistema(){
        this.finalizar = false;
        this.logado = false;
    }
    
    public void inicializar() {
    	this.bicicletas = IO.lerBicicletasArquivo();
    	this.estacoes = IO.lerEstacoesArquivo();
    	this.usuarios = IO.lerUsuariosArquivo(this.arquivoUsuario);
    	this.bicicletasManutencao = new ListaBicicletas(100);
    }
    
    public void iniciar() {
    	this.finalizar = false;
    	
    	this.escolheMenuUsuario();
    	this.processarInteracaoTipoUsuario();

    	this.inicializar();
    	do {
    		if (!logado) {
    			this.exibeMenuUsuario();
        		this.processarInteracaoUsuario();
    		}
    		else {
    			if (this.tipoUsuario == TIPO_USUARIO.COMUM) {
    				this.exibeMenuUsuarioComum();
    				this.processarInteracaoUsuarioComum();
    			}else {
    				this.exibeMenuUsuarioADM();
    				this.processarInteracaoUsuarioADM();
    			}
    		}
    		
    	}while(!finalizar);
    	System.out.println("ENCERANDO programa...");
    }
    
    public void escolheMenuUsuario() {
    	System.out.println(" ______________________________________________________________________________________________________________ ");
    	System.out.println ("                                           TIPO DE USUARIO                                                     ");
    	System.out.println(" ______________________________________________________________________________________________________________ ");
    	System.out.println("1 - USUARIO COMUM; ");
    	System.out.println("2 - USUARIO ADMINISTRADOR; ");
    	System.out.println("0 - SAIR DO PROGRAMA. ");
        System.out.println("|______________________________________________________________________________________________________________|");
		System.out.println("Digite a Opcao Desejada: ");
    }
    
    public void processarInteracaoTipoUsuario() {
    	Scanner keyboard = new Scanner(System.in);
    	int opcao = keyboard.nextInt();
    	switch (opcao) {
    	case 1: 
    		this.tipoUsuario = TIPO_USUARIO.COMUM;
    		this.arquivoUsuario = "usuario-comum.txt";
    		this.arquivoUsuarioBin = "login-comum.bin";
    		break;
    	case 2:
    		this.tipoUsuario = TIPO_USUARIO.ADMINISTRADOR;
    		this.arquivoUsuario = "usuario-adm.txt";
    		this.arquivoUsuarioBin = "login-adm.bin";
    		break;
    	case 0: this.finalizar = true;
    	}
    }
    
    public void exibeMenuUsuario(){
    	System.out.println(" ______________________________________________________________________________________________________________ ");
        System.out.println("|                                             BICICLETAS UFF                                                   |");
    	System.out.println(" ______________________________________________________________________________________________________________ ");
        System.out.println("1 - CADASTRAR NOVO USUARIO; ");
        System.out.println("2 - LOGIN (USUARIO); ");
        System.out.println("3 - RECUPERAR LOGIN/SENHA; ");
        System.out.println("0 - SAIR DO PROGRAMA.");
        System.out.println("|______________________________________________________________________________________________________________|");
		System.out.println("Digite a Opcao Desejada: ");
    }
    
    public void processarInteracaoUsuario() {
    	Scanner keyboard = new Scanner(System.in);
    	int opcao = keyboard.nextInt();
    	switch(opcao) {
    	case 1: this.cadastrarUsuario(); break;
    	case 2: this.login();break;
    	case 3: IO.recuperarSenha(this.arquivoUsuarioBin); break;
    	case 0: finalizar = true;
    	}
    }
    
    /*Usuários comuns podem entretanto consultar estações, consultar bicicletas, alugar e devolver uma bicicleta.*/
    public void exibeMenuUsuarioComum() {
    	System.out.println("-------------------------------");
    	System.out.println("1 - CONSULTAR ESTACOES;");
    	System.out.println("2 - CONSULTAR BICICLETAS; ");
    	System.out.println("3 - ALUGAR BICICLETAS; ");
    	System.out.println("4 - DEVOLVER BICICLETA;");
    	System.out.println("0 - SAIR DO PROGRAMA.");
    	System.out.println("-------------------------------");
    	System.out.println("Digite a Opcao Desejada: ");
    }
    
    public void processarInteracaoUsuarioComum() {
    	Scanner keyboard = new Scanner(System.in);
    	int opcao = keyboard.nextInt();
    	switch (opcao) {
    	case 1: this.consultarEstacoes(); break;
    	case 2: this.consultarBicicletas(); break;
    	case 3: this.alugarBicicleta();break;
    	case 4: this.devolverBicicleta();break;
    	case 0: this.finalizar = true;
    	}
    }
    
    public void exibeMenuUsuarioADM() {
    	System.out.println("-------------------------------");
    	System.out.println("1 - CADASTRAR BICICLETAS;");
    	System.out.println("2 - CONSULTAR BICICLETAS;");
    	System.out.println("3 - CADASTRAR ESTACOES; ");
		System.out.println("4 - CONSULTAR ESTACOES; ");
		System.out.println("5 - ALUGAR BICICLETA; ");
		System.out.println("6 - DEVOLVER BICICLETA; ");
		System.out.println("7 - MANUTENCAO BICICLETA; ");
		System.out.println("8 - FIM MANUTENCAO BICICLETA; ");
		System.out.println("0 - SAIR DO PROGRAMA. ");
    	System.out.println("-------------------------------");
    	System.out.println("Digite a Opcao Desejada: ");
    }
  
    
    public void processarInteracaoUsuarioADM() {
		Scanner keyboard = new Scanner(System.in);
		int opcao = keyboard.nextInt();
    	switch (opcao) {
		case 1: this.cadastrarBicicletas(); break;
		case 2: this.consultarBicicletas(); break;
		case 3: this.cadastrarEstacoes(); break;
		case 4: this.consultarEstacoes(); break;
		case 5: this.alugarBicicleta(); break;
		case 6: this.devolverBicicleta();break;
		case 7: this.manutencaoBicicleta();break;
		case 8: this.fimManutencao();break;
		case 0: this.finalizar = true;
		}	
    }

    
	public void cadastrarBicicletas() {
		Scanner teclado = new Scanner(System.in); 
		System.out.println("Digite Quantas Bicicletas quer Cadastrar: ");
		int numBicicletas = teclado.nextInt();
		int id, numPatrimonio, tipo, pos;
		for (int i = 0; i<numBicicletas; i++) {
			pos = i + 1;
			System.out.println("Digite o ID e NUM. de Patrimonio da " + pos + "a. Bicicleta (6 DIGITOS) E O TIPO (0-COMUM, 1- GPS): ");
			id = teclado.nextInt();
			numPatrimonio = teclado.nextInt();
			tipo = teclado.nextInt();
			Bicicleta b;
			if (tipo == 0) b = new Bicicleta(id, numPatrimonio);
			else {
				System.out.println("Digite o Modelo de GPS: ");
				String modelo = teclado.next();
				b = new BicicletaGPS(id,  numPatrimonio, modelo);
			}
			System.out.println("Deseja Alocar Bicicleta na Estacao ('s'/'n')? ");
			String resp = teclado.next();
			if (resp.toLowerCase().charAt(0) == 's') {
				this.consultarEstacoes();
				System.out.println("Digite o Identificador da Estacao Desejada: ");
				int idEstacao = teclado.nextInt();
				Estacao estacao = estacoes.getId(idEstacao);
				if (estacao!=null) {
					b.estacionar(estacao);
				}else System.out.println("Estacao INVALIDA!");
			}
			this.bicicletas.append(b);
		}
	}
	
	public void cadastrarEstacoes() {
		Scanner teclado = new Scanner(System.in);
		System.out.println("Quantas Estacoes quer Cadastras: ");
		int numEstacoes = teclado.nextInt();
		int pos;
		for (int i = 0; i < numEstacoes; i++) {
			pos = i + 1;
			System.out.println("Digite o ID, NOME e LOCALIDADE da " + pos + "a. ESTACAO: ");
			int id = teclado.nextInt();
			String nome = teclado.next();
			String localidade = teclado.next();
			this.estacoes.append(new Estacao(id, nome, localidade));
			System.out.println("Deseja Alocar Bicicletas na Estacao ('s'/'n')? ");
			String resp = teclado.next();
			if (resp.toLowerCase().charAt(0) == 's') {
				this.consultarBicicletas();
				System.out.println("Deseja Alocar QUANTAS Bicicletas na Estacao? ");
				int numBicicletas = teclado.nextInt();
				for (int j = 0; j < numBicicletas; j++) {
					System.out.println("Digite o ID da Bicicleta que quer Estacionar na Estacao: ");
					int idBicicleta = teclado.nextInt();
					this.estacionarBicicleta(idBicicleta, id);
				}
			}
		}
	}
	
	
	public void consultarBicicletas() {
        System.out.println("________________________________________________________________________________________________________________");
		System.out.println("Bicicletas Cadastradas: ");
		for (int i = 0; i < this.bicicletas.length(); i++) {
			try {
				System.out.println(bicicletas.get(i));				
			}catch (ArrayIndexOutOfBoundsException e) {
				System.out.println(e);
			}
		}
        System.out.println("________________________________________________________________________________________________________________");
	}
	
	public void consultarEstacoes() {
        System.out.println("________________________________________________________________________________________________________________");
        System.out.println("Estacoes Cadastradas: ");
        for (int i = 0; i < this.estacoes.length(); i++) {
        	try {
        		System.out.println(estacoes.get(i));
        	}catch(ArrayIndexOutOfBoundsException e) {
        		System.out.println(e);
        	}
        }
        System.out.println("________________________________________________________________________________________________________________");
	}
	
	
	
	/* Implemente o método para mover uma bicicleta de uma estação para outra */
	public void estacionarBicicleta(int idBicicleta, int idEstacao){
		Bicicleta b = this.bicicletas.getId(idBicicleta);
		Estacao e = this.estacoes.getId(idEstacao);
		b.estacionar(e);
	}
	
	public void consultarUsuario() {
		 System.out.println("________________________________________________________________________________________________________________");
	     System.out.println("Usuarios Cadastrados: ");
	     for (int i = 0; i < this.usuarios.length();i++) {
	    	 try {
	    		 System.out.println(usuarios.get(i));
	    	 }catch (ArrayIndexOutOfBoundsException e) {
	    		 System.out.println(e);
	    	 }
	     }
	     System.out.println("________________________________________________________________________________________________________________");
	}
	/*
	11)Implemente na classe Sistema a funcionalidade de cadastrar um usuário. No cadastro do
	usuário, o usuário deve informar um login e senha, que devem ser armazenados em um arquivo
	binário.*/
	
	public Usuario cadastrarUsuarioArquivo() {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("________________________________________________________________________________________________________________");
		System.out.println("                                              CADASTRO DE USUARIO:                                               ");
		System.out.println("|_______________________________________________________________________________________________________________|");
		System.out.println("[ID]: ");
		int id = keyboard.nextInt();
		System.out.println("[MATRICULA]: ");
		int matricula = keyboard.nextInt();
		System.out.println("[NOME]: ");
		String nome = keyboard.next();
		System.out.println("[ENDERECO]: ");
		String endereco = keyboard.next();
		System.out.println("[TELEFONE]: ");
		String telefone = keyboard.next();
		System.out.println("[E-MAIL]: ");
		String email = keyboard.next();
		return new Usuario(id,matricula,nome,endereco,telefone,email);
	}
	
	public void cadastrarUsuario() {
		boolean continua = true;
		Scanner keyboard = new Scanner(System.in);
		do {
			Usuario u = this.cadastrarUsuarioArquivo();
			cadastrarUsuarioBinario(u);
			System.out.println("Deseja Cadastrar Outro Usuario ('s'/'n')?");
			String resp = keyboard.next();
			if (resp.toLowerCase().charAt(0) == 'n') continua = false;
		}while (continua);
	}

	
	final int TAM_REG = 10 + 4;

	public void cadastrarUsuarioBinario(Usuario u) {
		Scanner keyboard = new Scanner(System.in);
		FileOutputStream fo = null;
		System.out.println("==================================================");
		System.out.println("                CADASTRO DE LOGIN:               ");
		System.out.println("==================================================");
		System.out.println("Informe o LOGIN: ");
		String login = keyboard.next();
		String nomeArquivo = this.arquivoUsuarioBin;
		
		boolean existente = loginExistente(login, nomeArquivo);
		if (!existente) {
			System.out.println("Informe a SENHA (NUM. interios): ");
			int senha = keyboard.nextInt();
			u.getLogin().setLogin(login);
			u.getLogin().setSenha(senha);
			try {
				fo = new FileOutputStream(nomeArquivo, true);
				byte[] b = new byte[TAM_REG];
				Arrays.fill(b, (byte)0);
				ByteBuffer bb = ByteBuffer.wrap(b);
				bb.put(login.getBytes());
	            bb.putInt(10,senha);
	            fo.write(b);
			}catch(IOException e) {
				System.out.println(e);
			}finally {
				try{
					if (fo != null) fo.close();
				}catch (IOException e) {
					System.out.println(e);
				}
			}
			this.usuarios.append(u);
			IO.cadastrarUsuarioArquivo(u, this.arquivoUsuario);

		}else {
			System.out.println("LOGIN JA EXISTENTE! USUARIO NAO CADASTRADO!...");
		}
	}
	
	public boolean loginExistente(String login, String nomeArquivo) {
		int i = -1;
		try {
			FileInputStream fi = new FileInputStream(nomeArquivo);
			try (DataInputStream di = new DataInputStream(fi)) {
				boolean eof = false;
				do {
					i++;
					byte[] b = new byte[10]; //le a string Login
					di.read(b,0,10);
					int senha = di.readInt();
					String log = new String(b).trim();
					if (log.equals(login)) {
						this.usuario = usuarios.get(i);
						return true;
					}
				}while(!eof);
			}
		}catch(IOException e) {
			System.out.println(e);
		}
			
		return false;
	}
	/*13) Implemente na classe Sistema a funcionalidade de login para um usuário.*/
	public void login() {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("==============================================");
		System.out.println("                    LOGIN:                    ");
		System.out.println("==============================================");
		System.out.println("[LOGIN] : ");
		String login = keyboard.next();
		System.out.println("[SENHA]: ");
		String nomeArquivo = this.arquivoUsuarioBin;
		int senha = keyboard.nextInt();
		if (this.loginExistente(login,nomeArquivo)) {
			try {
				FileInputStream fi = new FileInputStream(nomeArquivo);
				DataInputStream di = new DataInputStream(fi);
				
				boolean eof = false;
				
				do {
					byte[] b = new byte[10];
					if (di.read(b,0,10)!= -1) {
						int sen = di.readInt();
						String log = new String(b).trim();
						if (log.equals(login) && sen == senha) {
							System.out.println("AUTENTICADO!");
							this.logado = true;
							return;
						}
					}else eof = true;
				}while(!eof);
				System.out.println("DADOS INCORRETOS! ");
			}catch(IOException e) {
				System.out.println(e);
			}
		}else {
			System.out.println("LOGIN INVALIDO! ");
		}

	}

	/*14) Implemente na classe Sistema a funcionalidade que permite a um usuário alugar uma bicicleta.
	Uma bicicleta só pode ser alugada se ela estiver estacionada ou não estiver em manutenção.*/
	public void alugarBicicleta() {
		Scanner keyboard = new Scanner(System.in); 
		System.out.println("==============================================");
		System.out.println("           ALUGUEL DE BICICLETAS              ");
		System.out.println("==============================================");
		System.out.println("Bicicletas Disponiveis: ");
		for (int i = 0; i < this.bicicletas.length(); i++) {
			Bicicleta b = this.bicicletas.get(i);
			if (b.getEstado() == ESTADO.PARADA)
				System.out.println(b);
		}
		System.out.println("------------------------------------------------");
		System.out.println("Digite o ID da Bicicleta que deseja Alugar: ");
		int id = keyboard.nextInt();
		Bicicleta b = this.bicicletas.getId(id);
		if (b.getEstado() == ESTADO.PARADA) {
			b.setEstado(ESTADO.ALUGADA);
			this.usuario.setBicicleta(b);
			b.setEstacao(null);
			b.setUsuario(this.usuario);
			System.out.println("Bicicleta " + id + " alugada com sucesso!");
		}else {
			System.out.println("IMPOSSIVEL ALUGAR! Bicicleta em estado de " + b.getEstado() + ". ");
		}
	}
	
	/*15) Implemente na classe Sistema a funcionalidade que permite a um usuário devolver uma
	bicicleta. Uma bicicleta só pode ser devolvida se ela estiver alugada.*/
	public void devolverBicicleta() {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("==============================================");
		System.out.println("             RETORNAR BICICLETAS              ");
		System.out.println("==============================================");
		for (int i = 0;i < this.bicicletas.length();i++) {
			Bicicleta b = this.bicicletas.get(i);
			if (b.getEstado() == ESTADO.ALUGADA)
				System.out.println(b);
		}
		System.out.println("------------------------------------------------");
		System.out.println("Digite o ID da Bicicleta que deseja Devolver: ");
		int idB = keyboard.nextInt();
		Bicicleta b = this.bicicletas.getId(idB);
		if (b.getEstado() == ESTADO.ALUGADA) {
			this.consultarEstacoes();
			System.out.println("Digite o ID da ESTACAO atual: ");
			int idE = keyboard.nextInt();
			this.estacionarBicicleta(idB, idE);
			System.out.println("Bicicleta " + idB + " retornada com sucesso!");
		}else {
			System.out.println("IMPOSSIVEL RETORNAR! Bicicleta em estado de " + b.getEstado() + ". ");
		}
	}
	
	/* 16) Implemente na classe Sistema a funcionalidade de indicar uma bicicleta para manutenção.
	Bicicletas em manutenção devem ser armazenadas em uma lista própria.*/
	public void manutencaoBicicleta() {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("==============================================");
		System.out.println("            MANUTENCAO DE BICICLETAS          ");
		System.out.println("==============================================");
		this.consultarBicicletas();
		System.out.println("------------------------------------------------");
		System.out.println("Digite o ID da Bicicleta que deseja por em Manutencao: ");
		int id = keyboard.nextInt();
		Bicicleta b = this.bicicletas.getId(id);
		if (b.getEstado() != ESTADO.MANUTENCAO) {
			b.setEstado(ESTADO.MANUTENCAO);
			this.bicicletasManutencao.append(this.bicicletas.getId(id));
			System.out.println("Bicicleta " + id + " colocada em manutencao com sucesso!");
		}
		else System.out.println("Impossivel! BICICLETA ja esta em MANUTENCAO! ");
	}
	
	/*17) Implemente na classe Sistema a funcionalidade de tirar uma bicicleta da manutenção e alocar a
	uma estação.*/
	public void fimManutencao() {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("==============================================");
		System.out.println("              ALOCACAO DE BICICLETAS          ");
		System.out.println("==============================================");
		for (int i = 0;i < this.bicicletasManutencao.length();i++) {
			Bicicleta b = this.bicicletasManutencao.get(i);
			if (b.getEstado() == ESTADO.MANUTENCAO)
				System.out.println(b);
		}
		System.out.println("------------------------------------------------");
		System.out.println("Digite o ID da Bicicleta que deseja remover da Manutencao: ");
		int idB = keyboard.nextInt();
		if (this.bicicletas.getId(idB).getEstado() == ESTADO.MANUTENCAO) {
			this.consultarEstacoes();
			System.out.println("Digite o ID da Estacao que deseja atribuir a bicicleta : ");
			int idE = keyboard.nextInt();
			this.bicicletasManutencao.removerId(idB);
			this.estacionarBicicleta(idB, idE);
			System.out.println("Bicicleta Alocada com sucesso!");
			return;
		}
		System.out.println("IMPOSSIVEL ALOCAR! A Bicicleta NAO estava em Manutencao! ");
	}

	
}
