--
-- EPITECH PROJECT, 2020
-- fun_evalexpr
-- File description:
-- Main
--

import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Token
import Text.Parsec.Language
import Text.Parsec.Expr
import System.Environment
import System.Exit
import Numeric
import Text.Parsec
import Text.Parsec.Token


calcul :: TokenParser ()
operators ="+-*/~"
calcul = makeTokenParser (javaStyle { opStart = oneOf operators, opLetter = oneOf operators})

test :: String -> IO() -- function to check the string in arg
test [] = putStrLn "the end" -- when there is no more element in string
test (x:xs) = case  my_Elem x ['+', '-', '*', '/', '^', ' ', '(', ')'] == False && is_digit [x] == False of
    False -> test xs
    True -> do
        putStrLn "Invalid char"
        exitWith (ExitFailure 84)

check_number :: Parser Double
checknbr = naturalOrFloat
check_number = do
   val <- checknbr calcul
   case val of
      Left x -> return (fromIntegral x)
      Right y -> return (y)

my_Elem :: Eq a => a -> [a] -> Bool -- pour vérifier si un élement appartient a une liste
my_Elem a [] = False
my_Elem a (x:xs) = case a == x of
    True -> True
    False -> my_Elem a (xs) 

handle_parsing :: Parser Double
this = chech_expression
that = check_number 
handle_parsing = parens calcul this <|> that -- <|> for parellel choice

parse_param :: Parser Double
parse_param = do
  whiteSpace calcul
  n <- chech_expression
  eof
  return n

chech_expression :: Parser Double
chech_expression = (flip buildExpressionParser) handle_parsing $ [
  [ Prefix (op soustrac negate), Prefix (op adit id)]
  , [Infix   (op multip (*)) AssocLeft , Infix  (op divis (/)) AssocLeft ]
  , [Infix   (op adit (+)) AssocLeft
    , Infix  (op soustrac (-)) AssocLeft ]
  ]
  where
    adit = "+"
    divis = "/"
    multip = "*"
    soustrac = "-"
    op token function = reservedOp calcul token >> return function

is_digit :: String -> Bool -- check is the str is a digit
is_digit str = case (reads str) :: [(Double, String)] of
      [(_, "")] -> True
      _         -> False

call_to_parsec :: String -> String -- caling parsec if there is no error
fails = "error" 
call_to_parsec s =
  case ret of
    Left e -> fails ++ (show e)
    Right n -> (showFFloat (Just 2) n "")
 where
   ret = parse parse_param "" s

main :: IO ()
main = do
       args <- getArgs
       if (length args == 1)
           then putStr . unlines $ map call_to_parsec args
       else usage

usage :: IO() -- print usage when there is more than 1 arguments
usage = do
    putStrLn "USAGE: ./evalexpr expr"
    putStrLn ""
    putStrLn "expr\t->\tA mathematical expression"
    exitWith (ExitFailure 84)
