#include "Mult_Node.h"

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
Mult_Node::Mult_Node()
: Bin_Node(),
	prec_(2)
{}


void Mult_Node::accept(Node_Visitor & vis)
{
	vis.Visit_Multiplication_Node(*this);
}

int Mult_Node::get_prec()
{
	return this->prec_;
}
