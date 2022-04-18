#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int n = 0;
	if(argc<2){
		printf("How many elements you want to display: ");
		scanf("%d", &n);
	}
	else{
		n = atoi(argv[1]);
	}
	int i = 0, n1 = 0, n2 = 1;
	printf("The first %d value: %d, %d", n, n1, n2);
	for(i = 2; i < n; i++){
		int n3 = n1 + n2;
		printf(", %d", n3);
		n1 = n2;
		n2 = n3;
	}
	printf("\n");
	return 0;
}
