#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "classes.h"

using namespace std;
#define log(x) cout << x << endl;
#define convert(str, arr) strcpy(arr, str.c_str());

namespace pr {
    int strdist(const string str, const string strB)
    {
	    int rows = str.length();
        int cols = strB.length();
        char x[str.length() + 1];
        char y[strB.length() + 1];
        char* str1 = convert(str, x);
        char* str2 = convert(strB, y);
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
    };

    
}