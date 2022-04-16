#include <iostream>
#include <vector>

using namespace std;

int main() {

	/*vector<vector<int>> matrix;

	int matrix_dimension = 0;

	cout << endl;

	cin >> matrix_dimension;

	for (int j = 0; j < matrix_dimension; j++) {
		cout << "Вводите весы ребер для V" << j << " вершины(где нет, ставить 0):" << endl;
		for (int i = 0; i < matrix_dimension; i++) {
			int temp = 0;
			cin >> temp;
			matrix[j].push_back(temp);
		}
	}*/

	system("chcp 1251");

	vector< vector<int> > matrix = {
					{ 0, 4, 0, 0, 9, 10, 0, 0},
					{ 4, 0,1, 0, 3, 0, 2, 0},
					{ 0,1, 0, 1,0, 1, 0, 7},
					{ 0, 0, 1, 0, 0,0, 8, 6},
					{ 9, 3,0, 0, 0, 4, 0, 0},
					{ 10, 0, 1,0, 4, 0, 1,0},
					{ 0, 2, 0, 8, 0, 1, 0,5},
					{ 0, 0, 7, 6, 0,0,5, 0},
	};
	int matrix_dimension = 8;

	int ves = 0;
	vector<int> mnoj;
	mnoj.push_back(0);

	vector<pair<int, int>> vershins;

	for (int j = 0; j < matrix_dimension - 1; j++) {
		int min = 999999;
		int index = 0;
		int index1 = 0;
		for (int k = 0; k < mnoj.size(); k++) {
			for (int i = 0; i < matrix_dimension; i++) {
				if (matrix[mnoj[k]][i] > 0 && matrix[mnoj[k]][i] < min
					&& find(mnoj.begin(), mnoj.end(), i) == mnoj.end()) {
					min = matrix[mnoj[k]][i];
					index = i;
					index1 = mnoj[k];
				}
			}
		}
		ves = ves + min;
		mnoj.push_back(index);
		matrix[index1][index] = -1;
		matrix[index][index1] = -1;
		vershins.push_back(make_pair(index, index1));
	}

	cout << "Минимальный вес: " << ves;

	cout << endl;

	for (int i = 0; i < vershins.size(); i++) {
		cout << "[" << vershins[i].second + 1 << ";" << vershins[i].first + 1 << "]";
	}

	return 0;

}
