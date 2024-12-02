class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int searchWord_size = searchWord.size(), i = 1;
        stringstream s(sentence);
        string word;
        while(s >> word){
            if(word.substr(0, searchWord_size) == searchWord)
                return i;
            ++i;
        }

        return -1;
    }
};