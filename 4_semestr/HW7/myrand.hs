import System.Random
import Control.Monad.State
import Data.Time.Clock.POSIX

data Tree a = Leaf a | Branch (Tree a) a (Tree a) deriving (Show)

makeRandTree :: (Random a) => Tree a -> State StdGen (Tree a)
makeRandTree (Leaf a) = do
             gen <- get
             (x,gen') <- return $ random gen
             put gen'
             return (Leaf x)
             
makeRandTree (Branch l x r) = do
             gen <- get
             (x,gen') <- return $ random gen
             put gen'
             left <- makeRandTree l
             right <- makeRandTree r
             return (Branch left x right)

transform :: Tree Int -> Int -> Tree Int
transform tree n = evalState (makeRandTree tree) (mkStdGen n)

mtree = Branch ( Branch (Leaf 1) 2 (Leaf (-1)) ) 1 ( Branch (Leaf 2) 3 (Leaf (-2)) )

main = do
     n <- round `fmap` getPOSIXTime
     putStrLn $ show (transform mtree n)