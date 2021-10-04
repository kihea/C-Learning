#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define log(x) cout << x << endl;

void printf(vector<vector<int>> input) {
	for (int size = 0; unsigned(size) <= input.size() - 1; size++) {
		for (int i = 0; unsigned(i) <= input[size].size() - 1; i++) {
			int value = input[size][i];
			cout << value << " ";
		}
		log(endl);
	}
}
int Levensthein(string str1, string str2)
{
	string strA = str1 > str2 ? str2 : str1;
	string strB = str1 > str2 ? str1 : str2;
	int rows = size(strA);
	int cols = size(strB);

	if (str1 == str2) {
		return 0;
	}
	else if (rows == 0) {
		return rows;
	}
	else if (rows == 0) {
		return cols;
	}

	vector<vector<int>> matrix;
	matrix.assign(rows + 1, vector<int>(cols + 1, 0));

	for (int i = 1; i <= rows; i++) {
		matrix[i][0] = i;
	}
	for (int j = 1; j <= cols; j++) {
		matrix[0][j] = j;
	}
	
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			try {
				if (strA.at(i - 1) == strB.at(i - 1)) {
					matrix[i][j] = matrix[i - 1][j - 1];
				}
				else {
					matrix[i][j] = min(matrix[i][j - 1] + 1, min(matrix[i - 1][j] + 1, min(matrix[i - 1][j - 1] + 1, i > 1 && j > 1 ? matrix[i - 2][j - 2] + 1 : cols + 1)));;
				}
			}
			catch (...) {
				return matrix[i - 1][j - 1] + cols - rows + 1;
				
			}
		}
	}
	return matrix[rows][cols];
}

int main() {
	string testStrings[][2] = {
		{"he", "eh"},
		{"Kidoysadadad", "Jido"}
	};

	for (int i = 0; unsigned(i) < sizeof(testStrings); i++) {
		log(Levensthein(testStrings[i][0], testStrings[i][1]))
	}
	return 0;
}