import modules.basic_functions as func
import modules.row_transposition as row_trans

ptxt = 'I AM THE BEST'
key = '12'
ctxt = row_trans.cipher(ptxt, key)

dtxt = row_trans.decipher(ctxt, key)

func.c_print('Row Transposition Cipher', ptxt, key, ctxt, dtxt)