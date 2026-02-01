#include<iostream>
#define MAX 5

using std :: cout;
using std :: endl;

template<class T>
class queue
{
    int m_iRear;
    int m_iFront;
    T Queue[MAX];

public:
    queue()
    {
        m_iRear = -1;
        m_iFront = 0;
    }
    ~queue()
    {
        m_iRear = 0;
        m_iFront = 0;
    }

    
    void EnQueue(T iNo)
    {
        if(IsQueueFull())
        {
            cout << "\nQueue is Full\n";
            return;
        }

        if(m_iRear == MAX - 1)          
            m_iRear = 0;
        else
            ++(m_iRear);

        Queue[m_iRear] = iNo;
    }

    T DeQueue()
    {
        T iDelData ;

        if(IsQueueEmpty())
        {
            cout << "\nQueue is Empty\n";
            return -1;
        }

        iDelData = Queue[m_iFront];

        if(m_iRear == m_iFront)
        {
            m_iRear = -1;
            m_iFront = 0;
        }
        else
            ++(m_iFront);

        return iDelData;
    }

    int IsQueueFull()
    {
        if((m_iFront == 0 && m_iRear == MAX - 1) || (m_iRear == m_iFront - 1 && m_iRear != -1))
            return 1;
        return 0;
    }

    int IsQueueEmpty()
    {
        if(m_iRear == -1)
            return 1;
        return 0;
    }

    void Display()
    {
        int iCounter = m_iFront;

        if(m_iRear == -1)
        {
            cout << "\nQueue is Empty\n";
            return ;
        }

        if(m_iRear < m_iFront)              // circular
        {
            for( ; iCounter <= MAX - 1 ; iCounter++)
                cout << Queue[iCounter] << " ";

            iCounter = 0;
        }

        for( ; iCounter <= m_iRear ; iCounter++)
            cout << Queue[iCounter] << " ";
    }

};
