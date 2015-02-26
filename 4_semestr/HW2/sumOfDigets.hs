intToList :: Integer -> [Integer]
intToList x | x < 10 = [x]
            | x >= 10 = (mod x 10) : intToList (div x 10)

sumOfDigets :: Integer -> Integer
sumOfDigets n = foldl (+) 0 (intToList n) 
