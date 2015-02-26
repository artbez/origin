myFstNumPosition :: Integer -> [Integer] -> Integer -> Integer
myFtsNumPosition x [] y = -1
myFstNumPosition x (x1:xs) y = if (x == x1) then y else myFstNumPosition x xs (y + 1)

fstNumPosition :: (Integer, [Integer]) -> Integer
fstNumPosition (x, l) = myFstNumPosition x l 0
