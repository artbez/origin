data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findEl :: Tree a -> (a -> Bool) -> Maybe a
findEl (Leaf a) func = if (func a) then Just a else Nothing
findEl (Branch l a r) func = if (func a) then Just a
                             else case (findEl l func, findEl r func) of
                                  (Just x, _) -> Just x
                                  (_, Just x) -> Just x
                                  (_, _) -> Nothing
