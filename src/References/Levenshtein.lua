local function newMatrix(N, M)
	local mt = {}
	for i = 0, N do
		mt[i] = {}
		for j = 0, M do
			mt[i][j] = 0
		end
	end
	return mt
end
local function LevenshteinDistance(strA, strB)
	local rows = string.len(strA) 
	local cols = string.len(strB) 
	if rows == 0 then --Length of a is 0? The distance is just the length of b, because it would take that many substitutions to make b
		return cols
	elseif cols == 0 then 
		return rows
	elseif strA == strB then --Same string? The distance is 0
		return 0
	end
	local matrix = newMatrix(rows, cols) --Create a matrix or 2D array
	
	--Initialize Matrix
	for i = 1, rows do
		matrix[i][0] = i
	end
	for j = 1, cols do
		matrix[0][j] = j
	end
	
	for i = 1, rows do --If you initialized your matrix with 1s instead of 0s, start at 2 instead of 1 here
		for j = 1, cols do
			if (strA:byte(i) == strB:byte(i)) then
				--If the two characters in both strings are the same
				matrix[i][j] = matrix[i-1][j-1]
			else
				local insertion = matrix[i][j-1] + 1
				local deletion = matrix[i - 1][j] + 1
				local subsitution = matrix[i - 1][j - 1] + 1
                
				matrix[i][j] = math.min(insertion, deletion, subsitution)
                if i > 1 and j > 1 and strA:byte(i) == strB:byte(j-1) and strA:byte(i-1) == strB:byte(j) then
                    local transposition = matrix[i-2][j-2] + 1
                    matrix[i][j] = math.min(matrix[i][j], transposition)
                end
			end


		end
	end
	return matrix[rows][cols], matrix
end