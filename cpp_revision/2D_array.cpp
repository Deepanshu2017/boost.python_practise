#include <iostream>
using namespace std;

class TwoDimensional {
	private:
		int **arr = NULL;	//C++14 supports default initilization
		int row = 0, col = 0;
	public:
		TwoDimensional(int row, int col) {
			this->row = row;
			this->col = col;
			arr = new int*[row];
			for(int i = 0; i < row; ++i)
				arr[i] = new int[col];
		}

		void fill_array(void) {
			for(int i = 0; i < row; ++i)
				for(int j = 0; j < col; ++j)
					arr[i][j] = (i + 1) * (j + 1);
		}

		void print(void) {
			for(int i = 0; i < row; ++i)
				for(int j = 0; j < col; ++j)
					cout << arr[i][j] << " \n"[j == col - 1];
		}

		~TwoDimensional() {
			for(int i = 0; i < row; ++i)
				delete[] arr[i];
			delete[] arr;
		}
};

int main(void) {

	TwoDimensional _2D(3, 4);
	_2D.fill_array();
	_2D.print();

	return 0;
}
