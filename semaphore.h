#ifndef Semaphore_Structs
#define Semaphore_Structs
typedef struct Semaphore {
    bool active;
    bool lock;
    int max_limit;
    int count;
} Semaphore;
#endif

#ifndef Semaphore_CreateFuncs
#define Semaphore_CreateFuncs
    void *createSemaphore(int limit, int active) {
        Semaphore *semaphore = malloc(sizeof(Semaphore));
        semaphore->active = active;
        semaphore->lock = false;
        semaphore->max_limit = limit;
        semaphore->count = limit;
        return semaphore;
    }
#endif

#ifndef Semaphore_CheckFuncs
#define Semaphore_CheckFuncs
    bool checkSemaphoreAvailability(Semaphore *semaphore) {
        if (semaphore->active == false ||
            semaphore->lock == true ||
            semaphore->count < 1)
            return false;
        return true;
    }
#endif

#ifndef Semaphore_DeleteFuncs
#define Semaphore_DeleteFuncs
    void deleteSemaphore(Semaphore *semaphore) {
        if (semaphore->active == true || semaphore->count != semaphore->max_limit) {
            my_print("SEMAPHORE NOT DISABLED OR NOT DONE: MAY STILL BE IN NEED\nRAISING EXCEPTION!",'\n');
            exit(1);
        }
        free(semaphore);
    }
#endif