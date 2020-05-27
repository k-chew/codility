def solution(X, Y, D):
    assert(X <= Y)
    assert(D > 0)
    if (Y - X) % D == 0: 
        return (Y - X) // D
    else:
        return ((Y - X) // D) + 1
