#include <iostream>
#include <fstream>
#include "Types.h"
#include "Def.h"
#include "Method.h"
using namespace std;

void In_txt(ifstream& f, ifstream& f2, ifstream& f3, ofstream& f_out) {
    f.open("in.txt");
    f2.open("in2.txt");
    f3.open("in3.txt");
    f_out.open("out.txt");
}
void Input_List(ifstream& f, Form_L1& list1, int& last) {
    char s = 'a';
    int i = 0;
    last = 0;
    AddNewElem(list1.head);
    Go_To(list1.cur, list1.head);
    AddNewElemElem(list1.cur->elem.head);
    Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
    f.unsetf(ios::skipws);
    while (!f.eof()) {
        f >> s; 
        if (f.eof()) {
            Go_NULL_null(&list1.cur->elem.cur->next);
            Go_To_to(list1.cur->elem.last, list1.cur->elem.cur);
            break;
        }
        i++;
        if (s == '\n') {
            Go_NULL_null(&list1.cur->elem.cur->next);
            Go_To_to(list1.cur->elem.last, list1.cur->elem.cur);
            AddNewElem(list1.cur->next);
            Go_To(list1.cur, list1.cur->next);
            AddNewElemElem(list1.cur->elem.head);
            Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
            i = 0;
        }
        if ((i == Size_String)) {
            AddNewElemElem(list1.cur->elem.cur->next);
            Go_To_to(list1.cur->elem.cur, list1.cur->elem.cur->next);
            i = 0;
        }


    }
    Go_NULL(&list1.cur->next);
    Go_To(list1.last, list1.cur);
    Go_NULL_null(&list1.cur->elem.cur->next);
    Go_To_to(list1.cur->elem.last, list1.cur->elem.cur);
    f.close();
    Go_To(list1.cur, list1.head);
    Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
    cout << "Which file open?\n";
    int a;
    cin >> a;
    if (a == 1) {
        f.open("in.txt");
    }
    else if(a==2) {
        f.open("in2.txt");
    }
    else if (a == 3) {
        f.open("in3.txt");
    }

    while (list1.cur->next != NULL) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            Go_Input(&list1,i,f);
            i++;
            if (i == Size_String) {
                i = 0;
                Go_To_to(list1.cur->elem.cur, list1.cur->elem.cur->next);
            }
        }
        i = 0;
        Go_Input(&list1, i, f);
        while (list1.cur->elem.cur->s[i] != '\n') {
            i++;
            Go_Input(&list1, i, f);
        }
        Go_To(list1.cur, list1.cur->next);
        Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
    }
    while (!f.eof()) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            Go_Input(&list1, i, f);
            i++;
            last++;
            if (i == Size_String) {
                i = 0;
                Go_To_to(list1.cur->elem.cur, list1.cur->elem.cur->next);
            }
        }
        i = 0;
        Go_Input(&list1, i, f);
        while (true) {
            if (f.eof()) {
                Go_Marker(&list1, i);
                break;
            }
            i++;
            last++;
            Go_Input(&list1, i, f);
        }
    }
}