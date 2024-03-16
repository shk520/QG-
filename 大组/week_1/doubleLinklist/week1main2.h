#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node *prior;
    struct Node *next;
}Node,*pNode;    //这里 pNode 等价于 Node* 是指向结点的指针

pNode creat(int n);

void output(pNode h);

void Insert(pNode h,int i,int data);

void Delete(pNode h,int i);

void DestoryList(pNode h);

#endif
