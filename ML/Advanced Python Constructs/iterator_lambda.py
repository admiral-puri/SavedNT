#Implementation of iterator, lambda
class Spelling:
	def __init__(self, word='Python'):
		self.word = word
		self.index = -1

	def __iter__(self):
		# some initialization
		return self

	def __next__(self):
		self.index += 1
		if self.index == len(self.word):
			raise StopIteration
		else:
			return self.word[self.index]

def main():
	for i in Spelling('Computer'):
		print(i, end=' ')

	l1 = [1,2,3,4,5,6,7,8,9]
	l2 = list(filter(lambda q: q%2==1, l1))
	print(l2)

	l3 = list(filter(lambda  q : q in "aeiou" , Spelling('elephant')))
	print(l3)

main()