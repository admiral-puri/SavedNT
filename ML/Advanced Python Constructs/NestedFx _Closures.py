#Nested functions and Closures

#A nested function is a function defined inside another function. 
#It is created, used and destroyed dynamically, by the enclosing function, thus hiding it from the global scope.
#It has read only access of variables of the enclosing scope.

# A Closure is a nested function object that remembers values of the enclosing scope even if they are not present in memory. 


def outerFx(msg):
	print('in outerFx, msg:', msg)
	#nested function
	var = len(msg)
	def innerFx():
		print('in innerFx, msg:', msg)#value of msg stored in closure
		print('length :', var)#value of var stored in closure
		print('innerFx ends')
	#innerFx()
	print('outerFx ends')
	return innerFx

def main():
	ptrFx1 = outerFx('hello')
	ptrFX2 = outerFx('Python')
	print('---------------')
	ptrFx1()
	ptrFX2()


main()