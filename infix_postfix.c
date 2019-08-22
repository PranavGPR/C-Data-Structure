#include<stdio.h>
char stack[20];
int top=-1;
void push(char x)
{
    stack[++top]=x;

}
char pop()
{
	   return stack[top--];
}
int priority(char x)
{
    switch(x)
	{
	case '#':return 0;
	case '(':return 1;
	case '+':
	case '-':return 2;
	case '*':
	case '/':return 3;
	}
	return 0;
}
int main()
{
    char infx[50],pofx[50],ch,x;
	int i=0,k=0;
	printf("\nRead the infix expression:");
	scanf("%s",&infx);
	push('#');
	while((ch=infx[i++])!='\0')
	{
	if(ch=='(')
	push(ch);
	else
	  if(isalnum(ch))
	  pofx[k++]=ch;
	  else
	    if(ch==')')
		{
		  while(stack[top]!='(')
		  pofx[k++]=pop();
		  x=pop();
		}
		else
		{
		  while(priority(stack[top])>=priority(ch))
		  pofx[k++]=pop();
		  push(ch);
		 }
	}
	while(stack[top]!='#')
	pofx[k++]=pop();
	pofx[k]='\0';
	printf("\n\nGiven infix expression:%s \n\nPostfix expression:%s\n",infx,pofx);
}

