#include<stdio.h>
#include<stdlib.h>
struct Node {
int number;
struct Node * next;
};
typedef struct Node node;
node* insertStart(node* head, node* newNode)
{
 node* temp = head;
 newNode->next = temp;
 head = newNode;
 return head;
}
node* insertLast(node* head, node* newNode)
{
 if(head == NULL)
 {
 head = insertStart(head, newNode);
 return head;
 }
 node* curr= head;
 while(curr->next != NULL)
 {
 curr = curr->next;
 }
 curr->next = newNode;
 return head;
}
//Q1:
node* makeList()
{
 int n;
 node* head = NULL;
 printf("Enter elements of the list:\n");
 while(1)
 {
 scanf("%d",&n);
 if(n == -1)
 break;
 node* newNode = (node*)malloc(sizeof(node*));
 newNode->number = n;
 newNode->next = NULL;
 if(n%2 == 1)
 {
 head = insertStart(head, newNode);
 }
 else if(n%2 == 0)
 {
 head = insertLast(head, newNode);
 }
 }
 printf("Linked list created\n");
 return head;
}
//Q2:
node* cutlastaddhead(node* head)
{
 printf("Cutting last element and insert the last element at start\n");
 if(head==NULL || head->next == NULL)
 {
 return head;
 }
 node* curr = head;
 node* prev = NULL;
 while(curr->next != NULL)
 {
 prev = curr;
 curr = curr->next;
 }
 node* last = curr;
 prev->next = NULL;
 head = insertStart(head , last);
 return head;
}
//Q3:
node* deleteMiddle(node* head)
{
 printf("Deleting middle element of the list\n");
 int size = 0;
 node* curr = head;
 while(curr!=NULL)
 {
 curr = curr->next;
 size++;
 }
 if(size == 0)
 {
 return NULL;
 }
 else if(size==1)
 {
 free(head);
 return NULL;
 }
 else if(size == 2)
 {
 node* newhead = head->next;
 free(head);
 head = newhead;
 return head;
 }
 int index = 0;
 curr = head;
 node* prev = NULL;
 while(index < (size/2) )
 {
 index++;
 prev = curr;
 curr = curr->next;
 }
 node* toBeDeleted = curr;
 prev->next = toBeDeleted->next;
 free(toBeDeleted);
 return head;
}
//Q4:
node* changeFirstAndLast(node* head)
{
 printf("Swapping first and last element of the list\n");
 if(head == NULL || head->next == NULL)
 {
 return head;
 }
 node* curr = head;
 node* prev = NULL;
 while(curr->next != NULL)
 {
 prev = curr;
 curr=curr->next;
 }
 node* last = curr;
 last->next = NULL;
 prev->next = NULL;
 node* first = head;
 head = head->next;
 first->next = NULL;
 head = insertStart(head, last);
 head = insertLast(head, first);
 return head;
}
//Q5:
node* cutheadaddlast(node* head)
{
 printf("Cutting head and insert the head at last\n");
 if(head == NULL || head->next == NULL)
 {
 return head;
 }
 node* first = head;
 head = head->next;
 first->next = NULL;
 head = insertLast(head, first);
 return head;
}
void printList(node* head)
{
 printf("Elements of the list are: ");
 node* curr=head;
 while(curr!=NULL)
 {
 printf("%d ",curr->number);
 curr= curr->next;
 }
 printf("\n");
}
//Q6:
node* makeList2()
{
 int n;
 node* head = NULL;
 printf("Enter elements of the list:\n");
 while(1)
 {
 scanf("%d",&n);
 if(n == -1)
 break;
 node* newNode = (node*)malloc(sizeof(node*));
 newNode->number = n;
 newNode->next = NULL;
 if(n%2 == 1)
 {
 head = insertLast(head, newNode);
 }
 else if(n%2 == 0)
 {
 head = insertStart(head, newNode);
 }
 }
 printf("Linked list created\n");
 return head;
}
int main()
{
 node* head = NULL;
 head = makeList();
 printList(head);
 head = cutlastaddhead(head);
 printList(head);
 head = deleteMiddle(head);
 printList(head);
 head = changeFirstAndLast(head);
 printList(head);
 head = cutheadaddlast(head);
 printList(head);
 head = makeList2();
 printList(head);
}
