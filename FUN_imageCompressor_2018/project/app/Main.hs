module Main where

import System.Environment
import System.Exit
import Data.Char
import System.IO
import Data.List


main :: IO ()
main = do
    args <- getArgs
    handling_args args


handling_args :: [String] -> IO ()
handling_args [] = do
    putStrLn "USAGE: ./imageCompressor n e IN"
    putStrLn ""
    putStrLn "      n number of colors in the final image"
    putStrLn "      e convergence limit"
    putStrLn "      IN path to the file containing the colors of the pixels"
    exitWith $ ExitFailure 84

handling_args x = handling_args []


checkIfElem :: Int -> [Int] ->Bool
checkIfElem x l 
         |x`elem` l =True
         |otherwise=False