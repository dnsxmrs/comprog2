#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#include<string.h>

struct node {
    int num[10];
    char name[40], stcode, sdisplay[8];
    float hrswrk, rate, deduct, basicpay, otpay, netpay;
    struct node *next;
};

struct node *head, *curr, *tail;

int main() {
    int nmwrkrs, i = 0;
    char y;
    float z;
    head = curr = tail = NULL;

    printf("HOW MANY WORKERS DO YOU HAVE? ");
    scanf("%d", &nmwrkrs);
    // FILE *fp;
    // fp = fopen("friend.txt", "w");
    // int i;
    // if (fp == NULL) {
    //     printf("File cannot be created!");
    //     exit(1);
    // }
    for (i = 0; i < nmwrkrs; i++) {  // paki fool-proof lahat ng user-input
        curr = (struct node *) malloc (sizeof(struct node));
        printf("Enter employee number(0000000000): ");
        scanf("%d", &curr->num);
        printf("Enter employee name(30 char): ");
        scanf("%s", curr->name);
        printf("Is the employee (R)Regular/(C)Casual? ");
        scanf("%c", &curr->stcode);
        if (curr->stcode == 'R' || 'r') {
            printf("Employee's basic salary amount: ");
            scanf("%f", &curr->basicpay);
            strcpy(curr->sdisplay, "Regular");
        } else if (curr->stcode == 'C' || 'c') {
            printf("Employee's basic salary rate: ");
            scanf("%f", &curr->rate);
            strcpy(curr->sdisplay, "Casual");
        }
        printf("Enter employee's hours worked: ");
        scanf("%d", &curr->hrswrk);
        printf("Enter employee's salary deductions: ");
        scanf("%d", &curr->deduct);

        if (curr->stcode == 'R' || 'r') {
            if (curr->hrswrk <= 160) {
                curr->rate = curr->basicpay / curr->hrswrk;
                curr->netpay = curr->basicpay - curr->deduct;
            } else {
                curr->rate = curr->basicpay / 160;
                curr->otpay = (curr->hrswrk - 160) * (curr->rate+(curr->rate/2));
                curr->netpay = curr->basicpay + curr->otpay - curr->deduct;
            }
        } else if (curr->stcode == 'C' || 'c') {
            if (curr->hrswrk <= 160) {
                curr->basicpay = curr->rate / curr->hrswrk;
                curr->netpay = curr->basicpay - curr->deduct;
            } else {
                curr->rate = curr->basicpay / 160;
                curr->otpay = (curr->hrswrk - 160) * (curr->rate+(curr->rate/2));
                curr->netpay = curr->basicpay + curr->otpay - curr->deduct;
            }
        }
        if (head == NULL) {
            head = curr;
            head->next = NULL;
            tail = curr;        
        } else {
            tail->next = curr;
            curr->next = NULL;
            tail = curr;            
        }
    }
    system("CLS");
    curr = head;
    for (i = 0; i < nmwrkrs; i++) {
        printf("#%d Employee\n", i+1);
        printf("%d %s\n", curr->num, curr->name);
        printf("%s %f\n", curr->sdisplay, curr->basicpay);
        printf("%f %f\n", curr->otpay, curr->deduct);
        printf("%f\n", curr->netpay);
        curr = curr->next;
    }
    

    return 0;
}