#ifndef JSHASH_H_
#define JSHASH_H_

struct entry_s {
	char *key;
	void *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;	
};

typedef struct hashtable_s hashtable_t;


/* Create a new hashtable. */
hashtable_t *ht_create( int size );
/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, char *key );
/* Create a key-value pair. */
entry_t *ht_newpair( char *key, void *value );
/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, char *key, void *value );
/* Retrieve a key-value pair from a hash table. */
char *ht_get( hashtable_t *hashtable, char *key );

hashtable_t *Hash;

void makeHash();

#endif
