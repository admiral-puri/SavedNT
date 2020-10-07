#Topic Modeling
#Loading the Content
#Feature Extraction
#Content Dictionary Formation
#Creating a Content BOW

from nltk.tokenize import RegexpTokenizer
from nltk.stem import SnowballStemmer
from nltk.corpus import stopwords
from gensim import corpora

def getContent(fileName):
	fh = open(fileName)
	lines = []
	for x in fh:
		x = x.strip()
		if len(x) > 0:
			lines.append(x)

	fh.close()
	return  lines


def processText(sentence):
	tokenizer = RegexpTokenizer(r'\w\w+')
	stemmer =  SnowballStemmer('english')
	sw = stopwords.words('english')

	tokens = tokenizer.tokenize(sentence.lower())
	features = [stemmer.stem(x) for x in tokens if x not in sw]
	return features

def main():
	#load the content
	content = getContent('d:/default_methods.txt')

	#feature extraction per chunk (problem instance) of the content
	content_features = [processText(x) for x in content]
	# lets see
	for x in content_features:
		print(x)

	#form a dictionary
	dictionary = corpora.Dictionary(content_features)
	#lets see the dictionary
	for x in dictionary.iteritems():
		print(x)

	#create a bow from the content_features
	content_bow = [dictionary.doc2bow(x) for x in content_features]
	#lets see the bow
	for x in content_bow:
		print(x)


main()