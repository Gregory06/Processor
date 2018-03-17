//
// Created by Greg Postnikoff on 23.10.17.
//

#ifndef PROCESOR_MYSTACK_H
#define PROCESOR_MYSTACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int StackConstruct ( Stack_t * MyStack, int Count ) {

    if ( Count < 0 )
        return COUNT_ERROR;

    MyStack->MaxSize = Count;

    MyStack->Data =  (float *) calloc(sizeof(float), Count);

    if ( MyStack->Data == NULL )
        return MEMBER_ERROR;

    MyStack->count = 0;

    MyStack->Hash = 0;

    MyStack->LeftCheck = MyStack->RightCheck = SOME_RANDOME_NUM;

    return OK;

}

void StackPush ( Stack_t * MyStack, float Data ) {

    if (MyStack->count < MyStack->MaxSize) {
        MyStack->Data[MyStack->count] = Data;
        MyStack->count++;
    }

    MyStack->Hash = CountHash( MyStack );

}

float StackPop ( Stack_t * MyStack ) {

    if (MyStack->count > 0) {

        MyStack->count--;

        MyStack->Hash = CountHash(MyStack);

        return MyStack->Data[MyStack->count];

    }

}

bool StackOk ( Stack_t * MyStack ) {

    if (MyStack->count < 0) return false;

    if (MyStack->LeftCheck != MyStack->RightCheck) return false;

    if (MyStack->Hash != CountHash( MyStack )) return false;

    return true;
}

int CountHash ( Stack_t * MyStack ) {

    int Hash = 0;
    for ( int i = 0; i < MyStack->MaxSize; i++ )
        Hash += MyStack->Data[i] * (i + 1) + MyStack->MaxSize - MyStack->count;

    return Hash;

}

void StackDump ( Stack_t * MyStack ) {

    printf("Left %d, Right %d: ", MyStack->LeftCheck, MyStack->RightCheck);
    if (MyStack->LeftCheck == MyStack->RightCheck)
        printf("OK\n");
    else
        printf("NOT OK!\n");

    printf("Current pos: %d", MyStack->count );
    if ( MyStack->count < 0 )
        printf(": NOT OK!\n");
    printf("\n");

    printf("Max size: %d", MyStack->MaxSize);
    if ((MyStack->MaxSize < 0) || (MyStack->MaxSize < MyStack->count))
        printf(": NOT OK!\n");
    printf("\n");

}

#endif //PROCESOR_MYSTACK_H
