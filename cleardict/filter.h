#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <list>

#define MAXLENPASS 256

class Filter{

public:
    Filter(){}
    ~Filter(){}

    void wordsLength(std::list<std::string> &words, const size_t len_min=0, const size_t len_max=MAXLENPASS);

    void removeSpace(std::list<std::string> &words);

    void removeDigits(std::list<std::string> &words);

    void digits(std::list<std::string> &words);

    void removeAlpha(std::list<std::string> &words);

    void alpha(std::list<std::string> &words);

    void removePunct(std::list<std::string> &words);

    void removeOther(std::list<std::string> &words);

    void punct(std::list<std::string> &words);

private:
    bool isDigits(const std::string &str);

    bool isAlpha(const std::string &str);

    bool isPunct(const std::string &str);
};
#endif // FILTER_H
