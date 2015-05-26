import Control.Monad
import Control.Monad.Error
import Control.Exception.Base
import System.Directory
import Data.Maybe

menu :: IO ()
menu = do
     putStr "0 - exit\n"
     putStr "1 - add contact\n"
     putStr "2 - find phone by name\n"
     putStr "3 - find name by phone\n"
     putStr "4 - save current data to file\n"
     putStr "5 - read data from file\n"


type PhoneBook = [(String, String)]

add :: PhoneBook -> String -> String -> IO PhoneBook
add book name phone = case (lookup name book) of
         Just _ -> fail "Contact is already exist"
         Nothing -> return ((name, phone) : book)

findPhone :: PhoneBook -> String -> Maybe String
findPhone book name = lookup name book
         
findName :: PhoneBook -> String -> Maybe [String]
findName book phone = let res = map fst $ filter (\(x,y) -> y == phone) book in
              case (res) of
                   [] -> Nothing
                   _  -> Just res where

saveToFile :: PhoneBook -> String -> IO ()
saveToFile book file = writeFile file (show book)

act :: PhoneBook -> IO ()
act book = do
    com <- getLine
    case (com !! 0) of
         '0' -> return ()
         '1' -> do putStrLn "Enter name and number"
                   curr <- getLine
                   case (words curr) of
                       [name, number] -> do t <- add book name number; act t
                       _              -> fail "Uncurrect line"
         '2' -> do putStrLn "Enter name"
                   curr <- getLine
                   case (words curr) of
                        [name] -> do putStrLn $ show (findPhone book name)
                                     act book
                        _      -> fail "Uncurrect line"
         '3' -> do putStrLn "Enter phone"
                   curr <- getLine
                   case (words curr) of
                        [phone] -> do putStrLn $ show (findName book phone)
                                      act book
                        _       -> fail "Uncurrect line"
         '4' -> do putStrLn "Enter filename"
                   curr <- getLine
                   case (words curr) of
                        [file] -> do saveToFile book file
                                     act book
                        _      -> fail "Incurect line"
         '5' -> do putStrLn "Enter filename"
                   curr <- getLine
                   case (words curr) of
                        [fileN] -> do fileExists <- doesFileExist fileN
	                              if fileExists then do
                                        preInput <- readFile fileN
                                        input <- readIO preInput :: IO PhoneBook
                                        putStrLn (show input)
                                        act input
                                      else
                                        fail "File doesn't exist"
                        _      -> fail "Incurrect line"
         _  -> fail "wrong command"
    `catch` (\e -> do putStrLn (show (e :: IOError));act book)

main = do menu
          act []


