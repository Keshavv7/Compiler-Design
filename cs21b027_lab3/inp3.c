#include <stdio.h>

void printFactors(int x){
	int i = 1;
	while (i<=(x/2)+1){
		if (x%i==0){
			printf(i, "\n");
		}
		i++;
	}
	return;
}
int main(){
	printFactors(36);
	return 0;
}
