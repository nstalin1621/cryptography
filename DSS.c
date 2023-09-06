#include <stdio.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/dsa.h>
int main() 
{
    DSA *dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
    if (!dsa) {
        fprintf(stderr, "Error generating DSA parameters\n");
        return 1;
    }
    if (!DSA_generate_key(dsa)) {
        fprintf(stderr, "Error generating DSA key pair\n");
        DSA_free(dsa);
        return 1;
    }
    unsigned char message[] = "Hello, Digital Signature!";
    int message_len = strlen((const char *)message);
    unsigned char signature[DSA_size(dsa)];
    unsigned int sig_len;
    if (!DSA_sign(0, message, message_len, signature, &sig_len, dsa)) {
        fprintf(stderr, "Error creating signature\n");
        DSA_free(dsa);
        return 1;
    }
    if (DSA_verify(0, message, message_len, signature, sig_len, dsa)) {
        printf("Signature is valid!\n");
    } else {
        printf("Signature is NOT valid!\n");
    }
    DSA_free(dsa);
    return 0;
}