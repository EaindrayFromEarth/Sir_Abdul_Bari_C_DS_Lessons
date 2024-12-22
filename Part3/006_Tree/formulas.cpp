/*
T(n) = [(2n C n) / (n + 1)]
T(n) = [(2n C n) / (n + 1)] * n! // For labeled nodes
T(n) = Σ (T(i - 1) * T(n - i)) for i = 1 to n // Recursive relation

// If height is given:
Max nodes: n = 2^(h + 1) - 1
Min nodes: n = h + 1

// If nodes are given:
Min height: h = log2(n + 1) - 1
Max height: h = n - 1

// Relationship between internal nodes and external nodes:
deg(0) = deg(2) + 1

// Strict binary tree:
If height is given:
Min nodes: n = 2^h + 1
Max nodes: n = 2^(h + 1) - 1

If nodes are given:
Min height: h = log2(n + 1) - 1
Max height: h = (n - 1) / 2


m-ary Trees:

1. For a strict m-ary tree:
   - If height is given:
     - Minimum nodes: n = m^h
     - Maximum nodes: n = m^(h + 1) - 1

   - If nodes are given:
     - Minimum height: h = log_m(n + 1)
     - Maximum height: h = n - 1

2. General properties:
   - Total number of nodes (n) in a complete m-ary tree of height h:
     n = (m^(h + 1) - 1) / (m - 1)

   - Total number of leaves in a complete m-ary tree of height h:
     Leaves = m^h

   - Total number of internal nodes in a complete m-ary tree of height h:
     Internal nodes = (m^(h + 1) - 1) / (m - 1) - m^h

3. Relationship between internal nodes and external nodes:
   - For any m-ary tree:
     External nodes = Internal nodes + 1

4. Height of an m-ary tree:
   - Height (h) can be calculated based on the number of nodes (n):
     h = log_m(n * (m - 1) + 1) - 1


Representation of Bineary Tree
 element -> i
 left child -> 2*i
 right child -> 2*i+1
 Parent - [i/2]

*/
