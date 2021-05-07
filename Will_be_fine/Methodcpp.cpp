#include <iostream>
#include <fstream>
#include "Types.h"
#include "Def.h"
#include "Method.h"
using namespace std;

void AddNewElem(L1*& p) {
	p = new L1;
}
void AddNewElemElem(list*& p) {
	p = new list;
}
void Go_To(L1*& from, L1*& to) {
	from = to;
}
void Go_To_to(list*& from, list*& to) {
	from = to;
}
void Go_NULL(L1** p) {
	*p = NULL;
}
void Go_NULL_null(list** p) {
	*p = NULL;
}
void Go_Marker(Form_L1* p,int& i) {
	p->cur->elem.cur->s[i] = p->mark;
}


void Go_Input(Form_L1* p, int& i, ifstream& f) {
	f >> p->cur->elem.cur->s[i];
}
void Go_Output(Form_L1* p, int& i, ofstream& f) {
	f << p->cur->elem.cur->s[i];
}