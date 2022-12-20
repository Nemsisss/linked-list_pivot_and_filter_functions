# linked-list_pivot_and_filter_functions
A recursive implementation of pivot and filter functions for linked lists.

Pivot function:
Given a linked list pointed to by head, creates two lists where all values less than or equal to the pivot value are placed in a linked list whose head will be pointed to by smaller and all values greater than the pivot value are placed in a linked list whose head will be pointed to by larger.  The input list pointed to by head is empty upon return and head is set to NULL (i.e. we are not making copies) in the smaller and larger lists but simply moving Nodes out of the input list and into the two other lists.

Filter function:
 Given a linked list pointed to by head, removes (filters out) nodes whose value does not meet the criteria given by the predicate function object, pred (i.e. pred is a function object that implements `bool operator()(int value)` and returns *true* for items that should be *removed/filtered*.  Removed items are deallocated.
