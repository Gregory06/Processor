#include <stdio.h>
#include <cmath>
#include "/Users/MyMac/CLionProjects/TopProgramming/ComileLite/Consts.h"


enum {
    SOME_RANDOME_NUM = 45627,
    MEMBER_ERROR = 3,
    COUNT_ERROR = 2,
    OK = 0,
    SUCCESS_OPEN_FILE = 0,
    ERROR_OPEN_FILE = 1
};



#define DEF_CMD(name, num, code) \
            CMD_##name = num,

enum Commands {

#include "/Users/MyMac/CLionProjects/TopProgramming/ComileLite/commands.h"
    CMD_MAX = 30

};

#undef DEF_CMD

struct MyCode {

    float * MachineCode = NULL;

    int Size = 0;

};

struct Stack_t {

    int LeftCheck = 0;

    float * Data = NULL;

    int count = 0, MaxSize = 0;

    int Hash = 0;

    int RightCheck = 0;

};

struct CPU_t {

    Stack_t MyStack = {};

    Stack_t RetStack = {};

    float * Reg = {};

    float RAM[RamSize] = {};

};


#include "FuncNames.h"


int main() {

    FILE * FileIn = NULL;

    char filename[MaxFileNameSize] = {};

    int FILEOpenRes = OpenFile( &FileIn, filename );

    if ( FILEOpenRes != SUCCESS_OPEN_FILE ) {
        printf("ERROR OPEN FILE");
        return 0;
    }

    MyCode MyProg = CopyFile( FileIn );

    CPU_t MyProc = {};

    MyProc.RAM[(int )MyProc.Reg[(int)MyProg.MachineCode[9]]];

    CPUConstruct( &MyProc, &MyProg );

    RunProgramm( &MyProg, &MyProc );

    return 0;

}

#include "StackFunc.h"

#include "FileFunc.h"

#include "CPUFunc.h"