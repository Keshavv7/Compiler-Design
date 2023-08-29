#include <stdio.h>

int add(int a, int b, int c){
	return a+b+c;
}

void printAll(int sum){
	for (int i=1; i<=sum; i++){
		printf(i, "\n");
	}
	return;
}

int main(){
	int a = 1;
	int b = 2;
	int c = 3;
	printAll(add(a,b,c));
	return 0;
}
