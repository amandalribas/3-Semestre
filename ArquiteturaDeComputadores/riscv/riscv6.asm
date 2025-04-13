.data
	input1: .asciz "Ïnsira o primeiro Valor: "
	input2: .asciz "Insira o Segundo Valor: "
	resultado: .asciz "Resultado: \n"
	line: .asciz "\n"
	
.text
#primeiro Valor	
	li a7, 4 #printString
	la a0, input1
	ecall
	
	li a7,5 #readInt
	ecall #salva no a0
	mv t0, a0 #move t0 <- a0

#segundo valor	
	li a7, 4 #printString
	la a0, input2
	ecall
	
	li a7,5 #readInt
	ecall #salva no a0
	mv t1, a0 #move t0 <- a0
	
#contas
	add t2, t0, t1
	sub t3, t0, t1
	mul t4, t0, t1
	div t5, t0, t1
	rem t6, t0, t1 #Resto da Div
	
#Prints Resultados

	li a7, 4
	la a0, resultado
	ecall
	
	 li a7, 1 #printa Soma
	 mv a0, t2
	 ecall
	 
	 li a7, 4 #pula linha
	 la a0, line
	 ecall
	 
	 li a7, 1 #printa sub
	 mv a0, t3
	 ecall
	 
	 li a7, 4 #pula linha
	 la a0, line
	 ecall
	 
	 li a7, 1 #mult
	 mv a0, t4
	 ecall
	 
	 li a7, 4 #pula linha
	 la a0, line
	 ecall
	 
	 li a7, 1 #div
	 mv a0, t5
	 ecall
	 
	 li a7, 4 #pula linha 
	 la a0, line 
	 ecall
	 
	 li a7, 1 #resto
	 mv a0, t6
	 ecall
	 
	  