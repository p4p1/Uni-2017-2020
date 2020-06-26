module Lib
    ( isNumberStr,
    parseNo,
    parseFlag,
    parseSequence
    ) where

import Data.Char



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
--
parseNo :: [String] -> Int
parseNo (x:xs)
    | isNumberStr x = read x :: Int
    | otherwise = 0
parseNo _ = 0

parseFlag :: [String] -> Int
parseFlag x
    | length x == 2 &&
         x !! 1 == "--check" = 1
    | length x == 2 &&
         x !! 1 == "--unique" = 2
    | length x == 2 &&
         x !! 1 == "--clean" = 3
    | length x < 3 = 0
    | x !! 2 == "--check" = 1
    | x !! 2 == "--unique" = 2
    | x !! 2 == "--clean" = 3
    | otherwise = 0

parseSequence :: [String] -> String
parseSequence x
    | length x < 2 = "01"
    | x !! 1 !! 0 == '-' = "01"
    | otherwise = x !! 1
