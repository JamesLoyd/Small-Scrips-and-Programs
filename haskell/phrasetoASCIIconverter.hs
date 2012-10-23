import Data.Char
import Data.List

main :: IO ()
main = interact $ concat . (intersperse " ") . map (show . ord)

