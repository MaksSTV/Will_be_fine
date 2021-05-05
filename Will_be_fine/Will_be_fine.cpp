// Will_be_fine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
const int Size_String = 5;
const int Size_Key_String = 50;

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
    char mark = '@';
};
void In_txt(ifstream& f, ifstream& f2, ofstream& f_out) {
    f.open("in.txt");
    f2.open("in2.txt");
    f_out.open("out.txt");
}
void Input_List(ifstream& f, Form_L1& list1, int& last) {
    char s = 'a';
    int i = 0;
    last = 0;
    list1.head = new L1;
    list1.cur = list1.head;
    list1.cur->elem.head = new list;
    list1.cur->elem.cur = list1.cur->elem.head;
    f.unsetf(ios::skipws);
    while (!f.eof()) {
        f >> s;
        if (f.eof()) {
            list1.cur->elem.cur->next = NULL;
            list1.cur->elem.last = list1.cur->elem.cur;
            break;
        }
        i++;
        if (s == '\n') {
            list1.cur->elem.cur->next = NULL;
            list1.cur->elem.last = list1.cur->elem.cur;
            list1.cur->next = new L1;
            list1.cur = list1.cur->next;
            list1.cur->elem.head = new list;
            list1.cur->elem.cur = list1.cur->elem.head;
            i = 0;
        }
        if ((i == Size_String)) {
            list1.cur->elem.cur->next = new list;
            list1.cur->elem.cur = list1.cur->elem.cur->next;
            i = 0;
        }


    }
    list1.cur->next = NULL;
    list1.last = list1.cur;
    list1.cur->elem.cur->next = NULL;
    list1.cur->elem.last = list1.cur->elem.cur;

    f.close();
    list1.cur = list1.head;
    list1.cur->elem.cur = list1.cur->elem.head;
    cout << "Which file open?\n";
    int a;
    cin >> a;
    if (a == 1) {
        f.open("in.txt");
    }
    else {
        f.open("in2.txt");
    }

    while (list1.cur->next != NULL) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            f >> list1.cur->elem.cur->s[i];
            i++;
            if (i == Size_String) {
                i = 0;
                list1.cur->elem.cur = list1.cur->elem.cur->next;
            }
        }
        i = 0;
        f >> list1.cur->elem.cur->s[i];
        while (list1.cur->elem.cur->s[i] != '\n') {
            i++;
            f >> list1.cur->elem.cur->s[i];
        }
        list1.cur = list1.cur->next;
        list1.cur->elem.cur = list1.cur->elem.head;
    }
    while (!f.eof()) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            f >> list1.cur->elem.cur->s[i];
            i++;
            last++;
            if (i == Size_String) {
                i = 0;
                list1.cur->elem.cur = list1.cur->elem.cur->next;
            }
        }
        i = 0;
        f >> list1.cur->elem.cur->s[i];
        while (true) {
            if (f.eof()) {
                list1.cur->elem.cur->s[i] = list1.mark;
                break;
            }
            i++;
            last++;
            f >> list1.cur->elem.cur->s[i];
        }

    }

}
void Out(ofstream& f_out, Form_L1& list1, int& last) {
    list1.cur = list1.head;
    list1.cur->elem.cur = list1.cur->elem.head;
    int i = 0;
    while (list1.cur->next != NULL) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            f_out << list1.cur->elem.cur->s[i];
            i++;
            if (i == Size_String) {
                i = 0;
                list1.cur->elem.cur = list1.cur->elem.cur->next;
                if (list1.cur->elem.cur->s[i] == '\n') {
                    f_out << "-------->";
                }
                else {
                    f_out << "->";
                }
            }
        }
        i = 0;
        f_out << list1.cur->elem.cur->s[i];
        while (list1.cur->elem.cur->s[i] != '\n') {
            if (list1.cur->elem.cur->s[i + 1] == '\n') {
                f_out << "-------->";
            }
            i++;
            f_out << list1.cur->elem.cur->s[i];
        }

        list1.cur = list1.cur->next;
        list1.cur->elem.cur = list1.cur->elem.head;
    }
    while (last != 0) {
        //int last1 = 0;
        i = 0;
        int flag = 0;
        while (list1.cur->elem.cur->next != NULL) {
            f_out << list1.cur->elem.cur->s[i];
            i++;
            last--;


            if (i == Size_String) {



                i = 0;
                list1.cur->elem.cur = list1.cur->elem.cur->next;
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
            /*if (list1.cur->elem.cur->s[i] == list1.mark) {
                f_out << "-------->x";
                break;
            }*/

            f_out << list1.cur->elem.cur->s[i];


            while (list1.cur->elem.cur->s[i] != list1.mark) {
                i++;
                //last1++;
                last--;
                if (last == 0) {
                    f_out << "-------->x\n";

                    break;
                }
                f_out << list1.cur->elem.cur->s[i];
            }
            //cout << last1 << last;

        }
    }
}

void Key_String(char Key[Size_Key_String]) {
    cout << "Input key string\n";
    cin >> Key;
    for (int i = 0; i < Size_Key_String; i++) {
        if (Key[i] == '\0') {
            break;
        }
        //cout << Key[i];
    }
}
void Check(Form_L1& list1, int& last) {
    char Key[Size_Key_String];
    Key_String(Key);
    list1.cur = list1.head;
    list1.cur->elem.cur = list1.cur->elem.head;
    // делаем прохiдку по всему списку
    int i = 0;
    int search = 0;
    int z = 0;
    while (list1.cur->next != NULL) {
        i = 0;
        search = 0;
        z = 0;

        while (list1.cur->elem.cur->next != NULL) {
            if ((Key[z] == list1.cur->elem.cur->s[i]) && (search != -1)) {// сравниваем слово с строкой
                search = 1;
            }
            else {
                search = -1;
            }
            z++;
            i++;
            if (i == Size_String) {
                i = 0;
                list1.cur->elem.cur = list1.cur->elem.cur->next;
            }
        }
        i = 0;
        search = 0;
        while (list1.cur->elem.cur->s[i] != '\n') {
            if ((Key[z] == list1.cur->elem.cur->s[i]) && (search != -1)) { // продолжаем сравнивать до конца строки с тем условием, что сходство еще есть
                search = 1;
            }
            else {
                search = -1;
            }
            i++;
            z++;
        }
        if ((Key[z] == '\0') && (list1.cur->elem.cur->s[i] == '\n') && (search != -1)) {//если конец строки и конец вводимой строки и они до этого были одинаковы
            search = 2;
            cout << "String found\n";//находим и выходим
            break;
        }
        list1.cur = list1.cur->next;
        list1.cur->elem.cur = list1.cur->elem.head;
    }
    while ((last != 0) && (search != 2)) {//отдельная обработка последней строки, с условием, что мы еще до этого не нашли похожих строк
        search = 0;
        z = 0;
        i = 0;
        int flag = 0;
        while (list1.cur->elem.cur->next != NULL) {
            if ((Key[z] == list1.cur->elem.cur->s[i]) && (search != -1)) {
                search = 1;
            }
            else {
                search = -1;
            }
            z++;
            i++;
            last--;
            if (i == Size_String) {
                i = 0;
                list1.cur->elem.cur = list1.cur->elem.cur->next;
                if (list1.cur->elem.cur->s[i] == list1.mark) {
                    if ((list1.cur->elem.cur->s[i] == list1.mark) && (Key[z] == '\0')) {
                        search = 2;
                        cout << "String found\n";
                        flag = -1;
                        break;
                    }
                    flag = -1;
                    break;
                }
            }
        }
        search = 0;
        if (flag != -1) {
            while (list1.cur->elem.cur->s[i] != list1.mark) {
                if ((Key[z] == list1.cur->elem.cur->s[i]) && (search != -1)) {
                    search = 1;
                }
                else {
                    search = -1;
                }
                i++;
                z++;
                last--;
                if (last == 0) {
                    if ((last == 0) && (search != -1) && (Key[z] == '\0')) {
                        search = 2;
                        cout << "String found\n";
                        break;
                    }
                    break;
                }
            }
        }
    }
}
int main()
{
    int last = 0;
    int b;
    Form_L1 list1, list2;
    ifstream f;
    ifstream f2;
    ofstream f_out;
    In_txt(f, f2, f_out);
    Input_List(f, list1, last);
    b = last;
    Out(f_out, list1, last);
    Input_List(f2, list2, last);
    Out(f_out, list2, last);
    Check(list1, b);
    system("pause");
    return 0;
}

