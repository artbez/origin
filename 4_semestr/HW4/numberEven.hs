func1 :: [Int] -> Int
func1 l = foldr (\x y -> y + 1) 0 (filter even l)

func2 :: [Int] -> Int
func2 l = foldr (\x y -> if (x == Nothing) then y else y + 1) 0 (map (\x -> if (x `mod` 2 == 0) then Just x else Nothing) l)

func3 :: [Int] -> Int
func3 l = foldr (\x y -> if (x `mod` 2 == 0) then y + 1 else y) 0 l