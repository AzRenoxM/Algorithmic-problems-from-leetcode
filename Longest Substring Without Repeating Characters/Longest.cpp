#include<iostream>
#include<string>
#include<set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string lon_string) {  
        std::set<char> set_buffer;
        std::string str_buffer;
        int solution{0};

        if(lon_string.size() == 0) return 0;

        for(size_t i{0}; lon_string.size() > i; i++){
            str_buffer.clear();
            set_buffer.clear();
            for(size_t j{i}; lon_string.size() > j; j++){                        
                set_buffer.insert(lon_string[j]);
                if (set_buffer.size() <= str_buffer.size()){
                    break;
                }
                str_buffer += lon_string[j];
            }
            if(str_buffer.size() > solution){
                solution = str_buffer.size(); 
            }
        }
        return solution;
    }
};

