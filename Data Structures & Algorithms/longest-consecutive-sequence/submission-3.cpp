// Brute force solution: sort the array, then iterate through it and
// count the longest sequence.
// We probably want to use a hash map or unordered map here.

// What about this:
// Iterate through the input, add each element to a set as we encounter it.
// Duplicates will be squashed, thats fine.
// Then, iterate through the set and count the longest sequence.
// This gets us a runtime of O(2n) and a size of O(2n).
// But, can't use an ordered set since that has an insert time of O(log n).
// That would make our runtime O(nlogn)


// Reading the hints, that is not exactly the approach they want us to take.
// They want us to iterate through nums, adding each element to a set.
// Then iterating through the set, find our starts of sequences.
// For each start of sequence, recursively building our current sequence
// If it is longer than our best sequence, update best sequence.

// How much memory are we using:
// nums_histo : O(n)
// best_sequence: O(n)
// sequence_starts: O(n) <for the worst case>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Initialize our set, best sequence, and starts vector
        unordered_set<int> nums_histo;
        vector<int> best_sequence;
        vector<int> sequence_starts;
        // Insert every element of nums into nums_histo
        for (auto num : nums) {
            nums_histo.insert(num);
        }
        // Iterate through nums_histo, find our sequence starts
        // A number is a sequence start if the previous number is not
        // present in nums_histo
        for (const auto& num : nums_histo) {
            if (nums_histo.find(num-1) == nums_histo.end()) {
                // We did not find the previous number
                sequence_starts.push_back(num);
            }
        }

        // for each num in sequence_starts
        for (auto num : sequence_starts) {
            // build the sequence starting with num
            vector<int> current_sequence = {num};
            auto next_num = num + 1;
            while (nums_histo.find(next_num) != nums_histo.end()) {
                current_sequence.push_back(next_num);
                next_num++;
            }

            // once the recursive function returns, then if current sequence
            // is longer than best sequence, set best sequence to current sequence.
            if (current_sequence.size() > best_sequence.size()) {
                best_sequence = current_sequence;
            }
        }
        return best_sequence.size();
    }
};
