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
    int iter[100], dbc = 0, exit = 0, srchd = 0, srtd = 0, insrtd = 0, dltd = 0, conti = 1, srt, temp, srch, cntr, i, menu, dsply;
    char cconti = 'Y';

    do {
    system("cls");
    printf("===============[ MAIN MENU ]==============\n\n");
    printf("  [ 1 ] = Create a Doubly Linked List\n");
    printf("  [ 2 ] = Display a Doubly Linked List\n");
    printf("  [ 3 ] = Sort a Doubly Linked List\n");
    printf("  [ 4 ] = Insert a Node\n");
    printf("  [ 5 ] = Delete a Node\n");
    printf("  [ 6 ] = Search a Number in the List\n");
    printf("  [ 7 ] = Exit\n\n");
    // printf("  ADD ON--------------------------------");
    // printf("  [ 8 ] = Group Members\n\n\n");
    if (dbc == 0) { // if doubly linked list is not yet created, the program will recommend it
        printf("(Creating a Doubly Linked List is recommended)\n");
    }
    printf("What do you want to do? ");
    scanf("%d", &menu);

    switch (menu) {
    case 1: // create a doubly linked list
        if (dbc == 1) { // creating doubly linked list, dbc = 0
            cconti = 'N';
            system("cls");
            printf("======[ CREATING DOUBLY LINKED LIST ]=====\n\n");
            printf("You already created a Doubly Linked List.\n");
            printf("Do you want to create a new one(Y/N)? ");
            scanf(" %c", &cconti);
            if (cconti == 'Y' || cconti == 'y'){
                dbc = 0;
                cconti = 'Y';
            }
        }
        if (dbc == 0 || cconti == 'Y') { // if doubly linked list is already exist, you'll get a prompt to create another one
            head = curr = tail = NULL; i = 1;
            curr = (struct node *) malloc (sizeof(struct node));
            system("cls");
            printf("======[ CREATING DOUBLY LINKED LIST ]=====\n\n");
            printf("Input integer for Node %d(0 to finish): ", i);
            scanf("%d", &curr->x);
            while (curr->x != 0) {
                if (head == NULL) {                             
                    head = curr;
                    head->prev = NULL;
                    head->next = NULL;
                    tail = curr;                        
                    dbc = 1; // doubly linked list is created even if it is only a head node
                } else {
                    tail->next = curr;
                    curr->prev = tail;
                    curr->next = NULL;
                    tail = curr;
                }
                curr = (struct node *) malloc (sizeof(struct node));
                printf("Input integer for Node %d(0 to finish): ", i++);
                scanf("%d", &curr->x);
            }
        }
        printf("\nReturning to Main Menu, press any key...");
        getch();
        break;

    case 2: // display the doubly linked list
        if (dbc) { // if there are a doubly linked list, the program is executed
            conti = 1;
            while (conti) {
                system("cls");
                printf("=============[ DISPLAY MENU ]=============\n\n");
                printf("  [ 1 ] = Normal Display\n");
                printf("  [ 2 ] = Reverse Display\n");
                printf("  [ 3 ] = Return to Main Menu\n\n");
                printf("What display method is in your mind? ");
                scanf("%d", &dsply);

                switch (dsply) {
                case 1: // normal display
                    system("cls");
                    curr = head;
                    printf("============[ NORMAL DISPLAY ]============\n\n");
                    while (curr != NULL) {
                        printf(" [ %d ] ", curr->x);
                        curr = curr->next;
                    }
                    printf("\n\nReturning to Display Menu, press any key...");
                    getch();
                    break;
                case 2: // reverse display
                    system("cls");
                    curr = tail;
                    printf("============[ REVERSE DISPLAY ]===========\n\n");
                    while (curr != NULL) {
                        printf(" [ %d ] ", curr->x);
                        curr = curr->prev;
                    }
                    printf("\n\nReturning to Display Menu, press any key...");
                    getch();
                    break;
                case 3: // return to main menu
                    conti = 0;
                    break;
                default: // input is not 1, 2, 3
                    system("cls");
                    printf("=============[ DISPLAY MENU ]=============\n\n");
                    printf("  ==========  [ Warning! ]  ==========  \n");
                    printf("Please input a number from 1 - 3 only.");
                    getch();
                    break;
                }
            }
        } else { // if there are no doubly exists, the program is skipped and prompted to make one
            system("cls");
            printf("=============[ DISPLAY MENU ]=============\n\n");
            printf("Program not executed.\n");
            printf("Create a Doubly Linked List first.");
            getch();
        }
        break;

    case 3: // sort the doubly linked list
        if (dbc) { // if there are a doubly linked list, the program is executed
            conti = 1;
            while (conti) {
                system("cls");
                printf("==============[ SORT  MENU ]==============\n\n");
                printf("  [ 1 ] = Ascending Sort\n");
                printf("  [ 2 ] = Descending Sort\n");
                printf("  [ 3 ] = Return to Main Menu\n\n");
                printf("What sort method is in your mind? ");
                scanf("%d", &srt);

                switch (srt) {
                case 1: // ascending sort
                    srtd = 1;
                    system("cls");
                    printf("============[ ASCENDING SORT ]============\n\n");
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
                    printf("The Doubly Linked List was sorted.");                   
                    getch();
                    break;
                case 2: // descending sort
                    srtd = 2;
                    system("cls");
                    printf("============[ DESCENDING SORT ]===========\n\n");
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
                    printf("The Doubly Linked List was sorted.");                   
                    getch();
                    break;
                case 3: // return to main menu
                    conti = 0;
                    break;
                default: // input is not 1, 2, 3
                    printf("==============[ SORT  MENU ]==============\n\n");
                    printf("  ===========  [ Warning! ]  ===========  \n");
                    printf("Please input a number from 1 - 3 only.");
                    getch();
                    break;
                }
            }
        } else { // if there are no doubly exists, the program is skipped and prompted to make one
            system("cls");
            printf("==============[ SORT  MENU ]==============\n\n");
            printf("Program not executed.\n");
            printf("Create a Doubly Linked List first.");
            getch();
        }
        break;

    case 4: // insert a node
        if (dbc == 1 && srtd != 0) { // if there are a doubly linked list, the program is executed
            cconti = 'Y';
            while (cconti == 'Y' || cconti == 'y') {
                insrtd = 0;
                system("cls");
                printf("=============[ INSERT A NODE ]============\n\n");
                curr = (struct node *) malloc (sizeof(struct node));
                printf("What is the number to be inserted? ");
                scanf("%d", &curr->x);
                if (srtd == 1) { // ascending
                    if (curr->x <= head->x) { // insert as head node
                        curr->next = head;
                        head->prev = curr;
                        curr->prev = NULL;
                        head = curr;
                        printf("\nThe number was inserted as the head node.\n");
                        getch();
                    } else if (head->x < curr->x && curr->x < tail->x) { // inserted in the middle
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
                            ind1 = ind->next;
                        }
                        printf("\nThe number was inserted somewhere in the middle.\n");
                        getch();
                    } else { // insert as tail node
                        tail->next = curr;
                        curr->prev = tail;
                        curr->next = NULL;
                        tail = curr;
                        insrtd = 1;
                        printf("\nThe number was inserted as the tail node.\n");
                        getch();
                    }
                } else { // descending
                    if (curr->x >= head->x) { // insert as head node
                        curr->next = head;
                        head->prev = curr;
                        curr->prev = NULL;
                        head = curr;
                        insrtd = 1;
                        printf("\nThe number was inserted as the head node.\n");
                        getch();
                    } else if (head->x > curr->x && curr->x > tail->x) {  // inserted in the middle
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
                        printf("\nThe number was inserted somewhere in the middle.\n");
                        getch();
                    } else { // insert as tail node
                        tail->next = curr;
                        curr->prev = tail;
                        curr->next = NULL;
                        tail = curr;
                        insrtd = 1;
                        printf("\nThe number was inserted as the tail node.\n");
                        getch();
                    }
                }
                printf("\n\n");
                curr = head;
                while (curr != NULL) {
                    printf(" [ %d ] ", curr->x);
                    curr = curr->next;
                }
                printf("\n\nDo you want to insert a number again(Y/N)? ");
                scanf(" %c", &cconti);
            } 
        } else if (dbc == 1 && srtd == 0) { // sort the doubly first
            system("cls");
            printf("=============[ INSERT A NODE ]============\n\n");
            printf("Sort the Doubly Linked List first.");
            getch();
        } else {  // if there are no doubly exists, the program is skipped and prompted to make one
            system("cls");
            printf("=============[ INSERT A NODE ]============\n\n");
            printf("Program not executed.\n");
            printf("Create a Doubly Linked List first.");
            getch();
        } 
        break;

    case 5: // delete a node
        if (dbc) { // if there are a doubly linked list, the program is executed
            cconti = 'Y';
            while (cconti == 'Y' || cconti == 'y') {
                dltd = 0;
                system("cls");
                printf("============[ DELETE A NUMBER ]===========\n\n");
                printf("Enter a number to delete: ");
                scanf("%d", &srch);
                for (curr = head; dltd != 1; curr = curr->next) {
                    if (curr->x == srch) {
                        ind = curr->prev;
                        ind1 = curr->next;
                        ind->next = ind1;
                        ind1->prev = ind;
                        free(curr); // freeing the memory and completely removing that node
                        dltd = 1;
                    }
                }
                if (dltd)  // if number is in the list, the number is deleted from the list
                    printf("\n%d was deleted from the list", srch);
                else // if the number is not in the list
                    printf("\n%d is not in the list.", srch);
                printf("\n\nDo you want to search another number(Y/N)? ");
                scanf(" %c", &cconti);
            }
        } else { // if there are no doubly exists, the program is skipped and prompted to make one
            system("cls");
            printf("============[ SEARCH A NUMBER ]===========\n\n");
            printf("Program not executed.\n");
            printf("Create a Doubly Linked List first.");
            getch();
        }
        break;

    case 6: // search a number
        if (dbc) { // if there are a doubly linked list, the program is executed
            cconti = 'Y';
            while (cconti == 'Y' || cconti == 'y') {
                system("cls");
                printf("============[ SEARCH A NUMBER ]===========\n\n");
                printf("Enter a number to search: ");
                scanf("%d", &srch);
                cntr = 0; srchd = 0; i = 1; // srchd is 'searched' long term
                // srch = number to search, cntr = number of occurence, iter[]= storage of node number  i = node number
                for (curr = head; curr != NULL; curr = curr->next) {
                    if (curr->x == srch) {
                        iter[cntr] = i;
                        cntr++;
                        srchd = 1;
                    }
                    i++;
                }
                if (srchd) { // if number is in the list, the number of occurrence and the number are displayed
                    printf("\n%d is in the list. It is in node number/s", srch);
                    for (i = 0; i < cntr; i++) {
                        printf(" [ %d ] ", iter[i]);
                    }
                } else // if the number is not in the list
                    printf("\n%d is not in the list.", srch);
                printf("\n\nDo you want to search another number(Y/N)? ");
                scanf(" %c", &cconti);
            }
        } else { // if there are no doubly exists, the program is skipped and prompted to make one
            system("cls");
            printf("============[ SEARCH A NUMBER ]===========\n\n");
            printf("Program not executed.\n");
            printf("Create a Doubly Linked List first.");
            getch();
        }
        break;

    case 7: // exiting the program
        exit = 1;
        printf("\nExiting the program!!\n");
        printf("Press any key to continue...");
        getch();
        break;

    default: // if input is not 1-7
        printf("\n\n  ===========  [ Warning! ]  ===========  \n");
        printf("Please input a number from 1 - 7 only.");
        getch();
        break;
    }
    } while (exit == 0);
}