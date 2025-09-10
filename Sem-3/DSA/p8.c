/* Q8.c : Queue using linked list with random insertion and deletion from file */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// Queue structure
typedef struct {
    Node *front, *rear;
} Queue;

// Create queue
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(Queue *q, int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->val = x;
    p->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = p;
    } else {
        q->rear->next = p;
        q->rear = p;
    }
    printf("Enqueued %d\n", x);
}

// Dequeue operation
int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    Node *temp = q->front;
    int val = temp->val;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    printf("Dequeued %d\n", val);
    return val;
}

// Display queue
void display(Queue *q) {
    Node *p = q->front;
    printf("Queue: ");
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("File not found!\n");
        return 0;
    }

    Queue *q = createQueue();
    srand(time(NULL));

    int x;
    while (fscanf(f, "%d", &x) == 1) {
        int op = rand() % 2; // 0 = enqueue, 1 = dequeue
        if (op == 0) {
            enqueue(q, x);
        } else {
            dequeue(q);
        }
        display(q);
    }

    fclose(f);
    return 0;
}
