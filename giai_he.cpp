/*
    giải hệ phương trình đồng dư:
    X = a (mod a1) (1)
    X = b (mod b1) (2)
    X = c (mod c1) (3)
    Ta giải 2 phương trình đầu xong lấy kết quả
    kết hợp kết quả với pt 3 giải ra kết quả cuối
    
    cách làm:
    từ pt 1 rút ra đc: X = a + a1*u (u thuộc Z)
    thay vào pt 2:
    a + a1*u =  b (mod b1)
    a1*u = b-a (mod b1) (tmg = b-a)
    a1*u = tmg (mod b1)
    giải pt 1 ẩn ra kết quả x = 

*/

#include <stdio.h>
#include <stdlib.h>

// tìm ước chung lớn nhất giữa hệ số ẩn vs hệ số mod
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

// rút gọn các hệ số
void kiemtra(int &g, int &h, int &i){
    int max;
    max = UCLN(g, i);
    if(h % max == 0){
        g /= max;
        h /= max;
        i /= max;
    }
}

// tìm nghiệm của phương trình 1 ẩn
void xuly(int &x, int &y, int &z, int &n){
    while(y < 0){
        y+=z;
    }
    if(x > z){
        kiemtra(x, y, z);
    }
    if(x > z){
        x %= z;
        kiemtra(x, y, z);
        if(x != 1){
            for(int i = 0; i <= x; i++){
                int tmg;
                tmg = y + (i*(z));
                if(tmg % x == 0){
                    n = tmg / x;
                    break;
                    }
                }
        }else{
            n = y;
        }
    }else if(x < z){
        kiemtra(x, y, z);
        if(x == 1){
            n = y;
        }else{
            for(int i = 0; i <= x; i++){
                int tmg;
                tmg = y + (i*(z));
                if(tmg % x == 0){
                    n = tmg / x;
                    break;
                }
            }
        }
    }
}

int main(){
    int a, a1, b, b1, c, c1, tmg, n=1;
    int ta, ta1, td1;
    printf("nhap vao cac gia tri: \n");
    printf("nhap a = "); scanf("%d", &a);
    printf("nhap a1 = "); scanf("%d", &a1);
    printf("nhap b = "); scanf("%d", &b);
    printf("nhap b1 = "); scanf("%d", &b1);
    printf("nhap c = "); scanf("%d", &c);
    printf("nhap c1 = "); scanf("%d", &c1);
    ta = a; //gán lấy giá trị ban đầu
    ta1 = a1; // gán lấy giá trị ban đầu
    tmg = b-a; 
    xuly(a1, tmg, b1, n);
    int d, d1;
    d = ta + ta1*n;
    d1 = ta1*b1;
    td1 = d1; // gán lấy giá trị
    tmg = c-d;
    n = 1;
    xuly(d1, tmg, c1, n);
    d += (td1*n);
    td1 *= c1;
    printf("\nnghiem cuoi X = %d (mod %d)", d, td1);
}