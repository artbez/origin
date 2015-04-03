isPrime :: Int -> Int -> Bool

isPrime x 1 = True
isPrime x n = if (x `mod` n == 0) then False else isPrime x (n - 1)

func = [ x | x <- [2..], isPrime x (x-1)]