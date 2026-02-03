#include<iostream>

using std :: cout;
using std :: endl;

template<class T>
class List;

template<class T>
class node
{
    T m_Data;
    node *pNext;

public:
    node()
    {
        m_Data = 0;
        pNext = NULL;
    }
    ~node()
    {
        m_Data = 0;
        pNext = NULL;
    }

    template<class T>
    friend class List;
};

template<class T>
class List
{
    node<T> *pFirst;

public:
    List()
    {
        pFirst = NULL;
    }
    ~List()
    {
        if(pFirst != NULL)
        {
            DeleteAll();
            pFirst = NULL;
        }
    }

    void InsertFirst(T Param);
    void InsertLast(T param);
    void InsertAtPosition(T param , int iPos);
    T DeleteFirst();
    T DeleteLast();
    T DeleteAtPosition(int iPos);
    void Display();
    int CountNodes();
    int SearchFirstOccurrence(T Key);
    int SearchLastOccurrence(T Key);
    int SearchAllOccurrences(T Key);
    void ConcatLists(List &refobj);
    void ConcatAtPosition(List &refobj , int iPos);
    void ReverseDisplay();
    void PhysicalReverse();
    void DeleteAll();
};

template<typename T>
void List<T> :: InsertFirst(T Param)
{
    node<T> *pNewNode = NULL;

    pNewNode = new node<T>;
    if(NULL == pNewNode)
    {
        cout << "\nMemory allocation FAILED\n";
        return;
    }

    pNewNode -> m_Data = Param;

    if(NULL == pFirst)                  // list jr Empty asel tr
        pNewNode -> pNext = NULL;       // new node chya next madhe NULL jato
    else                                // nahitr
        pNewNode -> pNext = pFirst;     // new node chya next madhe junya pahilyacha address jato ani ha pahila hoto

    pFirst = pNewNode;                  // pFirst madhe new node cha address jato
}

template<typename T>
void List<T> :: InsertLast(T Param)
{
    node<T> *pNewNode = NULL;
    node<T> *pTemp = NULL;

    pNewNode = new node<T>;
    if(NULL == pNewNode)
    {
        cout << "\nMemory allocation FAILED\n";
        return;
    }

    pNewNode -> m_Data = Param;
    pNewNode -> pNext = NULL;           // ha kadhipn NULL ch asnar

    if(NULL == pFirst)                  // list jr empty asel tr
    {
        pFirst = pNewNode;              // new node cha address pFirst madhe janar
        return;
    }

    pTemp = pFirst;                     // pointing to First node
    while(pTemp -> pNext != NULL)       // pTemp tuzya next madhe jo paryant NULL yet ny to paryant
        pTemp = pTemp -> pNext;

    pTemp -> pNext = pNewNode;          // last node chya next madhe new node cha address janar
}

template<typename T>
T List<T> :: DeleteFirst()
{
    T DelData;
    node<T> *pTemp = NULL;

    if(NULL == pFirst)
        return -1;

    pTemp = pFirst;                     // pointing to first node
    pFirst = pTemp -> pNext;            // second node cha address pFirst madhe

    DelData = pTemp -> m_Data;
    pTemp -> pNext = NULL;              // 1st node chya next madhe NULL
    delete pTemp;

    return DelData;
}

template<typename T>
T List<T> :: DeleteLast()
{
    T DelData;
    node<T> *pTemp = NULL;

    if(NULL == pFirst)
        return -1;

    pTemp = pFirst;

    if(NULL == pTemp -> pNext)                      // one node asel tr
    {
        DelData = pTemp -> m_Data;
        delete pTemp;
        pFirst = NULL;
    }
    else
    {
        while(pTemp -> pNext -> pNext != NULL)      // pTemp 2nd last node la thambto
            pTemp = pTemp -> pNext;

        DelData = pTemp -> pNext -> m_Data;
        delete pTemp -> pNext;                      // 2nd last node la thambun ch tyala free karto
        pTemp -> pNext = NULL;
    }

    return DelData;
}

template<typename T>
void List<T> :: Display()
{
    node<T> *pHead = pFirst;

    if(NULL == pHead)
    {
        cout << "\n\nList is empty\n";
        return ;
    }

    cout << "\n\nList is :\t";

    while(pHead != NULL)
    {
        cout << "|" << pHead -> m_Data << "|->";
        pHead = pHead -> pNext;
    }
}

template<typename T>
int List<T> :: CountNodes()
{
    node<T> *pHead = pFirst;

    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead -> pNext;
    }

    return iCount;
}

template<typename T>
int List<T> :: SearchFirstOccurrence(T Key)
{
    node<T> *pHead = pFirst;

    int iPos = 0;

    while(pHead != NULL)
    {
        iPos++;

        if(pHead -> m_Data == Key)
            return iPos;

        pHead = pHead -> pNext;
    }

    return 0;               //  If List is empty or Data Not Found
}

template<typename T>
int List<T> :: SearchLastOccurrence(T Key)
{
    node<T> *pHead = pFirst;

    int iPos = 0;
    int iLastPos = 0;

    while(pHead != NULL)
    {
        iPos ++;

        if(pHead -> m_Data == Key)
            iLastPos = iPos;

        pHead = pHead -> pNext;
    }

    return iLastPos;        // data jr ny sapdla ani list jr empty asel tr 0 return karto
}

template<typename T>
int List<T> :: SearchAllOccurrences(T Key)
{
    node<T> *pHead = pFirst;

    int iPos = 0;

    while(pHead != NULL)
    {
        if(pHead -> m_Data == Key)
            iPos ++;

        pHead = pHead -> pNext;
    }

    return iPos;            // data jr ny sapdla ani list jr empty asel tr 0 return karto
}

template<typename T>
void List<T> :: InsertAtPosition(T param , int iPos)
{
    int iCount;
    node<T> *pNewNode = NULL;
    node<T> *pTemp = NULL;

    iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount + 1)
    {
        cout << "\nPosition is Invalid\n";
        return;
    }

    if(1 == iPos)            
    {
        InsertFirst(param);
        return;
    }

/*    if(iPos == iCount + 1)       
    {
        InsertLast(ppHead , iNo);
        return ;
    }
*/

// khali yety mhanje 2 node chi teri list ahe

    pNewNode = new node<T>;
    if(NULL == pNewNode)
    {
        cout << "\nMemory allocation FAILED\n";
        return ;
    }

    pNewNode -> m_Data = param;

    pTemp = pFirst;
    iCount = 1;
    while(iCount < iPos - 1)                // ji position deli tyachya adhichya node la jaun thambaych
    {
        iCount ++;
        pTemp = pTemp -> pNext;
    }

    pNewNode -> pNext = pTemp -> pNext;     // new node chya next madhe ptemp chya next cha address
    pTemp -> pNext = pNewNode;              // pTemp chya next madhe new node cha address
}

template<typename T>
T List<T> :: DeleteAtPosition(int iPos)
{
    T temp;
    int iCount;
    node<T> *pTemp1 = NULL;
    node<T> *pTemp2 = NULL;

    iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount)
    {
        cout << "\nPosition is Invalid\n";
        return -1;
    }

    if(1 == iPos)                       // 1st node delete karaychya asel tr
        return DeleteFirst();

//    if(iPos == iCount)
//        return DeleteLast(ppHead);

    pTemp1 = pFirst;                    // pointing to first node
    iCount = 1;
    while(iCount < iPos - 1)            // position chya adhichya node la jaun thambto
    {
        iCount++;
        pTemp1 = pTemp1 -> pNext;
    }

    pTemp2 = pTemp1 -> pNext;           // pointing to deleting node

    pTemp1 -> pNext = pTemp2 -> pNext;  // jo node delete hoylay tyachya adhichya node chya next madhe tyachya pudhchyacha address taktoy
    temp = pTemp2 -> m_Data;

    delete pTemp2;

    return temp;
}

template<typename T>
void List<T> :: ConcatLists(List &refobj)
{
    node<T> *pTemp = NULL;

    if(NULL == refobj.pFirst)            // scenerio 1 & 2
        return;

    // khali alay mhanje second list ahe

    if(NULL == pFirst)                  // scenerio 3
    {
        pFirst = refobj.pFirst;         // dusrila pahil banvl
        refobj.pFirst = NULL;           // 2nd list empty
        return;
    }

    // khali alay mhanje donhi lists ahet
    // scenerio 4

    pTemp = pFirst;                     // pointing to first node
    while(pTemp -> pNext != NULL)       // jo paryant tuzya next madhe NULL yet ny
        pTemp = pTemp -> pNext;

    pTemp -> pNext = refobj.pFirst;     // 1st list chya last node chya next madhe 2nd list chya 1st node cha address
    refobj.pFirst = NULL;               // 2nd list empty
}

template<typename T>
void List<T> :: ReverseDisplay()
{
    node<T> *pHead = pFirst;

    if(NULL == pHead)
    {
        cout << "\nList is empty\n";
        return;
    }

    PhysicalReverse();
    Display();
    PhysicalReverse();
}

template<typename T>
void List<T> :: PhysicalReverse()
{
    node<T> *pNext = NULL;
    node<T> *pCurrent = pFirst;
    node<T> *pPrev = NULL;

    while(pCurrent != NULL)             // pCurrent madhe jo paryant NULL jat nay
    {
        pNext = pCurrent -> pNext;      // pCurrent chya pudhchya node la pNext set kela
        pCurrent -> pNext = pPrev;      // pCurrent chya next madhe tyachya magchyacha address takla
        pPrev = pCurrent;               // pPrev pCurrent chya jagi anla
        pCurrent = pNext;               // pCurreant pNext chya jagi nela
    }

    pFirst = pPrev;   // last la jevha pCurrent madhe NULL jaun loop chya baher yenar tevha prev ha last node la asnar manun tyacha address pFirst madhe
}

template<typename T>
void List<T> :: DeleteAll()
{
    node<T> *pTemp = NULL;

    while(pFirst != NULL)
    {
    pTemp = pFirst;
    pFirst = pTemp -> pNext;
    delete pTemp;
    }
}

template<typename T>
void List<T> :: ConcatAtPosition(List &refobj , int iPos)
{
    int iCount;
    node<T> *pTemp1 = NULL;
    node<T> *pTemp2 = NULL;


    iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount + 1)
    {
        cout << "\nPosition is Invalid\n";
        return;
    }

// we dont know 2nd list is present or not
// we dont know 1st list is present or not
// we surely know if 1st list empty then iPos == 1

    if(NULL == refobj.pFirst)
        return;

// surely 2nd list is present
// we dont know 1st list is present or not
// we surely know if 1st list empty then iPos == 1

    if(1 == iPos)
    {
        ConcatLists(refobj);                // dusri list philya list la jodun ali
        pFirst = refobj.pFirst;             // 2nd become 1st
        refobj.pFirst = NULL;               // 2nd become empty
        return;
    }

// surely both list are present

//    if(iPos == iCount + 1)
//    {
//        ConcatLists(ppHead1 , ppHead2);
//        return;
//    }

    pTemp1 = pFirst;
    iCount = 1;
    while(iCount < iPos - 1)
    {
        iCount ++;
        pTemp1 = pTemp1 -> pNext;
    }

    pTemp2 = refobj.pFirst;
    while(pTemp2 -> pNext != NULL)
        pTemp2 = pTemp2 -> pNext;

    pTemp2 -> pNext = pTemp1 -> pNext;
    pTemp1 -> pNext = refobj.pFirst;

    refobj.pFirst = NULL;
}


int main(void)
{
    int iDelData;

    List<int> lst;
    List<int> lst1;

    lst.InsertFirst(20);
    lst.InsertFirst(10);

    lst.Display();                  //  |10|->|20|->

    lst.InsertLast(30);
    lst.InsertLast(40);
    lst.InsertLast(50);
    lst.InsertLast(60);
    lst.InsertLast(20);

    lst.Display();                  //  |10|->|20|->|30|->|40|->|50|->|60|->|20|->

    lst.InsertAtPosition(50,3);
    lst.Display();                  //  |10|->|20|->|50|->|30|->|40|->|50|->|60|->|20|->

    iDelData = lst.DeleteFirst();
    if(iDelData != -1)
        cout << "\nDeleted data is " << iDelData << endl;       //  Deleted data is 10
    lst.Display();                                              //  |20|->|50|->|30|->|40|->|50|->|60|->|20|->

    iDelData = lst.DeleteLast();
    if(iDelData != -1)
        cout << "\nDeleted data is " << iDelData << endl;       //  Deleted data is 20
    lst.Display();                                              //  |20|->|50|->|30|->|40|->|50|->|60|->

    iDelData = lst.DeleteAtPosition(2);                         
    if(iDelData != -1)
        cout << "\nDeleted data is " << iDelData << endl;       //  Deleted data is 50
    lst.Display();                                              //  |20|->|30|->|40|->|50|->|60|->

    iDelData = lst.CountNodes();
    cout << "\nTotal node count is " << iDelData << endl;       //  Total node count is 5

    lst.Display();                                                                      //  |20|->|30|->|40|->|50|->|60|->
    iDelData = lst.SearchFirstOccurrence(20);
    if(iDelData != 0)
        cout << "\nFirst Occurrence of 20 is at " << iDelData << " position" << endl;   //  First Occurrence of 20 is at 1 position

    lst.Display();                                                                      //  |20|->|30|->|40|->|50|->|60|->
    iDelData = lst.SearchLastOccurrence(50);
    if(iDelData != 0)
        cout << "\nLast Occurrence of 50 is at " << iDelData << " position" << endl;    //  Last Occurrence of 50 is at 4 position

    lst.Display();                                                                      //  |20|->|30|->|40|->|50|->|60|->
    iDelData = lst.SearchAllOccurrences(50);
    if(iDelData != 0)
        cout << "\n50 found " << iDelData << " times" << endl << endl;                   //  50 found 1 times

    lst.Display();                  //  |20|->|30|->|40|->|50|->|60|->
    lst.PhysicalReverse();
    lst.Display();                  //  |60|->|50|->|40|->|30|->|20|->
    lst.PhysicalReverse();
    lst.Display();                  //  |20|->|30|->|40|->|50|->|60|->

    cout << endl << endl;

    lst.ReverseDisplay();           //  |60|->|50|->|40|->|30|->|20|->
    lst.Display();                  //  |20|->|30|->|40|->|50|->|60|->

    lst1.InsertLast(100);
    lst1.InsertLast(200);
    lst1.InsertLast(300);
    lst1.Display();                 //  |100|->|200|->|300|->

    lst.ConcatLists(lst1);
    lst.Display();                  //  |20|->|30|->|40|->|50|->|60|->|100|->|200|->|300|->
    lst1.Display();                 //  List is empty

    lst1.InsertLast(400);
    lst1.InsertLast(500);
    lst1.Display();                 //  |400|->|500|->
    lst.ConcatAtPosition(lst1,3);
    lst.Display();                  //  |20|->|30|->|400|->|500|->|40|->|50|->|60|->|100|->|200|->|300|->
    lst1.Display();                 //  List is empty

    lst.DeleteAll();
    lst1.DeleteAll();

    cout << endl << endl;

    lst.Display();                  //  List is empty
    lst1.Display();                 //  List is empty

    return 0;
}
