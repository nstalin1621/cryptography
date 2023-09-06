#include <stdio.h>
#include <stdint.h>
uint64_t key = 0x133457799BBCDFF1;
int initial_permutation[64] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
uint64_t des_encrypt(uint64_t input, uint64_t key) {
    uint64_t permuted_input = 0;
    for (int i = 0; i < 64; i++) {
        permuted_input |= ((input >> (64 - initial_permutation[i])) & 0x01) << (63 - i);
    }
    uint64_t xored_input = permuted_input ^ key;
    return xored_input;
}
int main() {
    uint64_t plaintext = 0x0123456789ABCDEF;
    uint64_t ciphertext = des_encrypt(plaintext, key);
    printf("Plaintext:  0x%016llX\n", plaintext);
    printf("Ciphertext: 0x%016llX\n", ciphertext);
    return 0;
}