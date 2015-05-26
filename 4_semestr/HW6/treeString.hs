import Control.Monad.State

data Tree = Node Char (Tree) (Tree) | Empty deriving(Show)

treeToString :: Tree -> String
treeToString Empty = "e"
treeToString (Node c l r) = 'n' : c : (treeToString l ++ treeToString r)

stringToTree :: String -> Tree
stringToTree str = evalState curr str where
             curr = do
                   cons <- get
                   case (cons) of
                        ('e' : tail) -> do
                                        put tail
                                        return (Empty)
                        ('n' : c : tail) -> do
                                            put tail
                                            l <- curr
                                            r <- curr
                                            return (Node c l r)


testString = "nanbeee"
testTree = Node 'a' (Node 'b' Empty Empty) Empty


