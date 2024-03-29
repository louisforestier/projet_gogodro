//Clémentine Guillot & Louis Forestier
#include "For.hh"
For::For(Instruction *fcond, Instruction *body)
    : m_condition(dynamic_cast<ForCondition *>(fcond)), m_body(body)
{
    if (verify_iteration())
        throw std::invalid_argument("Presence d'une affectation sur la variable d'iteration dans la boucle.");
}

For::~For()
{
    delete m_condition;
    delete m_body;
}

void For::visit(Visitor &visitor) const
{
    return visitor.visitFor(this);
}

bool For::verify_iteration() const
{
    ForCondition *forcondition = m_condition;
    Sequence *sequence = (Sequence *)m_body;
    std::string var = forcondition->getVar();
    bool result = false;
    SeqItem *seqtmp = sequence->getFirst();
    while (seqtmp != nullptr)
    {
        const Instruction *inst = seqtmp->getInst();
        const Affect *affect = dynamic_cast<const Affect *>(inst);
        if (affect != nullptr)
        {
            std::string v_affect = affect->getVar();
            result = (v_affect.compare(var) == 0);
        }
        const For *for_imbric = dynamic_cast<const For *>(inst);
        if (for_imbric != nullptr)
        {
            std::vector<std::string> variables;
            variables.push_back(var);
            result = for_imbric->verify_iteration(variables);
        }
        seqtmp = seqtmp->getNext();
    }
    return result;
}

bool For::verify_iteration(std::vector<std::string> variables) const
{
    ForCondition *forcondition = m_condition;
    Sequence *sequence = (Sequence *)m_body;
    std::string var = forcondition->getVar();
    bool result = false;
    SeqItem *seqtmp = sequence->getFirst();
    while (seqtmp != nullptr)
    {
        const Instruction *inst = seqtmp->getInst();
        const Affect *affect = dynamic_cast<const Affect *>(inst);
        if (affect != nullptr)
        {
            std::string v_affect = affect->getVar();
            for (std::string v : variables)
            {
                result = result || (v_affect.compare(v) == 0);
            }
        }
        else
        {
            const For *for_imbric = dynamic_cast<const For *>(inst);
            if (for_imbric != nullptr)
            {
                variables.push_back(var);
                result = for_imbric->verify_iteration(variables);
            }
        }
        seqtmp = seqtmp->getNext();
    }
    return result;
}
