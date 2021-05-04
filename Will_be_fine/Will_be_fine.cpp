// Will_be_fine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
const int N = 5;
struct list
{
    char s[N];
    list* next;
};
struct form_list {
    list *head, *cur, *last;
};
struct L1 {
    form_list elem;
    L1* next;
};
struct Form_L1 {
    L1 *head, *cur, *last;
    char mark='@';
};
void In_txt(ifstream& f, ifstream& f2, ofstream& f_out) {
    f.open("in.txt");
    f2.open("in2.txt");
    f_out.open("out.txt");
}
void Input_List(ifstream& f, Form_L1 &list1, int &last) {
    char s = 'a';
    int i = 0;
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
        if  ((i == N)) {
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
    f.open("in.txt");
    while (list1.cur->next != NULL) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            f >> list1.cur->elem.cur->s[i];
            i++;
            if (i == N) {
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
            if (i == N) {
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
    if (f.eof()) {
       // list1.cur->elem.cur->s[i] = list1.mark;
        cout << last;
    }
}
void Out(ofstream& f_out, Form_L1& list1, int &last) {
    list1.cur = list1.head;
    list1.cur->elem.cur = list1.cur->elem.head;
    int i = 0;
    while (list1.cur->next != NULL) {
        i = 0;
        while (list1.cur->elem.cur->next != NULL) {
            f_out << list1.cur->elem.cur->s[i];
            i++;
            if (i == N) {
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
    while (last!=0) {
        int last1 = 0;
        i = 0;
        int flag = 0;
        while (list1.cur->elem.cur->next != NULL) {
            f_out << list1.cur->elem.cur->s[i];
            i++;
            last--;
            last1++;
            if (i == N) {
                i = 0;
                list1.cur->elem.cur = list1.cur->elem.cur->next;
                if (list1.cur->elem.cur->s[i] == list1.mark) {
                    f_out << "-------->x";
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
                last1++;
                last--;
                if (last == 0) {
                    f_out << "-------->x";

                    break;
                }
                f_out << list1.cur->elem.cur->s[i];
            }
            cout << last1 << last;

        }
    }
}
int main()
{
    int last = 0;
    Form_L1 list1, list2;
    ifstream f;
    ifstream f2;
    ofstream f_out;
    In_txt(f, f2, f_out);
    Input_List(f, list1,last);
    Out(f_out, list1,last);
    system("pause");
    return 0;
}

