#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class PT {
	private:
		vector<int> vec_;
	public:
		PT(const initializer_list<int> &vec) {
			for(initializer_list<int>::iterator it = vec.begin(); it != vec.end(); ++it)
				vec_.push_back(*it);
		}
		void traverse() {
			for(auto i : vec_)
				cout << i << " ";
			cout << endl;
		}
};

int main(void) {

	PT p = {1, 2, 3, 4, 5};
	p.traverse();
	return 0;
}
