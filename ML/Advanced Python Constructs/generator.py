#Generator Functions
# Generator functions are functions that :
# generate a series of values
# or act on a set of values
# with an important feature of being able to pass back
# the value to the caller of the function while retaining
# the state, all through the yield statement.
# On next call, it resumes execution from the point next to last yield.

# As a generator function gets over StopIteration gets raised
# that allows the iterator loop to stop.

#    a b c
#  a b c
#a b c
#0 1 1 2 3 5 8 13 21 34 55 89
def fibonacci(max = 100):
	a = -1
	b = 1
	while True:
		c = a+b #0 1 1 2 3 5
		if c > max:
			break
		#print(c, end=' ')
		yield c
		a = b #1 0 1 1 2
		b = c #0 1 1 2 3


def main():
	for i in fibonacci(150):
		print(i, end= ' ')

main()