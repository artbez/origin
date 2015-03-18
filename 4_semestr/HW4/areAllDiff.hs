isAllDiff :: (Eq a) => [a] -> Bool

isAllDiff [] = True
isAllDiff (l1:ls) | l1 `elem` ls = False
                  | otherwise    = isAllDiff ls