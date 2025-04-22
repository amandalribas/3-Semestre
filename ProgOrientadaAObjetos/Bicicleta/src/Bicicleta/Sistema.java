package Bicicleta;

import java.util.Scanner;

public class Sistema {
	private ListaBicicletas bicicletas;

	
	public void inicializar() {
		this.bicicletas = new ListaBicicletas(100);
		int opcao;
		do {
			this.exibeMenu();
			opcao = this.escolherMenu();
			IO inOut = new IO();
			switch (opcao) {
			case 1: this.cadastrarBicicletas(); break;
			case 2: this.consultarBicicletas(); break;
			case 3: inOut.consultaBicicletasArquivo(); break;
			case 4: inOut.escreverBicicletasArquivo(); break;
			case 5: inOut.adicionarBicicletasArquivo(); break;
			}			
		}while(opcao != 0);
		System.out.println("Finalizando...");
	}
	
	public void exibeMenu() {
		System.out.println("----------------------------");
		System.out.println("1 - Cadastrar Bicicletas; (LISTA) ");
		System.out.println("2 - Consultar Bicicletas; (LISTA) ");
		System.out.println("3 - Consultar Bicicletas de ARQUIVO; ");
		System.out.println("4 - Escrever Bicicletas em ARQUIVO; ");
		System.out.println("5 - Adicionar Bicicletas em ARQUIVO; ");
		System.out.println("6 -  ");
		System.out.println("0 - Sair do Programa. ");
		System.out.println("----------------------------");
	}
	
	public int escolherMenu() {
		Scanner teclado = new Scanner(System.in);

		System.out.println("Digite a Opcao Desejada: ");
		int opcao = teclado.nextInt();
		return opcao;
	}
	
	
	public String leNomeArquivo() {
		Scanner teclado = new Scanner(System.in);
		System.out.println("Digite o nome do Arquivo: ");
		String arquivo = teclado.next();
		return arquivo;
	}
	
	public void cadastrarBicicletas() {
		Scanner teclado = new Scanner(System.in); 
		System.out.println("Digite Quantas Bicicletas quer Cadastrar: ");
		int numBicicletas = teclado.nextInt();
		int id, numPatrimonio, pos;
		for (int i = 0; i<numBicicletas; i++) {
			pos = i + 1;
			System.out.println("Digite o ID e NUM. de Patrimonio da " + pos + "a. Bicicleta: ");
			id = teclado.nextInt();
			numPatrimonio = teclado.nextInt();
			bicicletas.append(new Bicicleta(id, numPatrimonio));
		}
	}
	
	public void consultarBicicletas() {
		System.out.println("Bicicletas Cadastradas: ");
		for (int i = 0; i < this.bicicletas.length(); i++) {
			try {
				System.out.println(bicicletas.getBicicleta(i));				
			}catch (ArrayIndexOutOfBoundsException e) {
				System.out.println(e);
			}
		}
		System.out.println("----------------------------");
	}
	
	
}
