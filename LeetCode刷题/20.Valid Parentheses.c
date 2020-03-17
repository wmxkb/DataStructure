

bool isValid(char * s){
    //获取字符串的长度
    int len = strlen(s);
    //创建一个工作指针指向字符串起始位置
    char* s1 = s;
    //遍历字符串
    for(int i = 0 ; i < len ; ++i){
        switch(*(s+i)){
            //当检测到左括号，通过s1指针将其修改为对应右括号
            case '(':
                *s1++ = ')';
                break;
            case '{':
                *s1++ = '}';
                break;
            case '[':
                *s1++ = ']';
                break;
            default:
                //当第一次检测到右括号，此时需要满足:
                //         1.右括号不是第一个出现的
                //         2.右括号左侧与之对应的左括号与之匹配，
                //           这里我们修改过左括号，所以只需要判断它们是否相等
                if(s1 == s || *--s1 != *(s+i))
                    return false;
        }
    }
    //满足以上2个条件，并且左括号和右括号数量匹配，返回True
    return s1 == s;

}
