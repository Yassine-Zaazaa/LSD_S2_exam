#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *reverse(char *input) {
    int len = strlen(input);
    char * output = (char *)malloc((len + 1)* sizeof(char));
    for (int i = 0; i < len; i++) {
        output[len - i - 1] = input[i];
    }
    return output;
}

int main(int ac, char **av)
{
    if (ac != 2)
        printf("you have to pass a string to the program\n");
    else
        printf("The reversed string is : %s\n", reverse(av[1]));
}