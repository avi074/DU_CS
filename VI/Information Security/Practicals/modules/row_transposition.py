def cipher(plain_text: str, key: str) -> str:
    # Get the length of the key
    key_len = len(key)

    # Pad the plain text with extra spaces if necessary
    plain_text += ' ' * (key_len - len(plain_text) % key_len)

    # Calculate the number of rows
    rows = len(plain_text) // key_len

    # Create the matrix
    matrix = []
    for i in range(rows):
        matrix.append(list(plain_text[i * key_len:(i + 1) * key_len]))

    # Create the cipher text
    cipher_text = ""
    for j in range(key_len):
        for i in range(rows):
            cipher_text += matrix[i][key.index(str(j + 1))]

    return cipher_text


def decipher(cipher_text: str, key: str) -> str:
    # Get the length of the key
    key_len = len(key)

    # Calculate the number of rows
    rows = len(cipher_text) // key_len

    # Create the matrix
    matrix = []
    for i in range(rows):
        matrix.append([''] * key_len)

    # Fill in the matrix column by column
    col = 0
    for j in range(key_len):
        col_index = key.index(str(j + 1))
        for i in range(rows):
            matrix[i][col_index] = cipher_text[col]
            col += 1

    # Read the plain text from the matrix
    plain_text = ""
    for i in range(rows):
        for j in range(key_len):
            plain_text += matrix[i][j]

    # Remove any trailing spaces
    plain_text = plain_text.rstrip()

    return plain_text