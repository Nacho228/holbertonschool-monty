#include "monty.h"
/**
 * 
 * 
 * 
*/

instruction_t ops[] = {
        {"push", &push},
        {"pall", &pall},
        {NULL, NULL}
    };

instruction_t *get_op(char *opcode)
{
    int i;
    
    
    for(i = 0; ops[i].opcode != NULL; i++)
    {
        if(strcmp(opcode, ops[i].opcode) == 0)
            return (&ops[i]);
    }
    return (NULL);
}