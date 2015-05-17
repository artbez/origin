import Control.Monad

isBiggest :: (Ord a) => a -> a -> a -> Maybe a 
isBiggest x1 x2 x3 = if ((x1 < x2) && (x3 < x2)) then Just x2 else Nothing

biggest :: (Ord a) => [a] -> Maybe a
biggest (x1:x2:x3:xs) = (isBiggest x1 x2 x3) `mplus` (biggest $ x2:x3:xs)
biggest _ = Nothing