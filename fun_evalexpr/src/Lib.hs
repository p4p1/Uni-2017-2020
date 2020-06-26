module Lib
    ( isNumberStr,
    setPos,
    setString,
    isOperator,
    isNum,
    isDot,
    exit,
    endDigit,
    moveToDigit,
    died
    ) where

import Data.Char
import System.Exit

data Token = Token Int Char Int
    deriving (Show)

operator = "+-*/~"
validdigit = "0123456789"

exit = exitWith ExitSuccess
died = exitWith (ExitFailure 84)

-- IS NUMBER *&********************************
isNumberStr :: String -> Bool
isNumberStr ""  = False
isNumberStr "." = False
isNumberStr xs  =
  case dropWhile isDigit xs of
      ""       -> True
      ('.':ys) -> all isDigit ys
      _        -> False
-- IS NUMBER *&********************************

setPos :: [String] -> Int
setPos _ = 0

setString :: [String] -> String
setString (x:xs) = x
setString _ = ""

------------------------------------------

{-
 - Function to check if the char is an operator
 -}
isOperator :: Char -> String -> Bool
isOperator ch (x:xs)
    | ch /= x = (isOperator ch xs)
    | ch == x = True
isOperator _ "" = False

{-
 - Function to check if the char is a number
 -}
isNum :: Char -> String -> Bool
isNum ch (x:xs)
    | ch /= x = (isNum ch xs)
    | ch == x = True
isNum _ "" = False

{-
 - Function to check if the char is a dot
 -}
isDot :: Char -> Bool
isDot ch
    | ch /= '.' = False
    | ch == '.' = True

{-
 - Manipulation functions of table to find the digits
 -}
endDigit :: [String] -> [String]
endDigit (x:xs)
    | isNum (head x) validdigit = endDigit xs
    | isDot $ head x = endDigit xs
    | otherwise = xs
endDigit _ = []

moveToDigit :: [String] -> [String]
moveToDigit (x:xs)
    | isNum (head x) validdigit = xs
    | isDot $ head x = ["ERROR"]
    | otherwise = moveToDigit xs
moveToDigit _ = []

posToDigit :: [String] -> Int -> Int
posToDigit (x:xs) i
    | isNum (head x) validdigit = i
    | isDot $ head x = (-1)
    | otherwise = posToDigit xs (i + 1)
posToDigit _ _ = 0

posEndDigit :: [String] -> Int -> Int
posEndDigit (x:xs) i
    | isNum (head x) validdigit = posEndDigit xs (i + 1)
    | isDot $ head x = posEndDigit xs (i + 1)
    | otherwise = i
posEndDigit _ _ = 0
