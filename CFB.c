#include <stdio.h>
#include <string.h>
#define BLOCK_SIZE 16
void encryptBlock(char *block) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = (block[i] + 1) % 256; 
    }
}
void encryptCFB(char *input, char *iv, int length) {
    for (int i = 0; i < length; i++) {
        encryptBlock(iv);
        input[i] ^= iv[0];
        memmove(iv, iv + 1, BLOCK_SIZE - 1);
        iv[BLOCK_SIZE - 1] = input[i];
    }
}
int main() {
    char plaintext[] = "SHAIK";
    char iv[BLOCK_SIZE] = "KALESHA";
    int textLength = strlen(plaintext);
    encryptCFB(plaintext, iv, textLength);
    printf("Encrypted ciphertext: ");
    for (int i = 0; i < textLength; i++) {
        printf("%02X ", (unsigned char)plaintext[i]);
    }
    printf("\n");
    return 0;
}