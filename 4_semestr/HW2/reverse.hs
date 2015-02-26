myReverse :: [a] -> [a] -> [a]
myReverse [] x = x
myReverse (x1:xs) a = myReverse xs (x1 : a)

reverse2 :: [a] -> [a]
reverse2 a = myReverse a []
