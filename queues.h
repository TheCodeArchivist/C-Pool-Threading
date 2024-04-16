#ifndef Queues_Structs
#define Queues_Structs
    typedef struct QueueElement {
        void *element;
        struct QueueElement *next_element; // Next element = Element next to the taken element in the queue.
    } QueueElement;

    typedef struct QueueElement_Inst {
        struct Instruction *element;
        struct QueueElement_Inst *next_element; // Next element = Element next to the taken element in the queue.
    } QueueElement_Inst;

    typedef struct Queue {
        int n_elements_queue;
        struct QueueElement *first_element;
    } Queue;

    typedef struct Queue_Inst {
        int n_elements_queue;
        struct QueueElement_Inst *first_element;
    } Queue_Inst;
#endif

#ifndef Queues_CreateFuncs
#define Queues_CreateFuncs
    void *createQueue() {
        Queue *queue = malloc(sizeof(struct Queue));
        queue->n_elements_queue = 0;
        queue->first_element = NULL;
        return queue;
    }

    void *createQueueElement(void *element) {
        QueueElement *queue_element = malloc(sizeof(struct QueueElement));
        queue_element->element = element;
        queue_element->next_element = NULL;
        return queue_element;
    }

    void *createQueueElement_Inst(Instruction *element) {
        QueueElement_Inst *queue_element = malloc(sizeof(struct QueueElement_Inst));
        queue_element->element = element;
        queue_element->next_element = NULL;
        return queue_element;
    }

    void insertInQueue(Queue *queue, QueueElement *queue_element) {
        QueueElement *curr_element = queue->first_element;
        if (curr_element == NULL) {
            queue->first_element = queue_element;
            queue->n_elements_queue += 1;
            return;
        }

        queue_element->next_element = curr_element;
        queue->first_element = queue_element;
        queue->n_elements_queue += 1;
    }

    void insertInQueue_Inst(Queue_Inst *queue, QueueElement_Inst *queue_element) {
        QueueElement_Inst *curr_element = queue->first_element;
        if (curr_element == NULL) {
            queue->first_element = queue_element;
            queue->n_elements_queue += 1;
            return;
        }

        queue_element->next_element = curr_element;
        queue->first_element = queue_element;
        queue->n_elements_queue += 1;
    }

    void *returnQueueElement(Queue *queue) {
        QueueElement *first_element = queue->first_element;
        QueueElement *next_element = first_element->next_element;

        queue->first_element = next_element;
        return first_element;
    }

    void *returnQueueElement_Inst(Queue_Inst *queue) {
        QueueElement_Inst *first_element = queue->first_element;
        QueueElement_Inst *next_element = first_element->next_element;

        queue->first_element = next_element;
        return first_element;
    }
#endif

#ifndef Queues_PrintFuncs
#define Queues_PrintFuncs
    void printQueueRaw(Queue *queue) {
        int i = 1;
        QueueElement *curr_element = queue->first_element;
        while (curr_element != NULL) {
            my_print("Element ID: ", 0);
            print_unsint(i);
            putchar('\n');
            curr_element = curr_element->next_element;
            i += 1;
        }
        printf("%p\n",curr_element);
    }

    void printQueueInst(Queue_Inst *queue) {
        int i = 1;
        QueueElement_Inst *curr_element = queue->first_element;
        Instruction *instruction;
        while (curr_element != NULL) {
            my_print("Element ID: ", 0);
            print_unsint(i);
            putchar('\n');
            instruction = curr_element->element;
            my_print("Instruction ID: ", 0);
            print_unsint(instruction->instruction_id);
            putchar('\n');
            curr_element = curr_element->next_element;
            i += 1;
        }
        printf("%p\n",curr_element);
    }
#endif

#ifndef Queues_DeleteFuncs
#define Queues_DeleteFuncs
    void deleteQueue(Queue *queue) {
        QueueElement *first_element = queue->first_element;
        QueueElement *next_element;
        while (next_element != NULL) {
            next_element = first_element->next_element;
            free(first_element);
            first_element = next_element;
        }
        free(queue);
    }

    void deleteQueueInst(Queue_Inst *queue) {
        QueueElement_Inst *first_element = queue->first_element;
        QueueElement_Inst *next_element;
        Instruction *instruction;
        while (first_element != NULL) {
            next_element = first_element->next_element;
            instruction = first_element->element;
            free(instruction);
            free(first_element);
            first_element = next_element;
        }
        free(queue);
    }
#endif