#include <stdio.h>
#include <string.h>

// Function to calculate GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function for modular exponentiation (base^exp % mod)
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    char text[100];
    long long p, q, n, phi, e, d = 0;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the value of P and Q : ");
    scanf("%lld %lld", &p, &q);

    // Step 1: Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Step 2: Choose e
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }

    // Step 3: Calculate d (modular inverse of e)
    for (int i = 1; i < phi; i++) {
        if ((e * i) % phi == 1) {
            d = i;
            break;
        }
    }

    // Encryption
    long long encrypted[100];
    printf("Encrypted Text is: ");
    for (int i = 0; i < strlen(text); i++) {
        encrypted[i] = mod_exp(text[i], e, n);
        printf("%lld ", encrypted[i]);
    }

    // Decryption
    printf("\nDecrypted Text is: ");
    for (int i = 0; i < strlen(text); i++) {
        char decrypted_char = (char)mod_exp(encrypted[i], d, n);
        printf("%c", decrypted_char);
    }

    return 0;
}