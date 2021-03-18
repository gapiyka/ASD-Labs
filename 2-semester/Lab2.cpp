#define _CRT_SECURE_NO_WARNINGS
#define N 6
#include <stdio.h>
#include <malloc.h>


struct list
{
    int size, head, end;
    char* array;
};

struct list* init(int size)
{
    struct list* queue = (struct list*)malloc(sizeof(struct list));
    queue->head = 0;
    queue->size = size;
    queue->end = size - 1;
    queue->array = (char*)malloc(queue->size * sizeof(char));
    return queue;
}

char head(struct list* queue)
{
    return queue->array[queue->head];
}

char end(struct list* queue)
{
    return queue->array[queue->end];
}

void list_add(struct list* queue, char key)
{
    if (key == NULL) return;
    queue->end = (queue->end + 1)% queue->size;
    queue->array[queue->end] = key;
    printf("%c added to queue\n", key);
}

char remove_head(struct list* queue)
{
    char key = head(queue);
    queue->head = (queue->head + 1) % queue->size;
    return key;
}

void inverse_list(struct list* queue, struct list* newQueue)
{
    printf("\nINVERSE:\n");
    int counter = N - 1;
    char key;
    newQueue->head = newQueue->end;
    newQueue->end = newQueue->end - 1;
    while (head(newQueue) != end(queue)) {
        key = queue->array[queue->head];
        newQueue->head = (newQueue->head - 1);
        newQueue->array[newQueue->head] = key;
        printf("%c drag to new queue\n", key);
        remove_head(queue);
        counter--;
    }
    printf("\nTEST:\n");
    printf("First key in newQueue is %c\n", head(newQueue));
    printf("Last key in newQueue is %c\n\n", end(newQueue));
    free(queue);
}

int main()
{
    struct list* queue = init(N);

    char word[N];
    int counter = 0;
    printf("Please, input some word of %d(or less) characters:\n", N-1);
    scanf("%s", &word);
    
    
    while (word[counter] != word[N-1]) {
        list_add(queue, word[counter]);
        counter++;
    }
    printf("\nTEST:\n");
    printf("First key in queue1 is %c\n", head(queue));
    printf("Last key in queue1 is %c\n\n", end(queue));

    struct list* queue2 = init(N);
    inverse_list(queue, queue2);
    //printf("Last key in newQueue is %c\n\n", end(queue));//if uncomment this line - it`s throw exception, because list is free now

    //You can inverse queues again, uncomment 2 lines below
    //queue = init(N);
    //inverse_list(queue2, queue);

    return 0;
}