//implementing number node

#include "Num_Node.h"

Num_Node::Num_Node()
: num_(0),
	prec_(0)
{}

Num_Node::Num_Node(int n)
: num_(n)
{}

Num_Node::~Num_Node(){}

void Num_Node::accept(Node_Visitor & vis)
{
	vis.Visit_Number_Node(*this);
}

void Num_Node::set_left(Expr_Node * node){}
void Num_Node::set_right(Expr_Node * node){}
Expr_Node * Num_Node::get_left(){}
Expr_Node * Num_Node::get_right(){}

int Num_Node::get_number()
{
	return this->num_;
}

int Num_Node::get_prec()
{
	return this->prec_;
}	
