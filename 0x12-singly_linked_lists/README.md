# 0x12. C- Singly linked lists
A linked consist of a chain of `struct` type elements called nodes. Each node
contains a pointer to the next node in the chain.

The pointer in the last node in a linked list is a pointer to `NULL` or
in other word a `NULL` pointer. 

A linked list is more flexible than an array because you can easily insert and delete nodes
in a linked list allowing the list to grow and shrink as needed. 

Although unlike an array which any of its element can be accessed with the
same speed, accessing a node in a linked list is fast if the node is close to the
beginning of the list and slow if it's near the end.

## DECLARING A NODE TYPE
To set up a linked list, the first thing you will need is a structure that
represents a single node in the list. Lets assume that a node contains a
character pointer, unsigned int and a pointer to the next node in the list.
The structure of the node we look like this:
```C
struct node 
{
	char *str;  /* Data stored in the node */
	unsigned int len; /*Data stored in the node */
	struct node *next; /* pointer to the next node in the list */
}
```
when a structure has a member that points to its same kind of structure just like
`struct node` does, you are required to use a **structure tag**.

But you can also use `typedef` name to create the above `struct` like this:
```C
typdef struct node
{
	char *str;   /* Data stored in the node */
	unsigned int len; /* Data stored in the node */
	struct node *next; /* pointer to the next node in the list */ 
} list_t;
```

One advantage of a linked list is that nodes can be added at any point 
in the list. But adding nodes at the beginning of the list is the easiest
method.

Once a structure of a node is declared, you'll need a way to keep track of
where the list begins. In other words, you'll need a pointer variable that always
points to the first node in the list. 

For `struct node` we can create this pointer variable like this:
```C
struct node *head; /* head points to a structure of type struct node */

/* Since we don't have any nodes in the list yet, we can set the pointer to
 * point to a NULL address
 */

head = NULL;
```
Setting the pointer variable `head` to `NULL` indicates that the list is
intially empty.

## CREATING A NODE
To construct a linked list, you will need to create a node and then add the node you have 
created to the list and then repeat the same process the on and on till you have
created and added the total amount of nodes that you want in the linked list. 

Creating a node requires three steps:
- Allocate memory on the heap for the node
- Store data in the node
- insert the node into the list

When you create a node, you'll need a pointer variable that can point to the node
temporarily, until it has been inserted into the list. Then you can use `malloc`
to allocate memory for the new node and save the address returned by the
`malloc` operation in the pointer variable

```C
struct node *new_node;
```



