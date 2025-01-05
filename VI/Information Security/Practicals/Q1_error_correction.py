import modules.basic_functions as func


# Helper function to get the parity bits for a Hamming code
def get_parity_bits(msg):
    p1 = msg[0] ^ msg[1] ^ msg[3]
    p2 = msg[0] ^ msg[2] ^ msg[3]
    p3 = msg[1] ^ msg[2] ^ msg[3]
    return [p1, p2, msg[0], p3, msg[1], msg[2], msg[3]]


def remove_parity_bits(msg):
    return [msg[2], msg[4], msg[5], msg[6]]


# Helper function to correct an error in a Hamming code
def correct_error(msg):
    p1 = msg[0] ^ msg[2] ^ msg[4] ^ msg[6]
    p2 = msg[1] ^ msg[2] ^ msg[5] ^ msg[6]
    p3 = msg[3] ^ msg[4] ^ msg[5] ^ msg[6]
    error_index = p1 + p2 * 2 + p3 * 4 - 1
    if error_index >= 0:
        msg[error_index] ^= 1
    return msg


# Encode a msg with a (7, 4) Hamming code
msg = [1, 0, 1, 1]
encoded_msg = get_parity_bits(msg)

print("\n\t\t Practical 1 \n")
print("Message to be transmit\t : %s" % msg)

print("Encoded Message : %s" % encoded_msg)

# Add an error to the encoded msg
encoded_msg[3] ^= 1
print("Received Message : %s" % encoded_msg)

func.e_print("Error Occured !!!", 'error')
func.e_print("Solving the Error !!!", 'info')

# Correct the error and decode the msg
decoded_msg = remove_parity_bits(correct_error(encoded_msg))
print("Decoded Message: %s" % decoded_msg)
