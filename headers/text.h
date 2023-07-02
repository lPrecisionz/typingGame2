#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<utility>
#include<chrono>
#include<vector>
#include<cstdlib>
#include<iomanip>
#pragma once

class text{
	public:
		static int countWords(std::string input);
		static std::string generateText(std::ifstream& data, int wordsAmount);
		static std::string trimString(const std::string& string);
		static void setFileName(std::string fileName);
		static std::string databasePath;
		static std::string fileName;
		static std::string instructions;

	private:
		static std::string selectWordsFromVector(const std::vector<std::string>& allWords, int wordsAmount);
		static std::string loadVectorIntoString(const std::vector<std::string>& words);
		static std::vector<int> generatePositionsVector(int wordsAmount, int totalWords);
};
