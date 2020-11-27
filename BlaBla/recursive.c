#include <stdio.h>
#include <stdlib.h> 

// özyinelemeli fonksiyonumuz
int isPrime(int n, int i)
{
    if(i == 1)
        return 1;  
    else
    {
        if(n%i == 0)
            return 0;
        else
            isPrime(n, i-1);    
    }
}


int main()
{
    int num, prime;
    printf("Asal sayi olup olmadigini kontrol etmek istediginiz sayiyi giriniz: ");
    scanf("%d", &num);
    // (kontrol etmek istediginiz sayi ve onun yarisini bolmek icin kontrol veriyoruz)
    prime = isPrime(num, num/2);
    if(prime == 1)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}

