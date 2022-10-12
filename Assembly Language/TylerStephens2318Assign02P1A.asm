##########################################################################
# Tyler Stephens CS 2318-254, Assignment 2 Part 1 Program A
##########################################################################
			.data
string:			.space 70
eyiPrmpt:		.asciiz "Enter a integer: "
yiiLab:			.asciiz "The number you integer  "
eysPrmpt:		.asciiz "Enter String: "
ysiLab:			.asciiz "Your typed in string is  "
eycPrmpt:		.asciiz "Enter Character: "
yciLab:			.asciiz "Your entered character "

		        .text
			.globl main
main:
			li $v0,4
			la $a0, eyiPrmpt
			syscall
			li $v0,5
			syscall
			move $t0, $v0
			li $v0,4
			la $a0, yiiLab
			syscall
			li $v0,1
			move $a0, $t0
			syscall
			
			li $v0, 11
			li $a0, '\n'
			syscall
			li $v0, 11
			li $a0, '\n'
			syscall
		
			
			li $v0,4
			la $a0, eysPrmpt
			syscall
			li $v0, 8
			la $a0, string
			li $a1, 70
			syscall
			li $v0,4
			la $a0, ysiLab
			syscall
			la $a0, string
			syscall

			li $v0, 11
			li $a0, '\n'
			syscall
			
			li $v0,4
			la $a0, eycPrmpt
			syscall
			li $v0,12
			syscall
			move $t0, $v0
			li $v0, 11
			li $a0, '\n'
			syscall
			li $v0,4
			la $a0, yciLab
			syscall
			li $v0,11
			move $a0, $t0
			syscall
			
			li $v0, 10			# graceful exit
			syscall
