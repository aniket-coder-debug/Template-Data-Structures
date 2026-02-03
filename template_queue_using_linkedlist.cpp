#include<iostream>
#define MAX 5

using std :: cout;
using std :: endl;

template<class T>
class queue;

template<class T>
class node
{
    T Data;
    node *pNext;

public:
    node()
    {
        Data = 0;
        pNext = NULL;
    }
    ~node()
    {
        Data = 0;
        pNext = NULL;
    }

    template<class T>
    friend class queue;
};

template<class T>
class queue
{
    node<T> *pQueue;
public:
    queue()
    {
        pQueue = NULL;
    }
    ~queue()
    {
        if(pQueue != NULL)
        {
            DeleteAll();
            pQueue = NULL;
        }
    }

    void EnQueue(T iNo)
    {
        node<T> *pNewNode = NULL;
        node<T> *pTemp = NULL;
    
        if(IsQueueFull())
        {
            cout << "\nQueue is Full\n";
            return ;
        }
    
        pNewNode = new node<T>;
        if(NULL == pNewNode)
        {
            cout << "Memory allocation FAILED\n";
            return;
        }
    
        pNewNode -> Data = iNo;
        pNewNode -> pNext = NULL;
    
        if(pQueue == NULL)
        {
            pQueue = pNewNode;
            return;
        }
    
        pTemp = pQueue;
        while(pTemp -> pNext != NULL)
            pTemp = pTemp -> pNext;
    
        pTemp -> pNext = pNewNode;
    
    }

    T DeQueue()
    {
        T iDelData;
        node<T> *pTemp = NULL;

        if(IsQueueEmpty())
        {
            cout << "\nQueue is Empty\n";
            return -1;
        }

        pTemp = pQueue;
        pQueue = pTemp -> pNext;

        iDelData = pTemp -> Data;
        pTemp -> pNext = NULL;
        delete pTemp;

        return iDelData;
    }

    int IsQueueFull()
    {
        node<T> *pHead = pQueue;

        if(CountNodes() == MAX)
            return 1;
        return 0;
    }

    int IsQueueEmpty()
    {
        node<T> *pHead = pQueue;

        if(NULL == pHead)
            return 1;
        return 0;
    }

    void Display()
    {
        node<T> *pHead = pQueue;

        if(NULL == pHead)
        {
            cout << "\nList is emtpy\n";
            return;
        }

        while(pHead != NULL)
        {
            cout << "|" << pHead -> Data << "|->";
            pHead = pHead -> pNext;
        }
    }

    int CountNodes()
    {
        node<T> *pHead = pQueue;

        int iCount = 0;

        while(pHead != NULL)
        {
            iCount++;
            pHead = pHead -> pNext;
        }

        return iCount;
    }

    void DeleteAll()
    {
        node<T> *pTemp = NULL;

        while(NULL != pQueue)
        {
            pTemp = pQueue;
            pQueue = pTemp -> pNext;
            delete pTemp;
        }
    }
};


int main(void)
{
    char iDeldata;
    queue<char> obj;

    obj.EnQueue('A');
    obj.EnQueue('B');
    obj.EnQueue('C');

    obj.Display();

    iDeldata = obj.DeQueue();
    if(iDeldata != -1)
        cout << "\nDeleted data is " << iDeldata << endl;

    obj.Display();

    obj.DeleteAll();
    obj.Display();

    return 0;
}
