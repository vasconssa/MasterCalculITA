from sympy import *
from sympy.parsing.latex import parse_latex

def process(latexExpr):
    print(latexExpr)
    expr = parse_latex(latexExpr)
    result = N(expr.doit())
    return str(latex(result))

