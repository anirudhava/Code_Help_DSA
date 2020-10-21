int* stk;
int* temp;
int top1;//initially 0
in top2;//intially 0

void push(int x)
{
	if(top1==0 && top2==0)//when there r no elements in either of the stacks
	{
		stk[top1++]=x;
		temp[top2++]=x;
		return;
	}
	if(temp[top2-1]>x)
	{
		stk[top1++]=x;
		temp[top2++]=x;
		return;		
	}
	else
	{
		stk[top1++]=x;
	}
}

void pop()
{
	if(top1==0)
	{
		return;
	}
	if(temp[top2-1]==stk[top1-1])
	{
		top1--;
		top2--;
		return;
	}
	else
	{
		top1--;
	}
}

int get_min()
{
	return temp[top2-1];
}
