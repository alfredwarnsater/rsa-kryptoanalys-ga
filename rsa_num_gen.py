from random import randint
import sys

def is_prime(num, test_count):
    if num == 1:
        return False
    if test_count >= num:
        test_count = num - 1
    for x in range(test_count):
        val = randint(1, num - 1)
        if pow(val, num-1, num) != 1:
            return False
    return True

def generate_big_prime(n):
    found_prime = False
    while not found_prime:
        p = randint(2**(n-1), 2**n)
        if is_prime(p, 1000):
            return p

for i in range(11, 201):
    b1 = i/2
    b2 = i-b1

    p = generate_big_prime(b1)
    q = generate_big_prime(b2)
    n = p*q
    bitl = n.bit_length()
        
    print('%03d' % bitl, p, q, n)


