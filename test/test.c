#include "monty.h"
/**
 * main - Monty virtual machine.
 * @argc: number of arguments passed.
 * @argv: which arguments were passed.
 * Return: void.
*/
void main(int argc, char *argv[])
{
    char *filepath = NULL, *cmd = NULL, *opcode = NULL;
    const char *separator = " \t\n";
    FILE *file;
    size_t size = 0;
    int r = 0, line_number = 1;
    
    if (argc > 2 || argc == 1)
    {
        perror("USAGE: monty file\n"); 
        exit(EXIT_FAILURE);
    }
    
    filepath = argv[1];
    file = fopen(filepath, "r");
    
    if(file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filepath);
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        printf("$ "); /* Es para ver si entra en el loop, no se si hay que dejarlo */
        r = getline(&cmd, &size, file);
        if (r == -1) /* Ctrl + D cierra el loop */
        {
            exit(EXIT_FAILURE);
        }
        opcode = strtok(cmd, separator);
        /* if(opcode) */

    }
    free(cmd);
    fclose (file);
}