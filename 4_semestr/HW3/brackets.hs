isCorrect :: String -> Bool
isCorrect s = isCorrect' s [] where
          isCorrect' (x1:xs) k = case (x1, k) of
                     ('(', _) -> isCorrect' xs ('(':k)
                     ('[', _) -> isCorrect' xs ('[':k)
                     ('{', _) -> isCorrect' xs ('{':k)
                     (')', ('(':ks)) -> isCorrect' xs ks
                     (']', ('[':ks)) -> isCorrect' xs ks
                     ('}', ('{':ks)) -> isCorrect' xs ks
                     (_, _) -> False
          isCorrect' [] k = True
           