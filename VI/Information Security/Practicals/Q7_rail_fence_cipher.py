import modules.basic_functions as func
import modules.rail_fence_crypt as rail_fence

ptxt = 'IAMTHEBEST'
key = 3
ctxt = rail_fence.cipher(ptxt, key)

dtxt = rail_fence.decipher(ctxt, key)

func.c_print('Rail Fence Transposition Cipher', ptxt, key, ctxt, dtxt)
