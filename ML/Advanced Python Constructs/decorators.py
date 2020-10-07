#Decorators
#Python decorators are for adding functionality (code injection) into an existing code (wrapped function).
#This is also called metaprogramming as a part of the program tries to modify another part of the program at compile time.

#Python decorators are implemented as Higher order functions that 
#1) Take other functions (wrapped functions) as arguments.
#2) Create a nested function (wrapper function) which hosts meta code, invokes wrapped function through closure.
#3) Returns reference to nested function (wrapper functions).
#4) Updates wrapped function reference to refer to nested function (wrapper functions).

def makeOdd(ptrFx): #Higher order function
	def innerFx(num): #Wrapper Function
		#pre processing
		res = ptrFx(num)
		#post processing
		if res%2 == 0:
			res+=1
		return res
	return innerFx

@makeOdd #Decorator
def square(x): #Wrapped Function
	return x*x

@makeOdd #Decorator
def cube(x): #Wrapped Function
	return x*x*x

def main():
	val1 = square(10)
	val2 = cube(10)
	print(val1)
	print(val2)

main()