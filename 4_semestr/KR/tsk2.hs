data Tree a = Leaf a
              | Branch (Tree a) a (Tree a)
              
findALLMZ :: Tree Int -> [Int]
findALLMZ t = looker t [] where
          looker (Leaf a) list = if (a < 0) then (a : list) else list
          looker (Branch l a r) list = if (a < 0)
                                then looker r (a : (looker l list))
                                else looker r (looker l list)