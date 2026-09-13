int reverse(int num) {
    int rev_num;
    while (num > 0) {
        rev_num = rev_num*10 + num%10;
        num /= 10;
    }
    return rev_num;
}