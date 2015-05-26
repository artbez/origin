newtype Polynom = Polynom [Int] deriving (Eq)

sign :: Int -> String
sign x  | x > 0 = "+"
        | otherwise = ""
        
showStep :: Int -> Int -> String
showStep 0 _ = ""
showStep x 0 = show x
showStep x 1 = sign x ++ show x ++ "x"
showStep x n = sign x ++ show x ++ "x^" ++ show n

instance Show Polynom where
         show (Polynom l) = show' l 0 where
              show' [] n = ""
              show' (l1:ls) n = showStep l1 n ++ show' ls (n + 1)

add :: Polynom -> Polynom -> Polynom
add (Polynom p) (Polynom l) = Polynom (p `add'` l) where
                              add' p [] = p
                              add' [] l = l
                              add' (p1:ps) (l1:ls) = (p1 + l1) : add' ps ls

neg :: Polynom -> Polynom
neg (Polynom p) = Polynom (neg' p) where
                neg' [] = []
                neg' (p1:ps) = (-p1:ps)

take' :: Int -> [Int] -> [Int]
take' n l
    | n > length l = take' n (l ++ [0])
    | otherwise = take n l

mult :: Polynom -> Polynom -> Polynom
mult (Polynom l) (Polynom s) = Polynom [sum $ zipWith (*) (take' n l) (reverse $ take' n s) 
                          | n <- [1..(length l + length s)]]

testP = Polynom [1, 0, 3, -2, 1]
testQ = Polynom [1, 2]