#ifndef _BIN_NODE_H_
#define _BIN_NODE_H_

#include "Node_Visitor.h"
#include "Expr_Node.h"

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//base class for binary nodes, derives from Expr_Node
class Bin_Node : public Expr_Node
{
	public:
	
	Bin_Node();
	~Bin_Node();
	virtual void accept(Node_Visitor & vis);
	Expr_Node * get_left();
	Expr_Node * get_right();
	void set_left(Expr_Node * node);
	void set_right(Expr_Node * node);	

	protected:

	Expr_Node * left_;
	Expr_Node * right_;

};



#endif

