#define _CRT_SECURE_NO_WARNINGS
#define N 6
#include <stdio.h>
#include <malloc.h>

struct list
{
    char info; //char key
    struct list* pointer; //pointer on next list element(NULL by default)
};

struct list* init(char initChar) //initChar- initial key value
{
    struct list* lst;
    //give memory for list element
    lst = (struct list*)malloc(sizeof(struct list));
    lst->info = initChar;
    lst->pointer = NULL;
    return(lst);
}

struct list* list_add(list* lst, char newChar)
{
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->pointer; //save pointer for next node
    lst->pointer = temp; //ex-node sends for current
    temp->info = newChar; //save char info for current
    temp->pointer = p; //next pointer
    return(temp);
}

struct list* deletehead(list* root)
{
    struct list* temp;
    temp = root->pointer;
    free(root); //free memory
    return(temp); //new node
}

void print(list* lst)
{
    struct list* p;
    p = lst;
    do {
        printf("%c ", p->info); //print current char
        p = p->pointer; //move to next pointer
    } while (p != NULL);
}

struct list* FreeMemory(list* lst)
{
    struct list* node;
   
     node = deletehead(lst);
     if (node != NULL) node = FreeMemory(node);

     return node;
}

struct list* ReorderForNewList(list* lst) {
    struct list* p;
    p = lst;
    struct list* newList = init((char)"");
    do {
        list_add(newList, p->info);
        p = p->pointer;
    } while (p != NULL);
    newList = deletehead(newList);//remove head root- with unexpected symbol
    return newList;
}

int main() {
    struct list* MyList = init((char)"");
    struct list* SecondList;
    char word[N];
    int counter = 0;
    printf("Please, input some word of %d characters:\n", N-1);
    scanf("%s", &word);


    while (word[counter] != word[N-1]) {
        list_add(MyList, word[counter]);
        counter++;
    }
    MyList = deletehead(MyList);//remove head root- with unexpected symbol
    printf("\nWas:");
    print(MyList);
    SecondList = ReorderForNewList(MyList);
    printf("\nBecome:");
    print(SecondList);
    MyList = FreeMemory(MyList);
    //printf("%c", MyList->info);// if uncomment this line - it`s throw exception, because list is free now

    return 1;
}