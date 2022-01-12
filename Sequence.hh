#ifndef _SEQ_H
#define _SEQ_H

#include "Instruction.hh"

class SeqItem {
  Instruction* i;
  SeqItem* next;
 
public:
  SeqItem(Instruction* i, SeqItem* next = NULL);
  ~SeqItem();

  inline const Instruction* getInst() const { return i; }
  inline bool hasNext() const { return (next != NULL); }
  inline SeqItem* getNext() const { return next; }

  void add(Instruction* i);
};

class Sequence : public Instruction {

  SeqItem* first;
  
public:
  Sequence(Instruction* i);
  ~Sequence();

  void add(Instruction *i);
  SeqItem* getFirst() const;

  void visit(Visitor& visitor) const;
};

#endif
