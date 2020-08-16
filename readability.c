#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text_l);
int count_words(string text_w);
int count_sentences(string text_s);
int index(string text_i);

int main(void)
{
    string s = get_string("Text:  ");
    // printf("%i letter(s)\n", count_letters(foroms));
    // printf("%i word(s)\n", count_words(s));
    // printf("%i sentence(s)\n", count_sentences(s));

    float index = 0.0588 * ((float)(100 * count_letters(s)) / count_words(s)) - 
                  0.296 * ((float)(100 * count_sentences(s)) / count_words(s)) - 15.8;

    if (index >= 1 && index <= 16)
    {
        double r = round(index);
        printf("Grade %.0f\n", r);
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

}

int count_letters(string text_l)
{
    int letters = 0;
    for (int i = 0; i < strlen(text_l); i++)
    {
        if (isalpha(text_l[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text_w)
{
    int words = 1;
    for (int i = 0; i < strlen(text_w); i++)
    {
        if (text_w[i] == 32)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text_s)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text_s); i++)
    {
        if (text_s[i] == 33 || text_s[i] == 46 || text_s[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}


// int index(string text_i)
// {
//     // index = 0.0588 * L - 0.296 * S - 15.8
//     float index = 0.0588 * (100 * count_letters(s) / count_words(s)) - 0.296 * (100 * count_sentences(s) / count_words(s)) - 15.8;
//     return index;
// }