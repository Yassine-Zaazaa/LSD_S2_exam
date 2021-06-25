#include "stack.h"

int     recursive_check(/* add parameter */)
{
        // write recursive method for checking
}

int pairs(char  C1, char C2){
    if (C1 == '(' && C2 == ')')
        return 1;
    if (C1 == '[' && C2 == ']')
        return 1;
    if (C1 == '{' && C2 == '}')
        return 1;
    return 0;
}

int     iterative_check(char * C)
{
    t_stack * P = NULL;
    for(int i = 0; i < strlen(C); i++)
    {
        printf("%c\n", C[i]);
        if(C[i] == '(' || C[i] == '[' || C[i] == '{')
                push(&P, C[i]);
        
        if(C[i] == ')')
        {
            if(P == NULL)
                return 0;
            if(pairs(C[i], pop(&P)) == 0)
                return 0;
        }
        if(C[i] == ']')
        {
            if(P == NULL)
                return 0;
            if(pairs(C[i], pop(&P)) == 0)
                return 0;
        }
        if(C[i] == '}')
        {
            if(P == NULL)
                return 0;
            if(pairs(C[i], pop(&P)) == 0)
                return 0;
        }
    }
    if(P == NULL)
        return 1;
    else
        return 0;
}

int main(int ac, char ** av)
{
    if(ac != 2) {
            printf("you have to pass a string to the program\n");
    }

    int res = iterative_check(av[1]);
    int res2 = recursive_check(av[1]);
    printf("We begin with the iterative check\n");
    if(res == 0)
        printf("The string is well formatted\n");
    else if(res == -1)
        printf("The string isn't formatted\n");
}

