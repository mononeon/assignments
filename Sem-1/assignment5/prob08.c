#include <stdio.h>
 
void decodeStudentInfo(unsigned char info) {
    char gender = (info & 0x80) ? 'F' : 'M'; // Bit 7
    int yearOfStudy = (info & 0x60) >> 5;    // Bits 6-5
    int age = info & 0x1F;                   // Bits 4-0
 
    printf("Gender: %c\n", gender);
    printf("Year of Study: %d\n", yearOfStudy + 1); // Assuming 1-based year
    printf("Age: %d\n", age);
}
 
int main() {
    unsigned char info = 0xAB; // Example input: 10101011
    decodeStudentInfo(info);
    return 0;
}