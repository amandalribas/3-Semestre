.data
	input1: .asciz "Primeiro Valor: "
	input2: .asciz "Segundo Valor: "
	resultado: .asciz "Resultado: "
.text
#Primeiro Valor
	li, a7, 4 #PrintString
	la a0, input1
	ecall
	
	li, a7, 5 #ReadInt
	ecall
	
	mv t0, a0 #move t0 <- a0
	
#Segundo Valor
	li, a7, 4 #Print String
	la a0, input2
	ecall
	
	li, a7, 5 #ReadInt
	ecall
	
	mv t1, a0 #move t1 <- a0
	
#Resultado 
	div t2, t0, t1
	
	li a7, 4 #PrintString
	la a0, resultado
	ecall
	
	li a7, 1
	mv a0, t2
	ecall
		