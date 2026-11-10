class Solution {
public:
    bool isValid(string s) {
        // Variables:
        stack<char> open_characters;
        unordered_map<char, char> character_map;

        // Assign characters:
        character_map[')'] = '(';
        character_map['}'] = '{';
        character_map[']'] = '[';

        for (int index = 0; index < s.size(); index++) {
            // Open Characters:
            if (s[index] == '(' || s[index] == '[' || s[index] == '{') {
                open_characters.push(s[index]);
            }
            else if (!open_characters.empty() && character_map[s[index]] == open_characters.top()) {
                open_characters.pop();
            }
            else {
                return false;
            }
        }

        return open_characters.empty();
    }
};