#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plaintext, int rails, char *ciphertext) {
    int length = strlen(plaintext);
    char railsArr[rails][length];
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            railsArr[i][j] = '\0'; 
        }
    }
    int row = 0;
    int direction = 1;
    for (int i = 0; i < length; i++) {
        railsArr[row][i] = plaintext[i];
        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }
        row += direction;
    }
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            if (railsArr[i][j] != '\0') {
                ciphertext[index++] = railsArr[i][j];
            }
        }
    }
    ciphertext[index] = '\0';
}
int main() {
    char plaintext[100];
    char ciphertext[100];
    int rails;
    printf("Enter the plaintext: ");
    gets(plaintext);
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    railFenceEncrypt(plaintext, rails, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    return 0;
}