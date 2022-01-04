#ifndef _NUM_NODE_H_
#define _NUM_NODE_H_

#include "Node_Visitor.h"

class Num_Node : public Expr_Node
{
	public:

	Num_Node();
	Num_Node(int n);
	~Num_Node();
	virtual void accept(Node_Visitor & vis);
	void set_left(Expr_Node * node);
	void set_right(Expr_Node * node);
	Expr_Node * get_left();
	Expr_Node * get_right();
	int get_number();
	int get_prec();

	private:
	int num_;
	int prec_;

};


#endif
