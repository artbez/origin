data Info = BookInfo {
      title :: String,
      author :: String, 
      price :: Int
     }
     |
     JInfo {
      title :: String,
      year :: Int,
      number :: Int,
      price :: Int
     }
 
myF list = foldl (\y x -> (price x) + y) 0 list;
     