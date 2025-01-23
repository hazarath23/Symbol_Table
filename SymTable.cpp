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
void SymTable_init(struct symTable **oSymTable,const char *pcKey,void *pvValue)
{
    SymTable_t t = SymTable_new();
    t->k = pcKey;
    t->value =  pvValue;
    t->next=NULL;
    *oSymTable = t;
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
        cout<<oSymTable->k<<endl;exit(0);
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
void *SymTable_remove (struct symTable **oSymTable,const char *pcKey)
{
    struct symTable *gh = *oSymTable;
    if(strcmp(gh->k,pcKey)==0)
    {
        SymTable_t p = gh;
        void *val = p->value;
        if(gh->next!=NULL)
        *oSymTable=gh->next;
        else
        *oSymTable=NULL;
        free(p);
        return val;
    }
    else
    {
        while(gh!=NULL&&strcmp((gh->next)->k,pcKey)!=0)
        {
            gh=gh->next;
            if(gh->next==NULL)
            {
                return NULL;
            }
        }
        if(gh!=NULL&&strcmp((gh->next)->k,pcKey)==0)
        {
            SymTable_t p = gh->next;
            void* kr = p->value;
            if(p->next!=NULL)
            {
                gh->next = p->next;
            } 
            else
            {
                gh->next=NULL;
            }
            free(p);return kr;
        }
        return NULL;
    }
}
