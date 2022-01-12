#include "printer.hh"
#include <iostream>

using namespace std;


void Printer::visitInt(const Int* i) {
    cout << i->getValue();
}

void Printer::visitVar(const Var* v) {
    cout << v->getIdent();
}


void Printer::visitOpe(const Ope* o) {
    cout << "(";
    o->getLeft()->visit(*this);
    switch (o->getSymbol()) {
    case PLUS: cout << "+"; break;
    case MOINS: cout << "-"; break;
    case MULT: cout << "*"; break;
    case DIV: cout << "/"; break;
    case MOD: cout << "mod"; break;
    default: cout << " ??? "; break;
    }
    o->getRight()->visit(*this);
    cout << ")";
}

void Printer::visitAffect(const Affect* a) {
    cout << a->getVar() << " = ";
    a->getExpr()->visit(*this);
    cout << ";" << endl;
}

void Printer::visitFor(const For* f) {
    f->getCond()->visit(*this);
    f->getBody()->visit(*this);
}


void Printer::visitSeq(const Sequence* s) {
    cout << "ATTENTION Inversion possible (en fct de votre algo)!" << endl;
    SeqItem* t = s->getFirst();
    while (t != NULL) {
        t->getInst()->visit(*this);
        t = t->getNext();
    }
    cout << "ATTENTION Inversion possible (en fct de votre algo)!" << endl;
}


void Printer::visitColor(const Color* c) {
    cout << c->getColor() << endl;
}
void Printer::visitCoordinate(const Coordinate* c) {
    cout << "( ";
    c->getX()->visit(*this);
    cout << ",";
    c->getY()->visit(*this);
    cout << ")" << endl;
}

void Printer::visitLine(const Line* l) {
    cout << "Begin : ";
    l->getBegin()->visit(*this);
    cout << "End : ";
    l->getEnd()->visit(*this);
}
void Printer::visitMove(const Move* m) {
    cout << m->getC() << ";" << endl;
}
void Printer::visitPutDown(const PutDown* p) {
    cout << "put down" << endl;
}
void Printer::visitRaise(const Raise* r) {
    cout << "raise" << endl;
}
void Printer::visitRectangle(const Rectangle* r) {
    r->getCoord()->visit(*this);
    r->getLength()->visit(*this);
    r->gtWidth()->visit(*this);
}