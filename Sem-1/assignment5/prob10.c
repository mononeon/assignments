#include <stdio.h>
#include <stdint.h>
 
void printFloatStorage(float num) {
    uint32_t *p = (uint32_t *)&num;
    uint32_t bits = *p;
 
    int sign = (bits >> 31) & 0x1;
    int exponent = (bits >> 23) & 0xFF;
    int mantissa = bits & 0x7FFFFF;
 
    printf("Sign: %d\n", sign);
    printf("Exponent: %d\n", exponent);
    printf("Mantissa: %d\n", mantissa);
}
 
int main() {
    float num = -123.456f;
    printFloatStorage(num);
    return 0;
}