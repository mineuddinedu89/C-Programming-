#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char text[] = "Oh my, my dog and MY cat; mystery is not my game.";

    int length = (int)strlen(text);

    /* strtok changes the string, so work on a copy */
    char copy[sizeof(text)];
    strcpy(copy, text);

    int count = 0;
    char *tok = strtok(copy, " .,?!");
    while (tok != NULL) {
        char word[64];
        int i = 0;
        while (tok[i] != '\0' && i < 63) {
            word[i] = (char)tolower((unsigned char)tok[i]);
            i++;
        }
        word[i] = '\0';

        if (strcmp(word, "my") == 0) {
            count++;
        }
        tok = strtok(NULL, " .,?!");
    }

    printf("Length: %d\n", length);
    printf("Count: %d\n", count);
    return 0;
}