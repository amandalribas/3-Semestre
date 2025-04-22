.data
inputQuantidade: .asciz "Digite a Quantidade de Notas: "
inputNota: .asciz "Nota Obtida: "
media: .asciz "\nMedia Final: "
.text

#Print String ("Digite a Quantidade de Notas: ")
li a7, 4
la a0, inputQuantidade
ecall

#ReadInt Quantidade de Notas
li a7, 5
ecall #Quantidade de Notas - a0


mv t0, a0 #Quantidade de Notas - t0
addi t1, zero, 0 #Contador

for: 
	bge t1, t0, end
	#Print String ("Nota Obtida: ")
	li a7, 4
	la a0, inputNota
	ecall
	
	#ReadInt nota
	li a7, 5
	ecall #nota lida vai pro a0
	
	add t2, t2, a0
	addi t1,t1,1 #t1 - contador
	j for
end:
 	#Calcula Media colocando no t2
	div t2, t2, t0
	
	#Print String ("Media Final: ")
	li a7, 4
	la a0, media
	ecall
	#PrintInt Media Final
	li a7, 1
	mv a0, t2
	ecall
	