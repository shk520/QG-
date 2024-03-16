#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "week1main2.h"

pNode creat(int n){  //��������
    int i;
    pNode h,p,r;
    h=r=(pNode)malloc(sizeof(Node));//����h��ͷָ�룬r��βָ��
    if(h==NULL)    //�ڴ����ʧ��
        exit(-1);
    h->prior=h->next=NULL;  //��ͷ�ڵ������ָ����ָ��NULL
    printf("�������ݣ�");
    for(i=0; i<n; i++){
        p=(pNode)malloc(sizeof(Node));
        if(h==NULL)      //�ڴ����ʧ��
            exit(-1);
        scanf("%d",&p->data);
        p->next=NULL;
        r->next=p;
        p->prior=r;
        r=r->next;
    }
    return h;
}

void output(pNode h){   //��ӡ����
    pNode p=h->next;
    printf("��ӡ����");
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int empty(pNode h)    //�ж������Ƿ�Ϊ��
{
    pNode p=h->next;
    if(p==NULL)
        return 1;
    else
        return 0;
}

int length(pNode h){    //����������
    int length=0;
    pNode p=h->next;
    while(p){
        length++;
        p=p->next;
    }
    return length;
}

void Insert(pNode h,int i,int data){ //���� 1<=i<=length+1
    pNode p,r;
    p=r=h;
    int j=0;
    if(i==length(h)+1){ //�������λ��Ϊlength+1ʱ
        pNode q=(pNode)malloc(sizeof(Node));
        q->data=data;
        q->next=NULL;
        while(r->next) //�ҵ�����β���
            r=r->next;
        r->next=q;
        q->prior=r;
    }
    else{
        while(p&&(j<i)){  //�ҵ���i������
            p=p->next;
            j++;
        }
        if(!p||(j>i)) 
            exit(-1);
        pNode q=(pNode)malloc(sizeof(Node));
        q->data=data;
        //����ĺ��Ĳ���
        q->prior=p->prior;
        p->prior->next=q;
        q->next=p;
        p->prior=q;
    }
}

void Delete(pNode h,int i){  //ɾ��
    pNode p=h;
    int j=0;
    while(p&&(j<i)){  //�ҵ�ɾ�����
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
        printf("1. ��������\n");
        printf("2. ��������\n");
        printf("3. ������\n");
        printf("4. ɾ�����\n");
        printf("5. �˳�\n");
        printf("��ѡ��");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("�����������ݸ���");
			scanf("%d",&n);
			head=creat(n);
			output(head);
			system("pause"); 
        	system("cls");
            break;
        case 2:
            DestoryList(head);
            printf("����������\n");
            system("pause"); 
        	system("cls");
            break;
        case 3:
            printf("\n������� λ��i �� ����data :\n");
			scanf("%d",&i);
			scanf("%d",&data);
			Insert(head,i,data);
			output(head);
			system("pause"); 
        	system("cls");
            break;
        case 4:
            printf("\nҪɾ���ڼ�������");
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
            printf("��Ч��ѡ��\n");
            system("pause"); 
        	system("cls");
        }
    }
    return 0;
}
