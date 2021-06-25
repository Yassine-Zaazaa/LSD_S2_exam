#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *reverse(char *input) {
    int len = strlen(input);
    char *output = (char *)malloc(sizeof(char) * len + 1);
    for (int i = 0; i < len; i++) {
        output[len - i - 1] = input[i];
    }
    output[len] = '\0';
    return (output);
}

int main(int ac, char **av)
{
    if (ac != 2)
        printf("you have to pass a string to the program\n");
    else
        printf("The reversed string is : %s\n", reverse(av[1]));
}