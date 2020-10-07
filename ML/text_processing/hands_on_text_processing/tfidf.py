#Implementing TermFrequency and InverseDocumentFrequency
#Tf-Idf is a weight/score often used in information retrieval
#and text mining.

#This weight is a statistical measure used to evaluate how
#important a word is to a document in a collection or corpus.

#The importance increases proportionally to the number of
#times a word appears in the document but is offset by the
#frequency of the word in the corpus.

#Variations of the tf-idf weighting scheme are often used
#by search engines as a central tool in scoring and ranking
#a document's relevance given a user query.

#How to Compute:
#TF(t) = (Number of times term t appears in a document) / (Total number of terms in the document).
#IDF(t) = log_e(Total number of documents / Number of documents with term t in it).

import numpy as np
def tfidf(term, doc, corpus):
	term_frequency = doc.count(term)/len(doc)

	#approach1
	#number_of_docs_with_term = 0
	#for d in corpus:
	#	if term in d:
	#		number_of_docs_with_term+=1
	#approach
	number_of_docs_with_term = len([d for d in corpus if term in d])

	inverse_doc_frequency = np.log(len(corpus)/number_of_docs_with_term)

	return term_frequency * inverse_doc_frequency


doc1 = ['a','a','a']
doc2 = ['a','b','b']
doc3 = ['a','b','c']
corpus = [doc1, doc2, doc3]

print(tfidf('a', doc1, corpus))
print(tfidf('a', doc2, corpus))
print(tfidf('a', doc3, corpus))
print('---------------------------')
print(tfidf('b', doc1, corpus))
print(tfidf('b', doc2, corpus))
print(tfidf('b', doc3, corpus))
print('---------------------------')
print(tfidf('c', doc1, corpus))
print(tfidf('c', doc2, corpus))
print(tfidf('c', doc3, corpus))
