//Types of polymorphism:
//1: Ad-Hoc -------> when a function denotes different and potentially
//	 heterogeneous implementation. like function overloading
//
//2: Parametric ---> when code is written without mention of any specific
//   type. like templates or generic programming
//
//3: Subtyping ----> when a name denotes instance of many different classes
//   related by some common superclass. like pure virtual class
//
//This is a example of ploymorphism to see the static polymorphism
//simulation of the below code check file name simulation.cpp
#include <iostream>
using namespace std;

struct TreeNode {
	TreeNode *left, *right;
};

class Generic_Parser {
	public:
		void parse_preorder(TreeNode *node) {
			if(node) {
				process_node(node);
				parse_preorder(node->left);
				parse_preorder(node->right);
			}
		}
	private:
		virtual void process_node(TreeNode *node) {
			cout << "Foo" << endl;
		}
};

class EmployeeChart_parser : public Generic_Parser {
	private:
		void process_node(TreeNode *node) {
			cout << "I am in EmployeeChart_parser" << endl;
		}
};

int main(void) {

	//create tree
	TreeNode root;
	root.left = NULL;
	root.right = NULL;
	EmployeeChart_parser ep;
	ep.parse_preorder(&root);

	return 0;
}
