#ifndef Types_h
#define Types_h
#pragma once
using namespace std;
const int Size_String = 4;

struct list
{
    char s[Size_String];
    list* next;
};
struct form_list {
    list* head, * cur, * last;
};
struct L1 {
    form_list elem;
    L1* next;
};
struct Form_L1 {
    L1* head, * cur, * last;
    char mark = '¹';
};

#endif // !Types_h
