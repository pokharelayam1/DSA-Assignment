// Implementation of Doubly Linked List
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
 void insertAfter(struct Node *prevNode, int newData){
    if(prevNode == NULL){
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != NULL){
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
 }
 void deleteNode(struct Node **head, struct Node *delNode){
    if(*head == NULL || delNode == NULL){
        return;
    }
    if(*head == delNode){
        *head = delNode->next;
    }
    if(delNode->next != NULL){
        delNode->next->prev = delNode->prev;
    }
    if(delNode->prev != NULL){
        delNode->prev->next = delNode->next;
    }
    free(delNode);
 }
 void display(struct Node *head){
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
 }
    printf("\n");
 }
 int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    display(head);
    
    insertAfter(second, 25);
    display(head);

    deleteNode(&head, second);
    display(head);

    return 0;
    
 }