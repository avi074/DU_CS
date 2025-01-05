def cipher(text: str, key: int) -> str:
    rail = [''] * key
    direction = 1
    index = 0

    for char in text:
        rail[index] += char
        index += direction

        if index == 0 or index == key - 1:
            direction = -direction

    c_text = ''.join(rail)
    return c_text


def decipher(cipher_text: str, key: int) -> str:
    rail = [0] * key  # count the row length
    direction = 1
    index = 0

    for _ in cipher_text:
        rail[index] += 1
        index += direction

        if index == 0 or index == key - 1:
            direction = -direction

    # Fill in the rails with the ciphertext
    rail = [[''] * i for i in rail]
    i = 0
    for r in range(key):
        for c in range(len(rail[r])):
            rail[r][c] = cipher_text[i]
            i += 1

    # Read the plaintext from the rails
    direction = 1
    index = 0
    plain_text = ""

    for i in range(len(cipher_text)):
        plain_text += rail[index][0]
        rail[index] = rail[index][1:]
        index += direction

        if index == 0 or index == key - 1:
            direction = -direction

    return plain_text