#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkPassword(const char* password);

int main(void)
{
    char* password = (char*) malloc(sizeof(char*));

    int attempts = 0;
    int correct = 0;
    do
    {
        printf("Enter password: ");
        scanf("%s", password);
        correct = checkPassword(password);   
        attempts++;
    }
    while(!correct && attempts < 3);
    
    if(correct)
        printf("Access granted\n");

    free(password);
    return 0;
}

int checkPassword(const char* password)
{
    return strcmp(password, "wxyz") == 0;
}
