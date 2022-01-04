#ifndef _BUILDER_H_
#define _BUILDER_H_

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Add_Node.h"
#include "Sub_Node.h"
#include "Div_Node.h"
#include "Mult_Node.h"
#include "Mod_Node.h"
#include "Num_Node.h"
#include "Expr_Node.h"

//base builder interface
class Builder
{

	public:
	virtual void start_expression() = 0;
	virtual void build_number(int num) = 0;
	virtual void build_add_op() = 0;
	virtual void build_sub_op() = 0;
	virtual void build_div_op() = 0;
	virtual void build_mult_op() = 0;
	virtual void build_mod_op() = 0;

};


#endif
