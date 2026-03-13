// DO NOT MODIFY THIS FILE
// This is the test harness for the Flesch Reading Ease assignment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flesch.h"

#define MAX_TEXT_SIZE 10000

int main(int argc, char* argv[]) {
    char text[MAX_TEXT_SIZE];
    FILE* inputFile = NULL;

    // Read from file if provided, otherwise from stdin
    if (argc > 1) {
        inputFile = fopen(argv[1], "r");
        if (inputFile == NULL) {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
    } else {
        inputFile = stdin;
    }

    // Read the entire text into buffer
    size_t totalRead = 0;
    size_t bytesRead;
    while ((bytesRead = fread(text + totalRead, 1, MAX_TEXT_SIZE - totalRead - 1, inputFile)) > 0) {
        totalRead += bytesRead;
        if (totalRead >= MAX_TEXT_SIZE - 1) {
            break;
        }
    }
    text[totalRead] = '\0';

    if (argc > 1) {
        fclose(inputFile);
    }

    // Analyze the text
    TextStats stats = analyzeText(text);
    double score = calculateFleschScore(stats);

    // Print results
    printf("Sentences: %d\n", stats.sentences);
    printf("Words: %d\n", stats.words);
    printf("Syllables: %d\n", stats.syllables);
    printf("Flesch Score: %.1f\n", score);

    return 0;
}
