def inverse(a, n):
    t = 0
    newt = 1   
    r = n
    newr = a   
    while newr != 0:
        quotient = r // newr
        t, newt  = newt, t - quotient * newt
        r, newr = newr, r - quotient * newr

        print(t, newt, r, newr)

    if r > 1:
        return "a is not invertible"
    if t < 0:
        t = t + n
    return t

print(inverse(11, 26))