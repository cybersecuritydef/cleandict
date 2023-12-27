#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <list>

class Filter{

public:
    Filter(){}
    ~Filter(){}

    void words_length(std::list<std::string> &words, size_t len=0, size_t len_max=63);

    void remove_space(std::list<std::string> &words);

    void remove_digits(std::list<std::string> &words);

    void digits(std::list<std::string> &words);

    void remove_alpha(std::list<std::string> &words);

    void alpha(std::list<std::string> &words);

    void remove_punct(std::list<std::string> &words);

    void punct(std::list<std::string> &words);

private:
    bool is_digits(const std::string &str);

    bool is_alpha(const std::string &str);

    bool is_punct(const std::string &str);
};
#endif // FILTER_H
