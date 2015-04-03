tmp :: [Double] -> Double -> Double -> (Double, Double) 
tmp [] x1 x2 = (x1, x2)
tmp (l1:ls) x1 x2 = tmp ls (x1 + l1) (x2 * cos(x2))

myFunct :: [Double] -> Double
myFunct list = ((fst result) / (snd result)) where
        result = tmp list 0 1