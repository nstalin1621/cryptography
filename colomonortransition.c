#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void encrypt(char *plaintext, char *key) {
    int keyLength = strlen(key);
    int textLength = strlen(plaintext);
    int columns = keyLength;
    int rows = (textLength + columns - 1) / columns;
    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(columns * sizeof(char));
    }
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (count < textLength) {
                grid[i][j] = plaintext[count];
                count++;
            } else {
                grid[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < columns; i++) {
        int colIndex = key[i] - '0';
        for (int j = 0; j < rows; j++) {
            printf("%c", grid[j][colIndex]);
        }
    }
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}
int main() {
    char plaintext[] = "HELLOWORLD";
    char key[] = "3124"; 
    printf("Original Plaintext: %s\n", plaintext);
    printf("Encrypted: ");
    encrypt(plaintext, key);
    printf("\n");
    return 0;
}
