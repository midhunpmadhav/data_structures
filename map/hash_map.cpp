/*
 * Author      : Midhun P
 * Description : Map implementation
 * Remarks     : Implement map without STL
 */

#include <iostream>

using namespace std;

#define BUCKETS 10007

int find_hash(char *s){
  int p = 31;
  int pwr = 1;
  int hash = 0;
  char *c = s;

  for(char *c = s; *c != '\0'; ++c) {
    hash = (hash + (*c - '0' + 1) * pwr)%BUCKETS;
    pwr = (pwr*p)%BUCKETS;
  }

  return hash;
}

class Map {
private:
    char **data_store;

public:
    Map() {
        data_store = (char**) calloc (sizeof(char*), BUCKETS);
    }

    ~Map() {
        free(data_store);
    }

    void insert(char *data) {
        int hash = find_hash(data);

        if(data_store[hash])
            // Avoid collision by linear probing.
            while(data_store[++hash]);

        // Insert data.
        data_store[hash] = data;
    }

    void print() {
        for(int i = 0; i < BUCKETS; ++i)
            if(data_store[i])
                printf("%05d -> %s\n", i, data_store[i]);
    }
};

int main() {
  Map map;

  char a[] = "Hello_World_1";
  char b[] = "Hello_World_2";
  char c[] = "Hello_World_3";

  map.insert(a);
  map.insert(b);
  map.insert(c);

  map.print();
}