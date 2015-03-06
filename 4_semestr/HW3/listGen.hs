func (l1:l) (s1:s) (t1:t) = l1:s1:t1:(func l s t)

ll = listGen where
   listGen0 = map (\x -> x * 10 + 1) listGen
   listGen1 = map (\x -> x * 10 + 7) listGen
   listGen2 = map (\x -> x * 10 + 9) listGen
   listGen = [1, 7, 9] ++ (func listGen0 listGen1 listGen2) 
