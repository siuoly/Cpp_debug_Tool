#ifndef COLOR_H
#define COLOR_H
namespace color{
	static const char* red = "\033[31m";
	static const char* Red= "\033[31m";
	static const char* Green= "\033[32m";
	static const char* Yellow= "\033[33m";
	static const char* Blue= "\033[34m";
	static const char* Magenta= "\033[35m";
	static const char* Cyan= "\033[36m";
	static const char* reset= "\033[0m";
}
#endif 
/* Usage */
/*
#include<stdio.h>

void colorRed(){
	printf("\033[31m");
}

void colorGreen(){
	printf("\033[32m");
}

void colorYellow(){
	printf("\033[33m");
}

void colorBlue(){
	printf("\033[34m");
}

void colorMagenta(){
	printf("\033[35m");
}

void colorCyan(){
	printf("\033[36m");
}

void colorReset(){
	printf("\033[0m");
}

bool isPrime(int n)
{
	for(int i=2;i<=n/2;i++)
		if(n%i == 0) return false;
	if( n < 2 ) return false;
	return true;
}

int main(int argc, char*argv[])
{
	int n;
	for(int i=100;i<200;i++){
		for(int j=1;j<11;j++){
			n = i*10+j;
			if(isPrime(n))colorYellow(); 
			printf("%6d", n);
			colorReset();	
		}
			printf("\n");
	}
}
*/



