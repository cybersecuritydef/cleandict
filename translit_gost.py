import sys

def translit_gost(infile, outfile):
    dicts = {
            "а" : "a", "б" : "b",
            "в" : "v", "г" : "g",
            "д" : "d", "е" : "e",
            "ё" : "jo","ж" : "zh",
            "з" : "z", "и" : "i",
            "й" : "j", "к" : "k",
            "л" : "l", "м" : "m",
            "н" : "n", "о" : "o",
            "п" : "p", "р" : "r",
            "с" : "s", "т" : "t",
            "у" : "u", "ф" : "f",
            "х" : "kh","ц" : "c",
            "ч" : "ch","ш" : "sh",
            "щ" : "shh","ъ" : "",
            "ы" : "y", "ь" : "",
            "э" : "eh", "ю" : "ju",
            "я" : "ja","А" : "A",
            "Б" : "B", "В" : "V",
            "Г" : "G", "Д" : "D",
            "Е" : "E", "Ё" : "JO",
            "Ж" : "ZH","З" : "Z",
            "И" : "I", "Й" : "J",
            "К" : "K", "Л" : "L",
            "М" : "M", "Н" : "N",
            "О" : "O", "П" : "P",
            "Р" : "R", "С" : "S",
            "Т" : "T", "У" : "U",
            "Ф" : "F", "Х" : "KH",
            "Ц" : "C","Ч" : "CH",
            "Ш" : "SH","Щ" : "SHH",
            "Ъ" : "",  "Ы" : "Y",
            "Ь" : "",  "Э" : "EH",
            "Ю" : "JU","Я" : "JA",
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
        translit_gost(sys.argv[1], sys.argv[2])
    else:
        print("\nHelp: translit_gost.py infile.txt outfile.txt\n")


if __name__ == '__main__':
	main()
