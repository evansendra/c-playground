#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

enum Color
{
    GREEN = 0, BLUE = 1, YELLOW = 2
};

int main(void)
{
    char* input = (char*) malloc( sizeof( char* ));
    if(input == NULL)
        return 1;

    scanf("%s", input);

    Color color = YELLOW;

    if(strcmp(input, "foo") == 0)
        color = GREEN;
    else if(strcmp(input, "bar") == 0)
        color = BLUE;

    switch(color)
    {
        case GREEN:
            printf("\033[1;32mYou chose green!\033[1;0m\n");
            break;
        case BLUE:
            printf("\033[1;34mSO BLUE!\033[1;0m\n");
            break;
        case YELLOW:
            printf("\033[1;33mo hai im yello\033[1;0m\n");
            break;
        default:
            printf("\033[1;36mhow ugly is cyan?\033[1;0m\n");
            break;
    }

    free(input);
    return 0;
}
