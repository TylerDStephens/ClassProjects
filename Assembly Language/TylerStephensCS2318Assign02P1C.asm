##########################################################################
# Tyler Stephens CS 2318-254, Assignment 2 Part 1 Program C
##########################################################################

			.data

globalArr:		.word 3,5,2,4,1		# global int array of size 5 initialized
			 			
			.text
			.globl main
main:
												
			la $t0, globalArr	# $t0 has address of globalArr
			li $v0, 11
			li $a0, '\n'
			syscall

			li $v0, 1
			lw $a0, 0($t0)		#load globalArr[0] in memory into $a0
			syscall		
			lw $a0, 4($t0)         #load globalArr[1] in memory into $a0
			syscall
			lw $a0, 8($t0)		#load globalArr[2] in memory into $a0
			syscall
			lw $a0, 12($t0)		#load globalArr[3] in memory into $a0
			syscall	
			lw $a0, 16($t0)		#load globalArr[4] in memory into $a0
			syscall		
			li $v0, 11
			li $a0, '\n'
			syscall
			##Swap- new order should be 3, 1, 4, 2 and 5
			lw $t1, 4($t0)
			lw $t2, 8($t0)
			lw $t3, 12($t0)
			lw $t4, 16($t0)
			sw $t1, 16($t0)
			sw $t2, 12($t0)
			sw $t3, 8($t0)
			sw $t4, 4($t0)
		
			
			li $v0, 1
			lw $a0, 0($t0)		#load globalArr[0] in memory into $a0
			syscall		
			lw $a0, 4($t0)         #load globalArr[1] in memory into $a0
			syscall
			lw $a0, 8($t0)		#load globalArr[2] in memory into $a0
			syscall
			lw $a0, 12($t0)		#load globalArr[3] in memory into $a0
			syscall	
			lw $a0, 16($t0)		#load globalArr[4] in memory into $a0
			syscall	
			li $v0, 10		# graceful exit
			syscall

						
			
