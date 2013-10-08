#include <iostream>
#define MAX_SIZE 200
using namespace std;

struct stack{
    int data[MAX_SIZE];
    int min_index[MAX_SIZE];
    int top;
};

void init(stack* st)
{
    st->top = -1;
    for(int i=0;i<MAX_SIZE;i+=1)
    {
        st->min_index[i] = -1;
    }
}

int pop(stack* st)
{
    if(st->top<0)
    {
        cout << "Stack is empty" << endl;
	return -1;
    }
    
    return st->data[(st->top)--];
}

void push(stack* st, int value)
{
    if(st->top>=0)
    {
        if(value<st->data[st->top])
	{
	    st->data[++st->top] = value;
	    st->min_index[st->top] = st->top;
	}
	else
	{
	    st->data[++st->top] = value;
	    st->min_index[st->top] = st->min_index[st->top-1];
	}
    }
    else
    {
         st->data[++st->top] = value;
         st->min_index[st->top] = st->top;
    }
}

int min(stack *st)
{
    if(st->top>=0)
        return st->data[st->min_index[st->top]];
    else
    {
        cout << "Stack is empty" << endl;
	return -1;
    }
}

void print(stack st)
{
    for(int i=0;i<=st.top;i++){
        cout << "data[" << i << "]=" << st.data[i];
        cout << "; min[" << i << "]=" << st.min_index[i];
        cout << endl;
    }
}

int main()
{
    stack st;
    init(&st);
    push(&st, 4);
    push(&st, 2);
    push(&st, 3);
    push(&st, 1);

    cout << min(&st) << endl;
    pop(&st);
    cout << min(&st) << endl;
    pop(&st);
    cout << min(&st) << endl;
    pop(&st);
    cout << min(&st) << endl;
    pop(&st);
    cout << min(&st) << endl;
    return 0;
}

