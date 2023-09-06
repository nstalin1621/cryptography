#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 3 
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void encrypt(char message[], int key[][SIZE], int messageLength) {
    int i, j, k, cipher[messageLength];
    for (i = 0; i < messageLength; i += SIZE) {
        for (j = 0; j < SIZE; j++) {
            cipher[i + j] = 0;
            for (k = 0; k < SIZE; k++) {
                cipher[i + j] += key[j][k] * (message[i + k] - 'A');
            }
            cipher[i + j] %= 26;
        }
    }
    printf("Encrypted message: ");
    for (i = 0; i < messageLength; i++) {
        printf("%c", cipher[i] + 'A');
    }
    printf("\n");
}
int main() {
    int key[SIZE][SIZE];
    char message[100];
    int i, j, determinant = 0, messageLength;
    printf("Enter the key matrix (3x3):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &key[i][j]);
        }
    }
    printf("Enter the message to encrypt (in capital letters): ");
    scanf("%s", message);
    messageLength = strlen(message);
    if (messageLength % SIZE != 0) {
        printf("Message length must be a multiple of %d for Hill Cipher.\n", SIZE);
        return 0;
    }
    for (i = 0; i < SIZE; i++) {
        determinant += (key[0][i] * (key[1][(i + 1) % SIZE] * key[2][(i + 2) % SIZE] - key[1][(i + 2) % SIZE] * key[2][(i + 1) % SIZE]));
    }
    determinant = determinant % 26;
    if (determinant == 0 || gcd(determinant, 26) != 1) {
        printf("The determinant of the key matrix must be coprime with 26.\n");
        return 0;
    }
    encrypt(message, key, messageLength);
    return 0;
}