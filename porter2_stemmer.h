// NAMES



/*
 *
To use the stemmer, this is the code you will need:
main.cpp

std::ifstream in("testStemmer.txt");
string toStem;
while (in>>toStem)
{
    Porter2Stemmer::stem(toStem);
} // toStem now equals the stemmed word

*/


#ifndef _PORTER2_STEMMER_H_
#define _PORTER2_STEMMER_H_

#include <vector>
#include <string>

namespace Porter2Stemmer
{
    void stem(std::string & word);

    void trim(std::string & word);

    namespace internal
    {
        size_t firstNonVowelAfterVowel(const std::string & word, size_t start);

        size_t getStartR1(const std::string & word);

        size_t getStartR2(const std::string & word, size_t startR1);

        void changeY(std::string & word);

        void step0(std::string & word);

        bool step1A(std::string & word);

        void step1B(std::string & word, size_t startR1);

        void step1C(std::string & word);

        void step2(std::string & word, size_t startR1);

        void step3(std::string & word, size_t startR1, size_t startR2);

        void step4(std::string & word, size_t startR2);

        void step5(std::string & word, size_t startR1, size_t startR2);

        inline bool isShort(const std::string & word);

        bool special(std::string & word);

        bool isVowel(char ch);

        bool isVowelY(char ch);

        bool endsWith(const std::string & word, const std::string & str);

        bool endsInDouble(const std::string & word);

        bool replaceIfExists(std::string & word,
            const std::string & suffix, const std::string & replacement,
            size_t start);

        bool isValidLIEnding(char ch);

        bool containsVowel(const std::string & word, size_t start, size_t end);
    }
}

#endif

// Implementation taken from https://bitbucket.org/smassung/porter2_stemmer/src/078e3a0fea8713b68520332955dc5280a20bb162/porter2_stemmer.cpp?at=master
// Accessed 11/21/14

/**
 * @file porter2_stemmer.h
 * @author Sean Massung
 * @date September 2012
 *
 * Implementation of
 * http://snowball.tartarus.org/algorithms/english/stemmer.html
 *
 * Copyright (C) 2012 Sean Massung
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
