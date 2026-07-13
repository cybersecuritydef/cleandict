import sys

def translit(infile, outfile):
    dicts = {
            "а" : "a", "б" : "b",
            "в" : "v", "г" : "g",
            "д" : "d", "е" : "e",
            "ё" : "yo","ж" : "zh",
            "з" : "z", "и" : "i",
            "й" : "y", "к" : "k",
            "л" : "l", "м" : "m",
            "н" : "n", "о" : "o",
            "п" : "p", "р" : "r",
            "с" : "s", "т" : "t",
            "у" : "u", "ф" : "f",
            "х" : "kh","ц" : "ts",
            "ч" : "ch","ш" : "sh",
            "щ" : "shch","ъ" : "",
            "ы" : "y", "ь" : "",
            "э" : "e", "ю" : "yu",
            "я" : "ya","А" : "A",
            "Б" : "B", "В" : "V",
            "Г" : "G", "Д" : "D",
            "Е" : "E", "Ё" : "YO",
            "Ж" : "ZH","З" : "Z",
            "И" : "I", "Й" : "Y",
            "К" : "K", "Л" : "L",
            "М" : "M", "Н" : "N",
            "О" : "O", "П" : "P",
            "Р" : "R", "С" : "S",
            "Т" : "T", "У" : "U",
            "Ф" : "F", "Х" : "KH",
            "Ц" : "TS","Ч" : "CH",
            "Ш" : "SH","Щ" : "SHCH",
            "Ъ" : "",  "Ы" : "Y",
            "Ь" : "",  "Э" : "E",
            "Ю" : "YU","Я" : "YA",
        }
    try:
        with open(infile, "r", encoding='utf-8') as ifile:
            with open(outfile, "w") as ofile:
                print("\n[!] The process of transliteration\n")
                for line in ifile:
                    word = ""
                    for ch in line.strip():
                        if ch in dicts:
                            word += dicts[ch]
                        else:
                            word += ch
                    ofile.write("{}\n".format(word))
            print("[+] Successfuly\n") 
    except FileNotFoundError as e:
        print("[-] {}".format(e))


def main():
    if len(sys.argv) == 3:
        translit(sys.argv[1], sys.argv[2])
    else:
        print("\nHelp: translit.py infile.txt outfile.txt\n")


if __name__ == '__main__':
	main()
