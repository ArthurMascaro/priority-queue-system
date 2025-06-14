#include <string.h>
#include "queue.h"

void queue_init(t_queue *q) {
    q->front = 0;
    q->size  = 0;
}

void queue_enqueue(t_queue *q, const char *name) {
    if (q->size < MAX_QUEUE) {
        int idx = (q->front + q->size) % MAX_QUEUE;
        strcpy(q->names[idx], name);
        q->size++;
    }
}

void queue_dequeue(t_queue *q, char *name) {
    if (q->size > 0) {
        strcpy(name, q->names[q->front]);
        q->front = (q->front + 1) % MAX_QUEUE;
        q->size--;
    } else {
        name[0] = '\0';
    }
}

int queue_empty(t_queue *q) {
    return q->size == 0;
}

void init_queues(t_queue *general, t_queue *priority, t_queue *served) {
    queue_init(general);
    queue_init(priority);
    queue_init(served);
}

void add_to_queue(t_queue *q) {
    char name[MAX_NAME];
    scanf("%s", name);
    queue_enqueue(q, name);
}

void serve_customer(t_queue *general, t_queue *priority, t_queue *served, int *prio_count) {
    char name[MAX_NAME] = {0};
    if (!queue_empty(priority) && *prio_count < 3) {
        queue_dequeue(priority, name);
        (*prio_count)++;
    } else if (!queue_empty(general)) {
        queue_dequeue(general, name);
        *prio_count = 0;
    } else if (!queue_empty(priority)) {
        queue_dequeue(priority, name);
        (*prio_count)++;
    }
    if (name[0]) {
        queue_enqueue(served, name);
    }
}

void print_served(t_queue *served) {
    char name[MAX_NAME];
    while (!queue_empty(served)) {
        queue_dequeue(served, name);
        printf("%s\n", name);
    }
}