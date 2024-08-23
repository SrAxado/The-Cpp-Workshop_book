#include <iostream>
#include <cstdlib>
#include <ctime>

int askQuestion(std::string question) {
  std::string input = "";

  std::cout << question << ": ";
  getline(std::cin, input);
  
  return std::stoi(input);
}

void guessesRemaining(int& numGuesses) {
  --numGuesses;
  if (numGuesses > 0) 
    std::cout << "You have " << numGuesses << " guesses remaining\n";
  else
    std::cout << "Last guess\n";
}


int main() {
  // std::string input = "";
  int numGuesses = 0;
  int minNum = 0;
  int maxNum = 0;
  int guess = 0;
  int randomNum = 0;

  std::srand((unsigned) time(0));
  
  do {
    std::cout << "\n\n\n***Number guessing game***\n\n";
    // std::cout << "Enter the number of guesses: ";
    // getline(std::cin, input);
    // numGuesses = std::stoi(input);
    numGuesses = askQuestion("Enter the number of guesses");

    // std::cout << "Enter the minimum number: ";
    // getline(std::cin, input);
    // minNum = std::stoi(input);
    minNum = askQuestion("Enter the minimum number (bigger than 0)");
    

    // std::cout << "Enter the maximum number: ";
    // getline(std::cin, input);
    // maxNum = std::stoi(input);
    maxNum = askQuestion("Enter the maximum number");
    std::cout << std::endl;

    do {
      // std::cout << "Enter your guess: ";
      // getline(std::cin, input);
      // num = std::stoi(input);
      guess = askQuestion("Enter your guess");

      if (guess == 0) {
        std::cout << "Exiting\n";
        break;
      }

      randomNum = rand() % (maxNum - minNum) + minNum;

      if (randomNum < guess) {
        std::cout << "[ " << randomNum << " ] Your guess was too low.\n";
        guessesRemaining(numGuesses);

      } else if (randomNum > guess) {
        std::cout << "[ " << randomNum << " ] Your guess was too high.\n";
        guessesRemaining(numGuesses);

      } else if (randomNum == guess) {
        std::cout << "Well done, you guessed the number!\n\n";
        break;
      }

    } while (numGuesses > 1);


    if (guess == 0) {
      break;
    } else {
      guess = askQuestion("\nEnter 0 to exit, or any number to play again");
    }

  } while (guess != 0);


  return 0;
}