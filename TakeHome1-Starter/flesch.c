// flesch.c - Student Implementation File
// Implement the Flesch Reading Ease algorithm
//
// DO NOT modify the function signatures

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "flesch.h"

int isVowel(char);

int countSentences(const char* text) {
    // TODO: Implement this function
    int count = 0;
    int index = 0;
    while(text[index] != '\0')
    {
        char curr = text[index];
        if(curr == '.' || curr == ':' || curr == ';' || curr == '?' || curr == '!') {
            count++;
        }
        index++;
    }
    return count ? count : 1;
}

int countWords(const char* text) {
    // TODO: Implement this function
    int count = 1;
    int index = 0;
    int onWord = 1;

    while(text[index] != '\0')
    {
        char curr = text[index];
        int isDelimiter = curr == '.' || curr == ':' || curr == ';' || curr == '?' || curr == '!' || curr == ' ' || curr == '\n' || curr == '\t';
        if(!onWord && !isDelimiter) {
            onWord = 1;
            count++;
        } else if(isDelimiter) {
            onWord = 0;
        }
        index++;
    }
    printf("\n");

    return count;
}

int countSyllables(const char* text) {
    // TODO: Implement this function
    int count = 0;
    int index = 0;
    int onVowel = isVowel(text[0]);

    while(text[index] != '\0') {
        if(!onVowel && isVowel(text[index])) {
            onVowel = 1;
        } else if (onVowel && !isVowel(text[index])) {
            onVowel = 0;
            count++;
        }
    
        index++;        
    }
    return count;
}

int isVowel(char letter){
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U';
}

double calculateFleschScore(TextStats stats) {
    // TODO: Implement this function
    double val = 206.835 - (1.015 * stats.words / stats.sentences) - (84.6 * stats.syllables / stats.words);
    return val;
}

TextStats analyzeText(const char* text) {
    TextStats stats;
    stats.sentences = countSentences(text);
    stats.words = countWords(text);
    stats.syllables = countSyllables(text);
    return stats;
}
