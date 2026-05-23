class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.length() - 1;
        for (int i = 0; i < s.length() / 2 && j >= s.length() / 2; i++) {
            while (i < s.length() && !isalnum(s[i])) i++;
            while (j >= 0 && !isalnum(s[j])) j--;
            if (static_cast<char>(std::tolower(s[i])) 
                != static_cast<char>(std::tolower(s[j]))) {
                return false;
            }
            j--;
        }
        return true;
    }
};
