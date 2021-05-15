#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

/// Structs
struct Synonyms {
    string synonym;
    Synonyms *next{};
};

struct Word {
    string word;
    Word *nextWord{};
    Synonyms *syn{};
};

/// functions prototype
string getWordAndSynonyms();

void addWord(Word *&wordHead);

void sortSynonyms(Word *&word);

void swapSyn(Synonyms &, Synonyms &);

void sortWords(Word *head);

void swapWords(Word &, Word &);

void removeWord(Word *&head, const string &word);

void removeSynonym(Word *&, const string &, const string &);

void findWord(Word *, const string &);

Word *getWord(Word *, const string &);

string showWordAndSynonym(Word *);

void showAllWords(Word *);

void changeDictation(Word *&,const string &);

Synonyms *lastSynonym(Word *);

void writeInFile(Word *);

Word * readFromFile();

Word * addWordsFromFile(Word *&, const string& );

string menu();

int main() {

    Word *head = nullptr;



    int option = 1;
    string word;
    string synonym;
    string newWord ;
    Word * currentWord = nullptr;


    while (option) {

        cout << endl;
        cout << menu();
        string repeat(30, '*');

        cin >> option;

        switch (option) {
            case 1:
                addWord(head);
                break;

            case 2:
                cout << "Enter the word you want to remove:";
                cin >> word;

                removeWord(head, word);
                break;

            case 3:
                cout << "Enter the word:";
                cin.get();
                getline(cin, word);
                cout << "Enter the synonym you want to remove:";
                getline(cin, synonym);

                removeSynonym(head, word, synonym);
                break;

            case 4:
                cout << "Enter the word you want to find\n";
                cin >> word;
                findWord(head, word);
                break;

            case 5:
                showAllWords(head);
                break;

            case 6:
                cout << "Enter the word you want to change:";
                cin.get();
                getline(cin , word);

                cout << "Enter the new word:";
                getline(cin, newWord);

                currentWord = getWord(head, word);
                changeDictation(currentWord ,newWord);
                break;
            case 7:
                writeInFile(head);
                break;

            case 8:
                head = readFromFile();
                break;

            case 0:
                break;
            default:
                cout << "invalid option\n";
                cout << endl << repeat << endl;
                cout << menu();
        }
    }


    return 0;
}

string getWordAndSynonyms() {
    cin.get();
    cout << "Enter word and synonyms. (e.g compute:figure out,calculate ...)\n";
    string wordAndSyn;
    getline(cin, wordAndSyn);

    return wordAndSyn;
}

void addWord(Word *&wordHead) {
    string wordAndSyn = getWordAndSynonyms();

    char wordDelimiter = ':';
    char synDelimiter = ',';

    /// find word (split)
    int start = 0;
    int end = wordAndSyn.find(wordDelimiter);

    string _word = wordAndSyn.substr(start, end - start);

    /// check if the word exists in list or not
    Word *word = getWord(wordHead, _word);
    bool exist = true;

    if (word == nullptr) {
        exist = false;
        word = new Word;
        word->word = _word;
    }

    Synonyms *temp = nullptr;     /// if the word doesn't exist -> there is no synonym of that word

    /// add word to list
    if (!exist) {
        if (wordHead == nullptr)
            wordHead = word;
        else {
            Word *headTemp = wordHead;

            while (headTemp->nextWord)
                headTemp = headTemp->nextWord;

            headTemp->nextWord = word;
        }
        word->nextWord = nullptr;
    } else
        temp = lastSynonym(word);    /// temp is last synonym of existing word

    /// find first syn
    start = end + 1;
    end = wordAndSyn.find(synDelimiter);

    /// find and add synonyms (splitting)
    Synonyms *synonym;      /// the new synonym we want to add
    Synonyms *temp2 = nullptr;        /// the next synonym will be store here
    while (end != -1) {
        synonym = new Synonyms;

        string syn = wordAndSyn.substr(start, end - start);
        synonym->synonym = syn;
        synonym->next = temp2;
        temp2 = synonym;

        start = end + 1;
        end = wordAndSyn.find(synDelimiter, start);
    }

    /// add last synonym in buffer
    synonym = new Synonyms;
    synonym->synonym = wordAndSyn.substr(start);
    synonym->next = temp2;

    if (!exist)
        word->syn = synonym;
    else
        temp->next = synonym;

    /// sort Synonyms and words;
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

void removeWord(Word *&head, const string &word) {
    Word *temp = head;
    Word *previousWord = temp;

    while (temp) {

        if (temp->word == word) {
            Synonyms *synTemp = temp->syn;   /// synonyms head
            Synonyms *temp2 = synTemp;

            while (synTemp) {
                synTemp = synTemp->next;
                delete temp2;
                temp2 = synTemp;
            }

            /// if the word we want to remove is head or not
            if (temp == head)
                head = head->nextWord;
            else
                previousWord->nextWord = temp->nextWord;

            delete temp;

            cout << "word has been removed successfully\n";
            return;
        }
        previousWord = temp;
        temp = temp->nextWord;
    }
    cout << "couldn't find the word\n";
}

void removeSynonym(Word *&head, const string &kalame, const string &syn) {
    Word *word = getWord(head, kalame);

    if (word == nullptr) {
        cout << "the word doesn't exist\n";
        return;
    }

    Synonyms *synHead = word->syn;
    Synonyms *previousSyn = word->syn;

    bool onlyOneSynonym = false;

    if (synHead->next == nullptr)
        onlyOneSynonym = true;

    while (synHead) {
        if (syn == synHead->synonym) {

            if (synHead == word->syn)       /// change the head in synonyms if its first synonym
                word->syn = word->syn->next;
            else
                previousSyn->next = synHead->next;

            delete synHead;
            synHead = nullptr;

            if (onlyOneSynonym)
                removeWord(head, word->word);

            break;
        }

        previousSyn = synHead;
        synHead = synHead->next;
    }

}

void findWord(Word *head, const string &word) {

    bool found = false;
    while (head) {
        if (head->word == word) {
            found = true;
            cout << showWordAndSynonym(head);
            break;
        }
        head = head->nextWord;
    }
    if (!found)
        cout << "couldn't find the word!\n";
}

Word *getWord(Word *head, const string &word) {
    while (head) {
        if (head->word == word)
            return head;
        head = head->nextWord;
    }
    return nullptr;
}

string showWordAndSynonym(Word *word) {
    ostringstream print;
    Synonyms *head = word->syn;

    print << word->word << ' ';
    while (head) {
        print << head->synonym << ' ';
        head = head->next;
    }
    print << endl;
    return print.str();
}

void showAllWords(Word *head) {
    if (head == nullptr)
        cout << "there is no word in dictionary!\n";
    else
        while (head) {
            cout << showWordAndSynonym(head);
            head = head->nextWord;
        }
}

void changeDictation(Word *&word,const string &newWord) {
    word->word = newWord;
}

string menu() {
    ostringstream menu;
    menu << "1) add Word\n"
            "2) remove Word\n"
            "3) remove synonym\n"
            "4) find a word\n"
            "5) show words\n"
            "6) change dictation of a word\n"
            "7) save list\n"
            "8) read from file\n"
            "0) exit\n"
            "choose your call ->";
    return menu.str();
}

Synonyms *lastSynonym(Word *word) {
    Synonyms *head = word->syn;

    while (head->next)
        head = head->next;

    return head;
}

void writeInFile(Word * head){
    ofstream write("dictionary.txt");

    Word * temp = head;
    while (temp){
        write << showWordAndSynonym(temp);
        temp = temp->nextWord;
    }
    write.close();
}

Word * readFromFile(){
    Word * head = nullptr;
    Word * word ;

    const string fileAddress = "dictionary.txt";
    ifstream read(fileAddress);

    string nameAndSyn;
    getline(read, nameAndSyn);

    while (!read.eof()) {
        addWordsFromFile(word, nameAndSyn);
        word->nextWord = head;
        head = word;
        getline(read, nameAndSyn);
    }
    
    sortWords(head);
    return head;
}

Word * addWordsFromFile(Word *& word, const string& line) {

    word = new Word;
    stringstream nameAndSyn(line);
    string token;

    Synonyms * syn;
    Synonyms * temp = nullptr;

    bool firstTime = true;
    while (getline(nameAndSyn , token, ' ')){
        if (firstTime) {
            word->word = token;
            firstTime = false;
        }
        else{
            syn = new Synonyms;
            syn->synonym = token;
            syn->next = temp;
            temp = syn;
        }
    }
    word->syn = syn;
    sortSynonyms(word);

    return word;
}





