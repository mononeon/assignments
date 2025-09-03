#include <stdio.h>
#include <stdlib.h>
int decimalToBinary(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int temp = num; 
    // Extracting the last digit of the binary number 
    while (temp) { 
        int last_digit = temp % 10; 
        // Removing the last digit from the binary number 
        temp = temp / 10; 
  
        // Multiplying the last digit with the base value 
        // and adding it to the decimal value 
        dec_value += last_digit * base; 
  
        // Updating the base value by multiplying it by 2 
        base = base * 2; 
    } 
  
    // Returning the decimal value 
    return dec_value; 
} 

void toBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void toOctal(int num) {
    printf("%o\n", num);
}

void toHexadecimal(int num) {
    printf("%X\n", num);
}

int fromBinary(char *bin) {
    return (int)strtol(bin, NULL, 2);
}

int fromOctal(char *oct) {
    return (int)strtol(oct, NULL, 8);
}

int fromHexadecimal(char *hex) {
    return (int)strtol(hex, NULL, 16);
}

int main() {
    int choice;
    char input[32];
    int num;

    while (1) {
        printf("\n1. Binary to others\n2. Decimal to others\n3. Octal to others\n4. Hexadecimal to others\n5. Exit\n");
        scanf("%d", &choice);
        
        if (choice == 5) break;

        printf("Enter the number: ");
        scanf("%s", input);

        if (choice == 1) {
            num = fromBinary(input);
            printf("Decimal: %d\n", num);
            printf("Octal: ");
            toOctal(num);
            printf("Hexadecimal: ");
            toHexadecimal(num);
        } else if (choice == 2) {
            num = atoi(input);
            printf("Binary: ");
            toBinary(num);
            printf("Octal: ");
            toOctal(num);
            printf("Hexadecimal: ");
            toHexadecimal(num);
        } else if (choice == 3) {
            num = fromOctal(input);
            printf("Decimal: %d\n", num);
            printf("Binary: ");
            toBinary(num);
            printf("Hexadecimal: ");
            toHexadecimal(num);
        } else if (choice == 4) {
            num = fromHexadecimal(input);
            printf("Decimal: %d\n", num);
            printf("Binary: ");
            toBinary(num);
            printf("Octal: ");
            toOctal(num);
        }
    }
    return 0;
}