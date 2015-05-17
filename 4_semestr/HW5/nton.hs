nton :: Int -> [Int]
nton n = [1..n] >>= (\s -> map (*s) [1..n])