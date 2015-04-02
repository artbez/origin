addToSortedList :: (Ord a) => a -> [a] -> [a]
addToSortedList a [] = [a]
addToSortedList a (x1:xs) = if (a <= x1) then a:x1:xs
                            else x1:(addToSortedList a xs)

removeFromSortedList :: (Ord a) => a -> [a] -> [a]
removeFromSortedList a [] = []
removeFromSortedList a (x1:xs) = if (a == x1) then xs
                                 else x1:(removeFromSortedList a xs)
   
printSortedList :: (Show a) => [a] -> IO ()
printSortedList (ls) = putStrLn(show ls)

start :: [String] -> IO ()
start list = do
     cmd <- getLine
     case cmd of
          "0" -> return ()
          "1" -> do
                 x <- getLine
                 start $ addToSortedList x list
          "2" -> do
                 x <- getLine
                 start $ removeFromSortedList x list
          "3" -> do
                 printSortedList list
                 start list

main = do
     list <- return []
     start list