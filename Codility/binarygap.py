int solution(int N) {
    int i = N;
    int count = 0;
    int last = 1;
    int max_count = 0;
    int binary_digit;
    if (N % 2 == 0) { // discounts trailing zeroes
        while (binary_digit != 1) {
            i /= 2;
            binary_digit = i % 2;
        }
    }
    while (i > 0) {
        binary_digit = i % 2;
        i /= 2;
        if (binary_digit == 1) {
            if (last == 0 && count > max_count) {
                max_count = count;
                count = 0;
            }
            last = 1;
            count = 0;
        } else {
            ++count;
            last = 0;
        }
    }
    return max_count;       
}
