data Tree a = Leaf a
              | Branch (Tree a) a (Tree a)

treeHeight :: Tree a -> Integer
treeHeight (Leaf _) = 0
treeHeight (Branch left _ right) = max (treeHeight left) (treeHeight right) + 1

treeMinPath :: Tree a -> Integer
treeMinPath tree = treeMinPath tree 0 where
            treeMinPath (Leaf _) minP = minP
            treeMinPath (Branch left _ right) minP = min (treeMinPath left (minP + 1)) (treeMinPath right (minP + 1))
