#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 
 
bool isPalRec(char str[], int p, int f)  
{ 
    // Tek bir karakter kaldi ise 
    if (p == f) 
    return true; 
  
    //ilk kontrolumuzu yaptik. 
    if (str[p] != str[f]) 
    return false; 
  
    if (p < f + 1) {
    return isPalRec(str, p + 1, f - 1); 
    }

    return true; 
} 
  
bool isPalindrome(char str[]) 
{ 
    int n = strlen(str); 
    // uzunlugu 0 olan yani bos olan bir string girdigimizde
    if (n == 0) 
        return true; 
      // (string, ilk eleman, son elemean)
    return isPalRec(str, 0, n - 1); 
} 
  
int main() 
{ 
  
    // girilcek kelimeyi aliyoruz
    char str[100];
    printf( "Bir kelime giriniz :");
    gets( str );
    if (isPalindrome(str)) 
    printf("Palindromdur"); 
    else
    printf("Palindrom degildir"); 
  
    return 0; 
} 
