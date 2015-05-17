data Expression = X | Const Int | Expression :+: Expression | Expression :-: Expression
                    | Expression :*: Expression | Expression :^: Int
                    deriving (Eq, Show)

calculate :: Expression -> Int -> Int
calculate expl val =
          case expl of
                        (X) -> val
                        (Const c) -> c
                        (exp1 :+: exp2) -> (calculate exp1 val) + (calculate exp2 val)
                        (exp1 :*: exp2) -> (calculate exp1 val) * (calculate exp2 val)
                        (exp1 :-: exp2) -> (calculate exp1 val) - (calculate exp2 val)
                        (exp1 :^: n)    -> (calculate exp1 val) ^ n

simplification' :: Expression -> Expression
simplification' expl =
               case expl of
                            (exp1 :*: Const 1)      -> exp1
                            (Const 1 :*: exp1)      -> exp1
                            (Const 0 :+: exp1)      -> exp1
                            (exp1 :+: Const 0)      -> exp1
                            (exp1 :-: Const 0)      -> exp1
                            (Const 0 :*: _)         -> Const 0
                            ( _ :*: Const 0)        -> Const 0
                            (exp1 :^: 1)            -> exp1
                            (exp1 :^: 0)            -> Const 1
                            (Const c1 :+: Const c2) -> Const (c1 + c2)
                            (Const c1 :-: Const c2) -> Const (c1 - c2)
                            (Const c1 :*: Const c2) -> Const (c1 * c2)
                            (Const c :^: n)         -> Const (c ^ n)
                            _ -> expl

simplification :: Expression -> Expression
simplification expl =
               case expl of
                            (exp1 :+: exp2) -> simplification' (simplification exp1 :+: simplification exp2)
                            (exp1 :*: exp2) -> simplification' (simplification exp1 :*: simplification exp2)
                            (exp1 :-: exp2) -> simplification' (simplification exp1 :-: simplification exp2)
                            (exp1 :^: n)    -> simplification' (simplification exp1 :^: n)
                            (_) -> expl


diff :: Expression -> Expression
diff expl = case expl of
                            (exp1 :+: exp2) -> (diff exp1) :+: (diff exp2)
                            (exp1 :*: exp2) -> (diff exp1) :*: exp2 :+: exp1 :*: (diff exp2)
                            (exp1 :-: exp2) -> (diff exp1) :-: (diff exp2)
                            (exp1 :^: n)    -> Const n :*: exp1 :^: (n - 1) :*: (diff exp1)
                            (X) -> Const 1
                            (Const c) -> Const 0 
                            