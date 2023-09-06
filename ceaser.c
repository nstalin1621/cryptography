#include <stdio.h>
#include <string.h>

void caesarCipher(char text[], int shift) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }
} 
int main() {
    char input[100];
    int shift;
    printf("Enter a string: ");
    scanf("%[^\n]", input);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    caesarCipher(input, shift);
    printf("Encrypted text: %s\n", input);
    return 0;
}