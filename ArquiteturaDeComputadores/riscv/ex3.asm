.data
	x: .word 10
	y: .word 0
.text
la t0, x #endereco de x
lw t1, 0(t0) #val de x
la t2, y #endereco de y
#lw t3, 0(t2) #val de y
addi s0, t1, 2 #y = x + 2
sw s0, 0(t2) #salva y
