#include <stdio.h>
#include <stdlib.h>
int power(int base, unsigned int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int encrypt(int plaintext, int e, int n) {
    return power(plaintext, e, n);
}
int decrypt(int ciphertext, int d, int n) {
    return power(ciphertext, d, n);
}
int main() {
    int p = 17; 
    int q = 19; 
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 7;
    int d = 23;
    int plaintext = 65;
    int encrypted = encrypt(plaintext, e, n);
    int decrypted = decrypt(encrypted, d, n);
    printf("Original Plaintext: %d\n", plaintext);
    printf("Encrypted: %d\n", encrypted);
    printf("Decrypted: %d\n", decrypted);
    return 0;
}