#include "stack.h"

const char *recursive_check(const char *C)
{
        if( *C == '\0' || *C == ')' || *C == ']' || *C == '}') 
                return C; 
                
        if( *C == '(' )
        {
                const char *C2 = recursive_check(++C);
                if( *C2 == ')' || *C2 == ']' || *C2 == '}')
                {
                        return recursive_check(++C2);
                }
                return C - 1;
        }

        return recursive_check(++C);
}


int     pairs(char C1, char C2)
{
    if (C1 == '(' && C2 == ')')
        return 1;
    if (C1 == '{' && C2 == '}')
        return 1;
    if (C1 == '[' && C2 == ']')
        return 1;
    else
        return 0;
}

int     iterative_check(char C[])
{
    int i = 0;
    t_stack *P = NULL;
    while (C[i])
    {
        if (C[i] == '(' || C[i] == '[' || C[i] == '{')
            push(&P, C[i]);
        if (C[i] == ')' || C[i] == ']' || C[i] == '}') {
            if (P == NULL)
                return 0;
            if (pairs(pop(&P), C[i]) == 0)
                return 0;
        }
        i++;
    }
    if (P == NULL)
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
    printf("We begin with the iterative check\n");
    if(res == 1)
        printf("The string is well formatted\n");
    else if(res == 0)
        printf("The string isn't formatted\n");
    printf("Now the recursive check");
    const char * C2 = recursive_check(av[1]);
    printf("%s\n", C2);
    return 0;
}

