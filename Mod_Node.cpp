
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Mod_Node.h"
Mod_Node::Mod_Node()
: Bin_Node(),
	prec_(2)
{}

	
void Mod_Node::accept(Node_Visitor & vis)
{
	vis.Visit_Modulus_Node(*this);
}

int Mod_Node::get_prec()
{
	return this->prec_;
}
