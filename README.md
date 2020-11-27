# data-structures - Veri Yapıları
  <br>
  <img src="https://miro.medium.com/max/700/1*u2jndBtXWGGQK_DBKIDplA.jpeg" height="300" width="auto">
  <br>  

Yararlanılan siteye ulaşmak için [tıkla](https://www.geeksforgeeks.org/linked-list-set-1-introduction/?ref=lbp)


  
# Linked List | Set 1 (Giriş)

- Arrray gibi Linked List de doğrusal bir veri yapısıdır. Arraylerden farklı olarak, bağlantılı liste öğeleri bitişik bir konumda depolanmaz; öğeler pointer kullanılarak bağlanır.

## Neden Linked List?
Array benzer türlerdeki doğrusal verileri depolamak için kullanılabilir, ancak arrayler aşağıdaki sınırlamaları vardır.
  

1. Dizilerin boyutu sabittir: Öyleyse, eleman sayısının üst sınırını önceden bilmemiz gerekir. Ayrıca, genel olarak tahsis edilen bellek, kullanıma bakılmaksızın üst sınıra eşittir.
2. Bir eleman dizisine yeni bir eleman eklemek pahalıdır, çünkü odanın yeni elemanlar için yaratılması ve oda yaratmak için var olan elemanların kaydırılması gerekir.

- Örneğin, bir sistemde, bir dizi de sıralı bir kimlik listesi tutarsak.

> id[] = [1000, 1010, 1050, 2000, 2040].

Ve eğer yeni bir kimlik 1005 _eklemek_ istiyorsak, sıralı düzeni korumak için, tüm öğeleri 1000'den sonra taşımamız gerekir (1000 hariç).
Silme, bazı özel teknikler kullanılmadıkça dizilerde de pahalıdır. Örneğin, [] kimliğindeki 1010'u silmek için, 1010'dan sonraki her şeyin taşınması gerekir.

**Dizilere göre avantajları**

1. Dinamik boyut
2. Yerleştirme / silme kolaylığı

**Dezavantajlar:**

1. Rastgele erişime izin verilmez. İlk düğümden başlayarak öğelere sırayla erişmemiz gerekiyor. Dolayısıyla, varsayılan uygulamasıyla bağlantılı listelerde ikili arama yapamayız. Buradan okuyun.
2. Listenin her öğesi için bir işaretçi için fazladan bellek alanı gereklidir.
3. Önbellek dostu değil. Dizi elemanları bitişik konumlar olduğu için, bağlantılı listelerde bulunmayan bir referans yeri vardır.

**Temsil Etme** 
Bağlantılı bir liste, bağlantılı listenin ilk düğümüne bir gösterici ile temsil edilir. İlk düğüme kafa denir. Bağlantılı liste boşsa, başın değeri NULL olur.
Listedeki her düğüm en az iki bölümden oluşur:
Veriler(Data)
Bir sonraki düğüme işaretçi (Next)
C'de, yapıları kullanarak bir düğümü temsil edebiliriz. Aşağıda, tamsayı verileriyle bağlantılı bir liste düğümü örneği bulunmaktadır.

```
// A linked list node 
struct Node { 
    int data; 
    struct Node* next; 
}; 
```
```
// A simple C program to introduce 
// a linked list 
#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Program to create a simple linked 
// list with 3 nodes 
int main() 
{ 
    struct Node* head = NULL; 
    struct Node* second = NULL; 
    struct Node* third = NULL; 
  
    // allocate 3 nodes in the heap 
    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
  
    /* Dinamik olarak üç blok tahsis edilmiştir. Baş, ikinci ve üçüncü olarak bu üç bloğa işaretlerimiz var.

       head           second           third 
        |                |               | 
        |                |               | 
    +---+-----+     +----+----+     +----+----+ 
    | #  | #  |     | #  | #  |     |  # |  # | 
    +---+-----+     +----+----+     +----+----+ 
     
   # represents any random value. 
   Data is random because we haven’t assigned  
   anything yet  */
  
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with 
    // the second node 
  
    /* data has been assigned to the data part of the first 
     block (block pointed by the head). And next 
     pointer of first block points to second.   
     So they both are linked. 
  
       head          second         third 
        |              |              | 
        |              |              | 
    +---+---+     +----+----+     +-----+----+ 
    | 1  | o----->| #  | #  |     |  #  | #  | 
    +---+---+     +----+----+     +-----+----+     
  */
  
    // assign data to second node 
    second->data = 2; 
  
    // Link second node with the third node 
    second->next = third; 
  
    /* data has been assigned to the data part of the second 
     block (block pointed by second). And next 
     pointer of the second block points to the third  
     block. So all three blocks are linked. 
    
       head         second         third 
        |             |             | 
        |             |             | 
    +---+---+     +---+---+     +----+----+ 
    | 1  | o----->| 2 | o-----> |  # |  # | 
    +---+---+     +---+---+     +----+----+      */
  
    third->data = 3; // assign data to third node 
    third->next = NULL; 
  
    /* data has been assigned to data part of third 
    block (block pointed by third). And next pointer 
    of the third block is made NULL to indicate 
    that the linked list is terminated here. 
  
     We have the linked list ready.   
  
           head     
             | 
             |  
        +---+---+     +---+---+       +----+------+ 
        | 1  | o----->|  2  | o-----> |  3 | NULL | 
        +---+---+     +---+---+       +----+------+        
     
      
    Note that only head is sufficient to represent  
    the whole list.  We can traverse the complete  
    list by following next pointers.    */
  
    return 0; 
} 
```
