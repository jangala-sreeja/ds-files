# include<stdio.h>
int main(){
	int top=-1;
	int a[5];
	int op;
	do{
	
	printf("The options you have got\n");
	printf("1 : Push, 2 : Pop , 3 : exit\n");
	printf("Enter your option : ");
	scanf("%d",&op);
	switch(op){
		case 1:
			 top = push(a, top);
			break;
		case 2:
			 top = pop(a, top);
			break;
		case 3:
			break;
		default:
			printf("You entered an invalid value \n");
	}
}while(op != 3);
}

int push(int a[], int top){
	int element;
	int size = 5;
	if(top == size - 1){
					printf("The stack is full \n");
					return top;
				}else{
					top++;
					printf("Enter the element to be added : ");
					scanf("%d",&element);
					a[top] = element;
					return top;
				}
}


int pop(int a[], int top){
	int size = 5;
	
		if(top == -1){
					printf("The Stack is empty \n");
					return top;
				}else{
					printf("%d\n",a[top]);
					top = top -1;
					return top;
				}
	
}
