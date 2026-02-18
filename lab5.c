#include <stdio.h>
int main() 
{
    unsigned int dividend, divisor;
    int quotient = 0, remainder = 0;
    int i;
    printf("Enter 4-bit dividend (0-15): ");
    scanf("%u", &dividend);
    printf("Enter 4-bit divisor (1-15): ");
    scanf("%u", &divisor);
    for (i = 3; i >= 0; i--) 
    {
        remainder = (remainder << 1) | ((dividend >> i) & 1);
        if (remainder >= 0) 
        {
            remainder = remainder - divisor;
        } 
        else
        {
            remainder = remainder + divisor;
        }
        if (remainder >= 0) 
        {
            quotient = quotient | (1 << i);
        }
    }
    if (remainder < 0) 
    {
        remainder = remainder + divisor;
    }
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
    return 0;

}
