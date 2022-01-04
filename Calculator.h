#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Expression_Tree_Builder.h"
#include "Expression_Tree.h"
#include <string>
#include "Expr_Node.h"
#include "Builder.h"
#include "Node_Visitor.h"
#include "Eval_Expr_Tree.h"
#include <iostream>
#include <sstream>


class Calculator
{

	public:
	
	Calculator();
	~Calculator();
	Expression_Tree_Builder *  parser(std::string & infix);
	void run_calculator();
	bool expression_checker(std::string & infix);
	bool postfix_detector(std::string & str);
			
	
	private:
	Expression_Tree_Builder * builder_;
};


#endif
