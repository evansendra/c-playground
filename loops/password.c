#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int attempts = 0;
    int correct = 0;
    char* password = malloc(sizeof(char*));
    do
    {
        printf("Enter password: ");
        scanf("%s", password);
        if(strcmp(password, "wxyz") == 0)
            correct = 1;
        attempts++;
    }
    while(!correct && attempts < 3);
    
    if(correct)
        printf("Access granted\n");

    free(password);
    return 0;
}
