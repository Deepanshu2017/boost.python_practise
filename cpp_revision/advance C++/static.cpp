#include <bits/stdc++.h>
using namespace std;

struct node {
	string pos;
	node* left;
	node* right;
};

template<typename T>
class GenericParson {
	public:
		void inorderParsor(node *root) {
			if(root) {
				inorderParsor(root->left);
				inorderParsor(root->right);
				callAppropriate(root);
			}
		}
		void callAppropriate(node *root) {
			static_cast<T*>(this)->processNode(root);
		}
	private:
		void processNode(node *root) {
			cout << "I am in processNode of GenericParson and: " << root->pos << endl;
		}
};

class EmployeeParsor : public GenericParson<EmployeeParsor> {
	public:
		void processNode(node *root) {
			cout << "I am in processNode of EmployeeParsor and: " << root->pos << endl;
		}
};

class MilitaryParsor : public GenericParson<MilitaryParsor> {
	public:
		void processNode(node *root) {
			cout << "I am in processNode of MilitaryParsor and: " << root->pos << endl;
		}
};

int main(void) {
	
	node root;
	node left;
	node right;
	root.pos = "root";
	root.left = &left;
	root.right = &right;
	left.pos = "left";
	left.left = NULL;
	left.right = NULL;
	right.pos = "right";
	right.left = NULL;
	right.right = NULL;

	EmployeeParsor e;
	e.inorderParsor(&root);

	cout << endl;
	cout << "************************************************" << endl;
	cout << endl;

	MilitaryParsor m;
	m.inorderParsor(&root);

	return 0;
}
