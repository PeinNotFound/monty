#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - stack represents doubly links list (or queue)
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
 * struct instruction_s - funcyion of upcode
 * @opcode: opcode
 * @f: a function that handls the opcode
 *
 * Description: funcion of upcode
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes for opcodes */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/* Other fonctions */

void pall_error(void);
void pint_error(unsigned int line_number);
void pop_error(unsigned int line_number);
void swap_error(unsigned int line_number);
void add_error(unsigned int line_number);
void push_error(unsigned int line_number, FILE *file);
void malloc_error(void);
void global_error(unsigned int lr, FILE *file, char *token, stack_t **stack);

void sub_error(unsigned int line_number);
void div_error(unsigned int line_number);
void mul_error(unsigned int line_number);
void mod_error(unsigned int line_number);

void pchar_error(unsigned int line_number);

int execute_f(char *content, stack_t **stack,
			  unsigned int numberline, FILE *file);
void free_stack(stack_t **stack);
int is_valid_integer(const char *str);

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void pchar__error(stack_t **stack, unsigned int nubr, FILE *file, char *tokn);

#endif /* MONTY_H */
