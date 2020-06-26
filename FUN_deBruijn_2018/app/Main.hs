module Main where

import System.Environment
import System.Exit
import Text.Read
import Lib
import Control.Monad

{-
 - no, sequence, flag
 -  --check         -> 1
 -  --unique        -> 2
 -  --clean         -> 3
 -}

data Arguments = Arguments Int String Int
    deriving (Show)

getNo :: Arguments -> Int
getNo (Arguments x _ _) = x

getSequence :: Arguments -> String
getSequence (Arguments _ str _) = str

getFlag :: Arguments -> Int
getFlag (Arguments _ _ x) = x

usage :: IO()
usage = do
    putStrLn "USAGE: ./deBruijn n [a] [--check|--unique|--clean]"
    putStrLn ""
    putStrLn "\t--check\t\tcheck if a sequence is a de Bruijn sequence"
    putStrLn "\t--unique\tcheck if 2 sequences are distinct de Bruijn sequences"
    putStrLn "\t--clean\t\tlist cleaning"
    putStrLn "\tn\t\torderof the sequence"
    putStrLn "\ta\t\talphabet [def: \"01\"]"

createArgs :: [String] -> Arguments
createArgs x = Arguments (parseNo x) (parseSequence x) (parseFlag x)

main :: IO ()
main = do
    args <- getArgs
    if (length args < 1)
        then usage >> died
    else runArgument $ createArgs args

dispSequence :: Arguments -> [Int] -> String
dispSequence _  [] = ""
dispSequence arg (x:xs) = ((getSequence arg) !! x) : (dispSequence arg xs)
{-[((getSequence arg) !! x)] ++ (dispSequence arg xs)-}

runArgument :: Arguments -> IO ()
runArgument args
    | ((getFlag args) == 0) = do
        let a = replicate ((length (getSequence args)) * (getNo args)) 0
        let seq = []
        let [seq_n, a_n] = deBruijn_alg args 1 1 [seq, a]
        putStrLn $ dispSequence args seq_n
    | ((getFlag args) == 1) = putStrLn "OK"
    | ((getFlag args) == 2) = putStrLn "OK"
    | ((getFlag args) == 3) = putStrLn "OK"

processArg :: Arguments -> IO()
processArg x = do
    if (getNo x == 0)
        then usage >> died
     else
        print $ x


ext :: [Int] -> [Int] -> Int -> [[Int]]
ext seq a p = do
    let sequence  = seq ++ take (p) (tail a)
    [sequence, a]

assign :: Int -> Int -> [Int] -> [Int]
assign _ _ []  = []
assign n newVal (x:xs)
    | n == 0 = newVal : xs
    | otherwise = x:assign (n-1) newVal xs

forIn :: Int-> Arguments -> Int -> Int -> [[Int]] -> [[Int]]
forIn j x t p [seq, a] = do
    if (j == length (getSequence x))
        then [seq, a]
    else do
        let newA = assign t j a
        let [newSeq, secNewA] = deBruijn_alg x (t + 1) t [seq, newA]
        let secJ = j + 1
        forIn secJ x t p [newSeq, secNewA]

deBruijn_alg :: Arguments -> Int -> Int -> [[Int]] -> [[Int]]
deBruijn_alg x t p [seq, a] = do
    if (t > (getNo (x)))
        then do
            if ((getNo (x)) `mod` p == 0)
                then ext seq a p
            else
                [seq, a]
    else do
        let newA = assign t (a !! (t - p)) a
        let [newSeq, secNewA] = deBruijn_alg x (t + 1) p [seq, newA]
        forIn ((secNewA !! (t - p)) + 1) x t p [newSeq, secNewA]

exit = exitWith ExitSuccess
died = exitWith (ExitFailure 84)
