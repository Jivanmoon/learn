int main() {
    int i = 10, j = 20;
    int *p = &i;
    //更改指针的值
    p = &j;
    //更改指针所指对象的值
    *p = 30;
    return 0;
}