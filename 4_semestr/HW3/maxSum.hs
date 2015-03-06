maxSum' (l1:l2:l) (x,s) t | x >= l1 + l2 = maxSum' (l2:l) (x,s + 1) t
                          | x < l1 + l2 = maxSum' (l2:l) (l1 + l2, s + 1) s

maxSum' _ _ t = t

maxSum (l1:l2:l) = maxSum' (l2:l) (l1 + l2, 2) 1
maxSum _ = 0