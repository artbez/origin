myStepTwoList :: Integer -> Integer -> [Integer]
myStepTwoList 0 x = [x]
myStepTwoList n x = x : myStepTwoList (n - 1) (2 * x)

stepTwoList :: Integer -> [Integer]
stepTwoList x = myStepTwoList x 1