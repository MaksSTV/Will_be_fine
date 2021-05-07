#include <iostream>
#include <fstream>
#include "Types.h"
#include "Def.h"
#include "Method.h"
using namespace std;

int Check(Form_L1& list1, Form_L1& list3, int& last) {
    Go_To(list1.cur, list1.head);
    Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
    Go_To(list3.cur, list3.head);
    Go_To_to(list3.cur->elem.cur, list3.cur->elem.head);
    // делаем прохiдку по всему списку
    int i = 0;
    int search = 0;
    int z = 0;
    while (list1.cur->next != NULL) {
        i = 0;
        search = 0;
        if (z != 0) {
            Go_To(list1.cur, list1.cur->next);
            Go_To_to(list1.cur->elem.cur, list1.cur->elem.head);
        }
        if (list1.cur->next == NULL) {
            break;
        }
        z = 1;
        Go_To(list3.cur, list3.head);
        Go_To_to(list3.cur->elem.cur, list3.cur->elem.head);

        while ((list1.cur->elem.cur->next != NULL)&&(list3.cur->elem.cur->next != NULL)) {
            if ((list3.cur->elem.cur->s[i] == list1.cur->elem.cur->s[i]) && (search != -1)) {// сравниваем слово с строкой
                search = 1;
            }
            else {
                search = -1;
            }
            i++;
            if (i == Size_String) {
                i = 0;
                Go_To_to(list1.cur->elem.cur, list1.cur->elem.cur->next);
                Go_To_to(list3.cur->elem.cur, list3.cur->elem.cur->next);
            }
        }
        if (((list1.cur->elem.cur->next == NULL) && (list3.cur->elem.cur->next != NULL)) || ((list1.cur->elem.cur->next != NULL) && (list3.cur->elem.cur->next == NULL))) {
            continue;
        }
        else {
            i = 0;
            while (true) {
                if ((list3.cur->elem.cur->s[i] == list1.mark) && (list1.cur->elem.cur->s[i] == '\n') && (search != -1)) {
                    search = 2;
                    break;
                }
                if (((list3.cur->elem.cur->s[i] != list1.mark) && (list1.cur->elem.cur->s[i] == '\n') && (search == -1))||((list3.cur->elem.cur->s[i] == list1.mark) && (list1.cur->elem.cur->s[i] != '\n') && (search == -1))) {
                    search = -1;
                    break;
                }
                if (list3.cur->elem.cur->s[i] != list1.cur->elem.cur->s[i]) {
                    search = -1;
                    break;
                }
                if ((list3.cur->elem.cur->s[i] == list1.cur->elem.cur->s[i]) && (search != -1)) { // продолжаем сравнивать до конца строки с тем условием, что сходство еще есть
                    search = 1;
                }
                else {
                    search = -1;
                }
                i++;
            }
        }
        if (search == 2) {
            break;
        }
    }
    while ((last != 0) && (search != 2)) {//отдельная обработка последней строки, с условием, что мы еще до этого не нашли похожих строк
        search = 0;
        Go_To(list3.cur, list3.head);
        Go_To_to(list3.cur->elem.cur, list3.cur->elem.head);
        i = 0;
        int flag = 0;
        while ((list1.cur->elem.cur->next != NULL) && (list3.cur->elem.cur->next != NULL)) {
            if ((list1.cur->elem.cur->s[i] == list3.cur->elem.cur->s[i]) && (search != -1)) {
                search = 1;
            }
            else {
                search = -1;
            }
            i++;
            last--;
            if (i == Size_String) {
                i = 0;
                Go_To_to(list1.cur->elem.cur, list1.cur->elem.cur->next);
                Go_To_to(list3.cur->elem.cur, list3.cur->elem.cur->next);
                if ((list1.cur->elem.cur->s[i] == list1.mark) && (list3.cur->elem.cur->s[i] == list1.mark) && (search == 1)) {
                    search = 2;
                    flag = -1;
                    break;
                }
                if ((list1.cur->elem.cur->s[i] == list1.mark) && (list3.cur->elem.cur->s[i] == list1.mark) && (search == -1)) {
                    flag = -1;
                    break;
                }
                if (((list1.cur->elem.cur->s[i] != list1.mark) && (list3.cur->elem.cur->s[i] == list1.mark)) || ((list1.cur->elem.cur->s[i] == list1.mark) && (list3.cur->elem.cur->s[i] != list1.mark))) {
                    flag = -1;
                    break;
                }
            }
        }
        if (flag != -1) {
            while (true) {
                if ((list1.cur->elem.cur->s[i] == list3.cur->elem.cur->s[i]) && (search != -1)) {
                    search = 1;
                }
                else {
                    search = -1;
                }
                i++;
                last--;
                if (last == 0) {
                    if ((last == 0) && (search != -1) && (list1.cur->elem.cur->s[i] == list1.mark) && (list3.cur->elem.cur->s[i] == list1.mark)) {
                        search = 2;
                        break;
                    }
                    break;
                }
            }
        }
    }
    if (search == 2) {
        return 1;
    }
    else {
        return 0;
    }
}
int Add(Form_L1& list1, Form_L1& list2) {
    if (list1.cur->next != NULL) {
        Go_To(list2.last->next, list1.cur->next);
        Go_To(list1.cur->next, list2.head);
        return 1;
    }
    else {
        Go_To(list1.cur->next, list2.head);
        return 0;
    }
}