def crypt(text: str, key: str) -> str:
    c_text = ""
    key_stream = ""
    index = 0

    # Generate the key stream
    while len(key_stream) < len(text):
        key_stream += key[index]
        index = (index + 1) % len(key)

    # Encrypt the plain text using the key stream
    for i in range(len(text)):
        c_char = ord(text[i]) ^ ord(key_stream[i])
        c_text += chr(c_char)

    return c_text