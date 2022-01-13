//Clémentine Guillot & Louis Forestier
#include "Sequence.hh"
#include <iostream>

SeqItem::SeqItem(Instruction *i, SeqItem *next)
  : i(i),next(next)
{
}

SeqItem::~SeqItem() {
  delete i;
  if(next != NULL)
    delete next;
}

void SeqItem::add(Instruction *i) {
  if(next == NULL)
    next = new SeqItem(i);
  else
    next->add(i);  
}

Sequence::Sequence(Instruction *inst)
  : first(NULL)
{
  if(inst != NULL) {
    first = new SeqItem(inst);
  }
}

Sequence::~Sequence() {
  if(first != NULL)
    delete first;
}

void Sequence::add(Instruction *i) {
  if(first == NULL)
    first = new SeqItem(i,first);
  else
    first->add(i);
}

SeqItem* Sequence::getFirst() const
{
    return first;
}

void Sequence::visit(Visitor& visitor) const {
    visitor.visitSeq(this);
}