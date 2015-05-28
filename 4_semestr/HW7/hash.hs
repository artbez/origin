import Data.Char
import Control.Monad.State

data HashTable key value = HashTable {hash :: (key -> Int), table :: [(Int, value)]}

find :: key -> HashTable key value -> Maybe value
find k (HashTable _ []) = Nothing
find k (HashTable f l) =
     find' (f k) l where find' res (l1:ls) | fst l1 < res    = find' res ls
                                           | fst l1 == res   = Just (snd l1)
                                           | fst l1 > res    = Nothing

add :: key -> value -> HashTable key value -> HashTable key value
add k v (HashTable f l) = HashTable f (add' (f k) l) where
    add' x (l1:ls)    | x < fst l1  = (x, v) : l1 : ls
                      | x > fst l1  = l1 : (add' x ls)
                      | x == fst l1 = l1 : ls
    add' x [] = [(x, v)]

remH :: key -> HashTable key value -> HashTable key value
remH k (HashTable f l) = HashTable f (rem' (f k) l) where
    rem' x (l1:ls) | x < fst l1  = l1:ls
                   | x > fst l1  = rem' x ls
                   | x == fst l1 = ls
    rem' x [] = []

addState key value = do
         cur <- get
         put $ add key value cur

remState key = do
         cur <- get
         put $ remH key cur

myhash = add "rer" "ara" $ remH "er" $ add "ar" "er" $ add "vfdf" "trtrt" $ add "sas" "alala" $ HashTable (\t -> (foldl (\x y -> x + 17 * (ord y)) 0 t) `mod` 1000003) []

main = do
     x <- return $ table $ execState (addState "123" "123") myhash
     putStr $ show $ x

