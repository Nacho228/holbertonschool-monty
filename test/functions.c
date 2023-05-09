#include "monty.h"

/**
 * 
 * 
 * 
*/

/* void print_stack(stack_t *stack)
{
    stack_t *temp = stack;
    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
} */
/**
 * 
 * 
*/

void push(stack_t **stack, unsigned int line_number)
{
    char *arg = NULL;
    const char *separator = " \t\n";
    int n = 0;
    stack_t *new, *current;

    arg = strtok(NULL, separator);
    if(arg == NULL)
    { 
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    if(n == 0 && strcmp(arg, "0") != 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    new = malloc(sizeof(stack_t));
    if(new == NULL)
    {
        perror("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = n;
    new->prev = NULL;
    new->next = NULL;

    if(*stack == NULL)    
        *stack = new;
    else
    {
        current = *stack;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
        new->prev = current;
    }
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;
   
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
   current = NULL;
}
