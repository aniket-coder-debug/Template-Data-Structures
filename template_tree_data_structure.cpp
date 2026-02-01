#include<iostream>
#define MAX 25

using std :: cout;
using std :: endl;

template<typename T>
class queue;
template<typename T>
class node;
template<typename T>
class Tree;
template<typename T>
class BST
{
    BST *pLChild;
    T iData;
    BST *pRChild;

public:
    BST();
    ~BST();

    template<typename T>
    friend class Tree;
    template<typename T>
    friend class node;
};

template<typename T>
class Tree
{
    BST<T> *pRoot;
    
public:
    Tree();
    ~Tree();

private:
    void myPreorder(BST<T>*);
    void myInorder(BST<T>*);
    void myPostorder(BST<T>*);
    void myLevelorder(BST<T>*);
    void myDeleteAll(BST<T>**);
    int myCountBSTsVersion1(BST<T>*);
    int myCountBSTsVersion2(BST<T>*);
    int myCountLeafBSTs(BST<T>*);
    int myCountNonLeafBSTs(BST<T>*);
    T myLargestElement(BST<T>*);
    T mySmallestElement(BST<T>*);
    int myHeight(BST<T>*);

    bool mySearchBSTRecursive(BST<T>*,T);
    bool mySearchBSTNonRecursive(BST<T>*,T);

public:
    void Preorder();
    void Inorder();
    void Postorder();
    void Levelorder();

    void DeleteAll();
    int CountBSTsVersion1();
    int CountBSTsVersion2();
    int CountLeafBSTs();
    int CountNonLeafBSTs();
    T LargestElement();
    T SmallestElement();
    int Height();

    bool SearchBSTRecursive(T);
    bool SearchBSTNonRecursive(T);

    void InsertBST(T);
    void DeleteBST(T);
};


template<typename T>
class node
{
    BST<T> *iData;
    node *pNext;

public:
    node();
    ~node();

    template<typename T>
    friend class queue;
};

template<typename T>
class queue
{
    node<T> *pPtr;

public:
    queue();
    ~queue();

    void EnQueue(BST<T>*);
    BST<T>* DeQueue();
    bool IsQueueFull();
    bool IsQueueEmpty();
    int CountNodes();
};


template<typename T>
BST<T>::BST()
{
    pLChild = NULL;
    iData = 0;
    pRChild = NULL;
}
template<typename T>
BST<T>::~BST()
{
    pLChild = NULL;
    iData = 0;
    pRChild = NULL;
}

template<typename T>
Tree<T>::Tree()
{
    pRoot = NULL;
}
template<typename T>
Tree<T>::~Tree()
{
    cout << "\nIn Distructor\n";

    if(pRoot != NULL)
    {
        DeleteAll();
        pRoot = NULL;
    }
}

template<typename T>
void Tree<T>::myPreorder(BST<T>* pRoot)
{
    BST<T> *pTemp = pRoot;

    if(NULL == pTemp)
        return ;

    cout << pTemp -> iData << " ";
    myPreorder(pTemp -> pLChild);
    myPreorder(pTemp -> pRChild);
}
template<typename T>
void Tree<T>::Preorder()
{
    myPreorder(pRoot);
}

template<typename T>
void Tree<T>::myInorder(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    if(NULL == pTemp)
        return ;

    myInorder(pTemp -> pLChild);
    cout << pTemp -> iData << " ";
    myInorder(pTemp -> pRChild);
}
template<typename T>
void Tree<T>::Inorder()
{
    myInorder(pRoot);
}

template<typename T>
void Tree<T>::myPostorder(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    if(NULL == pTemp)
        return ;

    myPostorder(pTemp -> pLChild);
    myPostorder(pTemp -> pRChild);
    cout << pTemp -> iData << " ";

}
template<typename T>
void Tree<T>::Postorder()
{
    myPostorder(pRoot);
}

template<typename T>
void Tree<T>::myLevelorder(BST<T> *pRoot)
{
    queue<T> obj;
    BST<T> *pPtr = NULL;

    if(NULL == pRoot)
        return;

    obj.EnQueue(pRoot);

    while(! obj.IsQueueEmpty())
    {   
        pPtr = obj.DeQueue();

        cout << pPtr -> iData << " ";

        if(pPtr -> pLChild != NULL)
            obj.EnQueue(pPtr -> pLChild);

        if(pPtr -> pRChild != NULL)
            obj.EnQueue(pPtr -> pRChild);
    }
}
template<typename T>
void Tree<T>::Levelorder()
{
    myLevelorder(pRoot);
}

template<typename T>
void Tree<T>::myDeleteAll(BST<T> **ppRoot)
{
    if(NULL == *ppRoot)
        return;

    myDeleteAll(&(*ppRoot) -> pLChild);
    myDeleteAll(&(*ppRoot) -> pRChild);
    delete *ppRoot;
    *ppRoot = NULL;
}
template<typename T>
void Tree<T>::DeleteAll()
{
    myDeleteAll(&pRoot);
}

template<typename T>
int Tree<T>::myCountBSTsVersion1(BST<T> *pRoot)
{
    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    iCount ++;

    myCountBSTsVersion1(pRoot -> pLChild);
    myCountBSTsVersion1(pRoot -> pRChild);

    return iCount;

}
template<typename T>
int Tree<T>::CountBSTsVersion1()
{
    return myCountBSTsVersion1(pRoot);
}

template<typename T>
int Tree<T>::myCountBSTsVersion2(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    if(NULL == pRoot)
        return 0;

    return myCountBSTsVersion2(pTemp -> pLChild) + myCountBSTsVersion2(pTemp -> pRChild) + 1 ;
}
template<typename T>
int Tree<T>::CountBSTsVersion2()
{
    return myCountBSTsVersion2(pRoot);
}

template<typename T>
int Tree<T>::myCountLeafBSTs(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    if(pTemp -> pLChild == NULL && pTemp -> pRChild == NULL)
        iCount++;

    myCountLeafBSTs(pTemp -> pLChild);
    myCountLeafBSTs(pTemp -> pRChild);

    return iCount;
}
template<typename T>
int Tree<T>::CountLeafBSTs()
{
    return myCountLeafBSTs(pRoot);
}

template<typename T>
int Tree<T>::myCountNonLeafBSTs(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    if(pTemp -> pLChild != NULL || pTemp -> pRChild != NULL)
        iCount++;

    myCountNonLeafBSTs(pTemp -> pLChild);
    myCountNonLeafBSTs(pTemp -> pRChild);

    return iCount;
}
template<typename T>
int Tree<T>::CountNonLeafBSTs()
{
    return myCountNonLeafBSTs(pRoot);
}

template<typename T>
int Tree<T>::myHeight(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    int iLeftHeight;
    int iRightHeight;

    if(NULL == pRoot)
        return 0;

    iLeftHeight = myHeight(pTemp -> pLChild);
    iRightHeight = myHeight(pTemp -> pRChild);

    if(iLeftHeight > iRightHeight)
        return iLeftHeight + 1;
    else
        return iRightHeight + 1;
}
template<typename T>
int Tree<T>::Height()
{
    return myHeight(pRoot);
}

template<typename T>
T Tree<T>::mySmallestElement(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    if(NULL == pRoot)
        return 0;

    while(pTemp -> pLChild != NULL)
        pTemp = pTemp -> pLChild;

    return pTemp->iData;
}
template<typename T>
T Tree<T>::SmallestElement()
{
    return mySmallestElement(pRoot);
}

template<typename T>
T Tree<T>::myLargestElement(BST<T> *pRoot)
{
    BST<T> *pTemp = pRoot;

    if(NULL == pTemp)
        return 0;

    while(pTemp -> pRChild != NULL)
        pTemp = pTemp -> pRChild;

    return pTemp->iData;
}
template<typename T>
T Tree<T>::LargestElement()
{
    return myLargestElement(pRoot);
}

template<typename T>
bool Tree<T>::mySearchBSTRecursive(BST<T> *pRoot, T iKey)
{
    BST<T> *pTemp = pRoot;

    if(NULL == pTemp)
        return false;

    if(iKey < pTemp -> iData)
        return mySearchBSTRecursive(pTemp -> pLChild , iKey);
    else if(iKey > pRoot -> iData)
        return mySearchBSTRecursive(pTemp -> pRChild , iKey);
    else                                                        // mhanjech data found zala
        return true;
}
template<typename T>
bool Tree<T>::SearchBSTRecursive(T iKey)
{
    return mySearchBSTRecursive(pRoot,iKey);
}

template<typename T>
bool Tree<T>::mySearchBSTNonRecursive(BST<T> *pRoot, T iKey)
{
    BST<T> *pTemp = pRoot;

    while(pTemp != NULL)
    {
        if(iKey < pTemp -> iData)
            pTemp = pTemp -> pLChild;
        else if(iKey > pTemp -> iData)
            pTemp = pTemp -> pRChild;
        else 
            return true;
    }

    return false;
}
template<typename T>
bool Tree<T>::SearchBSTNonRecursive(T iKey)
{
    return mySearchBSTNonRecursive(pRoot,iKey);
}

template<typename T>
void Tree<T>::InsertBST(T iNo)
{
    BST<T> *pNewBST = NULL;
    BST<T> *pPtr = NULL;
    BST<T> *pParent = NULL;

    pPtr = pRoot;
    while(pPtr != NULL)
    {
        pParent = pPtr;
        if(iNo < pPtr -> iData)
            pPtr = pPtr -> pLChild;
        else if(iNo > pPtr -> iData)
            pPtr = pPtr -> pRChild;
        else
        {
            cout << "\nDuplicate data\n";
            return;
        }
    }

    // khali alyas pParent NULL ch ahe

    pNewBST = new BST<T>;
    if(NULL == pNewBST)
    {
        cout << "Memory allocation FAILED\n";
        return;
    }

    pNewBST -> iData = iNo;
    pNewBST -> pLChild = pNewBST -> pRChild = NULL;

    if(NULL == pParent)
        pRoot = pNewBST;
    else if(iNo < pParent -> iData)
        pParent -> pLChild = pNewBST;
    else
        pParent -> pRChild = pNewBST;
}

template<typename T>
void Tree<T>::DeleteBST(T iKey)
{
    BST<T> *pPtr = NULL;
    BST<T> *pParent = NULL;
    BST<T> *pSuccessor = NULL;
    BST<T> *pChild = NULL;

    pPtr = pRoot;
    while(pPtr != NULL)
    {
        if(iKey == pPtr -> iData)
            break;

        pParent = pPtr;

        if(iKey < pPtr -> iData)
            pPtr = pPtr -> pLChild;
        else
            pPtr = pPtr -> pRChild;
    }

    // pParent is NULL if Data not Found at root

    if(pPtr -> pLChild != NULL && pPtr -> pRChild != NULL)      // both childs
    {
        pSuccessor = pPtr -> pRChild;
        pParent = pPtr;

        while(pSuccessor -> pLChild != NULL)
        {
            pParent = pSuccessor;
            pSuccessor = pSuccessor -> pLChild;
        }

        pPtr -> iData = pSuccessor -> iData;
        pPtr = pSuccessor;
    }

    if(pPtr -> pLChild != NULL)
        pChild = pPtr -> pLChild;
    else
        pChild = pPtr -> pRChild;

    if(NULL == pParent)
        pRoot = pChild;
    else if(iKey < pParent -> iData)
        pParent -> pLChild = pChild;
    else
        pParent -> pRChild = pChild;

    delete pPtr;
}


template<typename T>
node<T>::node()
{
    iData = NULL;
    pNext = NULL;
}
template<typename T>
node<T>::~node()
{
    iData = NULL;
    pNext = NULL;
}

template<typename T>
queue<T>::queue()
{
    pPtr = NULL;
}
template<typename T>
queue<T>::~queue()
{
    pPtr = NULL;
}

template<typename T>
void queue<T>::EnQueue(BST<T> *pRoot)
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

    pNewNode -> iData = pRoot ;
    pNewNode -> pNext = NULL;

    if(pPtr == NULL)
    {
        pPtr = pNewNode;
        return;
    }

    pTemp = pPtr;
    while(pTemp -> pNext != NULL)
        pTemp = pTemp -> pNext;

    pTemp -> pNext = pNewNode;
}

template<typename T>
BST<T>* queue<T>::DeQueue()
{
    BST<T> *DelData = NULL ;
    node<T> *pTemp = NULL;

    if(IsQueueEmpty())
    {
        cout << "\nQueue is Empty\n";
        return NULL;
    }

    pTemp = pPtr;
    pPtr = pTemp -> pNext;

    DelData = pTemp -> iData;
    pTemp -> pNext = NULL;
    delete pTemp;

    return DelData ;
}

template<typename T>
bool queue<T>::IsQueueFull()
{
    if(CountNodes() == MAX)
        return true;
    return false;
}

template<typename T>
bool queue<T>::IsQueueEmpty()
{
    if(NULL == pPtr)
        return true;
    return false;
}

template<typename T>
int queue<T>::CountNodes()
{
    node<T>* pTemp = pPtr;
    int iCount = 0;

    while(pTemp != NULL)
    {
        iCount++;
        pTemp = pTemp -> pNext;
    }

    return iCount;
}


int main(void)
{
    Tree<char> obj1;
    bool bRet;                 

    obj1.InsertBST('P');
    obj1.InsertBST('Z');
    obj1.InsertBST('C');
    obj1.InsertBST('X');
    obj1.InsertBST('D');
    obj1.InsertBST('A');
    obj1.InsertBST('Q');
    obj1.InsertBST('J');

    obj1.Preorder();                                                            // P C A D J Z X Q
    cout << "\n\n";
    obj1.Inorder();                                                             // A C D J P Q X Z
    cout << "\n\n";
    obj1.Postorder();                                                           // A J D C Q X Z P
    cout << "\n\n";
    obj1.Levelorder();                                                          // P C Z A D X J Q
    cout << "\n\n";

    cout << "\nBST count is " << obj1.CountBSTsVersion1() << endl;              // 8
    cout << "\nBST count is " << obj1.CountBSTsVersion2() << endl;              // 8
    cout << "\nLeaf BST count is " << obj1.CountLeafBSTs() << endl;             // 3
    cout << "\nNonLeaf BST count is " << obj1.CountNonLeafBSTs() << endl;       // 5
    cout << "\nHeight of tree is " << obj1.Height() << endl;                    // 4
    cout << "\nSmallest element is " << obj1.SmallestElement() << endl;         // A
    cout << "\nLargest element is " << obj1.LargestElement() << endl;           // Z

    bRet = obj1.SearchBSTRecursive('Z');
    if(bRet == true)
        cout << "\nData Found\n";                                               // Data Found
    else 
        cout << "\nData Not Found\n";

    bRet = obj1.SearchBSTNonRecursive('A');
    if(bRet == true)
        cout << "\nData found\n\n";                                             // Data Found
    else 
        cout << "\nData Not Found\n\n";

    obj1.DeleteBST('J');                                                        // no childs
    obj1.Levelorder();                                                          // P C Z A D X Q
    cout << "\n\n";

    obj1.DeleteBST('X');                                                        // single child
    obj1.Levelorder();                                                          // P C Z A D Q
    cout << "\n\n";

    obj1.DeleteBST('P');                                                        // both childs
    obj1.Levelorder();                                                          // Q C Z A D
    cout << "\n\n";

    return 0;
}
