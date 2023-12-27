#include <iostream>
#include <algorithm>

#include "filter.h"

void Filter::remove_space(std::list<std::string> &words){
    std::string tmp;
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        tmp.clear();
        std::string s = *it;
        for(size_t index = 0; index < s.size(); index++)
            if(std::isspace(s[index]) == false)
                tmp += s[index];
        it = words.erase(it);
        words.insert(it, tmp);
    }
}

void Filter::words_length(std::list<std::string> &words, size_t len_min, size_t len_max){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        std::string s = *it;
        if(s.size() >= len_min && s.size() <= len_max)
            ++it;
        else
            it = words.erase(it);
    }
}

void Filter::remove_digits(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(is_digits(*it))
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::remove_alpha(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(is_alpha(*it))
            it = words.erase(it);
        else
            ++it;
    }
}


void Filter::remove_punct(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(is_punct(*it))
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::digits(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(is_digits(*it) == false)
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::alpha(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(is_alpha(*it) == false)
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::punct(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(is_punct(*it) == false)
            it = words.erase(it);
        else
            ++it;
    }
}

bool Filter::is_digits(const std::string &str){
    for(size_t index = 0; index < str.size(); index++){
        if(std::isdigit(str[index]) == false)
            return false;
    }
    return true;
}

bool Filter::is_alpha(const std::string &str){
    for(size_t index = 0; index < str.size(); index++){
        if(std::isalpha(str[index]) == false)
            return false;
    }
    return true;
}

bool Filter::is_punct(const std::string &str){
    for(size_t index = 0; index < str.size(); index++){
        if(std::ispunct(str[index]) == false)
            return false;
    }
    return true;
}
