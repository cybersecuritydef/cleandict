import sys

def con_layout_key(infile, outfile):
    keydict = {        
            "й" : "q", "ц" : "w",
            "у" : "e", "к" : "r",
            "е" : "t", "н" : "y",
            "г" : "u", "ш" : "i",
            "щ" : "o", "з" : "p",
            "х" : "[", "ъ" : "]",
            "ф" : "a", "ы" : "s",
            "в" : "d", "а" : "f",
            "п" : "g", "р" : "h",
            "о" : "j", "л" : "k",
            "д" : "l", "ж" : ";",
            "э" : "\'","я" : "z",
            "ч" : "x", "с" : "c",
            "м" : "v", "и" : "b",
            "т" : "n", "ь" : "m",
            "б" : ",", "ю" : ".",
            "Й" : "Q", "Ц" : "W",
            "У" : "E", "К" : "R",
            "Е" : "T", "Н" : "Y",
            "Г" : "U", "Ш" : "I",
            "Щ" : "O", "З" : "P",
            "Х" : "{", "Ъ" : "}",
            "Ф" : "A", "Ы" : "S",
            "В" : "D", "А" : "F",
            "П" : "G", "Р" : "H",
            "О" : "J", "Л" : "K",
            "Д" : "L", "Ж" : ":",
            "Э" : "\"","Я" : "Z",
            "Ч" : "X", "С" : "C",
            "М" : "V", "И" : "B",
            "Т" : "N", "Ь" : "M",
            "Б" : "<", "Ю" : ">",
            "ё" : "`", "Ё" : "~"
        }
    try:
        with open(infile, "r", encoding='utf-8') as ifile:
            with open(outfile, "w") as ofile:
                print("\n[!] Conversion process\n")
                for line in ifile:
                    word = ""
                    for ch in line.strip():
                        if ch in keydict:
                            word += keydict[ch]
                        else:
                            word += ch
                    ofile.write("{}\n".format(word))
            print("[+] Successfuly\n") 
    except FileNotFoundError as e:
        print("[-] {}".format(e))


def main():
    if len(sys.argv) == 3:
        con_layout_key(sys.argv[1], sys.argv[2])
    else:
        print("\nHelp: conlayoutkey.py infile.txt outfile.txt\n")


if __name__ == '__main__':
	main()
