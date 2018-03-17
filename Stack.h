//
// Created by Greg Postnikoff on 30.10.17.
//

#ifndef PROCESOR_STACK_H
#define PROCESOR_STACK_H

#define IMPLEMENT(ElemT) \
    struct Stack_t_##ElemT { \
    \
        int LeftCheck = 0;\
    \
        ElemT * Data = NULL;\
    \
        int count = 0, MaxSize = 0;\
    \
        int Hash = 0;\
    \
        int RightCheck = 0;\
    \
    };

#endif //PROCESOR_STACK_H
