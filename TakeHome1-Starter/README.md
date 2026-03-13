# Take Home Programming Test1: Flesch Reading Ease Test

## Overview

The Flesch Reading Ease Test is a readability formula that calculates how easy a piece of text is to read. It produces a score typically between 0-100 where higher scores indicate easier readability:

| Score | Reading Level |
|-------|---------------|
| 90-100 | 5th grade |
| 80-90 | 6th grade |
| 70-80 | 7th grade |
| 60-70 | 8th-9th grade |
| 50-60 | 10th-12th grade |
| 30-50 | College |
| 0-30 | College graduate |

## The Formula

```
Flesch Score = 206.835 - (1.015 × words/sentences) - (84.6 × syllables/words)
```

## Your Task

Implement the following functions in `flesch.c`:

1. `countSentences(const char* text)` - Count sentences in the text
2. `countWords(const char* text)` - Count words in the text
3. `countSyllables(const char* text)` - Count syllables in the text
4. `calculateFleschScore(TextStats stats)` - Calculate the Flesch score

## Counting Rules

### Sentences
A sentence ends with one of these characters: `. : ; ? !`

Each terminator counts as one sentence. For example:
- `"Hello."` → 1 sentence
- `"What?!"` → 2 sentences
- `"Wait... really?"` → 4 sentences (three periods + one question mark)

If no terminators exist in the text, count it as 1 sentence.

### Words
A word is a sequence of one or more characters delimited by:
- Whitespace (space, tab, newline)
- Sentence terminators (`. : ; ? !`)
- End of string

For example:
- `"Hello world"` → 2 words
- `"Hello.World"` → 2 words
- `"I_don't_like_spaces"` → 1 word (underscores are not delimiters)

### Syllables
Count syllables by counting groups of adjacent vowels (`a, e, i, o, u`, case-insensitive).

For example:
- `"real"` → 1 syllable (`ea` is one vowel group)
- `"regal"` → 2 syllables (`e` and `a` are separate groups)
- `"beautiful"` → 3 syllables (`eau`, `i`, `u`)

Note: This is a heuristic that may not match dictionary syllable counts.

### Compute Flesch Score

Flesch Score must be calculated using the formula provided. If the text has zero words, return a score of 0 to avoid division by zero.

## Files

- `main.c` - Test harness (DO NOT MODIFY)
- `flesch.h` - Header file with function prototypes (DO NOT MODIFY)
- `flesch.c` - Your implementation goes here
- `inputs/` - Test input files
- `expected/` - Expected output files

## Building and Testing

```bash
# Compile
gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror main.c flesch.c -o flesch

# Run with an input file
./flesch inputs/input_1.txt

# Compare output with expected
./flesch inputs/input_1.txt > output.txt
diff output.txt expected/expected_1.txt
```

## Submission

Submit only `flesch.c` to Gradescope.

## Grading

- File submission: 10%
- Compilation: 10%
- Output correctness: 80%
