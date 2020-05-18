#include "list.h"



using namespace std;

void print(listEntry e)
{
    cout<<e<<"\t";
}
int main() {


    List ls;
    listEntry E = 0;
    initlist(&ls);

    if (!listFull(&ls))
        Insert(0, 10, &ls);
    if (!listFull(&ls))
        Insert(1, 20, &ls);
    if (!listFull(&ls))
        Insert(2, 30, &ls);
    if (!listFull(&ls))
        Insert(3, 40, &ls);

    cout<<"The "<<listSize(&ls); cout<<" Elements You was Inserted ";Traverslist(&ls, print);cout<<endl;


    if (!listEmpty(&ls))
        Delete(2, &E, &ls);
    cout<<"THE Element was Deleted is "<<E<<endl;

    Replacelist(1,100, &ls);
    cout<<"The list After Editing\t";Traverslist(&ls, print);cout<<endl;















    return 0;
}
