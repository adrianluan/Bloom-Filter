Bloom-Filter
============

A bloom filter with a false positive error rate of 2.5% using 2Mb space for 2,000,000 strings.
- bf_t * create_bf() creates a Bloom filter with the above specification.
- void insert_bf(bf_t *b, char *s) inserts the string *s into the Bloom filter *b.
- int is_element(bf_t *b, char *q) returns 1 if the string *q is accepted by the Bloom
