#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <sstream>

#include <getopt.h>

#include "filter.h"

void die(const std::string &msg){
    std::cerr << msg << std::endl;
    exit(EOF);
}

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
    std::cout << "cleandict -f dict.txt -d --min=6 --max=10 -o newdict.txt\n";
}

bool read_words_file(const std::string &filename, std::list<std::string> &words){
    std::string line;
    std::ifstream file(filename, std::ios::in);
    if(file.is_open()){
        while(std::getline(file, line)){
            words.push_back(line);
        }
        file.close();
        return true;
    }
    return false;
}

bool save_words_file(const std::string &filename, const std::list<std::string> &words){
    std::ofstream file(filename);
    if(file.is_open()){
        for(auto it = words.begin(); it != words.end(); it++)
            file << *it << std::endl;
        file.close();
        return true;
    }
    return false;
}

void print_words(const std::list<std::string> &words){
    for(auto iter = words.begin(); iter != words.end(); iter++)
        std::cout << *iter << std::endl;
}

int main(int argc, char **argv){
    std::string outfile;
    std::string infile;
    std::list<std::string> words;
    Filter filter;
    bool del_digits = false;
    bool digits = false;
    bool del_alpha = false;
    bool alpha = false;
    bool del_punct = false;
    bool punct = false;
    size_t len_min = 0;
    size_t len_max = MAXLENPASS;
    int opt = 0;
    int index_opt = 0;
    struct option longopts[] = {
        {"min", 1, NULL, 'm'},
        {"max", 1, NULL, 'M'},
        {NULL, 0, NULL, 0}
    };
    opterr = false;
    while((opt = getopt_long(argc, argv, "f:o:m:M:hdDaApP", longopts, &index_opt)) != EOF){
        switch(opt){
            case 'm' :
                len_min = std::stol(optarg);
                if(len_min > len_max || len_min < 0)
                    die("[-] Invalid length min!");
                break;
            case 'M' :
                len_max = std::stol(optarg);
                if(len_max > MAXLENPASS || len_max < len_min)
                  len_max = MAXLENPASS;
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
                die("[-] Invalid argument!");
        }
    }
    std::cout << "[!] Read from file..." << std::endl << std::endl;
    if(read_words_file(infile, words)){
        if(words.size() > 0){
            std::cout << "[!] Sorting..." << std::endl << std::endl;
            words.sort();
            std::cout << "[!] Remove duplicate..." << std::endl << std::endl;
            words.unique();
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

            filter.words_length(words, len_min, len_max);

            std::cout << "[!] Save to file..." << std::endl << std::endl;
            if(! outfile.empty()){
                if(save_words_file(outfile, words)){
                    std::cout << "[+] Successful! " << std::endl << std::endl;
                    std::cout << "[+] Words count: " << words.size() << std::endl << std::endl;
                }
                else
                    die("[-] Error save to file !");
            }
            else
                print_words(words);
        }
        else
            die("[-] Wordlist empty!");
    }
    else
        die("[-] File not found!");
    return 0;
}
