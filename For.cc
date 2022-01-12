  #include "For.hh"
  For::For(Instruction* fcond, Instruction* body)
  : m_condition(fcond), m_body(body)
  {
      if (verify_iteration()) 
          throw std::invalid_argument("Presence d'une affectation sur la variable d'iteration dans la boucle.");
  }

  For::~For()
  {
      delete m_condition;
      delete m_body;
  }

  bool For::verify_iteration()
  {
      ForCondition* forcondition = (ForCondition*)m_condition;
      Sequence* sequence = (Sequence*)m_body;
      std::string var = forcondition->getVar();
      bool result = false;
      SeqItem* seqtmp = sequence->getFirst();
      while (seqtmp != nullptr) {
         /* const Instruction* inst = seqtmp->getInst();
          const Affect* affect = dynamic_cast<const Affect*>(inst);
          if (affect != nullptr) {
              std::string v_affect = affect->getVar();
              std::cout << var << std::endl;
              std::cout << v_affect << std::endl;
              result = (v_affect.compare(var) == 0);
          }*/
          std::cout << seqtmp->getInst() << std::endl;
          std::cout << seqtmp->hasNext() << std::endl;
          seqtmp = seqtmp->getNext();
      }
      return result;
  }
