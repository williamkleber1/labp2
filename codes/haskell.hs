inc:: Int -> Int
inc n = n + 1

fat:: Int -> Int
fat 0 = 1
fat n = n * fat (n - 1)

membro:: Int -> [Int] -> Bool
membro x [] = False
membro x (y:ys) = if (x == y)
                  then True
                  else membro x ys
        
somaLista:: [Int] -> Int
somaLista [] = 0
somaLista (y:ys) = y + (somaLista ys)

remove:: Int -> [Int] -> [Int]
remove x [] = []
remove x (y:ys) = if (x == y)
                    then (remove x ys)
                    else y:(remove x ys)
                  
adicionar:: Int -> [Int] -> [Int]
adicionar x [] = [x]
adicionar x (y:ys) = if (y >= x)
                     then y : x : ys
                     else y : adicionar x ys
          
len:: [Int] -> Int
len [] = 0
len (y:ys) = 1 + len ys