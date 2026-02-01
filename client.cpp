#include"server.h"

int main(void)
{
    char iDelData;
    queue<char> obj;

    obj.EnQueue('A');
    obj.EnQueue('B');
    obj.EnQueue('C');
    obj.EnQueue('D');

    obj.Display();                  //  A B C D          

    iDelData = obj.DeQueue();
    if(iDelData != -1)
        cout << "\ndeleted data is " << iDelData << endl;       //  deleted data is A      

    obj.EnQueue('E');

    obj.Display();                  //   B C D E      

    return 0;
}
