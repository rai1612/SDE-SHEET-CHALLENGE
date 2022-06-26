class Queue
{
    int *arr;
    int Front;
    int Back;

public:
    Queue()
    {
        arr = new int[100000];
        Front = -1;
        Back = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (Front == -1 || Front > Back)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        Back++;
        arr[Back] = data;

        if (Front == -1)
            Front++; // removing the empty status of the queue
    }

    int dequeue()
    {
        if (Front == -1 || Front > Back)
            return -1;
        int x = arr[Front];
        Front++;
        return x;
    }

    int front()
    {
        if (Front == -1 || Front > Back)
            return -1;
        return arr[Front];
    }
};