//
// Created by Greg Postnikoff on 23.10.17.
//

#ifndef PROCESOR_MYSTACKFUNC_H
#define PROCESOR_MYSTACKFUNC_H

int StackConstruct ( Stack_t * MyStack, int Count );

int CPUConstruct ( CPU_t * MyProc, MyCode * MyProg);

void StackPush ( Stack_t * MyStack, float Data );

float StackPop ( Stack_t * MyStack );

bool StackOk ( Stack_t * MyStack ) ;

int CountHash ( Stack_t * MyStack );

void StackDump ( Stack_t * MyStack );

MyCode CopyFile ( FILE * FileIn );

int OpenFile(FILE ** FileIn, const  char * filename);

int RunProgramm( MyCode * MyProg, CPU_t * MyProc );

int CheckVers(MyCode * MyProg);

#endif //PROCESOR_MYSTACKFUNC_H
