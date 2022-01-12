#include "printer.hh"
#include <iostream>

using namespace std;


void Printer::visitInt(const Int* i) {
    cout << i->getValue();
}

void Printer::visitVar(const Var* v) {
    cout << v->getName();
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
    cout << endl;
}

void Printer::visitFor(const For* f) {
    f->getCond()->visit(*this);
    f->getBody()->visit(*this);
}


void Printer::visitSeq(const Sequence* s) {
    cout << "Debut d'une sequence." << endl;
    SeqItem* t = s->getFirst();
    while (t != NULL) {
        t->getInst()->visit(*this);
        t = t->getNext();
    }
    cout << "Fin d'une sequence." << endl;
}


void Printer::visitColor(const Color* c) {
    cout << c->getColor() << endl;
}
void Printer::visitCoordinate(const Coordinate* c) {
    cout << "(";
    c->getX()->visit(*this);
    cout << ",";
    c->getY()->visit(*this);
    cout << ")" << endl;
}

void Printer::visitLine(const Line* l) {
    cout << "Debut : ";
    l->getBegin()->visit(*this);
    cout << "Fin : ";
    l->getEnd()->visit(*this);
}
void Printer::visitMove(const Move* m) {
    cout << "bouger vers";
    m->getC()->visit(*this);
    cout << endl;
}
void Printer::visitPutDown(const PutDown* p) {
    cout << "poser" << endl;
}
void Printer::visitRaise(const Raise* r) {
    cout << "lever" << endl;
}
void Printer::visitRectangle(const Rectangle* r) {
    r->getCoord()->visit(*this);
    r->getLength()->visit(*this);
    r->getWidth()->visit(*this);
}

void Printer::visitForCondition(const ForCondition* f) {
    cout << f->getVar() << " de ";
    f->getBegin()->visit(*this);
    cout << " a ";
    f->getEnd()->visit(*this);
    cout << endl;
}