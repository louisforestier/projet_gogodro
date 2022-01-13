#include "Drawer.hh"
#include <iostream>
const unsigned char Drawer::BLACK[3] = {0, 0, 0};
const unsigned char Drawer::WHITE[3] = {255, 255, 255};
const unsigned char Drawer::RED[3] = {255, 0, 0};
const unsigned char Drawer::ORANGE[3] = {255, 165, 0};
const unsigned char Drawer::YELLOW[3] = {255, 255, 0};
const unsigned char Drawer::GREEN[3] = {0, 255, 0};
const unsigned char Drawer::BLUE[3] = {0, 0, 255};
const unsigned char Drawer::PURPLE[3] = {128, 0, 128};

Drawer::Drawer(int sizeX, int sizeY)
    : m_sizeX(sizeX), m_sizeY(sizeY), m_currX(0), m_currY(0), m_isDrawing(false), m_img(sizeX, sizeY, 1, 3)
{
    std::copy(Drawer::BLACK, Drawer::BLACK + 3, m_color);
    m_img.fill(255);
}

Drawer::~Drawer()
{
    //m_img.save_bmp("toto.bmp");
}

void Drawer::visitInt(const Int *i)
{
    m_stack.emplace(i->getValue());
}

void Drawer::visitFloat(const Float *f)
{
    //m_stack.emplace(f);
}

void Drawer::visitVar(const Var *v)
{
    cout << v->getName();
    if (m_variables.count(v->getName()) > 0)
    {
        m_stack.emplace(m_variables[(v->getName())]);
    }
    else
        throw std::invalid_argument(v->getName() + std::string(" n'est pas une variable existante."));
}

void Drawer::visitOpe(const Ope *o)
{
    cout << "(";
    o->getLeft()->visit(*this);
    o->getRight()->visit(*this);
    int left = m_stack.top();
    m_stack.pop();
    int right = m_stack.top();
    m_stack.pop();
    int result = 0;
    switch (o->getSymbol())
    {
    case PLUS:
        result = left + right;
        break;
    case MOINS:
        result = left - right;
        break;
    case MULT:
        result = left * right;
        break;
    case DIV:
        result = left - right;
        break;
    case MOD:
        result = left % right;
        break;
    }
    m_stack.emplace(result);
}

void Drawer::visitAffect(const Affect *a)
{
    a->getExpr()->visit(*this);
    m_variables[a->getVar()] = m_stack.top();
    m_stack.pop();
}

void Drawer::visitFor(const For *f)
{
    f->getCond()->visit(*this);
    std::string var = f->getCond()->getVar();
    int max = m_stack.top();
    m_stack.pop();
    std::cout << "visitFor avant boucle" << std::endl;
    for (m_variables[var]; m_variables[var] < max; m_variables[var]++)
    {
        f->getBody()->visit(*this);
        std::cout << "tour de boucle i = " <<m_variables[var] << std::endl;
    }
}

void Drawer::visitSeq(const Sequence *s)
{
    SeqItem *t = s->getFirst();
    int ligne = 1;
    while (t != NULL)
    {
        t->getInst()->visit(*this);
        t = t->getNext();
        ligne++;
    }
    m_img.save_bmp("toto.bmp");
}

void Drawer::visitColor(const Color *c)
{
    switch (c->getColor())
    {
    case E_NOIR:
        std::copy(Drawer::BLACK, Drawer::BLACK + 3, m_color);
        break;
    case E_BLANC:
        std::copy(Drawer::WHITE, Drawer::WHITE + 3, m_color);
        break;
    case E_ROUGE:
        std::copy(Drawer::RED, Drawer::RED + 3, m_color);
        break;
    case E_ORANGE:
        std::copy(Drawer::ORANGE, Drawer::ORANGE + 3, m_color);
        break;
    case E_JAUNE:
        std::copy(Drawer::YELLOW, Drawer::YELLOW + 3, m_color);
        break;
    case E_VERT:
        std::copy(Drawer::GREEN, Drawer::GREEN + 3, m_color);
        break;
    case E_BLEU:
        std::copy(Drawer::BLUE, Drawer::BLUE + 3, m_color);
        break;
    case E_VIOLET:
        std::copy(Drawer::PURPLE, Drawer::PURPLE + 3, m_color);
        break;
    }
}

void Drawer::visitCoordinate(const Coordinate *c)
{
    c->getX()->visit(*this);
    c->getY()->visit(*this);
}

void Drawer::visitLine(const Line *l)
{
    l->getBegin()->visit(*this);
    l->getEnd()->visit(*this);
    int y2 = m_stack.top();
    m_stack.pop();
    int x2 = m_stack.top();
    m_stack.pop();
    int y1 = m_stack.top();
    m_stack.pop();
    int x1 = m_stack.top();
    m_stack.pop();
    m_img.draw_line(x1,x2,y1,y2,m_color);
    m_currX = x2;
    m_currY = y2;

}
void Drawer::visitMove(const Move *m)
{
    m->getC()->visit(*this);
    int y = m_stack.top();
    m_stack.pop();
    int x = m_stack.top();
    m_stack.pop();
    if (m_isDrawing)
    {
        m_img.draw_line(m_currX, m_currY, x,y,m_color);
    }
    m_currX = x;
    m_currY = y;
}

void Drawer::visitPutDown(const PutDown *p)
{
    m_isDrawing = true;
}
void Drawer::visitRaise(const Raise *r)
{
    m_isDrawing = false;
}
void Drawer::visitRectangle(const Rectangle *r)
{
    r->getCoord()->visit(*this);
    r->getLength()->visit(*this);
    r->getWidth()->visit(*this);
    int width = m_stack.top();
    m_stack.pop();
    int length = m_stack.top();
    m_stack.pop();
    int y = m_stack.top();
    m_stack.pop();
    int x = m_stack.top();
    m_stack.pop();
    m_img.draw_rectangle(x,y,width,length,m_color);
    m_currX = x;
    m_currY = y;
}

void Drawer::visitForCondition(const ForCondition *f)
{
    f->getBegin()->visit(*this);
    m_variables[f->getVar()] = m_stack.top();
    m_stack.pop();
    f->getEnd()->visit(*this);
}

void Drawer::visitPoint(const Point *p)
{
    p->getCoord()->visit(*this);
    int y = m_stack.top();
    m_stack.pop();
    int x = m_stack.top();
    m_stack.pop();
    m_img.draw_point(x, y, m_color);
    m_currX = x;
    m_currY = y;

}
