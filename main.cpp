#include <iostream>
#include <cstdlib>

struct Game {
	class Games {
	public:
		struct Settings {
			int HardnessLevel;
		};
		Settings GameSettings;

		void StartGame() {
			std::cout << "Game Started!" << std::endl;
			std::cout << "Choose Your Hardness Level (1-20) : ";
			std::cin >> GameSettings.HardnessLevel;
			if (GameSettings.HardnessLevel < 1 || GameSettings.HardnessLevel > 20) {
				std::cout << "[ERROR] Please input hardness level in 1-20 range." << std::endl;
				return;
			}

			srand(time(0));
			GuessAnswer = rand() % (BaseGuessNumber*GameSettings.HardnessLevel) + 1;
			std::cout << "Game Setup Done! Now Guess the number between 0 - " << BaseGuessNumber * GameSettings.HardnessLevel << std::endl;
			std::cout << "Guess : ";
			std::cin >> UserGuessInput;
			if (UserGuessInput < 0 || UserGuessInput > BaseGuessNumber * GameSettings.HardnessLevel) {
				std::cout << "[ERROR] Please guess number between 0 - " << BaseGuessNumber * GameSettings.HardnessLevel << " Only!" << std::endl;
				return;
			}

			if (UserGuessInput == GuessAnswer) {
				std::cout << "Congratulations!! You Win!!" << std::endl;
				std::cout << "Correct Answer: " << GuessAnswer << std::endl;
				std::cout << "Nice guessing! Well played!" << std::endl;
				return;
			}
			else {
				std::cout << "Incorrect guess Try again!" << std::endl;
				std::cout << "Answer Is: " << GuessAnswer << std::endl;
				return;
			}
		};
	private:
		int UserGuessInput;
		int BaseGuessNumber = 20;
		int GuessAnswer;
	};
	Games Games;
};


int main()
{
	Game mGame;
	mGame.Games.StartGame();
	system("pause >nul");
}
