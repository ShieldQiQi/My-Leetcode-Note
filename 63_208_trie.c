#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct TrieTemp {
    char value;
    int endFlag;
    struct TrieTemp *child[26];
} Trie;


Trie* trieCreate() {
    Trie *trie = (Trie*)malloc(sizeof(Trie));
    trie->value = 0;
    trie->endFlag = 0;
    for(int i=0; i<26; i++)
        trie->child[i] = NULL;
    return trie;
}

void trieInsert(Trie* obj, char * word) {
    int i = 0;
    while(word[i]) {
        if(obj->child[word[i]-'a'] == NULL) {
            obj->child[word[i]-'a'] = (Trie*)malloc(sizeof(Trie));
            obj->child[word[i]-'a']->value = word[i];
            obj->child[word[i]-'a']->endFlag = 0;
            for(int j=0; j<26; j++)
                obj->child[word[i]-'a']->child[j] = NULL;
        }
        obj = obj->child[word[i]-'a'];
        i++;
    }
    obj->endFlag = 1;
}

int trieSearch(Trie* obj, char * word) {
    int i = 0;
    while(word[i] && obj->child[word[i]-'a']!=NULL) {
        obj = obj->child[word[i]-'a'];
        i++;
    }
    if(word[i] || !(obj->endFlag))
        return false;
    return true;
}

int trieStartsWith(Trie* obj, char * prefix) {
    int i = 0;
    while(prefix[i] && obj->child[prefix[i]-'a']!=NULL) {
        obj = obj->child[prefix[i]-'a'];
        i++;
    }
    if(prefix[i])
        return false;
    return true;
}

void trieFree(Trie* obj) {
    for(int i=0; i<26; i++) {
        if(obj->child[i] != NULL)
            trieFree(obj->child[i]);
    }
    free(obj);
}

int main()
{
    char* word1 = "apple";
    char* word2 = "app";
    Trie *trie = trieCreate();
    trieInsert(trie, word1);
    printf("%d ", trieSearch(trie, word1));
    printf("%d ", trieSearch(trie, word2));
    printf("%d ", trieStartsWith(trie, word2));
    trieInsert(trie, word2);
    printf("%d ", trieSearch(trie, word2));
    return 0;
}