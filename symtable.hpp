#include<iostream>
#include<string.h>
using namespace std;
struct symTable
{
    const char *k;
    void* value;
    struct symTable* next;
};
typedef struct symTable* SymTable_t;
SymTable_t SymTable_new (void);
void SymTable_free (SymTable_t oSymTable);
int SymTable_getLength (SymTable_t oSymTable);
int SymTable_contains (SymTable_t oSymTable,const char *pcKey);
int SymTable_put (SymTable_t oSymTable,const char *pcKey,void *pvValue);
void *SymTable_replace (SymTable_t oSymTable,const char *pcKey,void *pvValue);
void *SymTable_get (SymTable_t oSymTable, const char *pcKey);
void *SymTable_remove (SymTable_t oSymTable,const char *pcKey);
