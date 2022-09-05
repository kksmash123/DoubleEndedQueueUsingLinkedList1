// DoubleEndedQueueUsingLinkedList.cpp 
// Enqueue and dequeue from the front and rear ends .



#include <iostream>

using namespace std;



struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;

}*front = NULL, * rear = NULL;



/*queue using linked list operations

1.isempty
2.isfull
3.display
4.enqueue front
5.enqueue rear
6.dequeue front
7.dequeue rear */

void display();
void dequeueRear();
void dequeueFront();
void enqueueRear(int);
void enqueueFront(int);
bool IsFull();
bool IsEmpty();



void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty . " << endl;
        return;
    }

    struct Node* p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

}


void dequeueRear()
{
    if (IsEmpty())
    {
        cout << "Queue is empty . deletion is not possible" << endl;
        return;
    }

    struct Node* p = rear;
    rear = rear->prev;

    if (!rear)
        front = NULL;

    else
    rear->next = NULL;

    cout << "Deleted -> " << p->data << " from the queue's rear end." << endl;
    delete p;


}


void dequeueFront()
{
    if (IsEmpty())
    {
        cout << "Queue is empty . deletion not possible ." << endl;
        return;
    }

    struct Node* p = front;
    front = front->next;

    if (!front)
        rear = NULL;
    else
    front->prev = NULL;

    cout << "Deleted -> " << p->data << " from the queue's front." << endl;
    delete p;
}


void enqueueRear(int x)
{
    if (IsFull())
    {
        cout << "Queue is Full . Insertion of -> " << x << " from the queue's rear is not posiible ." << endl;
        return;
    }
    struct Node* p = new Node;
    p->data = x;

    if (rear == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        front = rear = p;
        cout << "Since Queue is empty . Inserted -> " << x << " from queue's rear end . " << endl;
        return;
    }

    p->next = NULL;
    p->prev = rear;
    rear->next = p;
    rear = p;

    cout << "Inserted -> " << x << " from queue's rear end . " << endl;

}


void enqueueFront(int x)
{
    if (IsFull())
    {
        cout << "Queue is full . Insertion of -> " << x << " from queue's front is not possible ." << endl;
        return;
    }

    struct Node* p = new Node;
    p->data = x;
    
    if (front == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        front = rear = p;
        cout << "since queue is empty . Inserted -> " << x << " from the queue's front end . " << endl;
        return;
    }

    p->next = front;
    p->prev = NULL;
    front->prev = p;
    front = p;
    cout << "Inserted -> " << x << " from the queue's front end . " << endl;
}


bool IsFull()
{
    struct Node* temp = new Node;
    if (temp == NULL)    
        return 1;
    
    delete temp;
    return 0;
}


bool IsEmpty()
{
    return (front == NULL) ? 1 : 0;

}

int main()
{
    enqueueRear(15);
    enqueueFront(10);
    enqueueRear(25);
    enqueueRear(55);
    enqueueFront(100);
    enqueueFront(120);
    display();
    dequeueFront();
    dequeueFront();
    dequeueFront();
    dequeueFront();
    display();
    dequeueFront();
    dequeueFront();
    dequeueFront();
    display();
    enqueueRear(15);
    enqueueFront(10);
    enqueueRear(25);
    enqueueRear(55);
    dequeueRear();
    dequeueRear();
    dequeueRear();
    display();
    dequeueRear();
    dequeueRear();
    dequeueRear();
    display();
}
