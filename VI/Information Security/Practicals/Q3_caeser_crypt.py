import modules.basic_functions as func
import modules.caesar_crypt as caesar

text = "The quick brown fox jumps over the lazy dog."
shift = 3
encrypted_text = caesar.crypt(text, shift)
decrypted_text = caesar.crypt(encrypted_text, -shift)

func.c_print("Caesar Cipher", text, shift, encrypted_text, decrypted_text)
