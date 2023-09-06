#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareKey(char *key, char *keyTable) {
    int i, j, k;
    int len = strlen(key);
    int flag = 0, count = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            keyTable[i * SIZE + j] = 0;
        }
    }
    for (i = 0; i < len; i++) {
        if (key[i] == 'j')
            key[i] = 'i';
        flag = 0;
        for (j = 0; j < count + 1; j++) {
            if (key[i] == keyTable[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            keyTable[count] = key[i];
            count++;
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            flag = 0;
            if (keyTable[i * SIZE + j] == 0) {
                flag = 1;
                for (k = 0; k < len; k++) {
                    if (key[k] == 'j')
                        key[k] = 'i';
                    if (key[k] == count + 97) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)
                count++;
            keyTable[i * SIZE + j] = count + 97;
        }
    }
}
void generateDigraphs(char *input, char *digraphs) {
    int i = 0;
    while (i < strlen(input)) {
        if (input[i] == input[i + 1]) {
            digraphs[i * 2] = input[i];
            digraphs[i * 2 + 1] = 'x';
            i++;
        } else {
            digraphs[i * 2] = input[i];
            digraphs[i * 2 + 1] = input[i + 1];
            i += 2;
        }
    }
    if (strlen(input) % 2 != 0)
        digraphs[strlen(input) * 2 - 1] = 'x';
    digraphs[strlen(input) * 2] = '\0';
}
void search(char keyTable[SIZE][SIZE], char a, char b, int arr[]) {
    int i, j;
    if (a == 'j')
        a = 'i';
    if (b == 'j')
        b = 'i';
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyTable[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}
void encrypt(char keyTable[SIZE][SIZE], char *digraphs, char *encryptedText) {
    int i, arr[4];
    for (i = 0; i < strlen(digraphs); i += 2) {
        search(keyTable, digraphs[i], digraphs[i + 1], arr);
        if (arr[0] == arr[2]) {
            encryptedText[i] = keyTable[arr[0]][(arr[1] + 1) % 5];
            encryptedText[i + 1] = keyTable[arr[0]][(arr[3] + 1) % 5];
        } else if (arr[1] == arr[3]) {
            encryptedText[i] = keyTable[(arr[0] + 1) % 5][arr[1]];
            encryptedText[i + 1] = keyTable[(arr[2] + 1) % 5][arr[1]];
        } else {
            encryptedText[i] = keyTable[arr[0]][arr[3]];
            encryptedText[i + 1] = keyTable[arr[2]][arr[1]];
        }
    }
    encryptedText[i] = '\0';
}
int main() {
    char key[] = "keyword";
    char keyTable[SIZE][SIZE];
    char input[] = "hello";
    char digraphs[2 * SIZE];
    char encryptedText[2 * SIZE];
    prepareKey(key, (char *)keyTable);
    generateDigraphs(input, digraphs);
    encrypt(keyTable, digraphs, encryptedText);
    printf("Original Input: %s\n", input);
    printf("Encrypted Text: %s\n", encryptedText);
    return 0;
}