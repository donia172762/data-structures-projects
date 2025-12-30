#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//the struct
typedef struct node* ptr;
typedef  ptr Stack1;
typedef ptr Queue;
struct node
{
    char data;
    ptr Next;
};

void makeEmpty(Stack1 s);
int IsEmpty( Stack1 s);
Stack1 creatStack();
void push(char x , Stack1 s);
void pop(Stack1 s);
int top(Stack1 s);
void makeEmpty1(Queue s);
int IsEmpty1( Queue s);
Queue creatQueue();
void  enqueue(Queue Q, char num);
void dequeue();
void displayMain();
void lodedFile();
void exitFromProject();
int main() {
    int choice;
    displayMain();

    while(choice != 9 && choice < 9)
    {
        displayMain();
        printf("Enter a number you want to choice : ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1 :
                lodedFile();
                break;
            case 2 :
                exitFromProject();
                exit(choice);
        }

    }
    return 0;
}
int IsEmpty(Stack1 s)
{
    return  s->Next == NULL;
}
void makeEmpty(Stack1 s)
{
    if(s == NULL)
    {
        printf("empty stack");
    }

    else

    {
        while(!IsEmpty(s))
        {
           pop(s);
        }
    }
}

Stack1 creatStack()
{
    Stack1  L;
    L = (Stack1*) malloc(sizeof(Stack1 ));
    if(L == NULL)
    {
        printf("empty");
    }
    else
    {
        L->Next = NULL;
        makeEmpty(L);
    }
    return L;
}
void push(char x , Stack1 s)
{
    ptr newNode;
    newNode= (Stack1*) malloc(sizeof(Stack1));
    if(newNode == NULL)
    {
        printf("the List is empty");
    }
    else
    {
        newNode->data = x;
    }
}
void pop (Stack1 s)
{
    ptr temp;
    if(IsEmpty(s))
    {
        printf("the list is empty ");
    }
    else
    {
        temp = s->Next;
        s->Next = s->Next->Next;
        free(temp);
    }
}
int IsEmpty1( Queue s)
{
    return  s->Next == NULL;
}
Queue creatQueue()
{
    Queue Q;
    Q=(Queue)malloc(sizeof(struct node));
    if(Q==NULL){
        printf("Queue not created, NO Space!..\n");
    }
    Q->Next=NULL;
    return Q;
}
void enqueue(Queue Q, char num)
{

    ptr newNode = (ptr)malloc(sizeof(struct node));
    newNode->data=num;

    ptr temp;

    if(Q==NULL){
        printf("Queue Not Found..\n");
        return;
    }else if(newNode==NULL){
        printf("Out of space..\n");

    }else if(IsEmpty1(Q)){
        newNode->Next=Q->Next;
        Q->Next=newNode;
        return;
    }

    temp=Q->Next;

    while(temp->Next != NULL){
        temp=temp->Next; //rear->last element in the queue
    }

    newNode->Next=temp->Next;
    temp->Next=newNode;
}
void dequeue(Queue Q)
{
    ptr front=Q->Next;

    if(Q==NULL){
        printf("Queue Not Found..\n");
        return;
    }else if(IsEmpty1(Q)){
        printf("Queue is empty, Nothing to dequeue..\n");
        return;
    }else if(Q->Next->Next==NULL){ //has one element
        Q->Next=front->Next;
        free(front);
        return;
    }

    //queue has at least two elements

    Q->Next=front->Next;
    free(front);
    return;
}
void displayMain()
{
    printf("\nSELECT THE NUMBER OF OPERATION YOU WANT TO EXECUTE:\n ");
    printf("\n 1 - Load the input file which contains the initial text:\n ");
    printf(" 2- Print the loaded text:\n ");
    printf(" 3- Insert strings to the text:\n ");
    printf(" 4- Remove strings from the text:\n ");
    printf(" 5- Perform Undo operation:\n ");
    printf(" 6- Perform Redo operation:\n ");
    printf(" 7- Print the Undo Stack and the Redo stack:\n ");
    printf(" 8- Save the updated text to the output file:\n ");
    printf(" 9- Exit:\n ");

}
void lodedFile()
{
  char word[100][1000];
  FILE * input;
  input = fopen("districts.txt" , "r");
  int i =0;
      while(fgets(word[i] , 1000 , input)!=NULL)
      {
          i++;
      }
    fclose(input);
}
void exitFromProject()
{
    printf("exist.....");
}
