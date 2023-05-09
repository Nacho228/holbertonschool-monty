#include "monty.h"
/**
 * main - Monty virtual machine.
 * @argc: number of arguments passed.
 * @argv: which arguments were passed.
 * Return: void.
 */
int main(int argc, char *argv[])
{
    char *filepath = NULL, *cmd = NULL, *opcode = NULL;
    const char *separator = " \t\n";
    FILE *file;
    size_t size = 0;
    int line_number = 1;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        perror("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    filepath = argv[1];
    file = fopen(filepath, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filepath);
        exit(EXIT_FAILURE);
    }
    while (getline(&cmd, &size, file) != -1)
    {
       
     /*    if (r == -1) Ctrl + D cierra el loop 
        {
            exit(EXIT_FAILURE);
        } */
        opcode = strtok(cmd, separator);
        if(opcode == NULL)
        {
            line_number++;
            continue;
        }
        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, line_number);
        }
        if (strcmp(opcode, "pall"))
        {
            pall(&stack, line_number);
        }
        else
        {    
            line_number++;
            continue;
        }
    }
    free(cmd);
    fclose (file);
}