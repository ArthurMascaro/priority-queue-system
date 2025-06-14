#include <stdio.h>
#include <string.h>
#include "queue.h"

#define MAX_SERVED 1000

int main() {
    t_queue general, priority, served;
    int prio_count = 0;

    init_queues(&general, &priority, &served);

    char cmd[MAX_NAME];
    while (scanf("%s", cmd) == 1) {
        if (cmd[0] == 'g') {
            add_to_queue(&general);
        } else if (cmd[0] == 'p') {
            add_to_queue(&priority);
        } else if (cmd[0] == 's') {
            serve_customer(&general, &priority, &served, &prio_count);
        } else if (cmd[0] == 'f') {
            print_served(&served);
        }
    }

    return 0;
}