#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "week1main.h"
struct student * create(void){
	struct student *p1,*p2,*head;
	p1=p2=(struct student*)malloc(sizeof(struct student));
	scanf("%ld",&p1->num);
	head=NULL;
	    for(int i=0;p1->num!=0;i++){/*如果输入0，停止输入(停止创建链表)*/ 
        if(head==NULL)
            head=p1;
        else
            p2->next=p1;
        p2=p1;
p1=(struct student *)malloc(sizeof(struct student));
		scanf("%ld",&p1->num);			
	}
	p2->next=NULL;
	return(head);
}

struct student * NewNode(int data){                           //创建新的结点
    struct student * NewNode = (struct student *)malloc(sizeof(struct student));
    NewNode ->num = data;
    NewNode ->next = NULL;
    return NewNode;
}

void print(struct student *head){
	struct student *p;
	p=head;
	if(head!=NULL)
	do{
		printf("%ld ",p->num);
		p=p->next;
	}while(p!=NULL);
	printf("\n");
}

struct student* insert(struct student* ahead,struct student *s,int posData){
    struct student *p=ahead;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
     if(posData+1>len+1&&len!=0){//超出长度
        printf("插入失败!");
        printf("\n"); 
        return ahead;
    }
    if(len==0){
    	ahead=NewNode(s->num);
		return ahead;
	}
    p=ahead;
    int tag=1;
        while(tag!=posData){
            p=p->next;
            tag++;
        }
    struct student *q;
        if(p==ahead){
            s->next=ahead;
            ahead=s;
        }else{
            q=ahead;
            while(q->next!=p){
                q=q->next;
            }
            q->next=s;
            s->next=p;
        }
        return ahead;
}

struct student* Delete(struct student* ahead,int k){
    struct student* p=ahead;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
     if(k+1>len+1||k+1<=0){//超出长度
        printf("删除失败!");
        printf("\n"); 
        return ahead;
    }
    p=ahead;
	if(k==1){  //如果要删除的是头节点
    ahead=p->next;
      free(p); 
      return ahead;
    }
	int i;  
    for (i=1; i<k-1; i++) {
        p=p->next;
    }
    struct student* q=p->next;
    p->next=p->next->next;
    free(q);
    return ahead;
}

struct student* findvalue(struct student*ahead,long e){
    struct student *p; int j=1;
    p=ahead;
    int len=0;
    while(p!=NULL){
    	len++;
        if(p->num==e){
            printf("找到了，位置是%d\n",j);
            return p;
        }
        p=p->next;
        j++;
    }
    
    if(j>=len){
    printf("并没有找到%ld",e);
    return ahead;
    }
}

void changevalue(struct student* ahead,int n,long changeData){
	struct student *p=ahead;
    for(int i=0;i<n-1;i++){
        p=p->next;
        if(p==NULL){
            printf("没有找到该数据.\n");
            return;
        }
    }
    p->num=changeData;
}

void destroy(struct student* ahead){
    struct student* curNode = ahead;
    while (curNode){
        ahead = curNode->next;
        free(curNode);
        curNode = ahead;
    }
}

int main(){
	struct student *ahead;
    int choice;
    while (1) {
        printf("1. 创建链表\n");
        printf("2. 销毁链表\n");
        printf("3. 插入结点\n");
        printf("4. 删除结点\n");
        printf("5. 修改链表\n");
        printf("6. 查找数据\n");
        printf("7. 退出\n");
        printf("请选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("input list a:\n");
			ahead=create();
			print(ahead);
			system("pause"); 
        	system("cls");
            break;
        case 2:
            destroy(ahead);
            printf("链表已销毁\n");
            system("pause"); 
        	system("cls");
            break;
        case 3:
            printf("请输入要插入的位置和元素:");
			int posData,num;
			scanf("%d,%ld",&posData,&num);
		    struct student* s=(struct student *)malloc(sizeof(struct student));
		    s->num =num;
		    ahead=insert(ahead,s,posData);
    		print(ahead);
    		system("pause"); 
        	system("cls");
            break;
        case 4:
            printf("请输入要删除的节点:");
			int k;
			scanf("%d",&k);
		    ahead=Delete(ahead,k);
		    print(ahead);
		    system("pause"); 
        	system("cls");
            break;
        case 5:
            printf("请输入要修改数据的位置和新值:");
			int n;long changeData; 
			scanf("%d,%ld",&n,&changeData);
		    changevalue(ahead,n,changeData);
		    print(ahead);
		    system("pause"); 
        	system("cls");
            break;
        case 6:
            printf("请输入要查找的值");
			long e;
			scanf("%ld",&e);
			struct student *p;
			p=findvalue(ahead,e);
			system("pause"); 
        	system("cls");
            break;
        case 7:
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
