#A vocabulary from a text file.
 
from sklearn.feature_extraction.text import CountVectorizer

def getFileData(fileName):
	fh = open(fileName)
	output = []
	for x in fh:
		output.append(x.strip())
	fh.close()
	return output

vectorizer = CountVectorizer(stop_words='english')
fileData = getFileData('e:/horse.txt')
vectorizer.fit(fileData)
print(len(vectorizer.get_feature_names()))
print(vectorizer.get_feature_names())

bow = vectorizer.transform(fileData)
print(bow.toarray().transpose())

query = ['how long does a dog live']
result = vectorizer.transform(query)
print(result)