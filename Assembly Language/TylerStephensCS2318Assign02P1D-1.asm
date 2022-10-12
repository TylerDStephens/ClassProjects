##########################################################################
# Tyler Stephens CS 2318-254, Assignment 2 Part 1 Program D
##########################################################################
.data
e1Score:		.asciiz "Enter integer score for Exam 1: "
e2Score:		.asciiz "Enter integer score for Exam 2: "
finalScore:		.asciiz "Enter integer score for Final Exam: "
avgScore:		.asciiz "The weighted average is:  "
            	     	.text
		     	.globl main
main:
            ################################################
            #Enter the scores for the Exams
            ################################################
            li $v0, 4
            la $a0, e1Score
            syscall
            li $v0, 5
            syscall        
            move $t0, $v0

            li $v0, 4
            la $a0, e2Score   
            syscall
            li $v0, 5
            syscall      
            move $t1, $v0

            li $v0, 4
            la $a0, finalScore   
            syscall
            li $v0, 5
            syscall
            move $t2, $v0
            ################################################
            #Compute weighted average
            ################################################

            # multiply e1Score by 63
            li $t4, 63         
            mul $t0, $t0, $t4
            # divide e1score by 256
            sra $t0, $t0, 8
	    # multiply e2score by 128
            li $t5, 128         
            mul $t1, $t1, $t5
            # divide e2Score by 1024
            sra $t1, $t1, 10
            # divide finalScore by 2
            sra $t2, $t2, 1

            li $t4, 0     # ensure $t4 is 0
            add $t4, $t4, $t0
            add $t4, $t4, $t1
            add $t4, $t4, $t2

            li $v0, 4
            la $a0, avgScore
            syscall
            li $v0, 1
            move $a0, $t4
            syscall

            li $v0, 10      # graceful exit service
            syscall