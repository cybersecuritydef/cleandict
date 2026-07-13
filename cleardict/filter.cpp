#include <iostream>
#include <algorithm>

#include "filter.h"

void Filter::removeSpace(std::list<std::string> &words){
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

void Filter::wordsLength(std::list<std::string> &words, const size_t len_min, const size_t len_max){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        std::string s = *it;
        if(s.size() >= len_min && s.size() <= len_max)
            ++it;
        else
            it = words.erase(it);
    }
}

void Filter::removeDigits(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(isDigits(*it))
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::removeAlpha(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(isAlpha(*it))
            it = words.erase(it);
        else
            ++it;
    }
}


void Filter::removePunct(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(isPunct(*it))
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::removeOther(std::list<std::string> &words){
    std::string tmp;
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        tmp.clear();
        std::string s = *it;
        for(size_t index = 0; index < s.size(); index++)
            if(std::ispunct(s[index]) || std::isalnum(s[index]))
                tmp += s[index];
        it = words.erase(it);
        words.insert(it, tmp);
    }
}

void Filter::digits(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(isDigits(*it) == false)
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::alpha(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(isAlpha(*it) == false)
            it = words.erase(it);
        else
            ++it;
    }
}

void Filter::punct(std::list<std::string> &words){
    std::list<std::string>::iterator it = words.begin();
    while(it != words.end()){
        if(isPunct(*it) == false)
            it = words.erase(it);
        else
            ++it;
    }
}

bool Filter::isDigits(const std::string &str){
    for(size_t index = 0; index < str.size(); index++){
        if(std::isdigit(str[index]) == false)
            return false;
    }
    return true;
}

bool Filter::isAlpha(const std::string &str){
    for(size_t index = 0; index < str.size(); index++){
        if(std::isalpha(str[index]) == false)
            return false;
    }
    return true;
}

bool Filter::isPunct(const std::string &str){
    for(size_t index = 0; index < str.size(); index++){
        if(std::ispunct(str[index]) == false)
            return false;
    }
    return true;
}
