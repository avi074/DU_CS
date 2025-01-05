import modules.basic_functions as func
import modules.stream_cipher as stream

key = '12KEY34'
data = 'Hello World!'
cipher_text = stream.crypt(data, key)
dtxt = stream.crypt(cipher_text, key)

func.c_print("Stream Cipher", data, key, cipher_text, dtxt)