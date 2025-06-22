.data
	input1: .asciz "Primeiro Numero: "
	input2: .asciz "Segundo Numero: "
	resultado: .asciz "Resultado: "
 
.text
#leitura do primeiro numero
li a7, 4
la a0, input1
ecall

li a7, 5
ecall

mv t0, a0 #move o valor de a0 para t0

#leitura do segundo numero
li a7,4
la a0, input2
ecall

li a7, 5
ecall

mv t1, a0

#soma

add t2, t0, t1

#printando o resultado
li, a7, 4
la a0, resultado
ecall

li, a7, 1
mv a0, t2
ecall