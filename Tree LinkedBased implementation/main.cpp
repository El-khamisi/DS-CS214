#include "tree.h"



void print(TreeEntry e)
{
    cout<<e<<"\t";
}
int main() {


    Tree T;
    TreeEntry E;
    initTree(&T);


    E=4;
    InsertTree(&T,&E);
    E=1;
    InsertTree(&T,&E);
    E=3;
    InsertTree(&T,&E);
    E=5;
    InsertTree(&T,&E);




    inOrder(&T,print);

    if (find(&T,&E, 3))
        cout<<"the item is "<<E<<endl;
    else
        cout<<"Not find the elemnt ";
    if (find(&T,&E, 2))
        cout<<"the item is "<<E<<endl;
    else
        cout<<"Not find the elemnt ";

    if (DeleteTree(&T,&E,5))
        cout<<endl<<" The Deleted is "<<E<<endl;

cout<< " the whole tree is ";inOrder(&T,print);cout<<endl;




    clearTree(&T);
    inOrder(&T,print);

 cout<<treeSize(&T);




    return 0;
}
