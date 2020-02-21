def solution(X, Y, D):
    assert(X <= Y)
    assert(D >= 0)
    pos = X
    steps = 0
    while pos < Y:
        pos += D
        steps += 1
    return steps

