#Extracting the features of SMSSpamCollection
#Evaluating the tfidf of the words

import re
from sklearn.feature_extraction.text import TfidfVectorizer

#loading the SMSSpamCollection in memory
fh = open('E:/dataset/smsspamcollection/SMSSpamCollection')
pattern = re.compile(r'(.+)(\t)(.+)')
data = []
for msg in fh:
	x = re.search(pattern, msg)
	if x:
		data.append( x.group(3))
fh.close()

#data = ['Students were in college since morning', 'College activity got over at 5 pm', 'After 5 pm the students go back to their rooms', 'They get ready for the next activity', 'For some students the next activity is learning again', 'But theres one student who goes for work as well']

#Creating a TFIDFVectorizer
tVectorizer = TfidfVectorizer(stop_words='english')

#forming a vocabulary (feature extraction and tfidf evaluation)
tVectorizer.fit(data)

#output
for x, y in zip(tVectorizer.get_feature_names(), tVectorizer.idf_):
	print(x, y, sep=' : ')
