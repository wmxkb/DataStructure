#include<stdio.h>
#include<iostream>
#include "SqStack.h"
using namespace std;
bool isValid(string s);

int main(){
	string s;
	cin>>s;
	cout<<isValid(s);
	return 0;
}

bool isValid(string s) {
        SqStack S;
        InitStack(S);
        int len = s.length();
        for(int i = 0 ; i < len ; ++i){
            switch(s[i]){
            //当检测到左括号，改为对应右括号存入栈中
            case '(':
                Push(S, ')');
                break;
            case '{':
                Push(S, '}');
                break;
            case '[':
                Push(S, ']');
                break;
            case ']':
			case ')':
			case '}':
                //当第一次检测到右括号，此时需要满足:
                //         1.右括号不是第一个出现的
                //         2.栈顶元素与之匹配，
                //           这里我们修改过左括号，所以只需要判断它们是否相等
                char e = ' ';
                GetTop(S, e);
                if(s[i] != e || i == 0)
                    return false;
                Pop(S, e);
            }
        }
        return StackEmpty(S);
    }