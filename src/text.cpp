#include "../headers/text.h"

std::string text::databasePath = "../database/";
std::string text::fileName = "english.txt";
std::string text::instructions = "Type the text shown as fast as possible.\nEvery word must be right.\nYour time will be measured in words per minute (WPM)";

std::string text::generateText(std::ifstream& data, int wordsAmount){
    std::vector<std::string> allWords;
    std::string word;

    while (std::getline(data, word)) {
        allWords.push_back(word);
    }
    
    return text::selectWordsFromVector(allWords, wordsAmount);
}



std::string text::selectWordsFromVector(const std::vector<std::string>& allWords, int wordsAmount) {
    std::vector<int> randomPositions;
    randomPositions = text::generatePositionsVector(wordsAmount, allWords.size());
    
    std::vector<std::string> selectedWords;
    for (int position : randomPositions) {
        selectedWords.push_back(allWords[position]);
    }

    return text::loadVectorIntoString(selectedWords);
}


std::string text::loadVectorIntoString(const std::vector<std::string>& words) {
    std::string result;
    for (const std::string& str : words) {
        result += str + " ";
    }
    return result;
}


std::vector<int> text::generatePositionsVector(int wordsAmount, int totalWords) {
    std::vector<int> randomPositions;

    for (int i = 0; i < wordsAmount; i++) {
        int position = rand() % totalWords;
        randomPositions.push_back(position);
    }

    // Sorting the positions
    std::sort(randomPositions.begin(), randomPositions.end());

    return randomPositions;
}

std::string text::trimString(const std::string& string) {
    std::string trimmedString = string;
    trimmedString.erase(trimmedString.find_last_not_of(" \t\n\r\f\v") + 1);
    trimmedString.erase(0, trimmedString.find_first_not_of(" \t\n\r\f\v"));
    return trimmedString;
}

void text::setFileName(std::string fileName){
	text::fileName = fileName;
}

int text::countWords(std::string input) {
    int wordCount = 0;
    std::string word;

    std::istringstream iss(input);
    while (iss >> word) {
        wordCount++;
    }
    return wordCount;
}
