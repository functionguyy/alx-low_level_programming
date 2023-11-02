# 0x1A. C -Hash tables

## Learning Objectives
- What is a hash function
- What makes a good hash function
- What is a hash table, how do they work and how to use them
- What is a collision and what are the main ways of dealing with collisions in the context of a hash table
- What are the advantages and drawbacks of using hash tables
- What are the most common use cases of hash tables

## What is a hash function
A hash function is any function that can be used to map data of arbitrary size
to fixed-size values known as hashes. Hashes are values returned by a hash
function which are index values for a fixed-size table called a hash table.
This process of using a hash function to index a hash table is known as
hashing.

Hash functions rely on generating favourable probability distributions for
their effectiveness, reducing access time to nearly constant.

## What makes a good hash function
A good hash function satisfies two basic properties:
- It should be very fast to compute
- It should minimize duplication of output values (collision)

## Resources
- [Why does calloc exist](https://vorpus.org/blog/why-does-calloc-exist/)
- [More details on calloc](https://stackoverflow.com/a/18251590)
- [How to implement a hash table in C](https://benhoyt.com/writings/hash-table-in-c/)
- [Hash table implementation{github}](https://github.com/benhoyt/ht/blob/master/ht.c)
