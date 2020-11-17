#include<stdio.h>
struct stack{
	int a[20];
	int top;
	int max;	
};
struct stack push(struct stack s){
	if(s.top==s.max-1){
		printf("the stack is full");
		return s;
	}
	else{
		s.top++;
		int ele;
		printf("enter the element");
		scanf("%d",&ele);
		s.a[s.top]=ele;
		return s;
	}
}
struct stack pop(struct stack s){
	if(s.top==-1){
		printf("the stack is empty");
		return s;
	}
	else{
		printf("%d\n",s.a[s.top]);
		s.top = s.top -1;
		return s;
	}
}
void main(){
	struct stack s;
	s.top=-1;
	s.max=5;
	int op;
	do{
		printf("1 : Push, 2 : Pop , 3 : exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				s=push(s);
				break;
			case 2:
				s=pop(s);
				break;
			case 3:
				break;
			default:
				printf("Invalid option");
				break;
		}	
	}while(op!=3);	
}

