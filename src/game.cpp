#include "../headers/game.h"
void game::mainMenu(){
	std::cout << "Welcome!" << std::endl;
	std::cout << "1. Play level" << std::endl;
	std::cout << "2. Instructions" << std::endl;
	std::cout << "3. Set language" << std::endl;
    std::cout << "4. Leave" << std::endl;
	std::cout << "Option: ";
}

void game::setLanguage(){
    int optionLanguage;    
    std::cout << "Select language:" << std::endl;
    std::cout << "1. Portuguese" << std::endl;
    std::cout << "2. English" << std::endl;
    std::cout << "Option: ";
    std::cin >> optionLanguage;

    switch (optionLanguage){
        case 1:
            text::setFileName("portuguese.txt");
            break;
        case 2:
            text::setFileName("English.txt");
            break;
        default:
            std::cout << "Invalid option.\nGoing back to main Menu..." << std::endl;
            std::cin.get();
            break;
    }
    system("cls");
}

void game::showInstructions(){
	std::cout << "\nInstructions:" << std::endl;
	std::cout << text::instructions << std::endl;
	std::cin.ignore(); std::cin.get();
    system("cls");
}


std::pair<std::string, double> game::runLevel(std::string& userInput){
    int wordsAmount = 5;
    std::string challengeText;
    std::string databasePath = text::databasePath;
    std::string fileName = text::fileName;
    
    std::ifstream data(databasePath + fileName);
    if (!data.is_open()) {
        std::cout << "Unable to open file." << std::endl;
        exit(1);
    }
    challengeText = text::generateText(data, wordsAmount);
    data.close();
    
    std::cout << challengeText << std::endl;
    
    std::cin.ignore();
    
    auto start = std::chrono::high_resolution_clock::now();
    std::getline(std::cin, userInput);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;
    double seconds = duration.count();
    double wpm = game::calculateWPM(wordsAmount, seconds);
    
    int userInputWords = text::countWords(userInput);
    return std::make_pair(challengeText, wpm);
}


bool game::evaluate(const std::string& userInput, const std::string& levelText) {
	std::string trimmedUserInput = text::trimString(userInput);
	std::string trimmedLevelText = text::trimString(levelText);
    return trimmedUserInput == trimmedLevelText;
}



void game::result(bool evaluation, double wpm){
	if(evaluation){
		std::cout << "Congrats! You got every word right!" << std::endl;
		std::cout << "Speed: " << wpm << " words per minute" << std::endl;
		std::cout << "Press enter to continue." <<std::endl;
	} else{
		std::cout << "Defeat! You've failed!" << std::endl;
		std::cout << "Press enter to continue." << std::endl;
	}
    system("cls");
}


double game::calculateWPM(int wordsAmount, double seconds){
	return static_cast<double>(wordsAmount) / seconds * 60;
}
 

void game::run() {
    int optionMenu;
    bool optionInRange;

    do {
        game::mainMenu();
        std::cin >> optionMenu;
        system("cls");
        optionInRange = (optionMenu > 0 && optionMenu < 4);
        bool evaluation;
        std::string userInput;
        double wpm;
        std::string challengeText;

        switch (optionMenu) {
            case 1: {
                std::pair<std::string, double> result = game::runLevel(userInput);
                challengeText = result.first;
                wpm = result.second;
                evaluation = game::evaluate(userInput, challengeText);
                game::result(evaluation, wpm);
                std::cin.ignore();
                break;
            }
            case 2:
                game::showInstructions();
                break;
            case 3:
                game::setLanguage();
                break;
        }
    } while (optionInRange);
}
