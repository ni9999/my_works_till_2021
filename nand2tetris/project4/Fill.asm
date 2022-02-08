// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
// psuedo:
//  while(1) {
//   address = screen
//   i=0
//      if(kbd !== 0)
//           pressedornot = -1
//      else pressedornot = 0
//   
//   while(i <= 8192) //32bytes * (32*8) pixels???? 
//
//      address = pressedornot
//      address++
//      i++
//   }




//while(1) {
(LOOPONE)

@SCREEN
D=A

@address
M=D

@i
M=0

//      if(kbd !== 0)
//           pressedornot = -1
//      else pressedornot = 0


@KBD
D=M

@PRESSED
D;JNE //if KBD !== 0 jump


@notpressed
M=0
D=M

@PRESSEDORNOT
D;JMP

(PRESSED)
@pressed
M=-1
D=M

(PRESSEDORNOT)
@pressedornot
M=D

//while(i <= 8192)

(LOOPTWO)

//condition ==> if i>8192 goto loopone for keyboard input

@i
D=M

@8191
D=D-A

@LOOPONE
D;JGT

//condition complete now main loop
//      address = pressedornot

@pressedornot
D=M

@address
A=M
M=D
//      address++

@address
M=M+1

//      i++

@i
M=M+1



@LOOPTWO
0;JMP

(ENDTWO)

@LOOPONE
0;JMP

(ENDONE)














