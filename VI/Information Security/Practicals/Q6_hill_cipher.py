import modules.hill_cipher as hill
import modules.basic_functions as func

# Example
key = 'hill'
txt = "attack to dawn"
ctxt = hill.cipher(txt, key)
dtxt = hill.decipher(ctxt, key)  # type: ignore

func.c_print("HILL CIPHER", txt, key, ctxt, dtxt)  # type: ignore
