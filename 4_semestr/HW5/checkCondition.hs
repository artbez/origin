checkCondition :: (a -> Bool) -> [a] -> Bool
checkCondition f [] = True
checkCondition f (l1:ls) = if (not $ f l1) then False else checkCondition f ls