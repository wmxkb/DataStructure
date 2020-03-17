#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INISIZE 10
#define Status int
#define ERROR 0
#define PASS 1
#define OVERFLOW -1

//抽象数据类型线性表--顺序存储结构表示
typedef int ADT;
typedef struct {
    ADT* Element;
    int Length;
    int Listsize;
}List;

//初始化线性表
Status InitList(List& L) {
    L.Element = (ADT*)malloc(INISIZE * sizeof(ADT));
    if (!L.Element)exit(OVERFLOW);
    L.Length = 0;
    L.Listsize = INISIZE;
    return PASS;
}

//清空线性表
void ClearList(List& L) {
    memset(L.Element, 0, L.Listsize);
    L.Length = 0;
}

//摧毁线性表
void DestroyList(List& L) {
    free(L.Element);
    L.Element = NULL;
    L.Listsize = 0;
    ClearList(L);

}

//判断线性表是否为空
bool ListEmpty(List L) {
    return L.Length == 0 ? true : false;
}

//返回线性表中的元素个数
int ListLength(List L) {
    return L.Length;
}

//返回线性表中第i个元素的值
int GetElem(List L, int i, ADT& e) {
    if (i < 1 || i > L.Length) {
        return ERROR;
    }
    else {
        e = L.Element[i - 1];
        return PASS;
    }
}

//返回线性表中的一个与e满足关系compare()的数据元素的位序
int LocateElem(List L, ADT e, bool(*compare)(ADT, ADT)) {
    for (int i = 0; i < L.Length; ++i) {
        if (compare(e, L.Element[i])) {
            return i + 1;
        }
    }
    return ERROR;
}

//返回cur_e的前驱元素
int PriorElem(List L, ADT cur_e, ADT& pre_e) {
    int i = 1;
    if (L.Element[0] != cur_e) {
        while (i < L.Length && L.Element[i] != cur_e)
            i++;
        if (i < L.Length) {
            pre_e = L.Element[i - 1];
            return PASS;
        }
    }
    return ERROR;
}
//返回cur_e的后继元素
int NextElem(List L, ADT cur_e, ADT& next_e) {
    int i = 0;
    if (L.Element[L.Length - 1] != cur_e) {
        while (i < L.Length && L.Element[i] != cur_e)
            i++;
        if (i < L.Length - 1) {
            next_e = L.Element[i + 1];
            return PASS;
        }
    }
    return ERROR;
}
//在第i个元素前插入新元素
int ListInsert(List& L, int i, ADT e) {
//插入元素的操作一定要注意，不然很容易出现“堆被破坏”这类错误
    if (i >= 1 && i <= L.Length + 1) {
        if (L.Length >= L.Listsize) {
            ADT* p = (ADT*)realloc(L.Element, 2 * sizeof(ADT) * L.Listsize);
            if (!p)exit(OVERFLOW);
            L.Element = p;
            L.Listsize *= 2;
        }
        ADT* q = &(L.Element[i - 1]);
        for (ADT* p = &(L.Element[L.Length - 1]); p >= q; --p) {
            *(p + 1) = *p;
        }
        *q = e;
        ++L.Length;
        return PASS;
    }
    else {
        return ERROR;
    }
}
//删除第i个元素
int ListDelete(List& L, int i, ADT& e) {
    if (i >= 1 && i <= L.Length) {
        e = L.Element[i - 1];
        for (int j = i - 1; j < L.Length - 1; ++j) {
            L.Element[j] = L.Element[j + 1];
        }
        --L.Length;
        return PASS;
    }
    else {
        return ERROR;
    }
}

//visit方法遍历线性表
void ListTraverse(List L, void(*visit)(ADT)) {
    for (int i = 0; i < L.Length; ++i) {
        visit(L.Element[i]);
    }
}
