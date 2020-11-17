#include<stdio.h>
void main(){
	int a[20];
	int rear=-1;
	int front=-1;
	int op,size=5;
	do{
		printf("options\n1:push\n2:pop\n3:exit\nenter ur option ");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(rear==size-1){
					printf("the queue is full\n");
				}
				else{
					int ele;
					printf("enter the element\n");
					scanf("%d",&ele);
					rear++;
					a[rear]=ele;
				}
				break;
			case 2:
				if(front==rear){
					printf("the queue is empty\n");
				}
				else{
					front++;
					printf("element is:%d\n",a[front]);
				}
				break;
			case 3:
				break;
		}
	}while(op!=3);
}
