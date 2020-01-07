#include<stdio.h>
int a[10];
int i,n,x,num;
int front=-1,rear=-1;
int main()
{
	printf("enter total no of element in array\n");
	scanf("%d",&n);
	do
	{
		printf("1:insertion\n");
		printf("2:deletion\n");
		printf("3:display\n");
		printf("4:exit\n");
		printf("enter ur choice\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insertion();
				break;
			case 2:
				deletion();
				break;
			case 3:
				display();
				break;
		}
	}
	while(x<=3);
}
insertion()
{
	if((front==0&&rear==n-1)||(front==rear+1))
	printf("overflow\n");
	else
	{
		printf("enter the no to be insert\n");
		scanf("%d",&num);
		if(front==-1&&rear==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
			if(front!=0&&rear==n-1)
			{
				rear=0;
			}
			else
			{
			rear=rear+1;
			}
			
		}
	}
		a[rear]=num;
}
deletion()
{
	if(front==-1&&rear==-1)
	printf("underflow\n");
	else
	{
	if(front==rear)
	{
		printf("the deleted element is %d\n",a[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		if(front==n-1)
		{
			printf("the deleted element is %d\n",a[front]);
			front=0;	
		}
		else
		{
				printf("the deleted element is %d\n",a[front]);
				front=front+1;
		}
	}
   }
}
display()
{
	if(front==-1&&rear==-1)
	printf("queue is empty\n");
	else
	{
		printf("the queue is\n");
		if(front>rear)
		{
			for(i=front;i<n;i++)
			printf("%d\n",a[i]);
			for(i=0;i<=rear;i++)
			printf("%d\n",a[i]);
		}
		else
		{
			for(i=front;i<=rear;i++)
			printf("%d\n",a[i]);
		}
	}
}

