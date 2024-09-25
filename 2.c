#include <stdio.h>
int main(){
	float a;
	char c;
	printf("Input temperature: ");
	scanf("%f %c", &a, &c);
	if (c=='c'){
		printf("Ouput temperature: %.1ff", (a*9)/5+32);}
	else if (c=='f'){
		printf("Ouput temperature: %.1fc", (a-32)*5/9);}
	else{
		printf("Ouput error");}
}

