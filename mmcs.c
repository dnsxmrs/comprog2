#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

struct node{
    struct node *prev;
    int x;
    struct node *next;
};
struct node *head, *curr, *tail, *ind, *ind1;

int main () {
    int iter[100], exit = 0, srchd = 0, crtd = 0, srtd = 0, insrtd = 0, conti = 1, srt, temp, insrt, lsrt, srch, cntr, i, menu, dsply;
    char cconti = 'Y';
    // char conti;

    do {
    system("cls");
    printf("  ============= MAIN MENU ============\n\n");
    printf("  [ 1 ] = Create a Doubly Linked List\n");
    printf("  [ 2 ] = Display a Doubly Linked List\n");
    printf("  [ 3 ] = Sort a Doubly Linked List\n");
    printf("  [ 4 ] = Insert a Node\n");
    printf("  [ 5 ] = Delete a Node\n");
    printf("  [ 6 ] = Search a Number in the List\n");
    printf("  [ 7 ] = Exit\n\n\n");
    // printf("  ADD ON--------------------------------");
    // printf("  [ 8 ] = Group Members\n\n\n");
    
    printf("What number is in your mind? ");
    scanf("%d", &menu);

        switch (menu) {
        case 1:
            system("cls");
            head=curr=tail=NULL;
            curr = (struct node *) malloc (sizeof(struct node));
            printf("What is the value of x(0 to terminate): ");
            scanf("%d", &curr->x);
            while (curr->x != 0) {
                if (head == NULL) {                             
                    head = curr;
                    head->prev = NULL;
                    head->next = NULL;
                    tail = curr;
                } else {
                    tail->next = curr;
                    curr->prev = tail;
                    curr->next = NULL;
                    tail = curr;
                }
                curr = (struct node *) malloc (sizeof(struct node));
                printf("What is the value of x(0 to terminate): ");
                scanf("%d", &curr->x);
            }
            printf("\n\nReturning to Main Menu...");
            getch();
            break;
        
        case 2:
            conti = 1;
            while (conti) {
                system("cls");
                printf("  Display a Doubly Linked List\n\n");
                printf("  [ 1 ] = Normal Display\n");
                printf("  [ 2 ] = Reverse Display\n");
                printf("  [ 3 ] = Return to Main Menu\n\n");
                printf("What display method is in your mind? ");
                scanf("%d", &dsply);

                switch (dsply) {
                case 1:
                    system("cls");
                    curr = head;                     //            ; 
                    printf("  =====     Normal Display    =====\n\n");
                    while (curr != NULL) {
                        printf(" [ %d ] ", curr->x);
                        curr = curr->next;
                    }
                    printf("\n\n\nReturning to Display Menu...");
                    /* DITO NA YUNG CODE FOR NORMAL DISPLAY */
                    getch();
                    break;
                case 2:
                    system("cls");
                    curr = tail;
                    printf("  =====    Reverse Display    =====\n\n");
                    while (curr != NULL) {
                        printf(" [ %d ] ", curr->x);
                        curr = curr->prev;
                    }
                    printf("\n\n\nReturning to Display Menu...");
                    /* DITO NA YUNG CODE FOR REVERSE DISPLAY */
                    getch();
                    break;
                case 3:
                    conti = 0;
                    break;
                default:
                    printf("\nPlease input a number from 1 - 3 only.\n");
                    printf("==============Try Again!==============");
                    getch();
                    break;
                }
            }
            break;

        case 3:
            conti = 1;
            while (conti) {
                system("cls");
                printf("  Sort a Doubly Linked List\n\n");
                printf("  [ 1 ] = Ascending Sort\n");
                printf("  [ 2 ] = Descending Sort\n");
                printf("  [ 3 ] = Return to Main Menu\n\n");
                printf("What sort method is in your mind? ");
                scanf("%d", &srt);

                switch (srt) {
                case 1:
                    lsrt = 0;
                    system("cls");
                    printf("  =====     Ascending Sort    =====\n");
                    printf("The program will begin sorting...\n");          
                    for (curr = head; curr != NULL; curr = curr->next) {
                        for (ind = curr->next; ind != NULL; ind = ind->next) {
                            if (curr->x > ind->x) {
                                temp = curr->x;
                                curr->x = ind->x;
                                ind->x = temp;
                            }
                        }
                        printf("...\n");
                    }
                    printf("The Node Structure was sorted.");                   
                    getch();
                    break;
                case 2:
                    lsrt = 1;
                    system("cls");
                    printf("  =====    Descending Sort    =====\n");
                    printf("The program will begin sorting...\n");          
                    for (curr = head; curr != NULL; curr = curr->next) {
                        for (ind = curr->next; ind != NULL; ind = ind->next) {
                            if (curr->x < ind->x) {
                                temp = curr->x;
                                curr->x = ind->x;
                                ind->x = temp;
                            }
                        }
                        printf("...\n");
                    }
                    printf("The Node Structure was sorted.");                   
                    getch();
                    break;
                case 3:
                    conti = 0;
                    srt = lsrt;
                    break;
                default:
                    printf("\nPlease input a number from 1 - 3 only.\n");
                    printf("==============Try Again!==============");
                    getch();
                    break;
                }
            }
            break;

        case 4:
            cconti = 'Y';
            while (cconti == 'Y' || cconti == 'y') {
                system("cls");
                if (srt == 0) { // ascending
                    curr = (struct node *) malloc (sizeof(struct node));
                    printf("What is the number to be inserted? ");
                    scanf("%d", &curr->x);
                    if (curr->x <= head->x) {
                        curr->next = head;
                        head->prev = curr;
                        curr->prev = NULL;
                        head = curr;
                        printf("\n\nThe number was inserted as the head node.");
                    } else if (head->x <= curr->x && curr->x <= tail->x) {
                        ind = head;
                        ind1 = ind->next;
                        while (insrtd == 0) {
                            if (ind->x <= curr->x && curr->x <= ind1->x) {
                                ind->next = curr;
                                curr->prev = ind;
                                curr->next = ind1;
                                ind1->prev = curr;
                                insrtd = 1;
                            }
                            ind = ind->next;
                            ind1 = ind1->next;
                        }
                        printf("\n\nThe number was inserted somewhere in the middle.");
                    } else {
                        tail->next = curr;
                        curr->prev = tail;
                        curr->next = NULL;
                        tail = curr;
                        printf("\n\nThe number was inserted as the tail node.");
                    }
                } else { // descending
                    curr = (struct node *) malloc (sizeof(struct node));
                    printf("What is the number to be inserted? ");
                    scanf("%d", &curr->x);
                    if (curr->x > head->x) {
                        curr->next = head;
                        head->prev = curr;
                        curr->prev = NULL;
                        head = curr;
                        printf("\n\nThe number was inserted as the head node.");
                    } else if (head->x > curr->x && curr->x > tail->x) {
                        ind = head;
                        ind1 = ind->next;
                        while (insrtd == 0) {
                            if (ind->x > curr->x && curr->x > ind1->x) {
                                ind->next = curr;
                                curr->prev = ind;
                                curr->next = ind1;
                                ind1->prev = curr;
                                insrtd = 1;
                            }
                            ind = ind->next;
                            ind1 = ind1->next;
                        }
                        printf("\n\nThe number was inserted somewhere in the middle.");
                    } else {
                        tail->next = curr;
                        curr->prev = tail;
                        curr->next = NULL;
                        tail = curr;
                        printf("\n\nThe number was inserted as the tail node.");
                    }
                }
                printf("\n\nDo you want to insert a number again(Y/N)? ");
                scanf(" %c", &cconti);
            }
            break;

        case 5:
            system("cls");

            printf("Input number to delete: ");
            scanf("%d", &srch);
            


            printf("You picked number 5.");
            getch();
            break;

        case 6:
            system("cls");
            cconti = 'Y';
            while (cconti == 'Y' || cconti == 'y') {
                printf("Enter a number to search: ");
                scanf("%d", &srch);
                cntr = 0;
                i = 1; // srch = number cntr = number of iterations iter[]= storage of node number  i = node number
                for (curr = head; curr != NULL; curr = curr->next) {
                    if (curr->x == srch) {
                        iter[cntr] = i;
                        cntr++;
                        srchd = 1;
                    }
                    i++;
                }
                if (srchd) {
                    printf("\n%d is in the list. It is in node number/s", srch);
                    for (i = 0; i < cntr; i++) {
                        printf(" [ %d ] ", iter[i]);
                    }
                } else
                    printf("\n%d is not in the list.");

                printf("\n\nDo you want to continue (Y/N)? ");
                scanf(" %c", &cconti);
            }
            break;
            
        case 7:
            exit = 1;
            printf("\nExiting the program!!\n");
            printf("PRESS ANY KEY TO CONTINUE...");
            getch();
            break;

        default:
            printf("\nPlease input a number from 1 - 7 only.\n");
            printf("==============Try Again!==============");
            getch();
            break;
        }

    } while (exit == 0);
}