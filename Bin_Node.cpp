//implementing template pattern for binary nodes

#include "Bin_Node.h"

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
Bin_Node::Bin_Node()
:	left_(nullptr),
	right_(nullptr)
{}

Bin_Node::~Bin_Node()
{
	delete left_;
	delete right_;
}

void Bin_Node::accept(Node_Visitor & vis){}


Expr_Node * Bin_Node::get_left()
{
	return this->left_;
}

Expr_Node * Bin_Node::get_right()
{
	return this->right_;
}

void Bin_Node::set_left(Expr_Node * node)
{
	this->left_ = node;
}

void Bin_Node::set_right(Expr_Node * node)
{
	this->right_ = node;
}
