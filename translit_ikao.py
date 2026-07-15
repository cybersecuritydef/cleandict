import sys

def translit_ikao(infile, outfile):
    dicts = {
            "а" : "a", "б" : "b",
            "в" : "v", "г" : "g",
            "д" : "d", "е" : "e",
            "ё" : "e","ж" : "zh",
            "з" : "z", "и" : "i",
            "й" : "i", "к" : "k",
            "л" : "l", "м" : "m",
            "н" : "n", "о" : "o",
            "п" : "p", "р" : "r",
            "с" : "s", "т" : "t",
            "у" : "u", "ф" : "f",
            "х" : "kh","ц" : "ts",
            "ч" : "ch","ш" : "sh",
            "щ" : "shch","ъ" : "ie",
            "ы" : "y", "ь" : "",
            "э" : "e", "ю" : "iu",
            "я" : "ia","А" : "A",
            "Б" : "B", "В" : "V",
            "Г" : "G", "Д" : "D",
            "Е" : "E", "Ё" : "E",
            "Ж" : "ZH","З" : "Z",
            "И" : "I", "Й" : "I",
            "К" : "K", "Л" : "L",
            "М" : "M", "Н" : "N",
            "О" : "O", "П" : "P",
            "Р" : "R", "С" : "S",
            "Т" : "T", "У" : "U",
            "Ф" : "F", "Х" : "KH",
            "Ц" : "TS","Ч" : "CH",
            "Ш" : "SH","Щ" : "SHCH",
            "Ъ" : "IE",  "Ы" : "Y",
            "Ь" : "",  "Э" : "E",
            "Ю" : "IU","Я" : "IA",
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
        translit_ikao(sys.argv[1], sys.argv[2])
    else:
        print("\nHelp: translit_ikao.py infile.txt outfile.txt\n")


if __name__ == '__main__':
	main()
