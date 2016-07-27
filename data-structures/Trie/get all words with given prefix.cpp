/**

* Implement a trie class with following function – InsertAWord, CheckAWord,
* getAllWordsWithThisPrefix

*/

#include<bits/stdc++.h>

using namespace std;

class trieNode{
public:
    char data;
    bool isTerminal;
    unordered_map <char,trieNode*> children;

    trieNode(char data){
        this->data = data;
        isTerminal = false;
    }
};

class trie{

trieNode* root;
int numberOfWords;

public:
    trie(){
        root = new trieNode('\0');
        numberOfWords =0 ;
    }

    void addWordHelper(char* word, trieNode* node, int index){
        //I have reached the end of the word
        if(word[index] == '\0'){
            node->isTerminal = true;
            return;
        }
        //character of the word at the index matches the character present in the hash table of the node
        if(node->children.find(word[index]) != node->children.end()){
            trieNode* temp = node->children.find(word[index])->second;
            addWordHelper(word,temp,index+1);
        }
        //charcter not found so create new node
        else{
            trieNode* temp = new trieNode(word[index]);
            node->children[word[index]] = temp;
            addWordHelper(word,node->children.find(word[index])->second,index+1);
        }
    }

    void addWord(char* word){
        addWordHelper(word,root,0);
        numberOfWords++;
    }

    bool searchWordHelper(char* word, trieNode* node, int index){

        if(word[index] == '\0'){
            if(node->isTerminal == true){
                return true;
            }
            else{
                return false;
            }
        }

        if(node->children.find(word[index]) != node->children.end()){
                trieNode* temp = node->children.find(word[index])->second;
                return searchWordHelper(word,temp,index+1);
        }
        else{
            return false;
        }
    }

    bool searchWord(char* word){
        return searchWordHelper(word,root,0);
    }

    trieNode* returnTheNodeTillPrefixMatch(char* prefix, trieNode* node, int index){
        //I am standing at the last pos
        if(prefix[index] == '\0'){
            return node;
        }
        //there is a match but we are not yet at the last position
        if(node->children.find(prefix[index]) != node->children.end()){
            return returnTheNodeTillPrefixMatch(prefix,node->children.find(prefix[index])->second,index+1);
        }
        //there was no match at all
        else{
            return NULL;
        }
    }

    void printAllWordsHelper(trieNode* node, vector<char>& result){
        if(node->isTerminal == true){
            for(int i=0;i<result.size();i++){
                cout<<result[i];
            }
            cout<<endl;
        }
        unordered_map<char,trieNode*>::iterator it;
        for(it = node->children.begin();it != node->children.end();it++){
            result.push_back(it->first);
            printAllWordsHelper(it->second,result);
            result.pop_back();
        }

    }

    void printAllWordsWithThisPrefix(char* prefix){
        trieNode* temp = returnTheNodeTillPrefixMatch(prefix,root,0);
        //cout<<temp->data; //debugging
        vector<char> result;
        for(int i=0;i<strlen(prefix);i++){
            result.push_back(prefix[i]);
        }
        printAllWordsHelper(temp,result);

    }

};

int main(){
trie t;
char words[][100] = { "nest","new","not","news","apple","ape","banana"};

for(int i=0;i<7;i++){
	t.addWord(words[i]);
}

char searchWords[][100] = { "nest","never","new","news","newest","banan","banana"};

for(int i=0;i<7;i++){
	if(t.searchWord(searchWords[i])==true){
		cout<<searchWords[i]<<" is found in Trie "<<endl;
	}
	else{
		cout<<searchWords[i] <<" not found in Trie "<<endl;
	}
}

char prefix[] = {"ne"};
t.printAllWordsWithThisPrefix(prefix);
return 0;
}
