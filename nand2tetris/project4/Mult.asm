// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

//pseudo:
//i=0
//while(i<R0)
//	  multiplied += R1
//    i++

//initializing. multiplication will work on R2 and temp

@R2
M=0

@temp
M=0

@i
M=0

(LOOP)

//condition
@i
D=M //D=i

@R0
D=D-M //D=i-R0; if i<R0 then i-R0= - and i=R0 then i-R0=0

@END
D;JGE //if i-R0 >= 0 then goto end 

//condition done now main loop

//multiplied += R1
@R1
D=M

@temp
M=M+D 

//i++
@i
M=M+1

//go back to loop
@LOOP
0;JMP

(END)

@temp
D=M

@R2
M=D

@END
0;JMP

