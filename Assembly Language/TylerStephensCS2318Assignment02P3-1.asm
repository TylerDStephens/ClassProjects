###############################################################################
# Title: Assign02P3                   Author: Tyler Stephens
# Class: CS 2318-254, Spring 2021     Submitted: 4/10/2021
###############################################################################
# Program: MIPS tranlation of a given C++ program
###############################################################################
# Pseudocode description: supplied a2p2_SampSoln.cpp
###############################################################################
		.data
a1:		.space 36
a2:		.space 36
a3:		.space 36
eiaPrmpt:	.asciiz "# of int's for base array ( >= 1 and <= 9 ): "
taPrmpt:	.asciiz "# entered not in range ... try again..."
einPrmpt:	.asciiz "integer #"
spacer:		.asciiz  "================================" 
a1Msg:		.asciiz "a1: "
a2Msg:		.asciiz "a2: " 	
a3Msg:		.asciiz "a3: " 	
daPrmpt:	.asciiz "Do another (n or N = no, others = yes) "
byeMsg:		.asciiz "bye..."

		.text
		.globl main
main:               
               
########################################
# $t0: numInts
# $t1: used1
# $t2: used2
# $t3: used3
# $t4: numDup;
# $t5: oneInt;
# $t6: probeIndex;
# $t7: short-lived temporary
# $t8: i
# $s0: hopPtr;
# $s1: hopPtr2;
# $s2: hopPtr22;
# $s3: hopPtr3;
# $s4: endPtr;
# $s5: endPtr2;
# $v1: reply
########################################
begDW1:
		#numInts = 0;
		addi $t0, $zero, 0
		#goto WTest1
		j WTest1
begW1:
		#cout << "# of int's for base array ( >= 1 and <= 9 ): ";
		li $v0, 4
		la $a0, eiaPrmpt
		syscall
		#cin >> numInts;
		li $v0, 5
		syscall
		move $t0, $v0
		#//if (numInts < 1 || numInts > 9)
		#if (numInts < 1) goto begI1;
		#if (numInts <= 9) goto endI1;
		li $t7, 1
		blt, $t0, $t7, begI1
		li $t7, 9
		ble, $t0, $t7, endI1
begI1:
		#cout << "# entered not in range ... try again..." << endl;
		li $v0, 4
		la $a0, taPrmpt
		syscall
		#numInts = 0;
		li $t0, 0
endI1:
endW1:
#if (numInts == 0) goto begW1;
WTest1:		beqz $t0, begW1         

		#used1 = 0;
		li $t1, 0
		#i = 0;
		li $t8, 0
		#goto FTest1;
		j FTest1
		
#//for (i = 0; i < numInts; ++i)
begF1:          
		#cout << "integer #" << (i + 1) << ": ";
		li $v0, 4
		la $a0, taPrmpt
		syscall
		li $v0, 4
		la $a0, taPrmpt
		syscall
		li $v0, 1
		addi $a0, $t8, 1
		syscall
		#cin >> oneInt;
		li $v0, 12
		syscall
		move $t5, $v0
		#probeIndex = used1; 
		move $t6, $t1
		#goto WTest2;
		j WTest2
#//while ( probeIndex > 0 && *(a1 + probeIndex - 1) > oneInt ) 
begW2:
		#*(a1 + probeIndex) = *(a1 + probeIndex - 1);
		la $a0, a1
		sll $a3, $t6, 2
		add $a3, $a3, $a0
		lw $v0, -4($a3)
		sw $v0, 0($a3)
		#--probeIndex;
		subi $t6, $t6, 1
endW2:
#////WTest2:	if ( probeIndex > 0 && *(a1 + probeIndex - 1) > oneInt ) goto begW2;
WTest2:
		#if ( probeIndex <= 0 ) goto xitW2;
		blez $t6, xitW2
		#if ( *(a1 + probeIndex - 1) > oneInt ) goto begW2;
		bgt $a0, $t5, begW2 
xitW2:
		#*(a1 + probeIndex) = oneInt;
		move $a0, $t5 
		#++used1;
		addi $t1, $t1, 1 
		#++i;
		addi $t8, $t8, 1
endF1:
#if (i < numInts) goto begF1;
FTest1:		blt $t8, $t0, begF1

		#used2 = 0;
		li $t2, 0
		#goto FTest2;
		j FTest2
#//for (used2 = 0; used2 < used1; ++used2)
begF2:
		#*(a2 + used2) = *(a1 + used2);
		la $a1, a2
		sll $a3, $t2, 2
		add $a3, $a3, $a1
		lw $v0, 0($a3)
		sw $v0, 0($a3)
		#++used2;
		addi $t2, $t2, 1
endF2:
#if (used2 < used1) goto begF2;
FTest2:		blt $t2, $t1, begF2

		#*a3 = *a2;   //SAME AS: *(a3 + 0) = *(a2 + 0);
 		move $a2, $a1
		#numDup = 0;
		li $t4, 0
		#used3 = 1;
		li $t3, 4
		#hopPtr2 = a2 + 1; 
		la $t7, a2
		addi $s1, $t7, 1
		#hopPtr3 = a3 + 1;
		la $t7, a2
		addi $s2, $t7, 1
		#endPtr2 = a2 + used2; 
		sll $a1, $t1, 2                        
		add $s4, $s4, $a1     
		#goto WTest3;
		j WTest3
#//while (hopPtr2 < endPtr2)
begW3: 		#//if ( *hopPtr2 == *(hopPtr2 - 1) )
		#if ( *hopPtr2 != *(hopPtr2 - 1) ) goto else2;
               	lw $t7, 0($s1)
               	lw $a0, 0($s1)
               	addi $a0, $a0, -4
		bne $t7,$a0, else2
		
begI2:
		#++numDup;
		addi $t4, $t4, 1
		#++hopPtr2;
		addi $s1, $s1, 1
		#goto endI2;
		j endI2

else2:
		li $t7, 0
		#*hopPtr3 = *hopPtr2;
		lw $t7, 0($s1)
		sw $t7, 0($s3)
		#++used3;
		addi $t3, $t3, 1
		#++hopPtr3;
		addi $s3, $s3, 1
		#//if (numDup > 0)
		#if (numDup <= 0) goto else3;
		blez $t4, else3
begI3:
		#hopPtr22 = hopPtr2;
		move $s2, $s1
		#goto FTest3;
		j FTest3
#//for (hopPtr22 = hopPtr2; hopPtr22 < endPtr2; ++hopPtr22)
begF3:
		#*(hopPtr22 - 1) = *hopPtr22;
		lw $t7, 0($s1)
		subi $t7, $t7, 1
		sw $t7, 0($s1)
		#++hopPtr22;
		addi $s2, $s2, 1
endF3:
#if (hopPtr22 < endPtr2) goto begF3;
FTest3:   	blt $s2, $s5, begF3

		#--used2;
		subi $t2, $t2, 1
		#--endPtr2;
		subi $s5, $s5, 1
		#numDup = 0;
		li $t4, 0 
		#goto endI3;
		j endI3

else3:
		#++hopPtr2;
		addi $s1, $s1, 1
endI3:
endI2:
#if (hopPtr2 < endPtr2) goto begW3;
WTest3:		blt $s1, $s5, begW3
		#//if (numDup > 0)
		#if (numDup <= 0) goto endI4;
		blez $t4, endI4

begI4:
		#--used2;
		subi $t2, $t2, 1
endI4:
		#cout << endl << "================================" << endl;
		li $v0, 4
		la $a0, spacer
		syscall
		#cout << "a1: ";
		li $v0, 4
		la $a0, a1Msg
		syscall
		#hopPtr = a1;
		la $s0, a1
		#endPtr = a1 + used1;
		la $a0, a1
		sll $a3, $t1, 2
		add $a3, $a3, $a0
		move $s4, $a3
		#goto WTest4;
		j WTest4
#//while (hopPtr < endPtr)
begW4:
		#cout << *hopPtr << "  ";
		li $v0, 4
		la $a0, 0($s0)
		syscall
		#++hopPtr;
		addi $s0, $s0, 1
endW4:
#if (hopPtr < endPtr) goto begW4;
WTest4:		blt $s0, $s4, begW4

		#cout << endl;
		li $v0, 11                              
        	li $a0, '\n'                            
        	syscall    
		#cout << "a2: ";
		li $v0, 4
		la $a0, a2Msg
		syscall
		#hopPtr = a2;
		la $s0, a2
		#endPtr = a2 + used2;
		la $a1, a2
		sll $a3, $t2, 2
		add $a3, $a3, $a1
		move $s4, $a3
		#goto WTest5;
		j WTest5

#//while (hopPtr < endPtr)
begW5:
		#cout << *hopPtr << "  ";
		li $v0, 11
		la $a0, 0($s0)                                                          
        	syscall  
        	li $v0, 11                              
        	li $a0, ' '                            
        	syscall  
		#++hopPtr;
		addi $s0, $s0, 1
endW5:
#if (hopPtr < endPtr) goto begW5;
WTest5:		blt $s0, $s5, begW5

		#cout << endl;
		li $v0, 11                              
        	li $a0, '\n'                            
        	syscall    
		#cout << "a3: ";
		li $v0, 4
		la $a0, a3Msg
		syscall
		#hopPtr = a3;
		la $s0, a3
		#endPtr = a3 + used3;
		la $a2, a3
		sll $a3, $t3, 2
		add $a3, $a3, $a2
		move $s4, $a3
		#goto WTest6;
		j WTest6
		
#//while (hopPtr < endPtr)
begW6:        
		#cout << *hopPtr << "  ";
		li $v0, 11                              
        	la $a0, 0($s0)                            
        	syscall  
        	li $v0, 11                              
        	li $a0, ' '                            
        	syscall  
		#++hopPtr;
		addi $s0, $s0, 1
endW6:
WTest6:		#if (hopPtr < endPtr) goto begW6;
		#cout << endl << "================================" << endl;
		li $v0, 4
		la $a0, spacer
		syscall

                #cout << "Do another (n or N = no, others = yes) ";
                li $v0, 4
		la $a0, daPrmpt
		syscall
		#cin >> reply;
		li $v0, 12
		syscall
		move $v1, $v0
endDW1:
#               //while (reply != 'n' && reply != 'N');
#		//if (reply != 'n' && reply != 'N') goto begDW1;
#		if (reply == 'n') goto xitDW1;
		li $t7, 'n'
		beq $v1, $t7, xitDW1
#		if (reply != 'N') goto begDW1;
		li $t7, 'N'
		bne $v1, $t7, begDW1
xitDW1:

		#cout << endl << "================================" << endl;
		#cout << "bye..." << endl;
		#cout << "================================" << endl;
		li $v0, 4
		la $a0, spacer
		syscall
		li $v0, 4
		la $a0, byeMsg
		syscall
		li $v0, 4
		la $a0, spacer
		syscall
		#return 0;
		li $v0, 10
		syscall
