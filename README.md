# **English-Kreol-Translator** :octocat:

---

## :scroll: PROGRAM DESCRIPTION

### Line 165 : correct() function

A function to correct all sentences i.e capitalise the first letter and separate last word
from the dot at end end of a sentence with a whitespace.

### Line 170 : main() function

The driving code.

### Line 181 : PART 1

For both english and kreol datasets, sentences from respective dataset text file.
Each sentences are then pushed in repective vectors.

### Line 231 : PART 2

Combining english and kreol words of each sentences into pairs,
and finding the frequency of occurence of these pairs.

### Line 282 : PART 3

The pair of english words and their kreol translation is pushed to a file.
Frequency of each pair added on same line.

### Line 299 : PART 4

The word pairs are sorted in descending order of their frequency.

REF: https://stackoverflow.com/questions/34403415/print-map-values-in-descending-order-in-c

### Line 320 : PART 5

The sorted pairs are read from a file and pushed into vectors.

### Line 349 : PART 6

A file is created as a dictionary for the top 1000 translation. A map is used to do so and english words dublicates are eliminated.

### Line 365 : PART 7

Translating english words from dataset to kreol using the new mapping translation. If an english word is not found in the dictionary, it is translated by the english itself.

### Line 436 : PART 8

Checking the accuracy of the translation by crosschecking newly translated kreol words with given kreol words from dataset.

### Line 474 : USER INTERACTION :space_invader:

User input an english phrase which is translated into creol using the dictionary.

---

## :dart: THE ACCURACY OF THE TRANSLATOR IS 1%

---

## :open_file_folder: FILES CREATED

**'MappingFile.txt'** contains English-Kreol word pairs with their frequency.

**'SortedMap.txt'** contains word pairs sorted in descending values of frequency.

**'Dictionary.txt'** contains the most accurate word pairs.

**'KreolTranslation.txt'** contains the translated kreol sentences using the dictionary.

---

## :name_badge: PROBLEMS ENCOUNTERED

1.  Questions in english should be rephrased as when translated kreol question starts with 'Eski'.
    i.e whenever an english sentense ends with a '?', we assume it is a question,
    therefore its kreol translation will start with 'Eski'.
    _ex. "Are you ill?" translate to "Eski to malade?"_

2.  The program would be more efficient if we ask the user if the translation for the sentence he entered is correct.
    If so, the english sentence entered by the user and the translation in kreol obtained is added to the original dataset.
    In this way the more the program is used the more data we gather and the more precise the translation becomes.

3.  For verbs that ends with 'ing' a 'p' should be added before the verb without the 'ing' is translated.
    _ex. "I am eating." translate to "Mo p manze."_

---
