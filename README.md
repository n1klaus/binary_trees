# Binary trees

## Searching
```
 Iterative-Tree-Search(x, key)
   while x ≠ NIL and key ≠ x.key then
     if key < x.key then
       x := x.left
     else
       x := x.right
     end if
   repeat
   return x
```

## Minimum
```
BST-Minimum(x)
   while x.left ≠ NIL then
     x := x.left
   repeat
   return x
```

## Maximum
```
BST-Maximum(x)
   while x.right ≠ NIL then
     x := x.right
   repeat
   return x
```

## Successor
```
 BST-Successor(x)
   if x.right ≠ NIL then
     return BST-Minimum(x.right)
   end if
   y := x.parent
   while y ≠ NIL and x = y.right then
     x := y
     y := y.parent
   repeat
   return y
```

## Predecessor
```
 BST-Predecessor(x)
   if x.left ≠ NIL then
     return BST-Maximum(x.left)
   end if
   y := x.parent
   while y ≠ NIL and x = y.left then
     x := y
     y := y.parent
   repeat
   return y
```

## Insertion
```
1    BST-Insert(T, z)
2      y := NIL
3      x := T.root
4      while x ≠ NIL do
5        y := x
6        if z.key < x.key then
7          x := x.left
8        else
9          x := x.right
10       end if
11     repeat
12     z.parent := y
13     if y = NIL then
14       T.root := z
15     else if z.key < y.key then
16       y.left := z
17     else
18       y.right := z
19     end if
```

## Deletion
```
1    Shift-Nodes(T, u, v)
2      if u.parent = NIL then
3        T.root := v
4      else if u = u.parent.left then
5        u.parent.left := v
5      else
6        u.parent.right := v
7      end if
8      if v ≠ NIL then
9        v.parent := u.parent
10     end if
```

```
1    BST-Delete(T, z)
2      if z.left = NIL then
3        Shift-Nodes(T, z, z.right)
4      else if z.right = NIL then
5        Shift-Nodes(T, z, z.left)
6      else
7        y := Tree-Successor(z)
8        if y.parent ≠ z then
9          Shift-Nodes(T, y, y.right)
10         y.right := z.right
11         y.right.parent := y
12       end if
13       Shift-Nodes(T, z, y)
14       y.left := z.left
15       y.left.parent := y
16     end if
```

## Traversal
Inorder tree walk: Nodes from the left subtree get visited first, followed by the root node and right subtree.
```
 Inorder-Tree-Walk(x)
   if x ≠ NIL then
     Inorder-Tree-Walk(x.left)
     visit node
     Inorder-Tree-Walk(x.right)
   end if
```

Preorder tree walk: The root node gets visited first, followed by left and right subtrees.
```
Preorder-Tree-Walk(x)
   if x ≠ NIL then
     visit node
     Preorder-Tree-Walk(x.left)
     Preorder-Tree-Walk(x.right)
   end if
```

Postorder tree walk: Nodes from the left subtree get visited first, followed by the right subtree, and finally the root.
```
Postorder-Tree-Walk(x)
   if x ≠ NIL then
     Postorder-Tree-Walk(x.left)
     Postorder-Tree-Walk(x.right)
     visit node
   end if
```