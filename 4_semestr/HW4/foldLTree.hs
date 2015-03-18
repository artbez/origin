data Tree a = Branch (Tree a) a (Tree a) | Leaf a

foldLTree :: (a -> b -> b) -> b -> Tree a -> b
foldLTree func beg (Leaf a) = func a beg
foldLTree func beg (Branch l a r) = foldLTree func newBeg r where
          newBeg = foldLTree func (a `func` beg) l