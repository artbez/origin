pos :: Int -> [Int] -> Maybe Int
pos x list = if (prev == list) then Nothing
             else Just (length(prev) + 1)
             where prev = takeWhile (/=x) list
