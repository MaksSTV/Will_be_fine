#include <iostream>
#include <fstream>
#include "Types.h"
#include "Def.h"
#include "Method.h"
using namespace std;

void Out(ofstream& f_out, Form_L1& list1, int& last) {
    int fleg = 0;
    Go_To(list1.cur, list1.head);
    Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
    int i = 0;
    while (list1.cur->next != NULL) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            Go_Output(&list1,i,f_out);
            i++;
            if (i == Size_String) {
                i = 0;
                Go_To_to(list1.cur->elem.cur, list1.cur->elem.cur->next);
                if (list1.cur->elem.cur->s[i] == list1.mark) {
                    f_out << "-------->\n";
                    fleg = -1;
                    break;
                }
                if (list1.cur->elem.cur->s[i] == '\n') {
                    f_out << "-------->";
                }
                else {
                    f_out << "->";
                }
            }
        }
        if (fleg != -1) {
            i = 0;
            Go_Output(&list1, i, f_out);
            while (list1.cur->elem.cur->s[i] != '\n') {
                if (list1.cur->elem.cur->s[i + 1] == list1.mark) {
                    f_out << "-------->\n";
                    break;
                }
                if (list1.cur->elem.cur->s[i + 1] == '\n') {
                    f_out << "-------->";
                }
                i++;
                Go_Output(&list1, i, f_out);
            }
            fleg = 0;
        }
        Go_To(list1.cur, list1.cur->next);
        Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
    }
    while (last != 0) {
        i = 0;
        int flag = 0;
        while (list1.cur->elem.cur->next != NULL) {
            Go_Output(&list1, i, f_out);
            i++;
            last--;
            if (i == Size_String) {
                i = 0;
                Go_To_to(list1.cur->elem.cur, list1.cur->elem.cur->next);
                if (list1.cur->elem.cur->s[i] == list1.mark) {
                    f_out << "-------->x\n";
                    flag = -1;
                    break;
                }
                else {
                    f_out << "->";
                }
            }
        }
        if (flag != -1) {
            i = 0;
            Go_Output(&list1, i, f_out);
            while (list1.cur->elem.cur->s[i] != list1.mark) {
                i++;
                last--;
                if (last == 0) {
                    f_out << "-------->x\n";
                    break;
                }
                Go_Output(&list1, i, f_out);
            }
        }
    }
}
void Delete(Form_L1& list) {
    Go_To(list.cur, list.head);
    while (list.cur->next != NULL)
    {
        Go_To(list.cur, list.head->next);
        delete list.head;
        Go_To(list.head, list.cur);
    }
    delete list.head;
}