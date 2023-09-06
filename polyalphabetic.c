#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *message, char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    for (int i = 0; i < messageLen; i++) {
        char messageChar = toupper(message[i]);
        char keyChar = toupper(key[i % keyLen]);

        if (isalpha(messageChar)) {
            char encryptedChar = 'A' + (messageChar + keyChar - 2 * 'A') % 26;
            printf("%c", encryptedChar);
        } else {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}
int main() {
    char message[] = "HELLO";
    char key[] = "KEY";
    vigenereEncrypt(message, key);
    return 0;
}