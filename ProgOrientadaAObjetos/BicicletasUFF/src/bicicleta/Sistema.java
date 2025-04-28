package bicicleta;

import java.util.Scanner;

public class Sistema {
	private ListaBicicletas bicicletas;
	private ListaEstacoes estacoes;
    private boolean finalizar;

    public Sistema(){
        this.finalizar = false;
    }
    
    public void inicializar() {
    	this.bicicletas = IO.lerBicicletasArquivo();
    	this.estacoes = IO.lerEstacoesArquivo();
    }
    
    public void iniciar() {
    	this.finalizar = false;
    	this.inicializar();
    	do {
    		this.exibeMenuPrincipal();
    		this.processarInteracao();
    	}while(!finalizar);
    }
    
    public void exibeMenuPrincipal() {
    	System.out.println(" ______________________________________________________________________________________________________________ ");
        System.out.println("|                                                  BICICLETAS UFF                                              |");
        System.out.println("|______________________________________________________________________________________________________________|");
		System.out.println("1 - Cadastrar BICICLETAS");
		System.out.println("2 - Consultar BICICLETAS; ");
		System.out.println("3 - Cadastrar ESTACOES; ");
		System.out.println("4 - Consultar ESTACOES; ");
		System.out.println("0 - Sair do Programa. ");
		System.out.println("|______________________________________________________________________________________________________________|");
		System.out.println("Digite a Opcao Desejada: ");

	}
    public void processarInteracao() {
		Scanner keyboard = new Scanner(System.in);
		int opcao = keyboard.nextInt();
    	switch (opcao) {
		case 1: this.cadastrarBicicletas(); break;
		case 2: this.consultarBicicletas(); break;
		case 3: this.cadastrarEstacoes(); break;
		case 4: this.consultarEstacoes(); break;
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
	
	public void estacionarBicicleta(int idBicicleta, int idEstacao){
		/* Implemente o método para mover uma bicicleta de uma estação para outra */
		Bicicleta b = this.bicicletas.getId(idBicicleta);
		Estacao e = this.estacoes.getId(idEstacao);
		b.estacionar(e);
	}
	
}
