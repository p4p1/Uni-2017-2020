module Lexer
    ( lexer,
    dispLexer
    ) where

import Lib

operator = "+-*/~()"
validdigit = "0123456789"

{-
 - Function to display the lexed expretion
 -}
dispLexer :: [String] -> IO()
dispLexer (x:xs) = do
            putStrLn x
            dispLexer xs
dispLexer _ = putStr ""

{-
 - Strip down lexer that will split everything in a [String]
 - And catch basic syntax errors
 -}
v_lexer :: String -> [String]
v_lexer (x:xs)
    | isOperator x operator = [[x]] ++ lexer xs
    | isNum x validdigit = [[x]] ++ lexer xs
    | isDot x = [[x]] ++ lexer xs
    | x == ' ' = [] ++ lexer xs
    | otherwise = ["ERROR"]
v_lexer _ = []

{-
 - Function to combine the found digits
 -}
combine_digits :: [String] -> String
combine_digits (x:xs)
    | isNum (head x) validdigit = x ++ combine_digits xs
    | isDot $ head x = x ++ combine_digits xs
    | otherwise = ""
combine_digits _ = ""


loopDigits :: [String] -> Int -> [String]
loopDigits xs pos
    | pos < length xs = xs
    | otherwise = xs
loopDigits _ _ = ["ERROR"]

{-
 - The lexer to parse later on
 -}
lexer :: String -> [String]
lexer x = do
    let tab = v_lexer x
    if (last tab == "ERROR")
        then tab
    else loopDigits tab 0
lexer _ = []
