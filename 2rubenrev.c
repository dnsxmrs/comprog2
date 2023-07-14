#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
    int x;
    struct node *next, *prev;
};
struct node *head, *curr, *tail, *add, *temp;

void menu();
int func1(struct node *curr);
int func2(struct node *curr,int sel);
int func3(struct node *curr,int sel,int *sort);
int func4(struct node *curr,int *sort);
int func5(struct node *curr,int sel,int *sort);
int func6(struct node *curr,int sel,int *sort);

int main(){
    int *sort=0;
    int sel;
    head=curr=tail=add=NULL;
    MENU:
    system("CLS");
    menu();
    printf("Enter a number to perform the action: ");
    scanf("%d",&sel);
    switch (sel){
    case 1:
        system("CLS");
        func1(curr);
        break;
    case 2:
        system("CLS");
        if(head==NULL&&curr==NULL&&tail==NULL){
        printf("\"NO LINKED LIST HAS BEEN CREATED RETURNING TO MENU\"");getch();goto MENU;}
        else
            func2(curr,sel);
        break;
    case 3:
        system("CLS");
        if(head==NULL&&curr==NULL&&tail==NULL){
        printf("\"NO LINKED LIST HAS BEEN CREATED RETURNING TO MENU\"");getch();goto MENU;}
        func3(curr,sel,&sort);
        break;
    case 4:
        system("CLS");
        if(head==NULL&&curr==NULL&&tail==NULL){
        printf("\"NO LINKED LIST HAS BEEN CREATED RETURNING TO MENU\"");getch();goto MENU;}
        func4(curr,&sort);
        break;
    case 5:
        system("CLS");
        if(head==NULL&&curr==NULL&&tail==NULL){
        printf("\"NO LINKED LIST HAS BEEN CREATED RETURNING TO MENU\"");getch();goto MENU;}
        func5(curr,sel,&sort);
        break;
    case 6:
        system("CLS");
        if(head==NULL&&curr==NULL&&tail==NULL){
        printf("\"NO LINKED LIST HAS BEEN CREATED RETURNING TO MENU\"");getch();goto MENU;}
        func6(curr,sel,&sort);
        break;
    case 7:
        goto END;
        break;
    default:
        system("CLS");
        printf("\"You have inputted a invalid value\"\nPress \"1\" to return to menu, press \"0\" to fully exit the program\n ");
        scanf("%d",&sel);
        if(sel==1){
        goto MENU;
    }
        else{
        goto END;
        }
        break;
    }
    
    printf("\n\npress \"1\" to return to menu press \"0\" to exit program\n\n");
    scanf("%d",&sel);
    if(sel==1){
        goto MENU;
    }
    else{
        END:
        printf("\"PROGRAM EXITED\"");
    }
}


int func1(struct node *curr){
    curr = (struct node *)malloc(sizeof(struct node));
    printf("------Create a Doubly Linked List-----\n\nEnter linked list value: ");
    scanf("%d",&curr->x);
    while(curr->x!=0){
        if(head==NULL){
            head = curr;
            head->prev = NULL;
            head->next = NULL;
            tail = curr;
        }
        else{
            tail->next=curr;
            curr->prev=tail;
            curr->next=NULL;
            tail=curr;
        }
    curr = (struct node *) malloc(sizeof(struct node));
    printf("Enter linked list value: ");
    scanf("%d",&curr->x);
    }
}

int func2(struct node *curr,int sel){
    printf("-----------PRINTING LINKED LIST-----------\n\nMETHODS:\n\n[1]. NORMAL ORDER\n\n[2]. REVERSE ORDER\n\n\nSelect method: ");
    scanf("%d",&sel);
    
    switch (sel){
    case 1:
        printf("\n-------PRINTING IN NORMAL ORDER-------\n\n");
        curr=head;
        while(curr!=NULL){
            printf("%5d",curr->x);
            curr=curr->next;
        }
        printf("\n");
        break;
    case 2:
        printf("\n-------PRINTING IN REVERSE ORDER-------\n\n");
        curr=tail;
        while(curr!=NULL){
            printf("%5d",curr->x);
            curr=curr->prev;
        }
        printf("\n");
        break;
    default:
        break;
    }
}

int func3(struct node *curr,int sel,int *sort){
    int temp;
    int counter;
    printf("------SORTING DOUBLY LINKED LIST------\n\nMETHOD:\n\n[1]. ASCENDING ORDER\n\n[2]. DESCENDING ORDER\n\n\nSelect method: ");
    scanf("%d",&sel);
    switch (sel){
    case 1:
        do{
        counter=0;
        for(curr=head;curr->next!=NULL;curr=curr->next){
        if(curr->x > curr->next->x){
            temp=curr->x;
            curr->x=curr->next->x;
            curr->next->x=temp;
            counter=1;
        }
        }
        }while(counter);
        *sort=1;
        break;
    case 2:
        do{
        counter=0;
        for(curr=head;curr->next!=NULL;curr=curr->next){
        if(curr->x < curr->next->x){
            temp=curr->x;
            curr->x=curr->next->x;
            curr->next->x=temp;
            counter=1;
        }
        }
        }while(counter);
        *sort=2;
        break;
    default:
        break;
    }
    printf("\n\n-------|| \"LIST SORTED\" ||-------");
    return &sort;
}

int func4(struct node *curr,int *sort){
temp=NULL;
    switch (*sort){
    case 0:
        printf("|| \"PLEASE SORT THE LIST BEFORE ADDING ANOTHER NODE\" ||");
        break;
    case 1:
    add = (struct node *) malloc(sizeof(struct node));
    printf("\n\n-------|| INSERT A NODE ||-------\n\nEnter linked list value: ");
    scanf("%d",&add->x);
    if(head->x<add->x&&tail->x>add->x){// ascending sort
        curr=head;
        while(curr->x < add->x || curr->x == add->x){
            curr=curr->next;
        }
        temp=curr->prev;
        temp->next=add; //
        add->prev=temp; //
        curr->prev=add; //
        add->next=curr; //
    }
    if(add->x<head->x||add->x==head->x){
        curr=head;
        curr->prev=add;
        add->next=curr;
        add->prev=NULL;
        head=add;
    }
    if(add->x>tail->x||add->x==tail->x){
        curr=tail;
        curr->next=add;
        add->prev=curr;
        add->next=NULL;
        tail=add;
    }
        break;
    case 2:
    add = (struct node *) malloc(sizeof(struct node));
    printf("\n\n-------|| INSERT A NODE ||-------\n\nEnter linked list value: ");
    scanf("%d",&add->x);
    if(head->x>add->x&&tail->x<add->x){
        curr=head;
        while(curr->x>add->x||curr->x==add->x){
            curr=curr->next;
        }
        temp=curr->prev;
        temp->next=add;
        add->prev=temp;
        curr->prev=add;
        add->next=curr;
    }
    if(add->x>head->x||add->x==head->x){
        curr=head;
        curr->prev=add;
        add->next=curr;
        add->prev=NULL;
        head=add;
    }
    if(add->x<tail->x||add->x==tail->x){
        curr=tail;
        curr->next=add;
        add->prev=curr;
        add->next=NULL;
        tail=add;
    }
        break;
    default:
        break;
    }
}

int func5(struct node *curr,int sel,int *sort){
temp=NULL;
switch (*sort){
    case 0:
        printf("|| \"PLEASE SORT THE LIST BEFORE DELETING A NODE\" ||");
        break;
    case 1:
    printf("-------|| DELETE A NODE ||-------\n\nSelect node value to remove: ");
    scanf("%d",&sel);
    if(head->x<sel&&tail->x>sel){
    curr=head;
    while(curr->x!=sel){
        curr=curr->next;
    }
    temp=curr->prev;
    curr=curr->next;
    temp->next=curr;
    curr->prev=temp;
    }
    if(sel==head->x){
        curr=head;
        curr=curr->next;
        curr->prev=NULL;
        head=curr;
    }
    if(sel==tail->x){
        curr=tail;
        curr=curr->prev;
        curr->next=NULL;
        tail=curr;
    }
        break;
    case 2:
    printf("-------|| DELETE A NODE ||-------\n\nSelect node value to remove: ");
    scanf("%d",&sel);
    if(head->x>sel&&tail->x<sel){
    curr=head;
    while(curr->x!=sel){
        curr=curr->next;
    }
    temp=curr->prev;
    curr=curr->next;
    temp->next=curr;
    curr->prev=temp;
    }
    if(sel==head->x){
        curr=head;
        curr=curr->next;
        curr->prev=NULL;
        head=curr;
    }
    if(sel==tail->x){
        curr=tail;
        curr=curr->prev;
        curr->next=NULL;
        tail=curr;
    }
        break;
    default:
        break;
    }
}

int func6(struct node *curr,int sel,int *sort){
    int rep;
    int loc;
switch (*sort){
    case 0:
    printf("|| \"PLEASE SORT THE LIST BEFORE SEARCHING FOR A NODE VALUE\" ||");
        break;
    case 1:
    res1:
    printf("-------|| LINKED LIST VALUE SEARCHER ||-------\n\nInput value to search: ");
    scanf("%d",&sel);
    loc=0;
    curr=head;
    while(curr!=NULL){
    if(sel<head->x||sel>tail->x||curr==NULL){
        printf("%d is not in the list",sel);
        goto ex;
    }
    else if(curr->x==sel){
        printf("%d is in the list. It is in node number/s ",sel);
        curr=head;
        while(curr!=NULL){
        loc=loc+100;
        if(curr->x==sel){
        printf("%5d",loc);
        }
        curr=curr->next;
        }
        goto SET;
    }
    curr=curr->next;
    }
    ex:
    SET:
    printf("\n\nIf you want to search another number (press 1): ");
    scanf("%d",&rep);
    if(rep==1){
    goto res1;
    }
    else
        break;
    case 2:
    res2:
    printf("-------|| LINKED LIST VALUE SEARCHER ||-------\n\nInput value to search: ");
    scanf("%d",&sel);
    loc=0;
    curr=head;
    while(curr!=NULL){
    if(sel>head->x||sel<tail->x||curr==NULL){
        printf("%d is not in the list",sel);
        goto ex1;
    }
    else if(curr->x==sel){
        printf("%d is in the list. It is in node number/s: ",sel);
        curr=head;
        while(curr!=NULL){
        loc=loc+100;
        if(curr->x==sel){
        printf("%5d,",loc);
        }
        curr=curr->next;
        }
        goto SET1;
    }
    curr=curr->next;
    }
    ex1:
    SET1:
    printf("\n\nIf you want to search another number (press 1): ");
    scanf("%d",&rep);
    if(rep==1){
    goto res2;
    }
    else
        break;
    default:
        
        break;
    }
    
}
void menu(){
    printf("----------------|| MENU LINKED LIST ||----------------\n\n\n[1]. Create a Doubly Linked List\n\n[2]. Display a Doubly Linked List\n\n[3]. Sort a Doubly Linked List\n\n[4]. Insert a Node\n\n[5]. Delete a Node\n\n[6]. Search a Number in the List\n\n[7]. Exit the program\n\n");
}
