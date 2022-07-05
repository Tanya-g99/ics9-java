int main() {
    int a,b,c,d,m;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    m = a;
    if (m < b) m = b;
    if (m < c) m = c;
    if (m < d) m = d;
    printf("%d\n", m);
    return 0;
}