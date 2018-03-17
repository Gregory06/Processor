//
// Created by Greg Postnikoff on 23.10.17.
//

#ifndef PROCESOR_STACKFUNC_H
#define PROCESOR_STACKFUNC_H

int CPUConstruct ( CPU_t * MyProc, MyCode * MyProg) {

    StackConstruct( &MyProc->MyStack, MyProg->Size / 3 );

    StackConstruct( &MyProc->RetStack, MyProg->Size / 3 );

    int RegSize = 0;

#define REG(name, num) \
    RegSize++;

#include "/Users/MyMac/CLionProjects/TopProgramming/ComileLite/registr.h"

    MyProc->Reg = (float *) calloc(RegSize, sizeof(float));

    for (int i = 0; i < RegSize; i++)
        MyProc->Reg[i] = 0;

    return 0;

}

int RunProgramm( MyCode * MyProg, CPU_t * MyProc) {

//    if (!CheckVers(MyProg))
//        printf("WTFFF");

    int k = 0;
    float input = 0;

    for (int Pos = SgnPos; Pos < MyProg->Size;) {

#include "/Users/MyMac/CLionProjects/TopProgramming/ComileLite/Consts.h"

        switch ((int) MyProg->MachineCode[Pos]) {

#define DEF_CMD(name, num, code) \
    case CMD_##name:\
        code\
    break;

#include "/Users/MyMac/CLionProjects/TopProgramming/ComileLite/commands.h"

#undef DEF_CMD
            default:
                Pos++;
                break;



        };

    }

    return 0;

}

int CheckVers(MyCode * MyProg) {

    int counter = 0;

    for (int i = 0; i < StrSize;)

    switch ((int) MyProg->MachineCode[i++]) {

        case SGN1:
            counter++;
            break;
        case SGN2:
            counter++;
            break;
        case SGN3:
            counter++;
            break;
        case ProgVers:
            counter++;
            break;

    }

    if (counter != SgnPos)
        return SUCCESS;
    else
        return ERROR;

}

#endif //PROCESOR_STACKFUNC_H
