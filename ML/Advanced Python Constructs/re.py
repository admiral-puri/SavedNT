#Regular Expression
#A RE is a sequence of characters that define a search pattern.
#It (RE) is made up of meta characters like:
# . ? + * [] () {} | $ ^

# . (dot) : represents any character, other than newline.
# ? : represents 0 or 1 occurence of the previous.
# + : represents 1 to many occurrences of the previous.
# * : represents 0 to many occurrences of the previous.
# [] : a class of characters to match from.
# () : a group of characters to match.
# {} : frequency to look for
# ^ : match at beginning.
# $ : match at the end.
# | : alternation.


#Pythons RE module provides following functions:
# compile : compile a regEx string to result into a pattern.
# match : match a pattern at the beginning of the content.
# search : match a pattern at the in the content.
# findall : to find all occurrences of a pattern in the content. Returns a list.
# finditer : to find all occurrences of a pattern in the content. Returns an iterator.
# sub : to substitute all the occurrences of a pattern with a replace value.
# subn : to substitute all the occurrences of a pattern with a replace value. Result returned as a tuple containing updated string and replace count.

import  re

content = 'I enjoy journey in train while it rains. Don\'t ask why?'
#pattern = re.compile(r'\s.*?y\s')
#x = re.search(pattern, content)
#if x:
#	print(x)
#else:
#	print('not found')

#pattern = re.compile(r'(jou)(.*?)(ey)')
#maskpattern = re.compile(r'\w')
#x = re.search(pattern, content)

#if x:
#	res = x.group(1) + re.sub(maskpattern, '*', x.group(2)) + x.group(3)
#	print(x.group())
#	print(res)
#else:
#	print('not found')

pattern = re.compile(r'[cbr]at')
words = ['cat','dog', 'bat', 'ball', 'mat', 'man', 'woman', 'rat', 'hat']
for x in words:
	res = re.match(pattern, x)
	if res:
		print(x)