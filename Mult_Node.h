#ifndef _MULT_NODE_H_
#define _MULT_NODE_H_

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Node_Visitor.h"

class Mult_Node : public Bin_Node
{
	public:
	
	Mult_Node();
	virtual void accept(Node_Visitor & vis);
	int get_prec();
	
	private:

	int prec_;

};


#endif
