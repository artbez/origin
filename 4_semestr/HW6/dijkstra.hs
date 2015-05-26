import Control.Monad.State

data Graph v e = Graph [(Int, Int)] [(Int, Int, Int)]

getSecond :: Int -> [(Int, Int)] -> Int
getSecond _ [] = error "error"
getSecond a (l1:ls) = if (a == fst l1) then (snd l1) else getSecond a ls

repByFst :: (Int, Int) -> [(Int, Int)] -> [(Int, Int)]
repByFst a [] = []
repByFst a (l1:ls) | (fst a) == (fst l1) = a : (repByFst a ls)
                   | otherwise           = l1 : (repByFst a ls) 

getMin :: [(Int, Int)] -> (Int, Int)
getMin (l1:l2:ls)  | (snd l1) < (snd l2)   = getMin (l1:ls)
                   | otherwise = getMin (l2:ls)
getMin (l1:[]) = l1

inf = maxBound :: Int

initG :: [(Int, Int)] -> Int -> [(Int, Int)]
initG (l1:ls) src = if (fst l1) == src then ((src, 0):(initG ls src))
                     else ((fst l1,inf):(initG ls src))
initG [] stc = [] 

dijkstra' :: [(Int, Int)] -> [(Int, Int, Int)] -> Int -> [(Int, Int)]
dijkstra' v e src = if length v == 1 then v
                    else let newV = filter (\(x,y) -> x /= src) (execState (updator e) v) in
                          (getMin v):(dijkstra' newV e (fst $ getMin newV))
                            where updator ((f, s, c) : ls) | src == f = do
                                                                 current <- get
                                                                 let gt = getSecond src v in
                                                                  case (lookup s current) of
                                                                     Just val -> if (gt + c < val) then
                                                                                    do put $ repByFst (s, gt + c) current
                                                                                       updator ls
                                                                                 else updator ls
                                                                     Nothing  -> updator ls
                                                           | otherwise = updator ls
                                  updator [] = return []

dijkstra :: Graph v e -> Int -> [(Int, Int)]
dijkstra (Graph v e) src = dijkstra' (initG v src) e src

example = Graph [(0, 0), (1, 0), (2, 0), (3, 0)] [(0,1,8), (1,2,3), (2,3,11), (0, 2, 1)]