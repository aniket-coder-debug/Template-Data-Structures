#include <iostream>

using std :: cout;
using std :: endl;

template<class T>
class list;

template<class T>
class node
{
    node *pPrev;
    T Data;
    node *pNext;

public:
    node()
    {
        pPrev = NULL;
        Data = 0;
        pNext = NULL;
    }

    ~node()
    {
        pPrev = NULL;
        Data = 0;
        pNext = NULL;
    }

    template<class T>
    friend class list;
};

template<class T>
class list
{
    node<T> *pFirst;
    node<T> *pLast;

public:
    list()
    {
        pFirst = NULL;
        pLast = NULL;
    }

    ~list()
    {
        if(pFirst != NULL)
        {
            DeleteAll();
            pFirst = NULL;
            pLast = NULL;
        }
    }

    void InsertFirst(T iNo)
    {
        node<T> *pNewNode = NULL;

        pNewNode = new node<T>;
        if(pNewNode == NULL)
        {
            cout << "\nMemory allocation FAILED\n";
            return;
        }

        pNewNode -> Data = iNo;

        if(pFirst == NULL)
        {
            pFirst = pNewNode;
            pLast = pNewNode;
        }
        else
        {
            pNewNode -> pNext = pFirst;
            pFirst -> pPrev = pNewNode;
            pFirst = pNewNode;
        }

        pFirst -> pPrev = pLast;
        pLast -> pNext = pFirst;
    }

    void InsertLast(T iNo)
    {
        node<T> *pNewNode = NULL;

        pNewNode = new node<T>;
        if(NULL == pNewNode)
        {
            cout << "\nMemory allocation Failed\n";
            return;
        }

        pNewNode -> Data = iNo;

        if(pFirst == NULL)
        {
            pFirst = pNewNode;
            pLast = pNewNode;
        }
        else
        {
            pLast -> pNext = pNewNode;
            pNewNode -> pPrev = pLast;
            pLast = pNewNode;
        }

        pLast -> pNext = pFirst;
        pFirst -> pPrev = pLast;
    }

    void InsertAtPosition(T iNo , int iPos)
    {
        node<T> *pNewNode = NULL;
        node<T> *pTemp = NULL;
        int iCount;

        iCount = CountNodes();
        if(iPos <= 0 || iPos > iCount + 1 )
        {
            cout << "\nInvalid position\n";
            return;
        }

        if(1 == iPos)
        {
            InsertFirst(iNo);
            return;
        }

        if(iPos == iCount + 1)
        {
            InsertLast(iNo);
            return;
        }

        pNewNode = new node<T>;
        if(NULL == pNewNode)
        {
            cout << "\nMemory allocation Failed\n";
            return;
        }

        pNewNode -> Data = iNo;

        pTemp = pFirst;
        iCount = 1;
        while(iCount < iPos - 1)
        {
            ++iCount;
            pTemp = pTemp -> pNext;
        }

        pNewNode -> pNext = pTemp -> pNext;
        pTemp -> pNext -> pPrev = pNewNode;
        pNewNode -> pPrev = pTemp;
        pTemp -> pNext = pNewNode;
    }

    T DeleteFirst()
    {
        T DelData;

        if(NULL == pFirst)
            return -1;

        DelData = pFirst -> Data;

        if(pFirst == pLast)
        {
            delete pFirst;
            pFirst = pLast = NULL;
        }
        else
        {
            pFirst = pFirst -> pNext;
            delete pLast -> pNext;
            pLast -> pNext = pFirst;
            pFirst -> pPrev = pLast;
        }

        return DelData;
    }

    T DeleteLast()
    {
        T DelData;

        if(NULL == pFirst)
            return -1;

        DelData = pLast -> Data;

        if(pFirst == pLast)
        {
            delete pFirst;
            pFirst = NULL;
            pLast = NULL;
        }
        else
        {
            pLast = pLast -> pPrev;
            delete pLast -> pNext;
            pLast -> pNext = pFirst;
            pFirst -> pPrev = pLast;
        }

        return DelData;
    }

    T DeleteAtPosition(int iPos)
    {
        node<T> *pTemp = NULL;
        int iCount;
        T DelData;

        if(NULL == pFirst)
            return -1;

        iCount = CountNodes();
        if(iPos <= 0 || iPos > iCount)
        {
            cout << "\nInvalid Position\n";
            return -1;
        }

        if(1 == iPos)
            return DeleteFirst();

        if(iPos == iCount)
            return DeleteLast();

        pTemp = pFirst;
        iCount = 1;
        while(iCount < iPos)
        {
            ++iCount;
            pTemp = pTemp -> pNext;
        }

        DelData = pTemp -> Data;
        pTemp -> pPrev -> pNext = pTemp -> pNext;
        pTemp -> pNext -> pPrev = pTemp -> pPrev;
        delete pTemp;

        return DelData;
    }

    int CountNodes()
    {
        node<T> *pHead = pFirst;
        node<T> *pTail = pLast;

        int iCount = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            ++iCount;
            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return iCount;
        
    }

    int SearchFirstOccurrence(T iKey)
    {
        node<T> *pHead = pFirst;
        node<T> *pTail = pLast;

        int iPos = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            ++iPos;

            if(iKey == pHead -> Data)
                return iPos;

            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return 0;
    }

    int SearchLastOccurrence(T iKey)
    {
        node<T> *pHead = pFirst;
        node<T> *pTail = pLast;

        int iPos = 0;
        int iLastPos = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            ++iPos;

            if(iKey == pHead -> Data)
                iLastPos = iPos;

            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return iLastPos;
    }

    int SearchAllOccurrences(T iKey)
    {
        node<T> *pHead = pFirst;
        node<T> *pTail = pLast;

        int iCount = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            if(iKey == pHead -> Data)
                ++iCount;

            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return iCount;
    }

    void Display()
    {
        node<T> *pHead = pFirst;
        node<T> *pTail = pLast;

        if(NULL == pHead)
        {
            cout << "\nList is Empty\n";
            return;
        }

        cout << "\nList is:\n";

        do
        {
            cout << "<-|" << pHead -> Data << "|->";
            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        cout << endl;
        
    }

    void PhysicalReverse()
    {
        node<T> *pCurrent = pFirst;
        node<T> *pNext = NULL;

        if(NULL == pFirst)
            return;

        do
        {
            pNext = pCurrent -> pNext;
            pCurrent -> pNext = pCurrent -> pPrev;
            pCurrent -> pPrev = pNext;
            pCurrent = pNext;

        } while (pCurrent != pFirst);

        pLast = pCurrent;
        pFirst = pLast -> pNext;
    }

    void ReverseDisplay()
    {
        node<T> *pHead = pFirst;
        node<T> *pTail = pLast;

        if(NULL == pHead)
        {
            cout << "\nList is Empty\n";
            return ;
        }

        do
        {
            cout << "<-|" << pTail -> Data << "|->";
            pTail = pTail -> pPrev;

        } while (pTail != pHead -> pPrev);

        cout << endl;
        
    }

    void DeleteAll()
    {
        node<T> *pTemp = NULL;

        pLast -> pNext = NULL;

        while(pFirst != NULL)
        {
            pTemp = pFirst;
            pFirst = pTemp -> pNext;
            delete pTemp;
        }

        pLast = NULL;
    }

    void ConcatLists(list &refobj)
    {
        if(NULL == refobj.pFirst)
            return ;

        if(NULL == pFirst)
        {
            pFirst = refobj.pFirst;
            pLast = refobj.pLast;

            refobj.pFirst = refobj.pLast = NULL;
            return;
        }

        pLast -> pNext = refobj.pFirst;
        refobj.pFirst -> pPrev = pLast;
        pLast = refobj.pLast;
        pFirst -> pPrev = pLast;
        pLast -> pNext = pFirst;

        refobj.pFirst = refobj.pLast = NULL;
    }

    void ConcatAtPosition(list &refobj ,int iPos)
    {
        int iCount;
        node<T> *pTemp = NULL;

        iCount = CountNodes();
        if(iPos <= 0 || iPos > iCount + 1)
        {
            cout << "\nInvalid Position\n";
            return ;
        }

        if(NULL == refobj.pFirst)
            return;

        if(1 == iPos)
        {
            ConcatLists(refobj);
            pFirst = refobj.pFirst;
            pLast = refobj.pLast;

            refobj.pFirst = refobj.pLast = NULL;
            return;
        }

        if(iPos == iCount + 1)
        {
            ConcatLists(refobj);
            return;
        }

        pTemp = pFirst;
        iCount = 1;
        while(iCount < iPos - 1)
        {
            ++iCount;
            pTemp = pTemp -> pNext;
        }

        pTemp -> pNext -> pPrev = refobj.pLast;
        refobj.pLast -> pNext = pTemp -> pNext;
        pTemp -> pNext = refobj.pFirst;
        refobj.pFirst -> pPrev = pTemp;

        refobj.pFirst = refobj.pLast = NULL;
    }

};


int main(void)
{
    char Number;
    int ipTemp;

    list<char> obj1;
    list<char> obj2;

    obj1.Display();                                      // List is empty

    obj1.InsertFirst('C');
    obj1.InsertFirst('B');
    obj1.InsertFirst('A');
    obj1.Display();                                      // <-|A|-><-|B|-><-|C|->

    obj1.InsertLast('D');
    obj1.InsertLast('E');
    obj1.InsertLast('F');
    obj1.Display();                                      // <-|A|-><-|B|-><-|C|-><-|D|-><-|E|-><-|F|->

    obj1.InsertAtPosition('G',4);
    obj1.Display();                                      // <-|A|-><-|B|-><-|C|-><-|G|-><-|D|-><-|E|-><-|F|->

    Number = obj1.DeleteFirst();
    if(Number != -1)
        cout << "\n\nDeleted data is " << Number << endl;       // Deleted data is A

    obj1.Display();                                             // <-|B|-><-|C|-><-|G|-><-|D|-><-|E|-><-|F|->

    Number = obj1.DeleteLast();
    if(Number != -1)
        cout << "\n\nDeleted data is " << Number << endl;       // Deleted data is F

    obj1.Display();                                             // <-|B|-><-|C|-><-|G|-><-|D|-><-|E|->

    Number = obj1.DeleteAtPosition(2);
    if(Number != -1)
        cout << "\n\nDeleted data is " << Number << endl;       // Deleted data is C

    obj1.Display();                                             //  <-|B|-><-|G|-><-|D|-><-|E|->

    ipTemp = obj1.SearchFirstOccurrence('E');
    if(ipTemp != 0)
        cout << "\n\nFirst Occurrence of 'E' is at " << ipTemp << " position" << endl;     // First Occurrence of 'E' is at 4 position

    ipTemp = obj1.SearchLastOccurrence('B');
    if(ipTemp != 0)
        cout << "\n\nLast Occurrence of 'B' is at " << ipTemp << " position" << endl;      // Last Occurrence of 'B' is at 1 position

    ipTemp = obj1.SearchFirstOccurrence('B');
    if(ipTemp != 0)
        cout <<"\n\n'B' Found " << ipTemp << " times" << endl;  // 'B' Found 1 times

    obj1.Display();                                             //  <-|B|-><-|G|-><-|D|-><-|E|->
    ipTemp = obj1.CountNodes();
    cout << "\n\nTotal node count is " << ipTemp << endl;       // Total node count is 4

    obj1.PhysicalReverse();
    obj1.Display();                                      // <-|E|-><-|D|-><-|G|-><-|B|->
    obj1.PhysicalReverse();
    obj1.Display();                                      // <-|B|-><-|G|-><-|D|-><-|E|->
    obj1.ReverseDisplay();                               // <-|E|-><-|D|-><-|G|-><-|B|->
    obj1.Display();                                      // <-|B|-><-|G|-><-|D|-><-|E|->

    obj2.InsertLast('P');
    obj2.InsertLast('Q');
    obj2.InsertLast('R');
    obj1.Display();                                      // <-|B|-><-|G|-><-|D|-><-|E|->
    obj2.Display();                                      // <-|P|-><-|Q|-><-|R|->
    obj1.ConcatLists(obj2);
    obj1.Display();                                      // <-|B|-><-|G|-><-|D|-><-|E|-><-|P|-><-|Q|-><-|R|->
    obj2.Display();                                      // List is empty
    
    obj2.InsertLast('X');
    obj2.InsertLast('Y');
    obj2.InsertLast('Z');
    obj1.Display();                                      // <-|B|-><-|G|-><-|D|-><-|E|-><-|P|-><-|Q|-><-|R|->
    obj2.Display();                                      // <-|X|-><-|Y|-><-|Z|->
    obj1.ConcatAtPosition(obj2 , 3);
    obj1.Display();                                      // <-|B|-><-|G|-><-|X|-><-|Y|-><-|Z|-><-|D|-><-|E|-><-|P|-><-|Q|-><-|R|->
    obj2.Display();                                      // List is empty

    return 0;
}
