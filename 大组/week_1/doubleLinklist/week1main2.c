#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "week1main2.h"

pNode creat(int n){  //创建链表
    int i;
    pNode h,p,r;
    h=r=(pNode)malloc(sizeof(Node));//其中h是头指针，r是尾指针
    if(h==NULL)    //内存分配失败
        exit(-1);
    h->prior=h->next=NULL;  //将头节点的两个指针域都指向NULL
    printf("输入数据：");
    for(i=0; i<n; i++){
        p=(pNode)malloc(sizeof(Node));
        if(h==NULL)      //内存分配失败
            exit(-1);
        scanf("%d",&p->data);
        p->next=NULL;
        r->next=p;
        p->prior=r;
        r=r->next;
    }
    return h;
}

void output(pNode h){   //打印链表
    pNode p=h->next;
    printf("打印链表：");
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int empty(pNode h)    //判断链表是否为空
{
    pNode p=h->next;
    if(p==NULL)
        return 1;
    else
        return 0;
}

int length(pNode h){    //返回链表长度
    int length=0;
    pNode p=h->next;
    while(p){
        length++;
        p=p->next;
    }
    return length;
}

void Insert(pNode h,int i,int data){ //插入 1<=i<=length+1
    pNode p,r;
    p=r=h;
    int j=0;
    if(i==length(h)+1){ //当插入的位置为length+1时
        pNode q=(pNode)malloc(sizeof(Node));
        q->data=data;
        q->next=NULL;
        while(r->next) //找到链表尾结点
            r=r->next;
        r->next=q;
        q->prior=r;
    }
    else{
        while(p&&(j<i)){  //找到第i个结点的
            p=p->next;
            j++;
        }
        if(!p||(j>i)) 
            exit(-1);
        pNode q=(pNode)malloc(sizeof(Node));
        q->data=data;
        //插入的核心步骤
        q->prior=p->prior;
        p->prior->next=q;
        q->next=p;
        p->prior=q;
    }
}

void Delete(pNode h,int i){  //删除
    pNode p=h;
    int j=0;
    while(p&&(j<i)){  //找到删除结点
        p=p->next;
        j++;
    }
    if(p->next==NULL)
        p->prior->next=NULL;
    else{
        p->prior->next=p->next;
        p->next->prior=p->prior;
    }
    free(p);
}


void DestoryList(pNode h){
    pNode temp;
    while(h->next !=NULL){
    	temp=h;
    	h=h->next;
    	free(temp);
	}
	free(h);
}

int main(){
	int n,i,data;
	pNode head;
	int choice;
    while (1) {
        printf("1. 创建链表\n");
        printf("2. 销毁链表\n");
        printf("3. 插入结点\n");
        printf("4. 删除结点\n");
        printf("5. 退出\n");
        printf("请选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("输入输入数据个数");
			scanf("%d",&n);
			head=creat(n);
			output(head);
			system("pause"); 
        	system("cls");
            break;
        case 2:
            DestoryList(head);
            printf("链表已销毁\n");
            system("pause"); 
        	system("cls");
            break;
        case 3:
            printf("\n输入插入 位置i 和 数据data :\n");
			scanf("%d",&i);
			scanf("%d",&data);
			Insert(head,i,data);
			output(head);
			system("pause"); 
        	system("cls");
            break;
        case 4:
            printf("\n要删除第几个数据");
			scanf("%d",&i);
			Delete(head,i);
			output(head);
			system("pause"); 
        	system("cls");
            break;
        case 5:
	        system("pause"); 
	        system("cls");
	        break;
        default:
            printf("无效的选择\n");
            system("pause"); 
        	system("cls");
        }
    }
    return 0;
}
