#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node *prior;
    struct Node *next;
}Node,*pNode;    //���� pNode �ȼ��� Node* ��ָ�����ָ��

pNode creat(int n);

void output(pNode h);

void Insert(pNode h,int i,int data);

void Delete(pNode h,int i);

void DestoryList(pNode h);

#endif
