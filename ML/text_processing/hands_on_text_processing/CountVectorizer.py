#Text data requires pre processing before use for predictive modeling.
#The text must be parsed to remove words, called tokenization.
#Then the words need to be encoded as integers or floating point values
#for use as input to a machine learning algorithm, called feature extraction
#(or vectorization).

#The scikit-learn library offers easy-to-use tools to perform both
#tokenization and feature extraction of your text data.

#Feature Extraction on a toy data set

from sklearn.feature_extraction.text import CountVectorizer

data = ['Students were in college since morning', 'College got over at 5 pm', 'After 5 pm the students go back to their rooms', 'They get ready for the next activity', 'For some students the next activity is learning again', 'But theres one student who goes for work as well']
cVectorizer = CountVectorizer(stop_words='english')

#learn a vocabulary from data
cVectorizer.fit(data)
print(cVectorizer.get_feature_names())

#Using the vocabulary encode data, each sentence as a vector.
#bow = cVectorizer.transform(data)
#print(bow.toarray().transpose())

#Using the vocabulary encode query, as a vector.
query = ['when does the  next activity of student begin']
qBOW = cVectorizer.transform(query)
print(qBOW.toarray())
