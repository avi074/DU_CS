"""
    * Encryption:
        The given text using a Caesar cipher with the given shift value.

        Parameters:
        text (str) : The plaintext to encrypt.
        shift (int): The number of positions to shift each character by.

        Returns:
        str: The ciphertext.

    * Decryption:
        The given ciphertext using a Caesar cipher with the given shift value.

        Parameters:
        text (str) : The ciphertext to decrypt.
        shift (int): The number of positions to shift each character by. Use unary negative for decryption.

        Returns:
        str: The plaintext.

    * Example:
        text = "The quick brown fox jumps over the lazy dog."
        shift = 3
        encrypted_text = caesar_crypt(text, shift)
        decrypted_text = caesar_crypt(encrypted_text, -shift) # unary negative for converting algo

"""


def crypt(text: str, shift: int) -> str:
    converted_text = ""
    for char in text:
        if char.isalpha():
            # Shift the character by the given amount
            shifted_char = chr((ord(char.lower()) - 97 + shift) % 26 + 97)
            converted_text += shifted_char.upper() if char.isupper(
            ) else shifted_char
        else:
            converted_text += char
    return converted_text