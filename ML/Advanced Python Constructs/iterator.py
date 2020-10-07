#Iterator
#Iterator is an object that can be:
# iterated upon
# will return data, one element at a time
# implements iterator protocol.

class MyRange:
	def __init__(self, min =0, max = 100):
		self.min = min
		self.max = max
		self.cnt = min -1

	#mandatory definition
	def __iter__(self):
		#initializations here
		return self

	#mandatory definition
	def __next__(self):
		self.cnt+=1
		if self.cnt == self.max:
			raise StopIteration
		else:
			return self.cnt

def main():
	for i in MyRange(10, 15):
		print(i, end =' ')


main()