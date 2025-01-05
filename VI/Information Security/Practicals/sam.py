import random


def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        print(f'\t{a} \t{b} \t{g} \t{x} \t{y}')
        return (g, x - (b // a) * y, y)


def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('No modular inverse')
    else:
        return x % m


print(modinv(17, 26))
