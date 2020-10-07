#A gender predictor based on first name 
#Accuracy : 75%
#Result : Satisfactory, because prediction is based on a single feature

from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import BernoulliNB
from sklearn.model_selection import train_test_split
import random

feature_extraction = lambda q: q[-3:]

def loadCorpus(docs, labels):
	if not isinstance(docs, list):
		raise Exception('Corpus must be a list of documents')
	if not isinstance(labels, list):
		raise Exception('Labels must be a list of classes')
	if len(docs) != len(labels):
		raise Exception('Document count must match the label count')


	all = []
	for fileName, lbl in zip(docs, labels):
		fh = open(fileName)
		for x in fh:
			all.append((x.strip().lower(), lbl))
		fh.close()

	random.shuffle(all)
	random.shuffle(all)
	random.shuffle(all)

	names = []
	labels = []

	for nm, lbl in all:
		names.append(nm)
		labels.append(lbl)
	return names, labels


names, labels = loadCorpus(['d:/male.txt', 'd:/female.txt'], ['m','f'])
train_names, test_names, train_labels, test_labels = train_test_split(names, labels, test_size=0.2)

#create a vectorizer (feature extracter)
vectorizer = CountVectorizer( preprocessor=feature_extraction, )

#lets create a vocabulary
vectorizer.fit(train_names)
#print(vectorizer.get_feature_names())

#bow for the algorithm to learn from
bow = vectorizer.transform(train_names)

#bring in the algorithm
algo = BernoulliNB()

#train it
algo.fit(bow, train_labels)

print('I can predict the gender, given a name!!!')

#test
errCount = 0
for nm, lbl in zip(test_names, test_labels):
	#transform the nm over the vocabulary formed by the training set
	bow_instance = vectorizer.transform([nm])
	#predict
	result = algo.predict(bow_instance)
	print(nm, lbl, result[0], sep='--->')
	if result[0] != lbl:
		errCount+=1

print('Error Rate :', errCount, '/', len(test_names))
