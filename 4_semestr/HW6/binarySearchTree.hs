data BinarySearchTree a = Branch a (BinarySearchTree a) (BinarySearchTree a) | Empty deriving (Eq, Show)

add :: (Ord a) => a -> BinarySearchTree a -> BinarySearchTree a
add val (Empty) = Branch val Empty Empty
add val (Branch x l r) | val < x = Branch x (add val l) r
                       | val > x = Branch x l (add val r)
                       | otherwise = Branch x l r

findMax :: (Ord a) => BinarySearchTree a -> a
findMax tree = case tree of
        (Branch x l Empty) -> x
        (Branch x l r)     -> findMax r
        (Empty)            -> error "tree is empty"

remove :: (Ord a) => a -> BinarySearchTree a -> BinarySearchTree a
remove val (Empty) = Empty
remove val (Branch x l r) | val < x = Branch x (remove val l) r
                       | val > x = Branch x l (remove val r)
                       | otherwise = case (l,r) of
                              (Empty, Empty)            -> Empty
                              (Empty, _)                -> r
                              (_, Empty)                -> l
                              (Branch x1 l1 Empty, _)   -> Branch x1 l1 r
                              (Branch x1 l1 r1, _)      -> Branch newV (remove newV l1) r where newV = findMax l1

search :: (Ord a) => a -> BinarySearchTree a -> Bool
search a (Empty) = False
search val (Branch x l r) | val < x = search val l
                          | val > x = search val r
                          | otherwise = True



size :: BinarySearchTree a -> Int
size Empty = 0
size (Branch x l r) = 1 + size l + size r

height Empty = 0
height (Branch x l r) = 1 + max (height l) (height r)
