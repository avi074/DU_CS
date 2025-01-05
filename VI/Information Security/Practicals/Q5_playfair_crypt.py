import modules.basic_functions as funcs
import modules.playfair_crypt as playfair

plain_txt = "instruments"
key = "monarchy"
enc_txt = playfair.crypt(plain_txt, key, True)
dec_txt = playfair.crypt(enc_txt, key, False)

print('\n', end="Practical 5\n".center(40))
funcs.c_print("Playfair Cipher", plain_txt, key, enc_txt, dec_txt)