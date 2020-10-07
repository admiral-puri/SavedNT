#Stemming_Lemmatization
#Refer: Stemming_Lemmatization

from nltk.stem.porter import PorterStemmer
from nltk.stem.snowball import SnowballStemmer
from nltk.stem.lancaster import LancasterStemmer
from nltk.stem.wordnet import WordNetLemmatizer

words = ['eating', 'ran','running', 'ate', 'eats', 'runs', 'give', 'given', 'hospital', 'hospitalization', 'builder', 'builders', 'builds', 'building']
porter = PorterStemmer()
snowball = SnowballStemmer('english')
lancaster = LancasterStemmer()
lemma = WordNetLemmatizer()

for x in words:
	print(x, porter.stem(x), snowball.stem(x), lancaster.stem(x), lemma.lemmatize(x,pos='n'), lemma.lemmatize(x,pos='v'), sep='; ')

