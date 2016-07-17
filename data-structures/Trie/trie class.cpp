/* Trie class Implementation
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class trieNode{
public:
    char data;
    bool isTerminal;
    unordered_map<char,trieNode*> children;

    trieNode(char data){
        this->data = data;
        isTerminal = false;
    }
};

class trie{

trieNode* root;
int numOfWords;
public:
    trie(){
        root = new trieNode('\0');
        numOfWords = 0;
    }

    void addWordHelper(char* word,trieNode* node,int index){
        if(word[index] == '\0'){
            node->isTerminal = true;
            return ;
        }
        char currentChar = word[index];
        //this char was found with the node
        if(node->children.find(currentChar)!=node->children.end()){
            trieNode* temp = node->children.find(currentChar)->second;
            addWordHelper(word,temp,index+1);
        }
        //the char was not found in the trienode hashTable
        else{
            trieNode* temp = new trieNode(word[index]);
            node->children[word[index]] = temp;
            addWordHelper(word,temp,index+1);
        }
    }

    void addWord(char* word){
        addWordHelper(word,root,0);
        numOfWords++;
    }
    //start matching the index of the word
    //if there is a mismatch return false
    //if there is a match then there are 2 cases:
    //case 1: words[i+1] = '\0'
    //case 2: words[i+1] != '\0'
    //In case 1 return true as we have matched everything
    //In case 2 check the next index of the words array
    bool searchWordHelper(char* word, trieNode* node, int index){
        char currentChar = word[index];
        //current char is not found
        if(node->children.find(currentChar) == node->children.end()){
            return false;
        }
        //current char is found
        if(node->children.find(currentChar) != node->children.end()){
            if(word[index+1]=='\0'){
                if(node->children.find(currentChar)->second->isTerminal == true){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return searchWordHelper(word,node->children.find(currentChar)->second,index+1);
            }
        }
    }

    bool searchWord(char* word){
        return searchWordHelper(word,root,0);
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

return 0;
}
