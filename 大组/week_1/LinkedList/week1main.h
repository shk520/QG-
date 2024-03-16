#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct student{
	long num;
	struct student* next;
};

struct student lista,listb;

struct student * create(void);

struct student * NewNode(int data);

void print(struct student *head);

struct student* insert(struct student* ahead,struct student *s,int posData);

struct student* Delete(struct student* ahead,int k);

struct student* findvalue(struct student*ahead,long e);

void changevalue(struct student* ahead,int n,long changeData);

void destroy(struct student* ahead);


#endif
