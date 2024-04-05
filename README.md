This repository contains files pertaining to the creation of a file interpreter
for the fictional Monty language to practice stacks and queues concepts in C.



The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes
(Just like Python). It relies on a unique stack, with specific instructions to 
manipulate it. The goal of this project is to create an interpreter for Monty 
ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. 
Most of the industry uses this standard but it is not required by the specification 
of the language. There is not more than one instruction per line. 
There can be any number of spaces before or after the opcode and its argument:

push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

pint$
pop$
pop$
pint$
swap$
pall$
add$
pint$
pall$
nop$


Monty byte code files can contain blank lines (empty or made of spaces only, 
and any additional text after the opcode or its required argument is not taken 
into account.


Functionality includes the following instruction codes:

push: adds an element to the stack.
pall: prints all values on the stack starting from the top.
pint: prints the value at the top of the stack.
pop: removes the top element of the stack.
swap: swaps the top two elements of the stack.
add: adds the top two elements of the stack.
nop: does nothing.

Output from the above example would be as follows:

3
2
1
0
6
5
4
3
2
1
0
6
4
3
4
2
1
0
7
7
2
1
0
