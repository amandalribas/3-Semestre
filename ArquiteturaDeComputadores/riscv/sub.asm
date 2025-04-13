.data 
	input1: .asciz "Primeiro Valor: "
	input2: .asciz "Segundo Valor: "
	resultado: .asciz "Resultado: "
.text
#Primeiro Valor:
	li a7, 4
	la a0, input1
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	
#Segundo Valor:
	li a7, 4
	la a0, input2
	ecall
	
	li a7, 5
	ecall
	
	mv t1, a0
	
#Resultado
	sub t2,t0,t1
	
	li a7, 4
	la a0, resultado
	
	li a7, 1 #printa o int alocado no a0
	mv a0, t2
	ecall 
	
	