import string


# Create a Playfair cipher key matrix
def create_matrix(key: str) -> 'list[list[str]]':
    # Remove any duplicate characters from the key and convert to uppercase
    key = "".join(set(key.upper()))

    # Remove the letter 'J' from the key and add it to the end
    key = key.replace("J", "I")

    # Fill the rest of the matrix with the remaining letters of the alphabet
    alphabet = string.ascii_uppercase
    matrix = []
    for char in key + alphabet:
        if char != 'J' and char not in matrix:
            matrix.append(char)

    # Convert the matrix to a 5x5 grid
    matrix_grid = [matrix[i:i + 5] for i in range(0, 25, 5)]
    return matrix_grid


# Find the row and column of a given letter in the Playfair cipher matrix
def find_letter_position(matrix: 'list[list[str]]',
                         letter: str) -> 'tuple[int, int]':
    for i, row in enumerate(matrix):
        if letter in row:
            return (i, row.index(letter))
    raise ValueError("Letter(%s) not found in matrix" % {letter})


# Encrypt a plaintext message using the Playfair cipher
def crypt(text: str, key: str, encrypt: bool) -> str:
    # Create the Playfair cipher matrix
    matrix = create_matrix(key)

    if encrypt:
        # Prepare the plaintext by removing all non-alphabetic characters and converting to uppercase
        text = "".join(filter(str.isalpha, text.upper()))
        text = text.replace('J', 'I')

        # If the length of the plaintext is odd, add a trailing 'X'
        if len(text) % 2 == 1:
            text += "Z"

    # Divide the plaintext into pairs of letters and encrypt each pair
    ctext = ""
    num = 1 if encrypt else -1
    for i in range(0, len(text), 2):
        letter1 = text[i]
        letter2 = text[i + 1]
        row1, col1 = find_letter_position(matrix, letter1)
        row2, col2 = find_letter_position(matrix, letter2)
        if row1 == row2:
            ctext += matrix[row1][(col1 + num) % 5]
            ctext += matrix[row2][(col2 + num) % 5]
        elif col1 == col2:
            ctext += matrix[(row1 + num) % 5][col1]
            ctext += matrix[(row2 + num) % 5][col2]
        else:
            ctext += matrix[row1][col2]
            ctext += matrix[row2][col1]
    return ctext