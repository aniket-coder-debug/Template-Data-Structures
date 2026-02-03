#include<iostream>
#define MAX 5

using std :: cout;
using std :: endl;

template<class T>
class stack
{
    T pStack[MAX];
    int iTop;

public:
    stack()
    {
        iTop = -1;

        for(int iCounter = 0; iCounter < MAX ; iCounter++)
            pStack[iCounter] = 0;
    }
    ~stack()
    {
        iTop = -1;
        
        for(int iCounter = 0; iCounter < MAX ; iCounter++)
            pStack[iCounter] = 0;
    }

    void Push(T iNo)
    {
        if(IsFull())
        {
            cout << "\nStack Overflow\n";
            return;
        }

        pStack[++(iTop)] = iNo;           // adhi pudh sarak mag data bhar
    }

    T Pop()
    {
        if(IsEmpty())
        {
            cout << "\nStack is empty\n";
            return 0;
        }

        return pStack[(iTop)--];          // adhi value return kr ani mg mag ja
    }

    int IsFull()
    {
        if(iTop == MAX - 1)
            return 1;
        return 0;
    }

    int IsEmpty()
    {
        if(iTop == -1)
            return 1;
        return 0;
    }

    void Display()
    {
        for(int iCounter = 0; iCounter <= iTop ; iCounter++)
            cout << pStack[iCounter] << "\t";

        cout << endl;
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
    if(iPoppedData != 0)
        cout << "\nDeleted data is " << iPoppedData << endl;    

    obj.Display();                        

    return 0;
}
