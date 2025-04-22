.data
digiteN: .asciz "Digite o Valor de N: "
.text
li a7, 4
la a0, digiteN
ecall

li a7, 5
ecall

fib:
	beq a0, zero, return #if n == 0, return 
	li t0, 1
	beq a0, t0, return #if n == 1, return
	#t0 vira o contador
	li t1, 0 #n1
	li t2, 1 #n2
	li t3, 0 #aux
	for: 
		bge t0, a0, endFor
		mv t3, t2
		add t2, t2, t1
		mv t1,t3
		addi t0, t0, 1
		j for
	endFor:
		mv a0, t2
return:
	ret
#int fibSemRecursao(int n){
    #if (n == 0) return n;
    #if (n == 1) return 1;
    #int n1 = 0, n2 = 1;
    #int aux;
    #for (int i = 1; i < n; i++){
        #aux = n2;
        #n2 = n1 + n2;
        #n1 = aux;
    #}return n2;
#}