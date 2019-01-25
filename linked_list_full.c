#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>

struct Node             //create Node//
{
    int data;
    struct Node* next;
};


void Display(struct Node* node)    //display information//
{
    while(node != NULL){
        printf("%d ",node -> data);
        node = node -> next;
    }
    _getch();
}

void InsertFront(struct Node** head_ref)      //insert value in the front//
{
    system("cls");
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); //create new node//
    printf("Enter any value to store : ");
    scanf("%d",&new_node ->data);
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
    printf("Press 1 to store another value : ");
    int x;
    scanf("%d",&x);
    if(x==1) InsertFront(head_ref);

}

void InsertMiddle(struct Node** head_ref)    //insert at the middle//
{
    system("cls");
    struct Node* current = *head_ref;
    int i,count=0;
    while(current != NULL){
        count++;
        current = current -> next;
    }
    if(count<2){
        printf("Linked has less the 2 value!!\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); //create new node//
    current = *head_ref;  //change current from last to first//
    for(i=1;i<count/2;i++){
        current = current -> next;
    }
    printf("Enter any value to store : ");
    scanf("%d",&new_node ->data);
    new_node -> next = current -> next;
    current -> next = new_node;
    int x;
    printf("Press 1 to store another value : ");
    scanf("%d",&x);
    if(x==1) InsertFront(head_ref);
}

void InsertEnd(struct Node** head_ref)
{
    system("cls");
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  //create new node//
    printf("Enter any value to store : ");
    scanf("%d",&new_node ->data);
    new_node -> next = NULL;
    if(*head_ref==NULL){
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;

    while(last -> next != NULL){
        last = last -> next;
    }

    last -> next = new_node;

    int x;
    printf("Press 1 to store another value : ");
    scanf("%d",&x);
    if(x==1) InsertFront(head_ref);

}

void Delete(struct Node** head_ref)
{
    system("cls");
    struct Node* temp = *head_ref,*prev;
    if(temp == NULL) return;
    int key;
    printf("Enter the which you want to Delete : ");
    scanf("%d",&key);

    if(temp != NULL && temp -> data ==key){
        *head_ref = temp -> next;
        free(temp);
        return;
    }

    while(temp != NULL && temp -> data != key){
        prev = temp;
        temp = temp -> next;
    }

    prev -> next = temp -> next;
    free(temp);

}


void main()
{
    struct Node* head = NULL;
    int option;
    do{
        system("cls");
        system("COLOR 0B");
        printf("Linked List:\n");
        printf("01. Insert At the Front\n");
        printf("02. Insert in the Middle\n");
        printf("03. Insert At the End\n");
        printf("04. Delete\n");
        printf("05. Display\n");
        printf("06. Exit\n");
        printf("\n\nEnter your option : ");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            InsertFront(&head);
            break;
        case 2:
            InsertMiddle(&head);
            break;
        case 3:
            InsertEnd(&head);
            break;
        case 4:
            Delete(&head);
            break;
        case 5:
            Display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("\aWrong option!! Try Again\n");
            _sleep(700);
            system("CLS");
        }

    }while(option != 6);
}
