//implement calculator wrapper facade

#include "Calculator.h"
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
Calculator::Calculator()
:	builder_(new Expression_Tree_Builder())
{}

Calculator::~Calculator()
{
	delete builder_;
}	
//parses input and builds the composite tree
Expression_Tree_Builder * Calculator::parser(std::string & infix)
{
	//ensure infix expression is valid before parsing
	if(infix == " " || infix == "")
		return nullptr;
	else if(infix.find_first_not_of("-+*/%0123456789()") == std::string::npos)
		return nullptr;	
	
	std::istringstream input(infix);
	//start expression
	if(!builder_->get_tree())
		builder_->start_expression();

	std::string token;
	//used to handle parentheses
	Expression_Tree_Builder * outer_build;
	Expression_Tree_Builder * inner_build;
	//visitor used to evaluate sub expressions from parentheses
	Eval_Expr_Tree eval;
	//parse the expression and build the proper operator/operand as it comes in
	while(!input.eof())	 	
	{		
		input >> token;

		if(token == "+")
		{
			builder_->build_add_op();
		}
		else if(token == "-")
		{
			builder_->build_sub_op();
		}
		else if(token == "/")
		{
			builder_->build_div_op();
		}
		else if(token == "*")
		{
			builder_->build_mult_op();
		}
		else if(token == "%")
		{
			builder_->build_mod_op();
		}
		//finds the sub expression, then calls parser on the sub expression 
		else if(token == "(")
		{
		//ensure sub expression does not get built, processed, and inserted more than one time
			int paren = 1;
			while(paren != 0 && !input.eof())
			{
				input >> token;
				if(token == "(")
				{
					paren++;	
				}
				else if(token == ")")
				{
					paren--;
				}
			} 
			//find the inner expression from parentheses	
			int start = infix.find("(");
			int end = infix.rfind(")");
			if(end == std::string::npos)
				return nullptr;
			int sub_expr_length = end - start;
			std::string sub_expr_str = infix.substr(start + 1, sub_expr_length - 2);
			//save off the outer build of the expression tree
			outer_build = builder_;
			//parse the inner builder
			inner_build = parser(sub_expr_str);
			//try to use visitor to gain the result of the sub expression, then insert it into the outer_build
			try
			{
				inner_build->get_tree()->get_root()->accept(eval);
				outer_build->build_number(eval.get_result());
			}
			catch(std::exception & e)
			{
				throw e;
			}
			
			//set the builder_ to the outer_build
			builder_ = outer_build;
		}
		else if(token == ")")
		{
			continue;	
		}
		else if(token == " ")
		{
			continue;
		}
		//if it makes it here, its a number or garbage, first try to convert it to a number and build the number node
		//then throw the caught exception if it is garbage
		else if(token.find_first_not_of("-0123456789") == std::string::npos)
		{	
			try
			{
				int num = std::stoi(token);
				builder_->build_number(num);
			}
			catch(std::exception & e)
			{
				throw e;
			}
		}
		else
		{
			return nullptr;
		}
		
	}
	//return current state of the builder_
	return builder_;	
}
//runs the calculator
void Calculator::run_calculator()
{
	bool keep_going = true;
	while(keep_going)
	{
		//holds the built expression
		Expression_Tree_Builder *expr;	
		//takes user input  
		std::string infix;	
		std::cout << "Enter an expression: " << std::endl;
		std::getline(std::cin, infix);
		if(infix == "QUIT")
		{
			keep_going = false;
		}
		else if(!this->expression_checker(infix))
		{
			std::cout << "Invalid Expression." << std::endl;
			continue;
		}
		else if(!this->postfix_detector(infix))
		{
			std::cout << "Invalid Expression please use infix format for expressions." << std::endl;
		} 
		else if(infix != "QUIT")
		{
			//parses user input, if valid expression, builds the composite tree, then walks the composite tree to calculate the results
			//if invalid expression, catch exception and print it out
			try
			{
				expr = parser(infix);
			}
			catch(std::exception & e)
			{
				std::cout << e.what() << std::endl;
			}
			//if the expression was parsed properly, there is a valid builder
			if(expr)
			{
				try
				{
					Eval_Expr_Tree eval;
					expr->get_tree()->get_root()->accept(eval);
					std::cout << "Result: " << eval.get_result() << std::endl;
					//manage memory when many expressions are evaluated in a row
					delete this->builder_->get_tree();
					this->builder_->set_tree(new Expression_Tree());
				}
				catch(std::exception & e)
				{
					//restore tree state
					delete this->builder_->get_tree();
					this->builder_->set_tree(nullptr);
					std::cout << e.what() << std::endl;
				}
			}
			else
			{
				//restore tree state
				delete this->builder_->get_tree();
				this->builder_->set_tree(nullptr);
				std::cout << "Failed parsing expression." << std::endl;
			}
		}	
	}
}

//checks if the user has provided the proper ratio of operands to operators
bool Calculator::expression_checker(std::string & infix)
{
	int num_count = 0;
	int op_count = 0;	

	std::stringstream input(infix);
	std::string token;

	while(!input.eof())
	{
		input >> token;
		
		if(token == "*" ||  token == "+" || token == "/" || token == "-" || token == "%")
		{
			++op_count;
		}
		else if(token == " " || token == "(" || token == ")")
		{
			continue;
		}
		else
		{
			++num_count;
		}	
	}
	if(op_count >= num_count || op_count == 0)
	{
		return false;	
	}	
	else
	{
		return true;
	}
}


//checks if a user has entered a postfix formatted expression
bool Calculator::postfix_detector(std::string & str)
{
	std::stringstream input(str);
	std::string token;
		
	int sequential = 0;
	while(!input.eof())
	{
		input >> token;
		if(std::isdigit(token[0])) 
		{
			++sequential;
		}	
		else if(token[0] == '-' && token.length() > 1)
		{
			++sequential;
		}
		else if(!std::isdigit(token[0]) && token[0] != ' ')
		{
			--sequential;
		}
		
	if(sequential > 1)
		return false;
	}	
		return true;
	
}




































