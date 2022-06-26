// Stack class.
class Stack
{
    int *arr;
    int Top;
    int sz;

public:
    Stack(int capacity)
    {
        arr = new int[capacity];
        sz = capacity;
        Top = -1;
    }

    void push(int num)
    {
        Top++;
        arr[Top] = num;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        else
        {
            int x = arr[Top];
            Top--;
            return x;
        }
    }

    int top()
    {
        if (Top == -1)
            return -1;
        return arr[Top];
    }

    int isEmpty()
    {
        return Top == -1;
    }

    int isFull()
    {
        return Top == sz - 1;
    }
};