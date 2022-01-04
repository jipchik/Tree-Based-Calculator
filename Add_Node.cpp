//implementing add node

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Add_Node.h"

Add_Node::Add_Node()
://	Bin_Node(),
	prec_(1)
{}


void Add_Node::accept(Node_Visitor & vis)
{
	vis.Visit_Addition_Node(*this);
}

int Add_Node::get_prec()
{
	return this->prec_;
}
