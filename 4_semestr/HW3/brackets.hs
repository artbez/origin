isCorrect :: String -> Bool
isCorrect s = isCorrect' s 0 where
          isCorrect' s k 
            | k < 0  = False
            | k >= 0 = case s of
              []       -> k == 0
              '(':xs  -> isCorrect' xs (k + 1)
              ')':xs  -> isCorrect' xs (k - 1)
              _:xs    -> isCorrect' xs k
           