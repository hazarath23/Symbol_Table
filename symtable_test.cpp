#include <gtest/gtest.h>
#include "symtable.hpp"
using namespace std;
// For adding and Removing the elements
TEST(SymbolTableTest,addremove)
{
    SymTable_t headd = nullptr;
    int val1 = 10;
    float val2 = 20.5; 
    SymTable_put(headd,"intKey", static_cast<void*>(&val1));
    SymTable_put(headd,"floatKey", static_cast<void*>(&val2));
    int* intPtr = static_cast<int*>(SymTable_remove(headd,"int"));
    int result = *intPtr; 
    EXPECT_EQ(result, 10);
    //EXPECT_FLOAT_EQ(*static_cast<float*>(SymTable_get(headd,"floatKey")), 20.5);
    SymTable_free(headd);
}
//For checking the length of the symbol table
TEST(SymbolTableTest,Length)
{
    SymTable_t h = NULL;
    int val1 = 10;
    float val2 = 20.5; 
    SymTable_put(h,"int", static_cast<void*>(&val1));
    SymTable_put(h,"float", static_cast<void*>(&val2));
    EXPECT_EQ(SymTable_getLength(h),2);
    SymTable_free(h);
}
//For checking whether the key is in table or not
TEST(SymbolTableTest,Contains)
{
    SymTable_t h = NULL;
    int val1 = 10;
    float val2 = 20.5;
    SymTable_put(h,"int", static_cast<void*>(&val1));
    SymTable_put(h,"float", static_cast<void*>(&val2));
    EXPECT_TRUE(1==SymTable_contains(h,"char"));
    EXPECT_FALSE(1==SymTable_contains(h,"bool"));
    SymTable_free(h);
}
//For checking the replace function
TEST(SymbolTableTest,Replace)
{
    SymTable_t h = NULL;
    int val1 = 10;
    float val2 = 20.5; int val3 = 32;
    SymTable_put(h,"int", static_cast<void*>(&val1));
    SymTable_put(h,"float", static_cast<void*>(&val2));
    int* intPtr = static_cast<int*>(SymTable_replace(h,"int",static_cast<void*>(&val3)));
    int result = *intPtr; 
    EXPECT_EQ(result,10);
    SymTable_free(h);
}
//For fetching the elements according to the keys
TEST(SymbolTableTest,Get)
{
    SymTable_t h = NULL;
    int val1 = 10;
    float val2 = 20.5;
    SymTable_put(h,"int", static_cast<void*>(&val1));
    SymTable_put(h,"float", static_cast<void*>(&val2));
    int* intPtr = static_cast<int*>(SymTable_get(h,"int"));
    int result = *intPtr; 
    EXPECT_EQ(result,10);
    SymTable_free(h);
}

