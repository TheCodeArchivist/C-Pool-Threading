#ifndef ThreadPool_Structs
#define ThreadPool_Structs
    typedef struct Worker {
        int worker_id;

        /**
         * 0 -> Free
         * 1 -> Occupied
         * 2 -> Waiting
        */
        int worker_status;
        struct Worker *next_worker;
    } Worker;

    typedef struct Worker_ThreadPool {
        int threadpool_id;
        int n_workers;
        struct Worker *first_worker;
    } Worker_ThreadPool;
#endif

#ifndef ThreadPool_CreateFuncs
#define ThreadPool_CreateFuncs
    void *create_threadpool(int id, Worker *first_worker) {
        Worker_ThreadPool *threadpool = malloc(sizeof(struct Worker_ThreadPool));
        threadpool->threadpool_id = id;
        threadpool->n_workers = 1;
        threadpool->first_worker = first_worker;
        return threadpool;
    }

    void *create_worker(int id) {
        Worker *worker = malloc(sizeof(struct Worker));
        worker->worker_id = id;
        worker->worker_status = 0;
        worker->next_worker = NULL;
        return worker;
    }

    void insert_worker_thread(Worker_ThreadPool *threadpool, Worker *worker) {
        Worker *curr_worker = threadpool->first_worker;
        while (curr_worker->next_worker != NULL)
        {
            curr_worker = curr_worker->next_worker;
        }
        curr_worker->next_worker = worker;
    }

    void *create_threadpool_n_workers(int n_workers) {
        Worker_ThreadPool *threadpool = create_threadpool(1, create_worker(1));
        n_workers -= 1;
        int i;
        for (i=2; n_workers<=0; i++) {
            insert_worker_thread(threadpool, create_worker(i));
        }
        return threadpool;
    }

    void destroy_threadpool(Worker_ThreadPool *threadpool) {
        Worker *curr_worker = threadpool->first_worker;
        Worker *old_worker = curr_worker;
        while (curr_worker != NULL)
        {
            old_worker = curr_worker;
            curr_worker = curr_worker->next_worker;
            free(old_worker);
        }
    }
#endif

#ifndef ThreadPool_PrintFuncs
#define ThreadPool_PrintFuncs
    // ...
#endif