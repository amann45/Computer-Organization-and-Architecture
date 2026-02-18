#include <stdio.h>

int main() {
    unsigned int dividend, divisor;
    int quotient = 0;
    int remainder = 0;
    int i;

    printf("Enter 4-bit dividend (0-15): ");
    scanf("%u", &dividend);

    printf("Enter 4-bit divisor (1-15): ");
    scanf("%u", &divisor);

    // Restoring Division Algorithm
    for (i = 3; i >= 0; i--) {

        // Step 1: Left shift remainder and bring next bit of dividend
        remainder = (remainder << 1) | ((dividend >> i) & 1);

        // Step 2: Subtract divisor
        remainder = remainder - divisor;

        // Step 3: Check remainder
        if (remainder < 0) {
            // Restore remainder
            remainder = remainder + divisor;
            // Quotient bit remains 0 (no need to set explicitly)
        } else {
            // Set quotient bit to 1
            quotient = quotient | (1 << i);
        }
    }

    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    return 0;
}
