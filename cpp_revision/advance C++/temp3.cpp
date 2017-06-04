#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::string;

class OpenFile {
	public:
		OpenFile(string filename) {
			cout << filename << endl;
		}
		friend void destroyMe(OpenFile *ref);
	private:
		~OpenFile() {
			cout << "I am destroyed" << endl;
		}
};

void destroyMe(OpenFile *ref) {
	delete ref;
}

int main(void) {

	OpenFile *f = new OpenFile(string("Pooja"));
	destroyMe(f);

	return 0;
}
