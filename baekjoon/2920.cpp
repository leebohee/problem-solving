#include <stdio.h>

int Judge(int* arr);

int main(){
	int arr[8], i;
	
	for(i=0; i<8; i++){
		scanf("%d", &arr[i]);
	}
	
	switch(judge(arr)){
		case 0:
			printf("ascending\n");
			break;
		case 1:
			printf("descending\n");
			break;
		case 2:
			printf("mixed\n");
			break;
	}
	
}

int Judge(int* arr){
	int status=0;	// asc: 0 desc:1 mixed: 2
	int i;
	
	for(i=0; i<7; i++){
		if(arr[i]<arr[i+1]){
			if(status!=0){
				status=2;
				break;	
			}		
		}
		else{
			if(i==0){
				status=1;
				continue;
			}
			if(status!=1){
				status=2;
				break;
			}
		}
	}
	return status;
}
