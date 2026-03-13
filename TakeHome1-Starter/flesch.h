#ifndef FLESCH_H
#define FLESCH_H

// Structure to hold text statistics
typedef struct {
    int sentences;
    int words;
    int syllables;
} TextStats;

// Function prototypes - students must implement these in flesch.c

/**
 * Count the number of sentences in the text.
 * A sentence ends with: . : ; ? !
 * Multiple terminators in a row each count as a sentence.
 * If no terminators exist, count as 1 sentence.
 *
 * @param text The input text string
 * @return The number of sentences
 */
int countSentences(const char* text);

/**
 * Count the number of words in the text.
 * A word is a sequence of characters delimited by:
 * - Whitespace (space, tab, newline)
 * - Sentence terminators (. : ; ? !)
 * - End of string
 *
 * @param text The input text string
 * @return The number of words
 */
int countWords(const char* text);

/**
 * Count the number of syllables in the text.
 * Syllables are counted by counting groups of adjacent vowels (a, e, i, o, u).
 * Case-insensitive.
 * Example: "real" has 1 syllable (ea is one group)
 * Example: "regal" has 2 syllables (e and a are separate)
 *
 * @param text The input text string
 * @return The number of syllables
 */
int countSyllables(const char* text);

/**
 * Calculate the Flesch Reading Ease score.
 * Formula: 206.835 - (1.015 * words/sentences) - (84.6 * syllables/words)
 *
 * @param stats The text statistics (sentences, words, syllables)
 * @return The Flesch score (0-100 typically, can be negative for complex text)
 */
double calculateFleschScore(TextStats stats);

/**
 * Analyze text and return all statistics.
 * This function calls countSentences, countWords, and countSyllables.
 *
 * @param text The input text string
 * @return TextStats structure with all counts
 */
TextStats analyzeText(const char* text);

#endif // FLESCH_H
