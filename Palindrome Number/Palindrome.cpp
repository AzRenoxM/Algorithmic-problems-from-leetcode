#include<iostream>
#include<string>


class Solution {
public:
   bool isPalindrome(int x) {
        if(x < 0) return false;
        std::string number_str = std::to_string(x);

        for(size_t i{0}; i < (number_str.size() + 2) / 2; i++){
            if(number_str[i] == number_str[number_str.size() - 1 - i]) continue;
            else return false;
        }

        return true;
    }
};