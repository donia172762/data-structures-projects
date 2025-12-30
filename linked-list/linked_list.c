//Donia said  _ 1222600 _ sec2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node;
typedef struct node Node;
struct node
{
    char district[50];
    int totalPopualion;
    struct node1*town;
    struct node *next;
    Node*prev;
};
typedef Node List;
struct node1;
typedef struct node1 Node1;
struct node1
{
    char town[50];
    int popualtion;
    Node1 *next;
    Node1*prev;
};
typedef Node1 List1;
// this struct from creat list to alphabet charachters
struct node2;
typedef struct node2 Node2;
struct node2
{
    char data[50];//alphabt char
    Node2*next;
    Node2*prev;

};
typedef Node2 List3;

List1 * createlist1();//creation a list from town node
List * createlist2();// creation a list from a district node
int isLast(List * L );
int isList1(List1 *L );
int IsEmpty1(List *L);
int IsEmpty2(List1 *p);
void freeLinkedList1(List1* head);
void freeLinkedList2(List* head);
List * insertDistrict(char name[], List *L);//insert at the begining
void insertTown(char name[], List *distirct, int pop);// insert at the begining
void loudtheData(char filename,FILE* readFile, List *l,List1 *s);//loaded the information
void deleteDistrict(List * head);//delete any district i want to deleted it
void deleteTwon(List * head); // deleted the town i choice
void printbeforsorting( List *head); // print the information before sorting
void displayMainMenu();
List *insertNewDistrict(List *head );
void inserNewTown(List * head);
int calculatePop(List *pNode1);
void findMinMaxPopulation(List* head);
void sortDistrict();
List3 *createAlphList();
void insertLast(List3 *head, char string[50]);
int  findMaxLingth(List*head);
void addSpecialChar(List *head);
void sortTown();
void printAfterSorting(List * head);
void printtDisAndTotalPop(List *head);
void change(List *head);
void exitFromProject(); // exit
void outputFile(List *pNode);

int main()
{
    char filename[50] = "district.txt";
    displayMainMenu();
    char districtname[50];
    char town[50];
    printf("please select your option:\n");
    List1 *towns =createlist1();
    List *district=createlist2();
    FILE *infile = fopen("districts.txt","r");
    int choice ;
    scanf("%d",&choice);
    while (choice != 15 && choice < 15)
    {

        switch(choice)
        {
            case 1:
                loudtheData((char) filename, infile, district, towns);
                printf("\n the data has been louded successfully:)\n\n");
                printf("\n");
                break;
            case 2:

                printbeforsorting(district);
                break;
            case 3:
                sortTown(district);
                printbeforsorting(district);

                break;
            case 4:
                sortDistrict(district);
                break;
            case 5:
                printAfterSorting(district);
                break;
            case 6 :
                insertNewDistrict(district );
                printbeforsorting(district);
                break;
            case 7 :
                inserNewTown(district);
                printbeforsorting(district);

                break;
            case 8:
                deleteTwon(district);
                printbeforsorting(district);
                break;
            case 9:
                deleteDistrict(district);
                printbeforsorting(district);
                break;
            case 10:
                calculatePop(district);
                findMinMaxPopulation(district);

                break;
            case 11 :
                printtDisAndTotalPop(district);
                break;
            case 12 :
                change(district);
                printbeforsorting(district);
                break;
            case 13 :
                 outputFile(district);
                break;
            case 14 :
                exitFromProject();
                exit(choice);

        }
        displayMainMenu();
        scanf("%d",&choice);
    }
    freeLinkedList1(towns);
    freeLinkedList2(district);
    return 0;
}
List1 * createlist1()
{
    List1 *temp;
    temp = (List1*)malloc(sizeof(struct node1));
    if (temp==NULL)
    {
        printf("out of memory !\n");

    }
    else
    {
        temp->popualtion=0;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }
}
List * createlist2()
{
    List *L;
    L = (List*)malloc(sizeof(struct node));
    if (L==NULL)
    {
        printf("out of memory !\n");

    }
    else
    {
        L->totalPopualion=0;
        L->next = NULL;
        L->prev = NULL;
        L->town=createlist1();
        return L;
    }

}
List3 *createAlphList()
{
    List3 * L;
    L = (List3*) malloc(sizeof (struct node2));
    if(L == NULL)
    {
        printf("out of memory !\n");
    }
    else
    {
        L->prev = NULL;
        L->next = NULL;
        return L;
    }
}
int isLast(List * L )
{
    return  (L->next == NULL);
}
int isList1(List1 *L )
{
    return (L->next == NULL);
}
int IsEmpty1(List *L)
{
    return L->next == NULL;
}

int IsEmpty2(List1 *p)
{
    return p->next == NULL;
}
void freeLinkedList1(List1* head)
{
    List * current = (List *) head;
    List1* next;

    while (current != NULL)
    {
        next = (List1 *) current->next;
        free(current);
        current = (List *) next;
    }
}
void freeLinkedList2(List* head)
{
    List* current = head;
    List * next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
List * insertDistrict(char name[], List *L)
{
    char district[50] ;
    List *r, *tp;
    r = createlist2();
    r->prev = NULL;
    strcpy(r->district, name);
    r->totalPopualion= 0;
    r->next = NULL;
    tp = L;
    while(tp->next !=NULL)
        tp = tp->next;

    tp->next=r;
    return tp->next;

}

void insertTown(char name[], List *distirct, int pop)
{
    List1 *town=createlist1();
    town=strcpy(town->town,name);
    town->popualtion=pop;
    List1 *p = distirct->town;
    while (p->next != NULL)
    {
        p= p->next;
    }
    p->next = town;

    //}
    distirct->totalPopualion += town->popualtion;

}

void loudtheData(char filename,FILE* readFile, List *l,List1 *s)
{
    int population=0;
    char district[25];
    char town[25];
    char array[50];
    if (s==NULL && l==NULL)
    {
        printf("out of memory !\n");
    }
    else
    {
        readFile = fopen("districts.txt","r");
        if ((readFile == NULL))
        {
            printf(":");
            printf("the file is empty of data :(\n");
        }
        while(fgets(array,50,readFile)!= NULL)
        {
            char *check=strtok(array, "|");
            strcpy( district,check)  ;//make the next pointer of the head ->data for the first node
            check= strtok(NULL,"|");
            strcpy(town,check);//make the pointer of the small list head -> towns name
            check = strtok(NULL, "|");
            population= atoi(check);
            s->popualtion= population;
            l->totalPopualion=population+s->popualtion;
            s->prev =s;
            List *thisDistrict;
            char lastDistict[50];
            if( (strcmp(lastDistict,district)) != 0 )
            {
                thisDistrict= insertDistrict(district, l);
                strcpy(lastDistict,thisDistrict->district);
            }
            insertTown(town,thisDistrict,population);
        }

    }
    fclose(readFile);
}
int  findMaxLingth(List*head)
{
    int maxLength =0;
    List * L = head->next;
    while(L->next!=NULL)
    {
        int  lengthdis = strlen(L->district );
        if(lengthdis > maxLength)
        {
            maxLength = lengthdis;
            L= L->next;
        }
        L= L->next;
        printf("%d\n" , maxLength);
    }
    return maxLength;
}
void addSpecialChar(List*head)
{
    char district[50];
    int maxLength = findMaxLingth(head);
    List *L = head->next;
    while(L !=NULL)
    {
        int num = strlen(L->district);

        if(num < maxLength)
        {
            int space_num = maxLength - num;
            for(int i=0 ; i<space_num ; i++)
            {
                strcat(L->district , "*");
                strcpy(district , L->district);
            }

        }

        // Move to the next node
        L = L->next;
        printf("%s\n" , district);
    }
}
void insertLast(List3 *head, char string[50])
{
    char data[50];
    List3 * alapha = createAlphList();
    strcpy(alapha->data , data);
    alapha->next =NULL;
    if(head == NULL)
    {
        head = alapha;
        alapha->prev = NULL;
        return;
    }
    List3 *ptr = head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = alapha;
    alapha->prev =ptr;
}
void sortDistrict(List * L)
{
    int maxLen = findMaxLingth(L);
    addSpecialChar(L);
    List3 * R_array[27];//   Size is 27 lowercase letters and the spcial symbol
    R_array[1]="?";
    char b ='a';
    for (int x = 1; x < 27; x++) {
        strcpy(R_array[x]->data, (const char *) b);
        b++;
    }
    // Radix Sort from right to left (string )
    for (int P = maxLen - 1; P >= 0; P--)
    { // P is the Position

        // distribute nodes into the array
        List * current = L->next;
        while (current != NULL) {

            int index;

            //  the current character
            char currentC = (char) current->district;
            if ('a' <= currentC && currentC <= 'z') {// lowercase letters

                index = currentC - 'a' + 27;
            }

            insertLast(R_array, current->district);
            current = current->next;
        }

    }
}
void sortTown(List *head)
{
    List *thisDistrict;
    List1 *thisTown;
    List1 *temp;
    for(thisDistrict = head ->next ; thisDistrict!=NULL ; thisDistrict = thisDistrict->next) // this is district
    {
        for(thisTown = thisDistrict->town->next ; thisTown !=NULL ; thisTown = thisTown->next)
        {
            for(temp = thisTown->next ; temp!=NULL ; temp = temp->next)
            {
                if(temp->popualtion < thisTown->popualtion)
                {
                    List1 *ptr = createlist1();
                    strcpy(ptr->town , temp->town);
                    strcpy(temp->town , thisTown->town);
                    strcpy(thisTown->town , ptr->town);
                    ptr->popualtion = temp->popualtion;
                    temp->popualtion = thisTown->popualtion;
                    thisTown->popualtion = ptr->popualtion;
                    free(ptr);

                }
            }
        }
    }
}
void deleteDistrict(List * head) {
    char district[50];
    printf("enter a district you want to delete it : ");
    scanf("%s" , &district);

    List *temp = head;
    List *prv = NULL;
    while (temp != NULL) {
        if (strcmp(temp->district, district) == 0) {
            if (prv == NULL) {
                prv= temp->next;
            } else {
                prv->next = temp->next;
            }
            List1* ptr = temp->town;
            while (ptr != NULL) {
                List1 *toDelete = ptr;
                ptr = ptr->next;
                free(toDelete);
            }
            free(temp);
            return;
        }
        prv = temp;
        temp = temp->next;
        printf("%s is deleted\n" , district);
    }
}
void deleteTwon(List * head)
{
    char district[50];
    char town1[50];
    printf("enter a district  : ");
    scanf("%s", &district);
    printf("enter a town :");
    scanf("%s" , &town1);
    List *temp = head->next;
    while (temp != NULL) {
        if (strcmp(temp->district, district) == 0) {

            List1* ptr = temp->town;
            List1* prev = NULL;
            while (ptr  != NULL) {
                if (strcmp(ptr ->town, town1) == 0) {

                    if (prev == NULL) {
                        // Town to be deleted is the head of the list
                        temp->town = ptr ->next;
                    } else {
                        prev->next = ptr ->next;
                    }
                    free(ptr );
                    printf("Town %s deleted from district %s\n", town1, district);
                    return;
                }
                prev = ptr ;
                ptr  = ptr ->next;
            }

            printf("Town %s does not found \n", town1);
            return;
        }
        temp = temp->next;
    }

    // District not found
    printf("District '%s' not found\n", district);
}

void printbeforsorting( List *head)
{

    List  *l=head;
    if (IsEmpty2(l))
        printf("Empty list!\n");
    else
        do
        {
            l=l->next;
            List1 *towns =l->town;
            do
            {
                towns=towns->next;
                printf("%s|%s|%d\n",l->district,towns->town,towns-> popualtion);

            }
            while (!isList1(towns));



        }
        while(!isLast(l));
    printf("\n");
}
List *insertNewDistrict(List *head )
{
    char district[50];
    char town [50];
    int popualtion;
    printf("enter a new district you want to add : ");
    scanf("%s" , &district);
    printf("enter a new town : ");
    scanf("%s" , &town);
    printf("enter a new popualtion: ");
    scanf("%d" , &popualtion);
    List *newDistrict , *ptr;
    newDistrict = createlist2();
    newDistrict->prev = NULL;
    strcpy(newDistrict->district ,district);
    strcpy(newDistrict->town , town);
    newDistrict->totalPopualion = popualtion;
    newDistrict->next =NULL;
    ptr =newDistrict;
    while(ptr->next !=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next=newDistrict;
    newDistrict->prev = ptr;

    return ptr->next;

}
void inserNewTown(List * head)
{
    char district[50];
    char newtown[50];
    int population ;

    printf("Enter a district name : \n ");
    scanf("%s" , &district);

    printf("Enter a new town :\n ");
    scanf("%s" , &newtown);
    printf("enter a popualtion : \n");
    scanf("%d" , &population);
    List *L= head;
    if(L == NULL)
    {
        printf("does not found\n");
    }
    while(L!=NULL)
    {
        if(strcmp(L->district , district)!=0)
        {
            List1 *town =createlist1();
            strcpy(town->town , newtown);
            town->popualtion = population ;
            town->next = NULL;
            town->next = L->town;
            L->town = newtown;
            printf("New town '%s' added to district '%s' with population %d\n", newtown, district,population);
            return;
        }
        L = L->next;
    }
    printf("district does not found in the list %s " , district);
}
void displayMainMenu()
{
    printf("please Select an operation (1-14):\n");
    printf(" 1. loded input file\n");
    printf(" 2. print the informaion before sorting\n");
    printf(" 3. Sort the districts alphabetically\n");
    printf(" 4. Sort the towns for each district based on population in ascending order\n");
    printf(" 5. Print the sorted information\n");
    printf(" 6. Add a new district to the list of sorted districts \n");
    printf(" 7. Add a new town to a certain district\n");
    printf(" 8. Delete a town from a specific distric\n");
    printf(" 9. . Delete a complete district\n");
    printf(" 10. Calculate the population of Palestine, the max and min town population\n");
    printf(" 11. Print the districts and their total population\n");
    printf(" 12. Change the population of a town\n");
    printf(" 13. Save to output file\n");
    printf(" 14. Exit\n");
}
int calculatePop(List * head)
{
    List * temp = head;
    int totalPopulation =0;
    while (temp !=NULL)
    {
        totalPopulation=0;
        List1 *town = temp->town;
        while(town!=NULL)
        {
            totalPopulation +=town->popualtion;
            town = town->next;
        }
        printf("district %s , totalPopulation = %d\n" , temp->district , totalPopulation);
        temp=temp->next;
        // printf("district %s , totalPopulation = %d\n" , temp->district , totalPopulation);
    }
    return totalPopulation;

}
void findMinMaxPopulation(List* head) {
    List* temp = head->next;

    while (temp != NULL) {
        int maxPopulation = 0;
        int minPopulation = temp->totalPopualion;
        List1* ptr = temp->town->next;

        while (ptr != NULL) {
            if (ptr->popualtion < minPopulation) {
                minPopulation = ptr->popualtion;
            }
            if (ptr->popualtion > maxPopulation) {
                maxPopulation = ptr->popualtion;
            }
            ptr = ptr->next;
        }
        printf("District: %s, Min Population: %d, Max Population: %d\n", temp->district, minPopulation, maxPopulation);
        temp = temp->next;
    }

}
void printtDisAndTotalPop(List *head)
{
    while(head->next!=NULL) {
        head = head->next;
        calculatePop(head);
        head = head->next;


    }printf("district %s , popualtion  =  %d \n" , head->district , calculatePop(head));

}

void change(List * head) {
    char district[50];
    char town[50];
    int newPopulaion;
    printf("enter a district  :\n ");
    scanf("%s", &district);
    printf("enter a town name i want to change the population from it : \n");
    scanf("%s", &town);
    printf("enter a new populaion :\n ");
    scanf("%d", &newPopulaion);
    List *temp = head->next;
    while (temp != NULL) {
        if (strcmp(temp->district, district) == 0) {
            List1 *ptr = temp->town;
            while (ptr != NULL) {
                if (strcmp(ptr->town, town) == 0) {
                    ptr->popualtion = newPopulaion;
                    printf("Population of town %s in district %s updated to %d\n", town, district, newPopulaion);
                    return;
                }
                ptr = ptr->next;
            }
            printf("Town %s not found", town);
        }
        temp = temp->next;
    }
    printf("district %s not fount"  , district);
}
int size(List * L) {
    List * Ptr = L->next;
    int length = 0;// Initialize a counter for the num of nodes
    while (Ptr != NULL) {// count the number of nodes in the linkedlist
        length += 1; // Increment the counter
        Ptr = Ptr->next; // Move to the next node
    }
    return length;
}
void printAfterSorting(List * head)
{
    sortTown(head);
    sortDistrict(head);
    List *l=head;
    if (IsEmpty2(l))
        printf("no district\n");
    else
        do
        {
            l=l->next;
           List1*towns =l->town;
            if(IsEmpty1(towns))
                printf("%s|zero towns\n",l->district);
            else
                do
                {
                    towns=towns->next;
                    printf("%s|%s|%d\n",l->district,towns->town,towns->popualtion);

                }
                while (!isList1(towns));
        }
        while(!isLast(l));
    printf("\n");
}
void outputFile(List*head)
{
    FILE *wirteFile = fopen("output.txt" , "w");
    if(wirteFile == NULL)
    {
        printf("error");
    }
    List * temp = head;
    while(temp!=NULL)
    {
        fprintf(wirteFile  , "%s\n" , temp->district);
        temp = temp->next;
    }
    fclose(wirteFile);
    printf("Data saved to output");
}

void exitFromProject()
{
    printf("exist.....");
}
