// flesch.c - Student Implementation File
// Implement the Flesch Reading Ease algorithm
//
// DO NOT modify the function signatures

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "flesch.h"

int countSentences(const char* text) {
    // TODO: Implement this function
    return 0;
}

int countWords(const char* text) {
    // TODO: Implement this function
    return 0;
}

int countSyllables(const char* text) {
    // TODO: Implement this function
    return 0;
}

double calculateFleschScore(TextStats stats) {
    // TODO: Implement this function
    return 0.0;
}

TextStats analyzeText(const char* text) {
    TextStats stats;
    stats.sentences = countSentences(text);
    stats.words = countWords(text);
    stats.syllables = countSyllables(text);
    return stats;
}
