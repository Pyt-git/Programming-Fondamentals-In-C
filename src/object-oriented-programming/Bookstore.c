#include <stdio.h>
typedef struct Bookstore {
  int bookCount; 
  int booksSold; 

  void (*restock)(struct Bookstore *store, int amount); 
  void (*sellBook)(struct Bookstore *store, int amount); 
  double (*totalSells)(struct Bookstore *store, double price); 
  void (*print)(struct Bookstore *store, double price); 
} Bookstore; 

void restock(Bookstore *store, int amount) {
  if (amount < 0) {
    printf("invalid amount of books"); 
  } else {
    store->bookCount += amount; 
  }
}
void sellBook(Bookstore *store, int amount) {
  if (amount > store->bookCount || amount < 0) {
    printf("invalid amount of books"); 
  } else {
    store->bookCount -= amount; 
    store->booksSold += amount; 
  }
}
double totalSells(Bookstore *store, double price) {
  if (price < 0) {
    printf("Price is negative");
    return 0.0; 
  } 
  if (store->booksSold <= 0) {
    printf("no books sold yet"); 
    return 0.0; 
  }
  return store->booksSold * price;
}
void print(Bookstore *store, double price) {
  printf("Books remaining: %d, total sells %.2f", store->bookCount, store->totalSells(store, price))
}

void Bookstore_init(Bookstore *store, int bookCount; int booksSold) {
  store->bookCount = bookCount; 
  store->booksSold = booksSold; 
  store->restock = restock; 
  store->sellBook = sellBook; 
  store->totalSells = totalSells; 
  store->print = print; 
}

// Example usage - flexible initialization:
int main(void) {
  int initialBooks; 
  printf("Enter initial amount of books in stock: "); 
  scanf("%d", &initialBooks); 

  Bookstore *store = malloc(sizeof(Bookstore)); 
  if (store == NULL) {
    perror("malloc failed"); 
    return 1; 
  }

  Bookstore_init(store, initialBooks, 0) {
    store->sellBook(store, 5); 
    store->restock(store, 10); 
    store->print(store, 10.00);

    free(store); // release memory; 
    return 0; 
  }
}
