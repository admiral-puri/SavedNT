#Lambda Functions (AKA Lambda Expressions)
#A lambda function is a small anonymous function.
#A lambda function can take any number of arguments, but can only have one expression.

max = lambda a,b : a if a > b else b
cube = lambda a : a*a*a

#(c)a > b ? a : b
#(py) a if a > b else b


def main():
	print(max(10,2))
	print(cube(4))

main()