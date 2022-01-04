#ifndef _NODE_VISITOR_H_
#define _NODE_VISITOR_H_

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Expr_Node.h"
#include "Bin_Node.h"
class Add_Node;
class Num_Node;
class Sub_Node;
class Div_Node;
class Mult_Node;
class Mod_Node;

//base visitor interface
class Node_Visitor
{
	public:
	virtual void Visit_Addition_Node(Add_Node & node) = 0;
	virtual void Visit_Subtraction_Node(Sub_Node & node) = 0;
	virtual void Visit_Number_Node(Num_Node & node) = 0;
	virtual void Visit_Division_Node(Div_Node & node) = 0;
	virtual void Visit_Multiplication_Node(Mult_Node & node) = 0;
	virtual void Visit_Modulus_Node(Mod_Node & node) = 0;

};


#endif
