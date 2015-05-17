getInterList :: Int -> [[Int]]
getInterList 0 = [[]]
getInterList n = concatMap (\s -> [1:s, 2:s, 3:s]) $ getInterList (n - 1)
