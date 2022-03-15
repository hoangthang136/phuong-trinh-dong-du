/*
    ta có phương trình đồng dư bậc nhất 1 ẩn là ax = b(mod c)
*/

#include <stdio.h>

// tìm ước chung lớn nhất giữa a vs c
int UCLN(int a, int c){
    if(a == 0 || c == 0){
        return a + c;
    }
    while(a != c){
        if(a > c){
            a -= c;
        }else{
            c -= a;
        }
    }
    return a;
}

// tìm nghiệm t
int nghiem(int a, int b, int c){
    int n;
    for(int i = 1; i <= a; i++){
        int tmg;
        tmg = b + (i*c);
        if(tmg % a == 0){
            n = tmg / a;
            return n;
        }
    }
}

// xuất ra danh sách nghiệm
void xuat(int max, int b, int c, int d){
    printf("phuong trinh co %d nghiem: ", max);
        for(int i = 1; i <= max; i++){
            printf("\t%d", b);
            b += c;
        }
    printf("\tmod(%d)", d);
}

int main(){
    int a, b, c, d;
    printf("nhap so a: "); scanf("%d", &a);
    printf("nhap so b: "); scanf("%d", &b);
    printf("nhap so c: "); scanf("%d", &c);
    int max = UCLN(a, c);
    d = c;
    a /= max;
    b /= max;
    c /= max;
    if(a == 1){
        xuat(max, b, c, d);
    }else if(a > c){
        a %= c;
        if(a==1){
            xuat(max, b, c, d);
        }else{
            int n = nghiem(a, b, c);
            xuat(max, n, c, d);
        }
    }else if(c > a){
        int n = nghiem(a, b, c);
        xuat(max, n, c, d);
    }
}