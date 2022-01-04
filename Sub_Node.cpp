//implementing subtraction node

#include "Sub_Node.h"

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
Sub_Node::Sub_Node()
: Bin_Node(),
	prec_(1)
{}


void Sub_Node::accept(Node_Visitor & vis)
{
	vis.Visit_Subtraction_Node(*this);
}

int Sub_Node::get_prec()
{
	return this->prec_;
}
