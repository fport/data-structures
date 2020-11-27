#include<stdio.h>


void print_fact(int n)
{
    if (n==1) {
        return;
    }

    int num=2;
    while (n%num != 0)
        num++;
    printf("%d ",num);
    //tekrar print_fact fonksiyonumuzu cagiriyoruz
    print_fact (n/num);
}

int main ()
{
    int n;
    printf("Bir sayi giriniz : \n");
    scanf("%d",&n);
    print_fact(n);
}
