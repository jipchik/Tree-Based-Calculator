#ifndef _SUB_NODE_H_
#define _SUB_NODE_H_

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Node_Visitor.h"

class Sub_Node : public Bin_Node
{
	public:
	Sub_Node();
	virtual void accept(Node_Visitor & vis);
	int get_prec();
	
	private:
	
	int prec_;
};


#endif
