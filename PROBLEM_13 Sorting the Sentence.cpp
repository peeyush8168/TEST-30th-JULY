/*A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
*/


class Solution {
public:
    string sortSentence(std::string s) {
        vector<std::pair<int, std::string>> words;
        string word;
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    int pos = word.back() - '0';
                    word.pop_back();
                    words.push_back({pos, word});
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            int pos = word.back() - '0';
            word.pop_back();
            words.push_back({pos, word});
        }
        sort(words.begin(), words.end());
        string result;
        for (const auto& pair : words) {
            if (!result.empty()) {
                result += " ";
            }
            result += pair.second;
        }
        return result;
    }
};
