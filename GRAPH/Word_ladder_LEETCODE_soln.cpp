class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //queue has two components the word and the number of steps
        queue<pair<string,int>>q;
        //Starting by pushing the beginWord
        q.push({beginWord,1});
        //We have a set to store the wordss in the wordlist without duplicates
        //We also remove the used words from the list
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            //We will check if we can find a word from the set by changing a single alphabet in the word
            //We will try giving values from a to z for all the position
            for(int i=0;i<beginWord.size();i++){
                //If we reach the end word we will simply return steps
                if(word==endWord){
                    return steps;
                }
                char original = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                //We will change the word back into the original word after each try 
                word[i]=original;
            }

        }
        return 0;

        
    }
};