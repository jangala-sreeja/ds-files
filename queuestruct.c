#include<stdio.h>
#include<stdlib.h>
struct queue{
	int a[20];
	int r;
	int f;
};
void main(){
	int op,size=5;
	struct queue q;
	q.r=-1;
	q.f=-1;
	do{
		printf("options\n1:push\n2:pop\n3:exit\nenter ur option ");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(q.r==size-1){
					printf("the queue is full\n");
				}
				else{
					int ele;
					printf("enter the element\n");
					scanf("%d",&ele);
					q.r++;
					q.a[q.r]=ele;
				}
				break;
			case 2:
				if(q.f==q.r){
					printf("the queue is empty\n");
				}
				else{
					q.f++;
					printf("element is:%d\n",q.a[q.f]);
				}
				break;
			case 3:
				break;
		}
	}while(op!=3);
}

