//
// Created by Greg Postnikoff on 23.10.17.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef PROCESOR_FILEFUNC_H
#define PROCESOR_FILEFUNC_H

int OpenFile(FILE ** FileIn, const  char * filename) {

    *FileIn = fopen("/Users/MyMac/CLionProjects/TopProgramming/Procesor/1.txt", "r");

    if (!*FileIn) {

        return ERROR_OPEN_FILE;

    }

    return SUCCESS_OPEN_FILE;

}

MyCode CopyFile ( FILE * FileIn ) {

    float ForCount = 0;
    int Quant = 0;

    while (fscanf( FileIn, "%f", &ForCount ) == 1)
        Quant++;

    float * MachineCode = (float *) calloc( Quant, sizeof(float));

    fseek( FileIn, 0, SEEK_SET);

    int i = 0;

    while (fscanf( FileIn, "%f", &MachineCode[i] ) == 1)
        i++;

    MyCode MyProgramm;
    MyProgramm.MachineCode = MachineCode;
    MyProgramm.Size = Quant;

    return MyProgramm;

}

#endif //PROCESOR_FILEFUNC_H
