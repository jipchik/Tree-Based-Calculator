#ifndef _MOD_NODE_H_
#define _MOD_NODE_H_

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Node_Visitor.h"

class Mod_Node : public Bin_Node
{
	public:
	
	Mod_Node();
	virtual void accept(Node_Visitor & vis);
	int get_prec();

	private:

	int prec_;	

};

#endif
