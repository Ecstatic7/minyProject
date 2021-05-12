#include <iostream>

using namespace std;

/// Structs
struct Synonyms {
    string synonym;
    Synonyms *next;
};

struct Word {
    string word;
    Word *nextWord{};
    Synonyms *syn{};
};

/// functions prototype
string getWord();

void addWord(Word *&wordHead);

void sortSynonyms(Word *&word);

void swapSyn(Synonyms &, Synonyms &);

void sortWords(Word *head);

void swapWords(Word &, Word &);

void removeWord(Word *&word);

int main() {

    Word *wordHead = nullptr;

    addWord(wordHead);
    addWord(wordHead);

    Word *headTemp = wordHead;

    while (headTemp) {
        cout << headTemp->word << ":\t";

        Synonyms *synTemp = headTemp->syn;

        while (synTemp) {
            cout << synTemp->synonym << " | ";
            synTemp = synTemp->next;
        }

        headTemp = headTemp->nextWord;
        cout << endl;
    }

    return 0;
}

string getWord() {
    cout << "Enter word and synonyms. (e.g compute:figure out,calculate ...)\n";
    string wordAndSyn;
    getline(cin, wordAndSyn);

    return wordAndSyn;
}

void addWord(Word *&wordHead) {
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
    else {
        Word *headTemp = wordHead;

        while (headTemp->nextWord)
            headTemp = headTemp->nextWord;

        headTemp->nextWord = word;
    }
    word->nextWord = nullptr;

    /// find first syn
    start = end + 1;
    end = wordAndSyn.find(synDelimiter);

    Synonyms *temp = nullptr;
    /// find and add synonyms if there are more than 1 (splitting)
    while (end != -1) {
        Synonyms *synonym = new Synonyms;

        synonym->synonym = wordAndSyn.substr(start, end - start);
        synonym->next = temp;
        temp = synonym;

        start = end + 1;
        end = wordAndSyn.find(synDelimiter, start);
    }

    /// add last synonym
    Synonyms *synonym = new Synonyms;
    synonym->synonym = wordAndSyn.substr(start);
    synonym->next = temp;

    word->syn = synonym;

    /// sort Synonyms
    sortSynonyms(word);
    sortWords(wordHead);
}

void sortSynonyms(Word *&word) {
    Synonyms *temp = word->syn;

    while (temp) {
        Synonyms *tempPrim = temp;
        Synonyms *temp2 = temp->next;
        Synonyms *minimum = temp;

        bool isSort = true;

        while (temp2) {
            if (temp2->synonym < minimum->synonym) {
                minimum = temp2;
                isSort = false;
            }

            temp2 = temp2->next;
        }

        if (!isSort)
            swapSyn(*tempPrim, *minimum);

        temp = temp->next;
    }
}

void swapSyn(Synonyms &s1, Synonyms &s2) {
    Synonyms temp = s1;

    s1.synonym = s2.synonym;
    s2.synonym = temp.synonym;
}

void sortWords(Word *head) {
    Word *temp = head;

    while (temp) {
        Word *tempPrim = temp;
        Word *temp2 = temp->nextWord;
        Word *minimum = temp;

        bool isSorted = true;

        while (temp2) {
            if (temp2->word < minimum->word) {
                minimum = temp2;
                isSorted = false;
            }

            temp2 = temp2->nextWord;
        }

        if (!isSorted)
            swapWords(*tempPrim, *minimum);

        temp = temp->nextWord;
    }
}

void swapWords(Word &w1, Word &w2) {
    Word temp = w1;

    w1.syn = w2.syn;
    w1.word = w2.word;
    w2.syn = temp.syn;
    w2.word = temp.word;
}

void removeWord(Word *&head, Word *& word) {
    Word * temp = head;
    Word * previousWord = temp;

    while (temp){

        if (temp == word){
            Synonyms * synTemp = word->syn;
            Synonyms * temp2 = synTemp;

            while (synTemp) {
                synTemp = synTemp->next;
                delete temp2;
                temp2 = synTemp;
            }

            if (word == head)
                head = head->nextWord;
            else
                previousWord->nextWord = word->nextWord;

            delete word;
            break;
        }
        previousWord = temp;
        temp = temp->nextWord;
    }
}