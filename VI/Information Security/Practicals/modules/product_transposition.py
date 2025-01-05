'''
Product Cipher is a cipher technique where we use 
both substitution & transposition technique.
'''
import modules.caesar_crypt as cc
import modules.rail_fence_crypt as rfc


# Here Caeser & rail fence cipher is used !!!
def crypt(msg: str, key, encrypt: bool) -> str:
    if encrypt:
        txt = cc.crypt(msg, key)
        txt = rfc.cipher(txt, key)
    else:
        txt = rfc.decipher(msg, key)
        txt = cc.crypt(txt, -key)
    return txt