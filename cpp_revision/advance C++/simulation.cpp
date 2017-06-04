//Curiously recurring template pattern (static polymorphism, 
//simulated polymorshim)
//It is also a example of TMP (Template Meta Programming) or 
//compile-time meta programming
#include <iostream>
using namespace std;

struct TreeNode {
	TreeNode *left, *right;
};

template<typename T>
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
		void process_node(TreeNode *node) {
			static_cast<T*>(this)->process_node(node);
		}
};

class EmployeeChart_parser : public Generic_Parser<EmployeeChart_parser> {
	public:
		void process_node(TreeNode *node) {
			cout << "I am in EmployeeChart_parser" << endl;
		}
};

int main(void) {

	TreeNode root;
	root.left = NULL;
	root.right = NULL;
	EmployeeChart_parser ep;
	ep.parse_preorder(&root);

	return 0;
}
