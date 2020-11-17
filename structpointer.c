#include<stdio.h>
#include<stdlib.h>
struct stack{
	int arr[20];
	int top;
	int max;
};
void push(struct stack *s){
	if(s->top==s->max-1){
		printf("the stack is full");
	}
	else{
		s->top++;
		int ele;
		printf("enter the element");
		scanf("%d",&ele);
		s->arr[s->top]=ele;
	}
} 
void pop(struct stack *s){
	if(s->top==-1){
		printf("the stack is empty");
	}
	else{
		printf("%d",s->arr[s->top]);
		s->top--;
	}
}
void main(){
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	s->max=5;
	int op;
	do{
		printf("1 for push 2 for pop 3 break");
		printf("enter your options");
		scanf("%d",&op);
		switch(op){
			case 1:
				push(s);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				break;
			default:
				printf("invalid option");
				break;
		}
	}while(op!=3);	
}
