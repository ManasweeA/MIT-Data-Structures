#include<iostream>
using namespace std;
class stack
{
	char exp[20];
	int top=-1;
	char st[20];
	public:
				void push(char val)
				{
					top++;
					st[top]=val;
				}
				char pop()
				{
					char c=st[top];
					top--;
					return c;
				}
				int precedence(char c)
				{
					if(c=='(')
					return 0;
					
					if(c=='+' || c=='-')
					return 1;
					
					if(c=='*' || c=='/')
					return 2;
					
					if(c=='^')
					return 3;
				}
				void intopost()
				{
					int i,k=0;
					char post[20];
					cout<<"Enter expression : ";
					cin>>exp;
					
					for(i=0;exp[i]!='\0';i++)
					{
						if( isalpha(exp[i]) || isdigit(exp[i]) )
						{
							post[k]=exp[i];
							k++;
						}
						else if(exp[i]=='(')
						{
							push('(');
						}
						else if(exp[i]==')')
						{
							char ch;
							while((ch=pop())!='(')
							{
								post[k]=ch;
								k++;
							}
						}
						else
						{
							while(precedence(st[top])>=precedence(exp[i]))
							{
								post[k]=pop();
								k++;
							}
							push(exp[i]);
						}
					}
					while(top>=0)
					{
						post[k]=pop();
						k++;
					}
					post[k]='\0';
					cout<<"Postfix form is : "<<post<<endl;
			}
			
};
int main()
{
	stack s;
	s.intopost();
	return 0;
}
							
							
