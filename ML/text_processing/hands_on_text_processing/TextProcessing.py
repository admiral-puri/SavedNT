#Text data requires pre processing before use for predictive modeling.
#The text must be parsed to remove words, called tokenization. 
#Then the words need to be encoded as integers or floating point values 
#for use as input to a machine learning algorithm, called feature extraction 
#(or vectorization).

#The scikit-learn library offers easy-to-use tools to perform both 
#tokenization and feature extraction of your text data.

from sklearn.feature_extraction.text import CountVectorizer
data = ['A mouse is a pointing  device','A mouse has 3 buttons and a scroll']

#define a vectorizer
vectorizer = CountVectorizer(stop_words='english')

#learn a vocabulary from data (file(s))
vectorizer.fit(data)
print(vectorizer.vocabulary_)

#Using the vocabulary encode data each as a vector.
sbow = vectorizer.transform(data)

#the words of the vocubulary
print(vectorizer.get_feature_names())
print(len(vectorizer.get_feature_names()))

#encoded data in the form of a matrix/sparse matrix
print(sbow.toarray())

print('------------')
txt = ['buy one get one free']

testonTxt = vectorizer.transform(txt)
print(testonTxt.toarray())
