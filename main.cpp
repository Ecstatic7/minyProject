#include <iostream>

using namespace std;

struct Synonyms{
    string synonym;
    Synonyms * next;
};
struct Word{
    string word;
    Word * nextWord{};
    Synonyms * syn{};
};

string getWord();
//, Synonyms *& synHead
void addWord(Word *&wordHead);

int main() {

    Word * wordHead = nullptr;

    addWord(wordHead);

    Word * headTemp = wordHead;

    while (headTemp){
        cout << headTemp->word << ":\t";

        Synonyms * synTemp = headTemp->syn;
        while (synTemp){
            cout << synTemp->synonym << ", ";
            synTemp = synTemp->next;
        }
        headTemp = headTemp->nextWord;
    }

    return 0;
}

string getWord(){
    cout << "Enter word and synonyms. (e.g compute:figure out,calculate ...)\n";
    string wordAndSyn;
    getline(cin , wordAndSyn);

    return wordAndSyn;
}

void addWord(Word *&wordHead){
    string wordAndSyn = getWord();

    char wordDelimiter = ':';
    char synDelimiter = ',';

    /// find word (split)
    int start = 0;
    int end = wordAndSyn.find(wordDelimiter);

    /// add word to list
    Word *word = new Word;
    word->word = wordAndSyn.substr(start, end - start);

    if (wordHead == nullptr)
        wordHead = word;

    word->nextWord = nullptr;

    /// find first syn
    start =end + 1;
    end = wordAndSyn.find(synDelimiter);

    Synonyms * temp = nullptr;
    /// find and add synonyms if there are more than 1 (splitting)
    while (end != -1){
        Synonyms * synonym = new Synonyms;

        synonym->synonym = wordAndSyn.substr(start,end-start);
        synonym->next = temp;
        temp = synonym;

        start = end + 1;
        end = wordAndSyn.find(synDelimiter,start);
    }
    /// add last synonym
    Synonyms * synonym = new Synonyms;
    synonym->synonym = wordAndSyn.substr(start);
    synonym->next = temp;

    word->syn = synonym;
}
