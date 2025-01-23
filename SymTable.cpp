#include<string.h>
#include<iostream>
#include "symtable.hpp"
using namespace std; 
SymTable_t SymTable_new ()
{
    SymTable_t p = (SymTable_t)malloc(sizeof(struct symTable));
    p->k="Most Wanted!";p->value=NULL;
    p->next=NULL;
    return p;
}
void SymTable_free (SymTable_t oSymTable)
{
    SymTable_t p;
    while(oSymTable!=NULL)
    {
        p=oSymTable;
        oSymTable=oSymTable->next;
        free(p);
    }
}
int SymTable_getLength (SymTable_t oSymTable)
{
    int len=0;
    while(oSymTable!=NULL)
    {
        len+=1;
        oSymTable=oSymTable->next;
    }
    return len;
}
int SymTable_contains (SymTable_t oSymTable,const char *pcKey)
{
    while(oSymTable!=NULL)
    {
        if(strcmp(oSymTable->k,pcKey)==0)
        return 1;
        oSymTable=oSymTable->next;
    }
    return 0;
}
int SymTable_put (SymTable_t oSymTable,const char *pcKey,void *pvValue)
{
    SymTable_t t = SymTable_new();
    if(oSymTable==NULL)
    {
        t->k = pcKey;
        t->value =  pvValue;
        t->next=NULL;
        oSymTable = t;
        return 1;
    }
    else
    {
        int flag = 0;SymTable_t f = oSymTable;
        while(f!=NULL)
        {
            if(strcmp(f->k,pcKey)==0)
            {
            flag = 1; 
            break;
            }
            f=f->next;
        }
        if(flag==1)
        {
            return 0;
        }
        else
        {
            t->k = pcKey;
            t->value =  pvValue;
            t->next=NULL;SymTable_t f = oSymTable;
            while(f->next!=NULL)
            {
                f = f->next;
            }
            f->next = t;
            return 1;
        }
    }
}
void *SymTable_replace (SymTable_t oSymTable,const char *pcKey,void *pvValue)
{
    while(oSymTable!=NULL)
    {
        if(strcmp(oSymTable->k,pcKey)==0)
        {
            void* f = oSymTable->value;
            oSymTable->value=pvValue;
            return f;
        }
        oSymTable=oSymTable->next;
    }
    return NULL;
}
void *SymTable_get (SymTable_t oSymTable, const char *pcKey)
{
    while(oSymTable!=NULL)
    {
        if(strcmp(oSymTable->k,pcKey)==0)
        {
            return oSymTable->value;
        }
        oSymTable=oSymTable->next;
    }
    return NULL;
}
void *SymTable_remove (SymTable_t oSymTable,const char *pcKey)
{
    if(strcmp(oSymTable->k,pcKey)==0)
    {
        SymTable_t p = oSymTable;
        void *val = p->value;
        if(oSymTable->next!=NULL)
        oSymTable=oSymTable->next;
        else
        oSymTable=NULL;
        free(p);
        return val;
    }
    else
    {
        while(oSymTable!=NULL&&strcmp((oSymTable->next)->k,pcKey)!=0)
        {
            oSymTable=oSymTable->next;
            if(oSymTable->next==NULL)
            {
                return NULL;
            }
        }
        if(oSymTable!=NULL&&strcmp((oSymTable->next)->k,pcKey)==0)
        {
            SymTable_t p = oSymTable->next;
            void* kr = p->value;
            if(p!=NULL)
            {
                oSymTable->next = p->next;
            } 
            else
            {
                oSymTable->next=NULL;
            }
            free(p);return kr;
        }
        return NULL;
    }
}