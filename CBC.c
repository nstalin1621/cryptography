#include <stdio.h>
#include <string.h>
#define BLOCK_SIZE 16
void xorBlocks(char *block1, char *block2) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block1[i] ^= block2[i];
    }
}
void encryptBlock(char *block) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = (block[i] + 1) % 256;
    }
}
int main() {
    char plaintext[] = "HELLO";
    char iv[BLOCK_SIZE] = "KALESHA";
    int textLength = strlen(plaintext);
    int padding = BLOCK_SIZE - (textLength % BLOCK_SIZE);
    if (padding != BLOCK_SIZE) {
        textLength += padding;
        memset(plaintext + strlen(plaintext), 0, padding);
    }
    for (int i = 0; i < textLength; i += BLOCK_SIZE) {
        xorBlocks(plaintext + i, iv);
        encryptBlock(plaintext + i);
        memcpy(iv, plaintext + i, BLOCK_SIZE);
    }
    printf("Encrypted ciphertext: ");
    for (int i = 0; i < textLength; i++) {
        printf("%02X ", (unsigned char)plaintext[i]);
    }
    printf("\n");
    return 0;
}