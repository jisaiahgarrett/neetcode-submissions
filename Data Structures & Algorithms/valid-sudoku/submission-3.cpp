// Niave solution: manually check each row, col, and box. This will involve
// checking all 9 rows, all 9 cols, and all 9 boxes. Lots of inefficiency here
// each cell will be checked 3 times.
// We want O(n^2) or better.
// We can just iterate through each row and col, then, and track each 
// box as we go, that would be good enough.
// This feel object oriented to me.
// What objects are in this problem: Rows, Cols, Boxes
// I could describe a cell, but that seems overkill. A cell is a char.
// For each cell, add that cell to the correct row and col obj.
// If the value of the cell is not ".", then check if that value is already
// in the hashset backing the object, if it is, fail, else add it.
// If we find that adding a value to the object makes that object 
// invalid, then we can return early, since if one object is invalid
// the entire board is invalid.
// Do we even need to use objects here?
// Probably not, I can create a vector of hashsets representing the rows,
// cols, and boxes. I can use the same function to insert for each.
// We just need a way to map from index into the 9x9 board to each row and col.
// So, say we do a 2d for loop with i and j and the indices. 
// i is the rows
// j is the cols
// Then i represents the row_idx, j represents the col idx.
// we can map to box using the following:
// (0,0) -> 0
// (0,4) -> 1
// (0,8) -> 2
// (3,0) -> 3
// (3,3) -> 4
// (3,8) -> 5
// (8,0) -> 6
// (8,3) -> 7
// (8,8) -> 8
// What function gives this?
// 3*(i/3) + (j/3)
// (0,0) -> 0 + 0 + 1 -> 1
// (0,7) -> 0 + 2 + 1 -> 3
// (3,3) -> 3 + 1 + 1 -> 5
// (8,8) -> 6 + 2 + 1 -> 9


// Failed this test case
// [
// [".",".","4",".",".",".","6","3","."],
// [".",".",".",".",".",".",".",".","."],
// ["5",".",".",".",".",".",".","9","."],
// [".",".",".","5","6",".",".",".","."],
// ["4",".","3",".",".",".",".",".","1"],
// [".",".",".","7",".",".",".",".","."],
// [".",".",".","5",".",".",".",".","."],
// [".",".",".",".",".",".",".",".","."],
// [".",".",".",".",".",".",".",".","."]
// ]


class Solution {
public:
    bool insert_value(unordered_set<char> &set, char value) {
        if (value == '.') {
            return true;
        }
        if (set.find(value) != set.end()) {
            // value exists in set, return false
            return false;
        }
        set.insert(value);
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);


        // std::cout << insert_value(boxes.at(0), '.') << std::endl;
        // std::cout << insert_value(boxes.at(0), '.') << std::endl;
        // std::cout << insert_value(boxes.at(0), '1') << std::endl;
        // std::cout << insert_value(boxes.at(0), '1') << std::endl;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                auto value = board.at(i).at(j);
                // Test the row for duplicates
                if (insert_value(rows.at(i), value) != true) {
                    return false;
                }
                // Test the col for duplicates
                if (insert_value(cols.at(j), value) != true) {
                    return false;
                }
                // Test the box for dupliated.
                // Map the index to box
                int box_idx = 3*(i/3) + (j/3);
                if (insert_value(boxes.at(box_idx), value) != true) {
                    return false;
                } 
            }
        }
        return true;
    }
};
