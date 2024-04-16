#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "insts.h"
#include "queues.h"
#include "pool_threads.h"

/**
 * # Creates a set number of worker threads and instructions and executes them.
 * Takes in 2 arguments:
 * - N°1 (int) : Number of worker threads
 * - N°2 (int) : Number of instructions in pool
*/
int main(int argc, char** argv) {
    check_arguments(argc,2);
    int n_workers = get_number(argv[1]);
    int n_inst = get_number(argv[2]);
    int i;
    Queue *inst_queue = createQueue();
    Queue_Inst *inst2_queue = createQueue();
    printf("ninst: %d\n",n_inst);
    printf("nworkers: %d\n",n_workers);
    char* element = "Hello world!";
    for (i = 0; i < n_inst; i++) {
        printf("ITER: %i\n",i+1);
        QueueElement *new_element = createQueueElement(element);
        printf("Created element: %p\n",new_element);
        insertInQueue(inst_queue, new_element);
    }
    printQueueRaw(inst_queue);

    for (i = 0; i < n_inst; i++) {
        printf("ITER: %i\n",i+1);
        Instruction *element2 = malloc(sizeof(Instruction));
        element2->instruction_id = i + 1;
        QueueElement_Inst *new_element2 = createQueueElement_Inst(element2);
        printf("Created element: %p\n", new_element2);
        insertInQueue_Inst(inst2_queue, new_element2);
    }
    printQueueInst(inst2_queue);
    QueueElement *rec_element1 = returnQueueElement(inst_queue);
    QueueElement_Inst *rec_element2 = returnQueueElement_Inst(inst2_queue);
    printf("Rec1 Element: %s\n", rec_element1->element);
    printf("Rec2 ID: %d\n", rec_element2->element->instruction_id);
    deleteQueue(inst_queue);
    deleteQueueInst(inst2_queue);

    //// int *n_finds = boyer_moore(argv[1],argv[2]);
    //// my_print("Number of occurences in string: ",0);
    //// print_unsint(*n_finds);
    //// my_print("\n",0);
    //// free(n_finds);
    exit(0);
}