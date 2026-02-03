#include<iostream>
using std :: cout;
using std :: endl;

#define MAX 5

template<class T>
class stack;

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
    friend class stack;
};

template<class T>
class stack
{
    node<T> *pStack;

public:
    stack()
    {
        pStack = NULL;
    }
    ~stack()
    {
        if(pStack != NULL)
        {
            DeleteAll();
            pStack = NULL;
        }
    }

    void Push(T iNo)
    {
        node<T> *pNewNode = NULL;

        if(IsFull())
        {
            cout << "\nStack Overflow\n";
            return;
        }

        pNewNode = new node<T>;
        if(pNewNode == NULL)
        {
            cout << "\nMemory allocation FAILED\n";
            return;
        }

        pNewNode -> Data = iNo;

        if(NULL == pStack)
            pNewNode -> pNext = NULL;
        else
            pNewNode -> pNext = pStack;

        pStack = pNewNode;
    }

    T Pop()
    {
        T iDelData;
        node<T> *pTemp = NULL;

        if(IsEmpty())
        {
            cout << "\nStack is empty\n";
            return -1;
        }

        pTemp = pStack;
        pStack = pTemp -> pNext;

        iDelData = pTemp -> Data;
        pTemp -> pNext = NULL;
        delete pTemp;

        return iDelData;
    }

    int IsFull()
    {
        node<T> *pHead = pStack;

        if(CountNodes() == MAX)
            return 1;
        return 0;
    }

    int IsEmpty()
    {
        node<T> *pHead = pStack;

        if(NULL == pHead)
            return 1;
        return 0;
    }

    void Display()
    {
        node<T> *pHead = pStack;

        if(NULL == pHead)
        {
            cout << "\n\nStack is emtpy\n";
            return;
        }

        cout << "List is:\n";
        while(pHead != NULL)
        {
            cout << "|" << pHead -> Data << "|-> ";
            pHead = pHead -> pNext;
        }
    }

    int CountNodes()
    {
        node<T> *pHead = pStack;

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

        while(NULL != pStack)
        {
            pTemp = pStack;
            pStack = pTemp -> pNext;
            delete pTemp;
        }
    }
};


int main(void)
{
    char iPoppedData;
    stack<char> obj;

    obj.Push('A');
    obj.Push('B');
    obj.Push('C');

    obj.Display();                                           

    iPoppedData = obj.Pop();
    if(iPoppedData != -1)
        cout << "\n\nDeleted data is " << iPoppedData << endl;      

    obj.Display();                                           

    obj.DeleteAll();

    obj.Display();                                         

    return 0;
}
