def crypt(text: str, key: str, encrypt: bool) -> str:
    # Create a dictionary mapping each letter to its corresponding key letter
    letter_map = dict()

    for i in range(26):
        if encrypt:
            letter_map[chr(i + 97)] = key[i]
        else:
            letter_map[key[i]] = chr(i + 97)

    c_text = ""
    for char in text:
        if char.isalpha():
            # Substitute the character using the letter map
            c_text += letter_map[
                char.lower()].upper() if char.isupper() else letter_map[char]
        else:
            c_text += char
    return c_text