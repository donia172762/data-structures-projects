//donia said - sec2 - 1222600
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TABLE_SIZE 1000
typedef struct AVLnode *AVLNode;
struct AVLnode {
    char Element[1000]; // Change Element type to char array for strings
    int frequency;
    AVLNode Left;
    AVLNode Right;
    int Height;
};
struct hash {
    int frequency ;
    char* word;
    struct hash* next;
};
typedef struct hash* hashingTable;
hashingTable hashTable[TABLE_SIZE];
char words[300][1000];
int frequencies[500];
char word[1000];
AVLNode avlRoot = NULL;
AVLNode MakeEmpty(AVLNode T);
AVLNode Find(char* X, AVLNode T);
AVLNode FindMin(AVLNode T);
AVLNode FindMax(AVLNode T);
AVLNode Insert(AVLNode T, char* word);
void PrintInOrder(AVLNode t);
void displayMainMenu();
void readInputFile();
int hash(char *Key, int TableSize);
void exitFromProject();
int Max(int height, int height1);
bool isalpha(char i);
AVLNode *createAVLNode();
AVLNode Delete(char* word, AVLNode T);
hashingTable creatHashTable();
void insertToHashTable(hashingTable table[10], char* word);
void deleteFromHashTable(hashingTable table[10], char* word);
void printHashTable();
int searchHashTable(char*x);
void printThestatistics();
int main() {
    int choice=0;
    while (choice != 15 && choice < 11) {
        displayMainMenu();
        printf("Enter a number of any case you want: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readInputFile();
                printf("\nThe file is loaded successfully........\n");
                break;
            case 2:
                avlRoot = createAVLNode();
                printf("The AVL Tree is created successfully...\n");
                break;
            case 3:
                printf("Enter a word to insert: ");
                scanf("%s", word);
                avlRoot = Insert(avlRoot, word);
                printf("Inserted successfully........\n");
                break;
            case 4:
                printf("Enter the word you want to delete: ");
                scanf("%s", word);
                avlRoot = Delete(word, avlRoot);
                printf("Deleted successfully.............\n");
                break;
            case 5:
                PrintInOrder(avlRoot);
                break;
            case 6:
                creatHashTable();
                printf("Hash table created successfully......\n");
                break;
            case 7:
                printf("Enter a word you want to add: ");
                scanf("%s", word);
                insertToHashTable(hashTable, word);
                printf("The insert operation was successful........\n");
                break;
            case 8:
                printf("Enter a word to delete from the hash table: ");
                scanf("%s", word);
                deleteFromHashTable(hashTable, word);
                printf("The delete operation was successful........\n");
                break;
            case 9:
                printf("Enter a word to search in the hash table: ");
                scanf("%s", word);
                int freq = searchHashTable(word);
                if(freq == -1)
                {
                    printf("no");
                }
                else
                {
                    printf("%s  , freq =  %d" , word , freq);
                }
                break;
            case 10:
                printThestatistics();
                break;
            case 11:
                exitFromProject();
                exit(choice);
        }
    }
    return 0;
}
void displayMainMenu() {
    printf("\nPlease select an operation (1-11):\n");
    printf(" 1. Load data from the file.\n");
    printf(" 2. Create the AVL tree\n");
    printf(" 3. Insert a word to the AVL tree\n");
    printf(" 4. Delete a word from the AVL tree\n");
    printf(" 5. Print the words as sorted in the AVL tree\n");
    printf(" 6. Create the Hash Table\n");
    printf(" 7. Insert a word to the Hash table\n");
    printf(" 8. Delete a word from the hash table\n");
    printf(" 9. Search for a word in the hash table and print its frequency\n");
    printf(" 10. Print word statistics\n");
    printf(" 11. Exit the application\n");
}

void readInputFile() {
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[1000];
    int wordIndex = 0;

    while (fgets(line, 1000, input) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        char* token = strtok(line, " ");
        while (token != NULL) {
            char cleanedWord[1000];
            int validWordLength = 0;
            for (int i = 0; token[i]; i++) {
                if (isalpha(token[i])) {
                    cleanedWord[validWordLength++] = token[i];
                }
            }
            cleanedWord[validWordLength] = '\0';

            // Check if the word contains only alphabetic characters
            if (validWordLength > 0) {
                bool found = false;
                for (int i = 0; i < wordIndex; i++) {
                    if (strcmp(words[i], cleanedWord) == 0) {
                        frequencies[i]++;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    strncpy(words[wordIndex], cleanedWord, sizeof(cleanedWord) - 1);
                    words[wordIndex][sizeof(cleanedWord) - 1] = '\0'; // Ensure null termination
                    frequencies[wordIndex] = 1;
                    wordIndex++;
                }
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(input);
}

AVLNode *createAVLNode() {
    AVLNode newNode = (AVLNode)malloc(sizeof(struct AVLnode));
    if (newNode == NULL) {
        printf("Out of space!!!\n");
        exit(1);
    }
    newNode->Left = NULL;
    newNode->Right = NULL;
    newNode->Height = 0;
    newNode->frequency = 1;
    return newNode;
}
AVLNode MakeEmpty(AVLNode T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

AVLNode Find(char* X, AVLNode T) {
    if (T == NULL)
        return NULL;
    int compare = strcmp(X, T->Element);
    if (compare < 0)
        return Find(X, T->Left);
    else if (compare > 0)
        return Find(X, T->Right);
    else
        return T;
}

AVLNode FindMin(AVLNode T) {
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

AVLNode FindMax(AVLNode T) {
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;

    return T;
}

int Height(AVLNode P) {
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

int Max(int Lhs, int Rhs) {
    return Lhs > Rhs ? Lhs : Rhs;
}

AVLNode SingleRotateWithLeft(AVLNode K2) {
    AVLNode K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;

    return K1;
}

AVLNode SingleRotateWithRight(AVLNode K1) {
    AVLNode K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Right), K1->Height) + 1;

    return K2;
}

AVLNode DoubleRotateWithLeft(AVLNode K3) {
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

AVLNode DoubleRotateWithRight(AVLNode K1) {
    K1->Right = SingleRotateWithLeft(K1->Right);
    return SingleRotateWithRight(K1);
}

AVLNode Insert(AVLNode T, char* Word) {
    if (T == NULL) {
        T = createAVLNode();
        strcpy(T->Element, Word);
    } else {
        int compare = strcmp(Word, T->Element);
        if (compare < 0) {
            T->Left = Insert(T->Left, Word);
            if (Height(T->Left) - Height(T->Right) == 2) {
                if (strcmp(Word, T->Left->Element) < 0)
                    T = SingleRotateWithLeft(T);
                else
                    T = DoubleRotateWithLeft(T);
            }
        } else if (compare > 0) {
            T->Right = Insert(T->Right, Word);
            if (Height(T->Right) - Height(T->Left) == 2) {
                if (strcmp(Word, T->Right->Element) > 0)
                    T = SingleRotateWithRight(T);
                else
                    T = DoubleRotateWithRight(T);
            }
        } else {
            T->frequency++;
        }
    }
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

AVLNode Delete(char* X, AVLNode T) {
    if (T == NULL)
        return NULL;

    int compare = strcmp(X, T->Element);
    if (compare < 0) {
        T->Left = Delete(X, T->Left);
    } else if (compare > 0) {
        T->Right = Delete(X, T->Right);
    } else {
        if (T->Left && T->Right) { // Two children
            AVLNode tmp = FindMin(T->Right);
            strcpy(T->Element, tmp->Element);
            T->Right = Delete(T->Element, T->Right);
        } else {
            AVLNode tmp = T;
            T = (T->Left) ? T->Left : T->Right;
            free(tmp);
        }
    }

    if (T == NULL)
        return T;

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    if (Height(T->Left) - Height(T->Right) == 2) {
        if (Height(T->Left->Left) - Height(T->Left->Right) >= 0)
            T = SingleRotateWithLeft(T);
        else
            T = DoubleRotateWithLeft(T);
    } else if (Height(T->Right) - Height(T->Left) == 2) {
        if (Height(T->Right->Right) - Height(T->Right->Left) >= 0)
            T = SingleRotateWithRight(T);
        else
            T = DoubleRotateWithRight(T);
    }
    return T;
}

void PrintInOrder(AVLNode T) {
    if (T != NULL) {
        PrintInOrder(T->Left);
        printf("%s (frequency: %d)\t", T->Element, T->frequency);
        PrintInOrder(T->Right);
        T->frequency++;
    }
}

int hash(char *Key, int TableSize) {
    int hashValue = 0;
    while (*Key != '\0') {
        hashValue += *Key++;
    }
    return (hashValue % TableSize);
}

hashingTable creatHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    return *hashTable;
}

void  insertToHashTable(hashingTable hashtabel[10], char* word1) {
    int WordIndex = hash(word1, TABLE_SIZE);
    hashingTable newHashNode = (hashingTable*)malloc(sizeof(hashingTable));
    if(newHashNode == NULL)
    {
        printf("no");
    }
    strcpy(newHashNode->word , word1);
    newHashNode->frequency=1 ;
    newHashNode->next = hashtabel[WordIndex];
    hashtabel[WordIndex] = newHashNode;
    if(strcmp(newHashNode->word  , word1)==0)
    {
        newHashNode->frequency++;
        return;
    }
}

void deleteFromHashTable(hashingTable hashingTable1[10], char* word) {
    int index = hash(word, TABLE_SIZE);
    hashingTable thehash = hashingTable1[index];
    hashingTable temp = NULL;

    while (thehash != NULL && strcmp(thehash->word, word) != 0) {
        temp = thehash;
        thehash = thehash->next;
    }

    if (thehash == NULL) {
        printf("sorry , the word you want to delete not found..\n");
        return;
    }

    if (temp == NULL) {
        hashingTable1[index] = thehash->next;
    } else {
        temp->next = thehash->next;
    }

    free(thehash->word);
    free(thehash);
}
int searchHashTable(char*x)
{
    int wordIndex = hash(x , TABLE_SIZE);
    hashingTable searching = hashTable[wordIndex];
    while(searching!=NULL)
    {
        if(strcmp(searching->word , x)==0) {
            return searching->frequency;
        }
            searching = searching->next;
    }
    return -1;
}
void printThestatistics()
{
    int allOfWord = 0;
    int frequancyCount = 0;
    char *frequancyWord1 = NULL;
    hashingTable  countingFreq ;
    for(int i=0 ; i<TABLE_SIZE ; i++)
    {
        countingFreq = hashTable[i];
        while (countingFreq!=0)
        {
            allOfWord++;
            if(countingFreq->frequency >frequancyCount )
            {
                frequancyCount = countingFreq->frequency;
                frequancyWord1 = countingFreq->word;
            }
            countingFreq = countingFreq->next;
        }
    }
    printf("%d\n" , allOfWord);
    if(frequancyWord1!=NULL)
    {
        printf("the most freq word is %s\t , and count %d" , frequancyWord1 , frequancyCount);
    }
    else
    {
        printf("no");
    }
}
void traverseAVLTreeAndInsert(AVLNode root) {
    if (root != NULL) {
        traverseAVLTreeAndInsert(root->Left);
        insertToHashTable(root->Element, (char *) root->frequency);
        traverseAVLTreeAndInsert(root->Right);
    }
}

