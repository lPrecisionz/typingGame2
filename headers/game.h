#include"text.h"
#include<chrono>
#pragma once

class game{
	public:
		static void run();
	
	private:
		static void mainMenu();
		static std::pair<std::string, double> runLevel(std::string& userInput);
		static bool evaluate(const std::string& userInput, const std::string& levelText);
		static void result(bool evalutation, double wpm);
		static void showInstructions();
		static void setLanguage();
		static double calculateWPM(int wordsAmount, double seconds);
};
