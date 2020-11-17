#include<stdio.h>
int push(int top,int li[],int ele){
	li[top]=ele;
	return top;
}
int pop(int top){
	top--;
	return top;
}
void main(){
	int n,i;
	printf("enter the size of array");
	scanf("%d",&n);
	int li[n];
	int top=-1,op,ele;
	do{
		printf("enter 1 for push \n enter 2 for pop \n enter 3 for exit");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(top==n-1){
					printf("the stack is full");
				}
				else{
					top++;
					printf("enter the number");
					scanf("%d",&ele);
					top=push(top,li,ele);
				}
				break;
			case 2:
				if(top==-1){
					printf("stack is empty");
				}
				else{
					printf("%d",li[top]);
					top=pop(top);
				}
				break;
			case 3:
				break;
			default:
				printf("invalid option");		
		}
	}
	while(op!=3);
} 
