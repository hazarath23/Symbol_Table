#include<iostream>
#include "symtable.hpp"
using namespace std;
int main()
{ 
    string typ = "int";
    string typ2 = "char";
    SymTable_t head = NULL;
    int y = 190;
    int z = 165;
    void* ptr = static_cast<void*>(&y);
    void* ptr1 = static_cast<void*>(&z);
    SymTable_init(&head,typ.c_str(),ptr);
    int g2=SymTable_put(head,typ2.c_str(),ptr1);
    int* intPtr = static_cast<int*>(SymTable_replace(head,const_cast<char*>("int"),ptr1));
    int result = *intPtr; 
    cout<<result<<endl;
    int* intPtr1 = static_cast<int*>(SymTable_remove(&head,"int"));
    int result1 = *intPtr1; 
    cout<<result1<<endl;
    SymTable_free(head);
    return 0;
}
