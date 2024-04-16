#ifndef Instructions_Structs
#define Instructions_Structs
    typedef struct Instruction {
        int instruction_id;
        void* func_exec;
    } Instruction;
#endif