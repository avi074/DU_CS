import numpy as np
import modules.basic_functions as func


def get_cofactor(matrix: np.ndarray, i: int, j: int) -> np.ndarray:
    return np.delete(np.delete(matrix, i, axis=0), j, axis=1)


def get_cofactor_matrix(matrix: np.ndarray) -> np.ndarray:
    size = matrix.shape[0]
    cofactor_matrix = np.zeros((size, size))
    for i in range(size):
        for j in range(size):
            sign = (-1)**(i + j)
            cofactor = get_cofactor(matrix, i, j)
            cofactor_matrix[i, j] = sign * np.linalg.det(cofactor)
    return cofactor_matrix


def get_adjoint(matrix: np.ndarray) -> np.ndarray:
    cofactor_matrix = get_cofactor_matrix(matrix)
    adjoint_matrix = np.transpose(cofactor_matrix)
    return adjoint_matrix


def sanitize_str(text: str) -> str:
    return ''.join([char.upper() for char in text if char.isalpha()])


def is_total_square(num: int) -> 'tuple[int, bool]':
    n = np.sqrt(num)
    return int(n), n.is_integer()


def create_matrix(txt: str, size: 'list[int]') -> np.ndarray:
    txt_mat = [ord(char) - 65 for char in txt]  # 'A' = 65
    txt_mat = np.array(txt_mat, dtype=int).reshape(*size)
    return txt_mat.astype(int)


def mat_to_str(mat: np.ndarray) -> str:
    return ''.join([''.join(chr(ele + 65) for ele in row) for row in mat])


def create_key_matrix(key: str) -> np.ndarray:
    key = sanitize_str(key)
    lkey = len(key)
    n, is_square = is_total_square(lkey)  # type: ignore
    if not is_square:
        raise ValueError('SQUARE_MATRIX_ERROR : Key Length must be square !!!')
    return create_matrix(key, [n, n])


def check_key_matrix(key: np.ndarray):
    try:
        detk = round(np.linalg.det(key)) % 26
        inv_detk = pow(detk, -1, 26)
        if detk == 0:
            raise ValueError()
    except Exception:
        raise ValueError(
            'DET_INVERSE_ERROR : Key matrix is not invertible !!!')
    else:
        return inv_detk


def create_txt_matrix(txt: str, n: int) -> np.ndarray:
    txt = sanitize_str(txt)
    ltxt = len(txt)
    if ltxt % n != 0:
        txt += 'X' * (n - (ltxt % n))
    return create_matrix(txt, [-1, n])


def cipher(txt: str, key: str) -> 'str | None':
    try:
        key_mat = create_key_matrix(key)
        check_key_matrix(key_mat)
        txt_mat = create_txt_matrix(txt, key_mat.shape[0])
        ctxt_mat = np.dot(txt_mat, key_mat) % 26

    except Exception as e:
        msg = str(e) + "\nCan't Encrypt !!!"
        func.e_print(msg, 'error')
    else:
        return mat_to_str(ctxt_mat)


def decipher(ctxt: str, key: str) -> 'str | None':
    try:
        key_mat = create_key_matrix(key)
        ctxt_mat = create_txt_matrix(ctxt, key_mat.shape[0])
        inv = check_key_matrix(key_mat)
        inv_key = (inv * get_adjoint(key_mat)) % 26
        txt_mat = np.round(np.dot(ctxt_mat, inv_key)).astype(int) % 26
    except Exception as e:
        msg = str(e) + "\nCan't Decrypt !!!"
        func.e_print(msg, 'error')
    else:
        return mat_to_str(txt_mat)