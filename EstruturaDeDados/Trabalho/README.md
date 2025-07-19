Trabalho para a Disciplina de Estrutura de Dados e Seus Algorítmos na UFF - Universidade Federal Fluminense, no período 2025.1, realizado por Amanda Lemos Ribas.
O trabalho consiste em implementar as estruturas de dados árvore b+, hash e heap em disco, respeitando registros com nome, cpf (não necessariamente válido) e nota (de 0 a 100).

No terminal, para compilar, digite: 

    gcc geraRegistros.c heap.c hash.c main.c -o teste
    .\teste
  
geraRegistros.h é a biblioteca que acompanha o arquivo .c contendo o gerador de arquivos .bin aleatórios e funções auxiliares para serem utilizadas pelas estruturas de dados.

	Gera o cpf aleatório a partir da soma de dois valores aleatórios de 6 dígitos, respeitando determinado intervalo para não ultrapassar os 11 dígitos.
  
	Lê nomes e sobrenomes de arquivo.txt para gerar um aleatórios.
  
	Escreve em "arquivos/registros.bin" .bin os 10000 registros.
  
hash.h é a implementação do hash em disco, com endereçamento aberto, escreve em "arquivos/registrosHash.bin", tabela de tamanho 100.000.

	Registros vazios na tabela contém {-1,"",-1}
  
	Considera a chave como os primeiros 9 dígitos do cpf, adquirido na função do do geraRegistros.h geraChaveCpf()
  
	Função hash h(x), soma +k ao valor do rand(), k, inicialmente 0, acrescenta 1 a cada colisão.
    
    BUSCA na Tabela Hash:
      Calcula a chave hash usando a h(x,k)
      Percorre as posições até encontrar:
          O registro com o CPF desejado (sucesso)
          Uma posição vazia (-1) (fracasso)
          Percorrer toda a tabela (fracasso)
    
    INSERE na Tabela Hash:
      Calcula a chave hash usando função h(x,k)
      Busca ate encontrar posição vazia
      Se encontrar posição vazia, insere o registro
      Se a tabela estiver cheia (k >= M), retorna erro  

    EXCLUI na Tabela Hash:
    Localiza o registro usando a função de busca
    Se encontrado, substitui por um registro marcado como vazio (CPF = -1)
    Se não, sinaliza erro.

heap.h contém a implementação do Heap Máximo em Disco no arquivo de mesmo nome .c, escreve em "arquivos/registrosHeap.bin", a nota é a prioridade.
  
	Criação das funções auxiliares de subida e descida.
    SOBE:
      Compara com o pai (índice posicao/2)
      Se for maior que o pai, troca de posição
      Repete o processo até que a propriedade do heap seja restaurada
    DESCE: 
      Compara os filhos, seleciona o maior.
      Se o filho for maior que o pai, o pai deve descer, trocando com o filho
      Repete o processo até que a propriedade do heap seja restaurada
      
    INSERE no Heap:
      Chama a função sobe para ajustar a posição do novo elemento.

    BUSCA no Heap:
      Sempre retorna o elemento no topo do heap (posição 1 do array)

    EXCLUI no Heap:
      Substitui o elemento do topo pelo último elemento do heap
      Reduz o tamanho do heap
      Chama a função desce para ajustar a posição do novo topo

  bMais.h contém a implementação de B+ em memória secundária, ordenando pela chave CPF de 9 dígitos, lê os registros do arquivo .bin.
    
		Ordem D = 5
    
    INSERE na B+:
      Busca a folha correta para inserção (ordenado por CPF)
      Se a folha tiver espaço, insere o registro ordenadamente
      Se a folha estiver cheia (2D-1 chaves):
        Divide a folha em duas
        Promove a chave do meio para o nó pai
        Repete o processo de divisão recursivamente até a raiz se necessário

    BUSCA na B+:
      Começa na raiz da árvore
      Em cada nó, realiza busca binária para encontrar:
        A chave desejada (retorna o nó)
        O próximo filho a ser percorrido
        Nas folhas, verifica se a chave existe

        Localiza a folha que contém a chave

    EXCLUI na B+:
      Remove a chave da folha
      Se a folha ficar com menos de D-1 chaves:
      Tenta redistribuir com irmão adjacente
      Se não possível, realiza fusão com irmão
      Ajusta os nós pais recursivamente


main.c contém um menu que permite a escolha das operações GERAR, INSERIR, REMOVER e BUSCA de todas as Estruturas de Dados Citadas.
