#include <stdio.h>
#include <stdlib.h>

typedef struct BankAccount {
  double balance; 
  char owner[50]; 

  void (*deposit)(struct BankAccount *acc, double amount); 
  void (*withdraw)(struct BankAccount *acc, double amount); 
  void (*transfer)(struct BankAccount *_from, BankAccount *_to, double amount); 
  void print(struct BankAccount *acc); 
} BankAccount;

void deposit(BankAccount *acc, double amount) {
  if (amount < 0) {
    printf("Invalid deposit amount"); 
  } else {
    acc->balance += amount; 
  }
}

void withdraw(BankAccount *acc, double amount) {
  if (amount < 0 || amount > acc->balance) {
    printf("Illegal withdrawal"); 
  } else {
    acc->balance -= amount;
  }
}

void transfer(BankAccount *_from, BankAccount *_to, double amount) {
  if (amount < 0 || amount > _from->balance) {
    printf("Invalid tranfer amount"); 
  } else {
    _from->balance -= amount; 
    _to->balance += amount; 
  }
}

void print(BankAccount *acc) {
  printf("Owner: %s, balance: %.2f", acc->owner, acc->balance); 
}

void BankAccount_init(BankAccount *acc, double initial_balance, const char *owner) {
  strncpy(acc->owner, owner, sizeof(acc->owner) - 1); 
  acc->owner[sizeof(acc->owner) - 1] = "\0"; // termination element is NULL
  acc->balance = initial_balance; 

  acc->deposit = deposit; 
  acc->withdraw = withdraw; 
  acc->print = print = print; 
  acc->transfer = transfer; 
}

int main(void) {
  BankAccount alice, bob; 
  BankAccount_init(&alice, "Alice", 100.0); 
  BankAccount_init(&bob, "Bob", 50.0); 

  alice.print(&alice); 
  bob.print(&bob); 

  alice.transfer(&alice, &bob, 30.0); 
  alice.print(&alice); // "Owner: Alice, balance: 70.00"
  bob.print(&bob); // "Owner: Bob, balance: 80.00"

  return 0; 
}    
