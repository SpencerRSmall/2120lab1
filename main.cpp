#include "List.h"
#include "Node.h"

int main(){
    int num = 4;
    std::string hi= "hello";
    List<int> myList;

    std::cout << myList.empty();
    myList.insertStart(num);
    //std::cout << myList.empty();
    //myList.insertEnd(12);
    //myList.insertEnd(13);
    //myList.insertEnd(14);
    //myList.insertAt(7, 2);

    //num = myList.size();

   // myList.print(hi);

    myList.~List();





    

    return 0;
}