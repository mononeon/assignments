#include <stdio.h>
 
int bcdToDecimal(unsigned char bcd) {
    int tens = (bcd >> 4) & 0x0F;
    int units = bcd & 0x0F;
    return tens * 10 + units;
}
 
int main() {
    unsigned char bcd = 0x39; // Example input: 00111001 (39 in decimal)
    int decimal = bcdToDecimal(bcd);
    printf("Decimal: %d\n", decimal);
    return 0;
}
