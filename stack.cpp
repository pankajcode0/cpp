#include <iostream>
using namespace std;

int top = -1;

void push (int stack[],int x, int n)
{
    if(top == n-1)
    {
        cout <<"stack is full";
    }
    else{
        top = top+1;
        stack[top] = x;
    }
}

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
void pop ()
{
    if(isEmpty())
    {
        cout<<"stack is empty";
    }
    else{
        top = top-1;
    }
}
int size ()
{
    return top+1;
}

int topElement(int stack[])
{
    return stack[top];
}

int main()
{
    int stack[3];
    push(stack,5,3);

    cout << "current size" << size()<<endl;
    push(stack , 10 , 3);
        push (stack , 24 , 3) ;

        cout << "Current size of stack is " << size( ) << endl ;

        //As the stack is full, further pushing will show an overflow condition.
        push(stack , 12 , 3) ;

        //Accessing the top element
        cout << "The current top element in stack is " << topElement(stack) << endl;

        //Removing all the elements from the stack
        for(int i = 0 ; i < 3;i++ )
            pop( );
        cout << "Current size of stack is " << size( ) << endl ;

        //As the stack is empty , further popping will show an underflow condition.
        pop ( );  

    
}