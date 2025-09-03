#include <stdio.h> 

int main() 
{  	int n ; 

    printf("Enter n:\n");
    scanf("%d",&n);
int octalNum = 0, countval = 1; 
	int dNo = n; 

	while (n != 0) { 
	
		int remainder = n% 8; 

		 
		octalNum += remainder * countval; 

		countval = countval * 10; 
		n /= 8; 
	} 
	printf("%d\n", octalNum); 
	
	return 0; 
}