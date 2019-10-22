/**Author : Vivek Bhardwaj
** A standard Bit Manipulation Question
** Complexity O(2^N)
**/

#include<stdio.h>
#include<stdlib.h>


int main(){
	int*arr,n,i,mask,j;
	printf("Enter the no of elements in set\n");
	scanf("%d",&n);
	arr = malloc(n*sizeof(int));
	printf("Enter the elements of set\n");
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("{ ");
	for(i=0;i<(1<<n);i++){
		printf("{ ");
		for(j=0;j<=n;j++){
			mask= 1<<j;
			if(mask&i) printf("%d ",arr[j]);
		}
		printf(" }");
	}
	printf(" }");
	return 0;
}
