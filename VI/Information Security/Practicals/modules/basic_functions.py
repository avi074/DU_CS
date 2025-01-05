e_tags = {
    "error": lambda s: f"\033[91;1m{s}",
    "info": lambda s: f"\033[1m{s}",
    "warn": lambda s: f"\033[93;1m{s}",
    "pass": lambda s: f"\033[92;1m{s}",
    "end": "\033[0m"
}


def c_print(method: str, pTxt: str, key, cTxt: str, dTxt: str):
    print(f'''
        \033[1m{method}\033[0m \n
        Plain Text    : {pTxt}
        Key           : {key}
        Cipher text   : {cTxt}
        Decipher text : {dTxt}
    ''')


def e_print(msg: str, tag: str):
    print(e_tags[tag](msg), e_tags["end"])