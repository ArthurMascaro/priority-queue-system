#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 1000
#define MAX_NAME   50

typedef struct {
    char names[MAX_QUEUE][MAX_NAME];
    int  front;
    int  size;
} t_queue;

void queue_init(t_queue *q);
void queue_enqueue(t_queue *q, const char *name);
void queue_dequeue(t_queue *q, char *name);
int  queue_empty(t_queue *q);

void init_queues(t_queue *general, t_queue *priority, t_queue *served);
void add_to_queue(t_queue *q);
void serve_customer(t_queue *general, t_queue *priority, t_queue *served, int *prio_count);
void print_served(t_queue *served);

#endif
