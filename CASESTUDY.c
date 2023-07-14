#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#include<stdbool.h>

struct Node {
    struct Node *prev;
    int x;
    struct Node *next;
};
struct Node *head, *curr, *tail, *temp;

int ext = 0, mainc;
void members(void);
void employees(void);
void menu2(void);
int funct1(struct Node *curr);

int main () {
    while (mainc != 4) {
        system("CLS");
        printf("  ######   #######  #######  \n");
        printf(" ######## ###   ### ######## \n");
        printf(" ##   ### ##     ## ##     ##\n");
        printf("##        ##     ## ##     ##\n");
        printf("##        ##     ## ##     ##\n");
        printf("##        ##     ## ##     ##\n");
        printf("##        ##     ## ##     ##\n");
        printf("##    ### ##     ## ##     ##\n");
        printf(" ######## ###   ### ######## \n");
        printf("  ######   #######  #######  \n\n\n");
        printf("1 GROUP MEMBERS\n");
        printf("2 EMPLOYEES (FILE HANDLING)\n");
        printf("3 MAIN MENU\n");
        printf("4 EXIT THE PROGRAM\n\n");
        printf("Enter your choice: ");
        scanf("%d", &mainc);

        switch (mainc) {
        case 1:
            members();
            break;
        case 2:
            employees();
            // getch(); no need for getch for the mean time
            break;
        case 3:
            menu2();
            // getch(); no need for getch for the mean time
            break;
        case 4:
            system("CLS");
            printf("Exiting the program... press any key");
            getch();
            break;
        default:
            system("CLS");
            printf("\n\n  ===========  [ Warning! ]  ===========  \n");
            printf("Please input a number from 1 - 4 only.");
            getch();
            break;
        }
    }
}

void members() {
    system("CLS");
    printf("=============[ GROUP MEMBERS ]============\n\n");
    printf("MEMBER #1: ALOVEROS, BARON RANIEL I.\n");
    printf("MEMBER #2: BERTUSO, RUBEN JR.\n");
    printf("MEMBER #3: BORJA, MA. NADINE\n");
    printf("MEMBER #4: MARIAL, ERICE MICHAEL D.\n");
    printf("MEMBER #5: POLICARPIO, STYVN RICE KAYLE\n\n"); //VWADGAGDAG YAW NIYO SALITA HA
    printf("Press any key to return to menu...");
    getch();
}

void employees() {
    int choice1 = 1;
    while (choice1) {
        system("CLS");
        printf("SOURCE CODE FOR EMPLOYEES IS YET TO BE PASTED.\n");
        printf("Press 0 to exit...");
        scanf("%d", &choice1);
    }
}

void menu2() {
    int choice2, *sort = 0;
    while (choice2 != 7) {
        system("CLS");
        printf("===============[ MAIN MENU ]==============\n\n");
        printf("  [ 1 ] = Create a Doubly Linked List\n");
        printf("  [ 2 ] = Display a Doubly Linked List\n");
        printf("  [ 3 ] = Sort a Doubly Linked List\n");
        printf("  [ 4 ] = Insert a Node\n");
        printf("  [ 5 ] = Delete a Node\n");
        printf("  [ 6 ] = Search a Number in the List\n");
        printf("  [ 7 ] = Exit\n\n"); 
        scanf("%d", &choice2);
        switch (choice2) {
        case 1:
            funct1(curr);
            break;
        case 2:
            funct2(curr);
            break;
        case 3:
            funct3(curr, &sort);
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        default: // if input is not 1-7
            system("cls");
            printf("\n\n  ===========  [ Warning! ]  ===========  \n");
            printf("Please input a number from 1 - 7 only.");
            getch();
            break;
        }
    }
}

int funct1(struct Node *curr){
    system("CLS");
    int i = 1;
    curr = (struct Node *)malloc(sizeof(struct Node));
    printf("======[ CREATING DOUBLY LINKED LIST ]=====\n\n");
    printf("Input integer for Node %d(0 to finish): ", i);
    scanf("%d", &curr->x);
    while(curr->x != 0){
        if(head == NULL){
            head = curr;
            head->prev = NULL;
            head->next = NULL;
            tail = curr;
        }
        else{
            tail->next = curr;
            curr->prev = tail;
            curr->next = NULL;
            tail = curr;
        }
    curr = (struct Node *) malloc(sizeof(struct Node));
    printf("Input integer for Node %d(0 to finish): ", i++);
    scanf("%d", &curr->x);
    }
    printf("\n\nThe doubly linked list has been created.");
    printf("\nReturning to Main Menu, press any key...");
    getch();
}

int funct2 (struct Node *curr) {
    int dsply = 0;
    while (dsply != 3) {
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
}

int funct3 (struct Node *curr, int *sort) {
    
}