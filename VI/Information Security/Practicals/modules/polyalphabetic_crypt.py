def crypt(text: str, key: str, encrypt: bool) -> str:
    # Convert the key to a list of shift values
    shifts = [ord(char) - 97 if encrypt else 97 - ord(char) for char in key]

    converted_text = ""
    i = 0
    for char in text:
        if char.isalpha():
            # Shift the character by the current shift value
            shifted_char = chr(
                (ord(char.lower()) - 97 + shifts[i % len(key)]) % 26 + 97)
            converted_text += shifted_char.upper() if char.isupper(
            ) else shifted_char
            i += 1
        else:
            converted_text += char
    return converted_text