import Control.Monad

smartPrint :: [Int] -> IO ()
smartPrint [x] = putStr $ show x
smartPrint (l1:ls) = do putStr $ show l1; putStr "+"; smartPrint ls

explanationNumber :: Int -> IO ()
explanationNumber n = explNumber n 0 []
                  where explNumber n k l | n <= 0 = do smartPrint l; putStr "\n"
                                         | otherwise = do
                                                     when ((k > 0) && (k <= n)) $ explNumber (n - k) k (k:l)
                                                     when (k < n) $ explNumber n (k + 1) l     