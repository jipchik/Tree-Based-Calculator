
#include "Div_Node.h"

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
Div_Node::Div_Node()
: Bin_Node(),
	prec_(2)
{}


void Div_Node::accept(Node_Visitor & vis)
{
	vis.Visit_Division_Node(*this);
}

int Div_Node::get_prec()
{
	return this->prec_;
}
