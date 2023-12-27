#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <set>
#include <sstream>

#include <getopt.h>

#include "filter.h"

void help(){
    std::cout << "OPTIONS:\n\t";
    std::cout << "-f        file dict \n\t";
    std::cout << "-o        output words to file\n\t";
    std::cout << "-d        remove digits\n\t";
    std::cout << "-D        save only digits\n\t";
    std::cout << "-a        remove alpha\n\t";
    std::cout << "-A        save only alpha\n\t";
    std::cout << "-p        remove punct\n\t";
    std::cout << "-P        save only punct\n\t";
    std::cout << "--min     word length min\n\t";
    std::cout << "--max     word length max\n\t";
    std::cout << "-h        Using help\n";
    std::cout << "EXAMPLES:\n\t";
    std::cout << "cleandict -f dict.txt --min=6 -o newdict.txt\n\t";
    std::cout << "cleandict --conding -f dict.txt -o newdict.txt\n\t";
    std::cout << "cleandict -f dict.txt -d --min=6 --max=10 -o newdict.txt\n";
}

std::set<std::string> read_words_file(const std::string &filename){
    std::set<std::string> words;
    std::string line;
    std::ifstream file(filename, std::ios::in);
    if(file.is_open()){
        while(std::getline(file, line)){
            words.insert(line);
        }
        file.close();
    }
    else
        std::cerr << "[-] File not open!" << std::endl;
    return words;
}

bool save_words_file(const std::string &filename, const std::list<std::string> &words){
    std::ofstream file(filename);
    for(auto it = words.begin(); it != words.end(); it++)
        file << *it << std::endl;
    file.close();
    return true;
}

int main(int argc, char **argv){
    std::string outfile;
    std::string infile;
    std::set<std::string> un;
    Filter filter;
    bool del_digits = false;
    bool digits = false;
    bool del_alpha = false;
    bool alpha = false;
    bool del_punct = false;
    bool punct = false;
    uintmax_t len_min = 0;
    uintmax_t len_max = 63;
    int opt = 0;
    int index_opt = 0;
    struct option longopts[] {
        {"min", 1, NULL, 0},
        {"max", 1, NULL, 1},
        {NULL, 0, NULL, 0}
    };
    opterr = false;
    while((opt = getopt_long(argc, argv, "f:o:hdDaApP", longopts, &index_opt)) != EOF){
        switch(opt){
            case 0 :
                len_min = std::stol(optarg);
                break;
            case 1 :
                len_max = std::stol(optarg);
                break;
            case 'f' :
                infile = optarg;
                break;
            case 'o' :
                outfile = optarg;
                break;
            case 'd' :
                del_digits = true;
                break;
            case 'D' :
                digits = true;
                break;
            case 'a' :
                del_alpha = true;
                break;
            case 'A' :
                alpha = true;
                break;
            case 'p' :
                del_punct = true;
                break;
            case 'P' :
                punct = true;
                break;
            case 'h' :
                help();
                return 0;
            default :
                std::cerr << "Invalid argument: " << argv[argc - 1] << std::endl;
                return EOF;
        }
    }
    std::cout << "[+] Read from file..." << std::endl << std::endl;
    un = read_words_file(infile);
    std::list<std::string> words(un.begin(), un.end());
    if(words.size() > 0){
        std::cout << "[!] Clearning process..." << std::endl << std::endl;
        filter.remove_space(words);

        if(digits)
            filter.digits(words);
        else if(del_digits)
            filter.remove_digits(words);

        if(alpha)
            filter.alpha(words);
        else if(del_alpha)
            filter.remove_alpha(words);

        if(punct)
            filter.punct(words);
        else if(del_punct)
            filter.remove_punct(words);

        if(len_min > 0 && len_max > 0)
            filter.words_length(words, len_min, len_max);

        std::cout << "[+] Words count => " << words.size() << std::endl << std::endl;
        std::cout << "[+] Save to file..." << std::endl << std::endl;
        save_words_file(outfile, words);
    }
    return 0;
}
