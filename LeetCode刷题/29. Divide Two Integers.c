int divide(int dividend, int divisor){
    // 被除数为0  ， 直接返回 0
    if(dividend == 0)
        return 0;
    // 极端情况
    if((dividend == INT_MIN && divisor == -1) || (dividend == INT_MAX && divisor == 1))
        return INT_MAX;
    // 符号
    int sign=((dividend < 0)^(divisor < 0)) ? -1 : 1;
    long x = (long)dividend, y = (long)divisor;
    //转为正，C语言不支持负数位运算
    if(dividend < 0)
        x = -x;
    if(divisor < 0)
        y = -y;
    long result = 0;
    // 除数左移，累加
    while(x >= y){
        long temp = y, res = 1;
        while(x >= (temp<<1))
        {
            res <<= 1;
            temp <<= 1;
        }
        result += res;
        x -= temp;
    }
    return sign > 0 ? result : -result;
}
