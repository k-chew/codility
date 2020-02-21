def solution(A):
    N = len(A)
    sum1 = 0
    sum2 = sum(A)
    #print("the sum of the array is: " + str(sum2))
    min_diff = abs(sum(A[1:N]) - A[0])
    #print("the first difference is: " + str(min_diff))
    for i in range(N-1): # 0 < P < N
        #print(str(i))
        sum1 += A[i]
        sum2 -= A[i]
        #print("first sum is: " + str(sum1))
        #print("second sum is: " + str(sum2))
        if abs(sum2 - sum1) < min_diff:
            min_diff = abs(sum2 - sum1)
            #print("the new min_diff is: " + str(min_diff))
    return min_diff
