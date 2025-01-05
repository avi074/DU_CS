import modules.basic_functions as func
import modules.product_transposition as product

ptxt = 'IAMTHEBEST'
key = 3

ctxt = product.crypt(ptxt, key, True)

dtxt = product.crypt(ctxt, key, False)

func.c_print('Product Cipher', ptxt, key, ctxt, dtxt)