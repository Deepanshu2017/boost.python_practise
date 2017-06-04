#include <iostream>
using namespace std;

template<typename T>
T sq(T x) { return x * x; }

// auto sq(auto x) { return x * x; }

template<typename T>
class myVector {
private:
	T arr[1000];
	int size;
public:
	myVector() : size(0) { }
	void push(T x) { arr[size] = x; ++size; }
	int getSize() const { return size; }
	T get(int idx) const { return arr[idx]; }
	void print() const {for(int i = 0; i < size; ++i) cout << arr[i] << endl;}	
};

template<typename T>
myVector<T> operator* (const myVector<T> &rhs1, const myVector<T> &rhs2) {
	myVector<T> ret;
	for(int i = 0; i < rhs1.getSize(); ++i)
		ret.push(rhs1.get(i) * rhs2.get(i));
	return ret;
}

int main(void) {

	myVector<int> bv;
	bv.push(2);
	bv.push(5);
	bv.push(8);
	bv.push(9);

	cout << "SQUARED" << endl;
	bv = sq(bv);
	bv.print();

	cout << "value is: " << boolalpha;
	cout << true << "\n";

	return 0;
}
