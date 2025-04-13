.data #VARIAVEIS GLOBAIS 
	input1: .asciz "Primeiro Valor: "
	input2: .asciz "Segundo Valor: "
	resultado: .asciz "Resultado: "
.text
	
#PRIMEIRO VALOR: 
	li a7, 4
	la a0,input1 #Printa input 1
	ecall
	
	li a7, 5
	ecall #salva no a0 o int lido
	mv t0, a0 #move do a0 para t0
	
#SEGUNDO VALOR:
	li a7, 4
	la a0, input1 #printa input 2
	ecall
	
	li a7,5
	ecall
	mv t1, a0 #move do a0 para t1
	
#RESULTADO:

	mul t2, t0,t1
	
	li a7, 4
	la a0, resultado
	ecall
	
	li a7, 1 
	#printInt (1), printa o valor salvo no a0
	mv a0, t2
	ecall
	