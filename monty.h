#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct toolbox- File pointer, string for processing, current line position and
 * a pointer to the head of a doubly linked list.
 * @file: points to the file being interpreted.
 * @line: holds the current line being processed.
 * @line_ct: int representing the current line number.
 * @stack: pointer to the head of a doubly linked list.
 *
 * Description: a struct with space for all the variables the monty file interpreter
 * can pass to various functions to track and interpret monty files.
 */
typedef struct toolbox
{
	FILE *file;
        char *line;
        unsigned int line_ct;
        stack_t *stack;
} toolbox;

extern toolbox tools;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(void);
void op_find(void);
void create_stack(void);
void mem_set(char *str);
int is_blank(char *str);
int is_num(char *str);


#endif
