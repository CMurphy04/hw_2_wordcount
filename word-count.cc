/** 
 *  @file: wordcount_HW2
 *@author: Collin Haggerty-Murphy
    @date: 2/12/23
   @brief: word counter that reads and outputs a number of sentences and words in a string
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

int main(){

    bool cont = true;

    while(cont)
    {
        string input = "", append;
        cout << "\nEnter a paragraph ..." << endl;

        while(true)
        {
            getline(cin, append);
            if(input.length() == 0)
            {
                input += append;       // stitches lines together for continuous string of text
            }
            else
            {
                input += " " + append; // adds space after finished words
            }
            if(input.length() > 2 && input.substr(input.length()-3, 3) == "@@@") // checks last 3 characters in string
            {
                break;
            }
        }
        //cout << input; //test for now to check what the input is

        int wordCount = 0;
        int sentenceCount = 0;
        double wordAvg = 0.0;

        for(int i = 0; i < input.length()-3; i++){
        
            if(input[i] == '!' || input[i] == '?' || input[i] == '.')
            {
                sentenceCount++; // checks for sentences using punctuation
                continue;
            }
            if(input[i] == ' ' ) //assume no text starts with a space
            {
                wordCount++;  // checks for words
            }
        }

        if(wordCount == 0){ // catch for when no words are given
            cout << "\n\nWord count: " << wordCount << "\nSentence count: " << sentenceCount << "\nYou did not enter any text!\n";
        }
        else if(sentenceCount == 0) // catch for when no punctuation is given
        {
            cout << "\n\nWord count: " << wordCount << "\nSentence count: " << sentenceCount << "\nYou did not enter any sentences!\n";
        }
        else{
            wordAvg = wordCount/((sentenceCount * 10.0)/10.0); // avg. words per sentence rounding to nearest tenth
            cout << "\n\nWord count: " << wordCount << "\nSentence count: " << sentenceCount << "\nAverage words per sentence: " << wordAvg << endl;
        }

        cout << "\nWould you like to continue? (y/n)\n";
        input = "";
        getline(cin, input);

        if(input == "n"){
            cont = false;
        }
    }
};