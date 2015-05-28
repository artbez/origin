import Control.Monad.Cont

map_cps :: (a -> b) -> [a] -> Cont r [b]
map_cps f [] = return []
map_cps f (l1:ls) = do
        res <- map_cps f ls
        return $ f l1 : res


filter_cps :: (a -> Bool) -> [a] -> Cont r [a]
filter_cps f  [] = return []
filter_cps f (l1:ls) = do
           res <- filter_cps f ls
           if (f l1) then return (l1 : res)
                     else return res


main = do
     runCont (map_cps (\x -> x * x) [1, 2, 3, 4, 5]) print
     runCont (filter_cps (\x -> x `mod` 2 == 0) [1, 2, 3, 4, 5]) print 