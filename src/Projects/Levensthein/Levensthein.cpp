// Online C++ compiler to run C++ program online
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
int Levensthein(const char* str1, const char* str2, int rows, int cols)
{
	
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
		    int cost = 1;
        
			
				if (str1[i-1] == str2[j-1]) {
					cost = 0;
				}
        
			
      int deletion = matrix[i-1][j] + 1;
			int insertion = matrix[i][j-1] + 1;
			int substitution = matrix[i-1][j-1] + cost;
      matrix[i][j] = min(deletion, min(insertion, substitution));
			
      if (i > 1 && j > 1 && str1[i-1] == str2[j-2] && str1[i-2] == str2[j-1]) {
        int transposition = matrix[i-2][j-2] + 1;
        matrix[i][j] = min(matrix[i][j], transposition);
      }
      
		}
	}
	return matrix[rows][cols];
}

int main() {
	const char* testStrings[][2] = {
		{"he", "eh"},
		{"Kidoysadadad", "Jido"},
		{"bro","bbro"}
	};
  int lengths[][2] = {
    {2,2},
    {12, 4},
    {3, 4}
  };
	for (int i = 0; unsigned(i) < sizeof(testStrings); i++) {
		log(Levensthein(testStrings[i][0], testStrings[i][1], lengths[i][0], lengths[i][1]));
    
	}
	return 0;
}
