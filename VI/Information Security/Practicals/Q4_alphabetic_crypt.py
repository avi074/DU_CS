import modules.basic_functions as func
import modules.monoalphabetic_crypt as mono_sub
import modules.polyalphabetic_crypt as poly_sub

plaintext = "Hello, World!"
key = "phqgiumeaylnofdxjkrcvstzwb"

cipher_text = mono_sub.crypt(plaintext, key, True)
decrypted_text = mono_sub.crypt(cipher_text, key, False)
func.c_print('Monoalphabetic Cipher', plaintext, key, cipher_text,
             decrypted_text)

key = "secret"
cipher_text = poly_sub.crypt(plaintext, key, True)
decrypted_text = poly_sub.crypt(cipher_text, key, False)
func.c_print('Polyalphabetic Cipher', plaintext, key, cipher_text,
             decrypted_text)
