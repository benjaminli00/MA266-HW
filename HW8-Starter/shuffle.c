#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void pick(CardDeck, CardDeck, CardDeck, int, int);

// do NOT modify this function
static void printDeck(CardDeck deck)
{
    int ind;
    for (ind = 0; ind < deck.size; ind ++)
        {
        printf("%c ", deck.cards[ind]);
        }
    printf("\n");
}

void shuffle(CardDeck origDeck, int round)
{
    if(round == 0)
    {
        printDeck(origDeck);
        return;
    }
    else
    {
        int numSplits = origDeck.size - 1;

        CardDeck * leftDecks;
        CardDeck * rightDecks;

        leftDecks = malloc(sizeof(CardDeck) * numSplits);
        rightDecks = malloc(sizeof(CardDeck) * numSplits);

        //run divide
        divide(origDeck, leftDecks, rightDecks);

        //send pairs to interleave
        for(int i = 0; i< numSplits; i++)
        {
            interleave(leftDecks[i], rightDecks[i], round);
        }

        free(leftDecks);
        free(rightDecks);
    }
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
    for(int i = 0; i < origDeck.size - 1; i++) //i is where split occurs
    {
        leftDeck[i].size = i + 1;
        rightDeck[i].size = origDeck.size - i - 1;

        memcpy(leftDeck[i].cards, origDeck.cards, sizeof(char) * (i + 1));
        memcpy(rightDeck[i].cards, &origDeck.cards[i + 1], sizeof(char) * (origDeck.size - i - 1));
        // leftDeck[i].deck = origDeck.deck;
        // rightDeck[i].deck = &origDeck.deck[i + 1];
    }
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
    CardDeck outL;
    int deckSize = leftDeck.size + rightDeck.size;

    outL.size = 0;

    pick(leftDeck, rightDeck, outL, deckSize, round);
}

void pick(CardDeck leftDeck, CardDeck rightDeck, CardDeck outL, int deckSize, int round)
{
    if(outL.size == deckSize)
    {
        shuffle(outL, round - 1);
        return;
    }
    else if(leftDeck.size == 0)
    {
        outL.cards[outL.size] = rightDeck.cards[0];
        outL.size += 1;

        rightDeck.size -= 1;
        memcpy(rightDeck.cards, &rightDeck.cards[1], sizeof(char) * rightDeck.size);

        pick(leftDeck, rightDeck, outL, deckSize, round);
    }
    else if(rightDeck.size == 0)
    {
        outL.cards[outL.size] = leftDeck.cards[0];
        outL.size += 1;

        leftDeck.size -= 1;
        memcpy(leftDeck.cards, &leftDeck.cards[1], sizeof(char) * leftDeck.size);

        pick(leftDeck, rightDeck, outL, deckSize, round);
    }
    else
    {
        CardDeck outR; 
        
        outR.size = outL.size;
        memcpy(outR.cards, outL.cards, sizeof(char) * outL.size);

        outL.cards[outL.size] = leftDeck.cards[0];
        outL.size += 1;

        outR.cards[outR.size] = rightDeck.cards[0];
        outR.size += 1;

        CardDeck tempLeft;
        tempLeft.size = leftDeck.size - 1;
        memcpy(tempLeft.cards, &leftDeck.cards[1], sizeof(char) * tempLeft.size);

        CardDeck tempRight;
        tempRight.size = rightDeck.size - 1;
        memcpy(tempRight.cards, &rightDeck.cards[1], sizeof(char) * tempRight.size);
        
        pick(tempLeft, rightDeck, outL, deckSize, round);
        pick(leftDeck, tempRight, outR, deckSize, round);
    }
}

