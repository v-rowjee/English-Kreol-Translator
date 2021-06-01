/*
ROWJEE Ved Hurry
2015080
BSc (Hons) Computer Science L1, Group B
Computer Programming, ICT 1017Y
Date: 01 June 2021;
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ostream>
#include <fstream>
#include <iterator>
#include <map>
#include <bits/stdc++.h>
using namespace std;

class Sentences
{

private:
    //string variable to store one sentence
    string sentence;
    //integer variable to store the number of words in one sentence
    int numWords;
    //boolean variable to store whether a sentence is a question
    vector<string> words;

public:
    Sentences();
    Sentences(string sentencesEng);
    //get and set method to retrieve a sentence and to change it
    string getSentence();
    void setSentence(string sentencesEng);
    //method to return the number of words in a sentence
    int getNumWords();
    //method to determine whether a sentence is a question
    vector<string> getWords();
    //sentences less than n words
    ~Sentences();
};

Sentences::Sentences() {}

Sentences::Sentences(string sentencesEng)
{
    sentence = sentencesEng;
    numWords = getNumWords();
}

string Sentences::getSentence()
{
    return sentence;
}

void Sentences::setSentence(string sentencesEng)
{
    sentence = sentencesEng;
}

int Sentences::getNumWords()
{
    int numChars = sentence.length();
    vector<string> setOfWords;
    string currentWord;
    for (int i = 0; i < numChars; i++)
    {
        if (sentence[i] == ' ' && !currentWord.empty())
        {
            setOfWords.push_back(currentWord);
            currentWord.clear();
        }
        else
        {
            currentWord += sentence[i];
        }
    }

    return (setOfWords.size() + 1);
}

vector<string> Sentences::getWords()
{
    int numChars = sentence.length();
    string currentWord;
    words.clear();

    for (int i = 0; i < numChars; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            words.push_back(currentWord);
            currentWord.clear();
        }
        else
        {
            currentWord += sentence[i];
        }
    }

    return words;
}

Sentences::~Sentences() {}

class Words
{

private:
    //string variable to store one word
    string word;
    vector<char> characters;

public:
    Words();
    //get and set method to retrieve a sentence and to change it
    string getWord();
    void setWord(string w);
    //method to return all the words in a sentence (as a vector)
    vector<char> getCharacters();
    ~Words();
};

Words::Words() {}

string Words::getWord()
{
    return word;
}

void Words::setWord(string w)
{
    word = w;
}

vector<char> Words::getCharacters()
{

    int numChars = word.length();

    for (int i = 0; i < numChars; i++)
    {
        characters.push_back(word[i]);
    }

    return characters;
}

Words::~Words() {}

string correct(string s)
{
    //store the punctuation
    char punctuation = s.back();
    //remove the punctuation
    s.pop_back();
    //separate the punctuation from the last word with a whitespace:
    s.push_back(' ');
    //place the punctuation back as another string
    s.push_back(punctuation);

    //first letter/character made lowercase
    s[0] = tolower(s[0]);

    return s;
}

int main()
{

    cout << "***************************************** \n"
         << "> ROWJEE Ved Hurry \n"
         << "> 2015080 \n"
         << "> BSc (Hons) Computer Science L1, Group B \n"
         << "> Computer Programming, ICT 1017Y \n"
         << "> Date: 01 June 2021 \n"
         << "***************************************** \n";

    //* PART 1
    // For both english and kreol datasets:
    // -load the sentences dataset from respective text file,
    // -each letter is transformed to lowercase,
    // -lowercase sentences are pushed in repective vectors

    vector<string> allSentencesEng, allSentencesKM;
    string sentenceFromFileEng, sentenceFromFileKM;
    int countSentenceEng(0), countSentenceKM(0);

    ifstream ifileEng("english_dataset.txt");
    while (!ifileEng.eof())
    {
        getline(ifileEng, sentenceFromFileEng);

        //adding dot to sentences that doesnt end with a punctuation
        if (sentenceFromFileEng.back() != '.' || sentenceFromFileEng.back() != '!' || sentenceFromFileEng.back() != '?')
        {
            to_string(sentenceFromFileEng.back()) = sentenceFromFileEng.back() + ".";
        }
        // Converting whole string to lowercase.
        for_each(sentenceFromFileEng.begin(), sentenceFromFileEng.end(), [](char &c)
                 { c = ::tolower(c); });

        // From file to vector
        allSentencesEng.push_back(sentenceFromFileEng);
        countSentenceEng++;
    }
    ifileEng.close();

    ifstream ifileKM("kreol_dataset.txt");
    while (!ifileKM.eof())
    {
        getline(ifileKM, sentenceFromFileKM);

        //adding dot to sentences that doesnt end with a punctuation
        if (sentenceFromFileKM.back() != '.' || sentenceFromFileKM.back() != '!' || sentenceFromFileKM.back() != '?')
        {
            to_string(sentenceFromFileKM.back()) = sentenceFromFileKM.back() + ".";
        }
        // Converting whole string to lowercase.
        for_each(sentenceFromFileKM.begin(), sentenceFromFileKM.end(), [](char &c)
                 { c = ::tolower(c); });

        // From file to vector
        allSentencesKM.push_back(sentenceFromFileKM);
        countSentenceKM++;
    }
    ifileKM.close();

    //* PART 2
    // Creating a vector of objects of type sentences
    vector<Sentences> sentencesEng(countSentenceEng), sentencesKM(countSentenceKM);

    // Assign each extracted sentence (from dataset) to one Sentence object
    for (int i = 0; i < countSentenceEng; i++)
    {
        sentencesEng[i].setSentence(allSentencesEng[i]);
    }
    for (int i = 0; i < countSentenceKM; i++)
    {
        sentencesKM[i].setSentence(allSentencesKM[i]);
    }

    // Creating a file where all the pairs of words(Eng -> KM) will be found.
    // Vectors variable to store the individual words in one sentence.
    vector<string> EngTemp, KreTemp;
    vector<string> EngFinal, KreolFinal;
    bool exists;
    vector<int> freq; //frequency

    for (int i = 0; i < countSentenceEng; i++)
    {
        EngTemp = sentencesEng[i].getWords();
        KreTemp = sentencesKM[i].getWords();

        for (int j = 0; j < EngTemp.size(); j++)
        {
            for (int k = 0; k < KreTemp.size(); k++)
            {
                exists = false;
                for (int m = 0; m < EngFinal.size(); m++)
                {
                    if (EngTemp[j] == EngFinal[m] && KreTemp[k] == KreolFinal[m])
                    {
                        exists = true;
                        freq[m]++;
                    }
                }
                if (exists == false)
                {
                    EngFinal.push_back(EngTemp[j]);
                    KreolFinal.push_back(KreTemp[k]);
                    freq.push_back(1);
                }
            }
        }
        KreTemp.clear();
        EngTemp.clear();
    }

    //* PART 3
    // The pair of english words and their kreol translation is pushed to a file.
    // Frequency of each pair added on same line.
    ofstream ofileMap("MappingFile.txt");
    map<string, int> myMap;
    //cout << EngFinal.size() << endl;
    for (int i = 0; i < EngFinal.size(); i++)
    {
        ofileMap << EngFinal[i] << "->";
        ofileMap << KreolFinal[i] << "\t";
        ofileMap << freq[i] << endl;

        myMap.insert(pair<string, int>(string(EngFinal[i] + "\n" + KreolFinal[i] + "\n"), freq[i]));
    }
    ofileMap.close();
    cout << "> 'MappingFile.txt' contains English-Kreol\n  word pairs with their frequency.\n\n";

    //* PART 4
    // Display mapping sorted by map value(frequency) in file.
    // REF: https://stackoverflow.com/questions/34403415/print-map-values-in-descending-order-in-c
    ofstream ofileSortedMap("SortedMap.txt");
    // Copy it into a pair of vector.
    vector<pair<string, int>> vectorMap(myMap.begin(), myMap.end());

    // Sort the vector according to the word count in descending order.
    sort(vectorMap.begin(), vectorMap.end(),
         [](const auto &lhs, const auto &rhs)
         { return lhs.second > rhs.second; });

    // Print out the vector.
    // We are printing only the pairs and not the frequency.
    for (const auto &item : vectorMap)
        ofileSortedMap << item.first
                       //<< item.second (frequency)
                       << "\n";
    ofileSortedMap.close();
    cout << "> 'SortedMap.txt' contains word pairs\n  sorted in descending values of frequency.\n\n";

    //* PART 5
    // Read the sorted pair from the file.
    ifstream ifileSortedMap("SortedMap.txt");
    string line1, line2, line3;
    vector<string> EngAccurate, KreAccurate;
    int count = 0;
    map<string, string> myMap2;

    // Read only Top 1000 pairs with highest frequency for more accuracy in translation.
    for (int i = 0; i < 1000; i++)
    {
        // First line read and stored in vector for english words.
        getline(ifileSortedMap, line1);
        EngAccurate.push_back(line1);

        // Second line read and stored in vector for kreol words.
        getline(ifileSortedMap, line2);
        KreAccurate.push_back(line2);

        // Insert the pair of words in a map.
        // Map removes any duplicate of english words.
        // i.e a word may have more than one meaning, we are storing only the pair with highest frequency.
        myMap2.insert(pair<string, string>(line1, line2));

        // Third line is ignored as it was only used for spacing.
        getline(ifileSortedMap, line3);
    }
    ifileSortedMap.close();

    //* PART 6
    // Create a file to store the top 1000 pairs with highest frequency.
    // All duplicates are removed.
    ofstream ofileDictionary("Dictionary.txt");
    vector<string> english, kreol;

    for (auto itr = myMap2.begin(); itr != myMap2.end(); ++itr)
    {
        ofileDictionary << itr->first << "->" << itr->second << endl;
        english.push_back(itr->first);
        kreol.push_back(itr->second);
    }
    ofileDictionary.close();
    cout << "> 'AccurateMapping.txt' contains the most\n  accurate word pairs.\n";
    cout << "  It can be considered as our Dictionary.\n\n";

    //* PART 7
    // Translating english words from dataset to kreol using the new mapping translation
    ifstream ifileEnglish("1000_English_B_110521_Test.txt");
    ofstream ofileKTranslation("KreolTranslation.txt");
    char punc;
    string line;
    vector<string> EnglishDatasetSentences, EnglishDatasetWords, Output;
    Sentences EnglishSentences;
    bool foundTranslation;

    while (!ifileEnglish.eof())
    {
        getline(ifileEnglish, line);
        punc = line.back();
        line = correct(line);

        EnglishSentences.setSentence(line);
        EnglishDatasetWords = EnglishSentences.getWords();

        for (auto it = EnglishDatasetWords.begin(); it != EnglishDatasetWords.end(); it++)
        {
            foundTranslation = false;
            for (int i = 0; i < english.size(); i++)
            {
                if (*it == english[i])
                {
                    foundTranslation = true;
                    Output.push_back(kreol[i]);
                }
            }
            // If kreol equivalent word found not in dictionary/mapping print the same english word.
            if (foundTranslation == false)
            {
                //cout << *it << " ";
                Output.push_back(*it);
            }
        }
        // Printing output in file
        for (int i = 0; i < Output.size(); i++)
        {
            if (i == 0)
            {
                // Make first letter of first word a capital letter.
                string firstOutput = Output[0];
                firstOutput[0] = toupper(firstOutput[0]);
                ofileKTranslation << firstOutput << " ";
            }
            else if (i == Output.size() - 2)
            {
                // Putting a dot to the last word.
                string lastOutput = Output[Output.size() - 2];
                lastOutput = string(lastOutput + punc);
                ofileKTranslation << lastOutput;
                break;
            }

            // In the middle of the sentence place whitespace.
            else
                ofileKTranslation << Output[i] << " ";
        }
        // Change line after each sentence
        ofileKTranslation << endl;
        // Output cleared so that new sentence can be translated
        Output.clear();
    }
    ifileEnglish.close();
    ofileKTranslation.close();
    cout << "> 'KreolTranslation.txt' contains the\n"
         << "  translated kreol sentences using the\n  dictionary.\n";
    cout << "*****************************************\n";

    //* PART 8
    // Checking the accuracy of the translation by crosschecking newly translated kreol words with given kreol words from dataset
    ifstream ifileOldDataset("1000_KM_B_110521_Test.txt");
    ifstream ifileNewTranslation("KreolTranslation.txt");
    // Float and not int because we will be using this value to calculate a float value.
    float accuracySentences(0);
    float SentenceAccPercentage;

    // Reading file line by line
    string lineOldT, lineNewT;
    vector<string> OldDataset, NewTranslation;
    while (!ifileOldDataset.eof())
    {
        getline(ifileOldDataset, lineOldT);
        OldDataset.push_back(lineOldT);
    }
    while (!ifileNewTranslation.eof())
    {
        getline(ifileNewTranslation, lineNewT);
        NewTranslation.push_back(lineNewT);
    }
    for (int i = 0; i < OldDataset.size(); i++)
    {
        if (OldDataset[i] == NewTranslation[i])
        {
            accuracySentences++;
        }
    }
    cout << "> Perfectly translated sentences: " << accuracySentences << endl;
    SentenceAccPercentage = (accuracySentences / 1000) * 100;
    cout << "> Accuracy: " << SentenceAccPercentage << "%" << endl;
    ifileOldDataset.close();
    ifileNewTranslation.close();

    cout << endl;

    cout << "*****************************************\n";

    //* USER INTERACTION
    // User input english sentence to translate.
    Sentences inputSent;
    vector<string> inputWords, resultWords;
    string input;
    char endline('\n');
    bool found;
    char punctuation;

    cout << "  ENG-KM TRANSLATOR:" << endl;
    cout << "> Enter english sentence: "
         << "\n  ";
    // Stop input when an endline is found i.e when user press enter.
    getline(cin, input, endline);
    // Getting that dot at the end of the string
    punctuation = input.back();
    // Correction the input sentence
    input = correct(input);

    inputSent.setSentence(input);
    inputWords = inputSent.getWords();

    cout << endl;
    cout << "> Kreol translation: "
         << "\n  ";
    for (auto it = inputWords.begin(); it != inputWords.end(); it++)
    {
        found = false;
        for (int i = 0; i < english.size(); i++)
        {
            if (*it == english[i])
            {
                found = true;
                resultWords.push_back(kreol[i]);
            }
        }
        // If kreol equivalent word found not in dictionary/mapping print the same english word.
        if (found == false)
        {
            resultWords.push_back(*it);
        }
    }

    // Printing result.
    for (int i = 0; i < resultWords.size(); i++)
    {
        if (i == 0)
        {
            // Make first letter of first word a capital letter.
            string firstResultWord = resultWords[0];
            firstResultWord[0] = toupper(firstResultWord[0]);
            cout << firstResultWord << " ";
        }
        else if (i == resultWords.size() - 2)
        {
            // Putting a dot to the last word.
            string lastResultWord = resultWords[resultWords.size() - 2];
            lastResultWord = string(lastResultWord + punctuation);
            cout << lastResultWord;
        }

        // In the middle of the sentence place whitespace.
        else
            cout << resultWords[i] << " ";
    }
    cout << "\n*****************************************\n\n";

    return 0;
}