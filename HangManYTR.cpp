#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>





int main(){

    char start;

    std:: system("CLS"); //really shouldn't use this

    std::cout<< " Hangman  " << std::endl;
    std::cout<< "By Andrew Nguyen(In Association with Two Neurons)" << std::endl;
    std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |       o    " << std::endl;
    std::cout <<" |       |    " << std::endl;
    std::cout <<" |     / | \\   " << std::endl;
    std::cout <<" |    /  |  \\  " << std::endl;
    std::cout <<" |      / \\    " << std::endl;
    std::cout <<" |     /   \\  " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<"_____________   " << std::endl;
    std::cout <<" \nYou Can Press Any Key (and enter) To Start\n ";

    std::cin >> start;

    //CLEAR SCREEN
    std:: system("CLS");

//GAME
//This sets the variables that will be used for the entire course of the game
int userAttempts(6); //The # of attempts the user has to correctly guess the answer
bool CorrectGuess = false;

char Guess; //the letter guesssed

char PreviousGuesses[7]; //this is an array of guesses, needs to be 1 longer than the user can guess 
PreviousGuesses[0] = '\0';

for(int i = 0; i < 6; i++)
{
    PreviousGuesses[i] = '-';
}
PreviousGuesses[6] = '\0';

std::string Word; //This stores the word player has to guess
std:: string wordList[99]; //this is a string array to store 100 strings
srand(time(NULL)); //This makes a random seed that is used to get random word from array above

//Generates random word
std:: ifstream RandomWord; //This file stream (reads in the varaible)
RandomWord.open("Words.txt"); //reads in the word file (list of words)

for(int i = 0; i < 99; i++)
{
RandomWord >> wordList[i]; //this is what fills the array with words from the list we have
//std:: cout << wordList[i] << std::endl; //(THIS IS FOR TESTING ATTEMPTS)

}

int RandomNumber = rand() % 100; //this returns a random number between 0 and 99
Word = wordList[RandomNumber];

//std::cout << Word << std::endl; //(TESTING ATTEMPTS ONLY) or could be to cheat

RandomWord.close();

//Make a word a mystery 
std:: string MysteryWord(Word.length(), '*'); //replaces each letter of the word with an '*' and stores it in MysteryWord
//std:: cout << MysteryWord << std::endl; //Tests the word (though we will use this later on)




    while(userAttempts >= 0)
    //Display information related to the word for the player
    {

//reset bool value
CorrectGuess = false;

          std:: cout << "The word you must guess is: \n\n ";
          std::cout << MysteryWord << std::endl;
          std::cout << "\nThere are " << MysteryWord.length() << " letters in the given word\n\n";
          std::cout << "You have " << userAttempts << " guesses left\n";
          if(PreviousGuesses[0] == '\0')
          {
              std::cout << std::endl;
          }
          else 
          {
              std:: cout << "Letters that you have guessed: " << PreviousGuesses << std::endl;
          }

          //get player guess
          std::cout << "\n\nGuess a letter: ";
          std::cin >> Guess;

          //Check whehter or not guess is correct?
          for(int i = 0; i < MysteryWord.length(); i++) //for the length of the word (using mystery) do the following
          {
              if(Word[i] == Guess) //this checks if the word(actual) has guess in it
                {
                    MysteryWord[i] = Guess; //the guess is then stored into index of MyseryWord
                    // std::cout << "Good job!! " << Guess << " is one of the letters!" << std::endl;
                    CorrectGuess = true;

                }
          }
          if(Word == MysteryWord)
          {
              std::cout << "\n\nCongrats!!! You guessed the word correctly!!!! :))) : " << MysteryWord << std::endl;
              break;
          }
          if(CorrectGuess == false)
          {
              userAttempts--;
              std::cout<<"Sorry,  " << Guess << " is not part of the word in the list" << std::endl;
          }
          else 
          {
 std::cout << "Good job!! " << Guess << " is one of the letters!" << std::endl;
          }

        switch(userAttempts)
        {
        case 6:
        {
     std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<"_____________   " << std::endl;
   // userAttempts--;
            break;

        }
        case 5:
        {
    std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |       o    " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<"_____________   " << std::endl;
   // userAttempts--;
   if(CorrectGuess == false)
   {
       PreviousGuesses[0] = Guess;

   }
            break;
        }
        case 4:
        {
    std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |       o    " << std::endl;
    std::cout <<" |       |    " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<"_____________   " << std::endl;
    //userAttempts--;
    if(CorrectGuess == false)
   {
       PreviousGuesses[1] = Guess;
       
   }
            break;
        }
        case 3:
        {
     std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |       o    " << std::endl;
    std::cout <<" |       |    " << std::endl;
    std::cout <<" |     / |    " << std::endl;
    std::cout <<" |    /  |    " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<"_____________   " << std::endl;
   // userAttempts--;
   if(CorrectGuess == false)
   {
       PreviousGuesses[2] = Guess;
       
   }
            break;
        }
        case 2:
        {
    std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |       o    " << std::endl;
    std::cout <<" |       |    " << std::endl;
    std::cout <<" |     / | \\   " << std::endl;
    std::cout <<" |    /  |  \\  " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<" |            " << std::endl;
    std::cout <<"_____________   " << std::endl;
   // userAttempts--;
   if(CorrectGuess == false)
   {
       PreviousGuesses[3] = Guess;
       
   }
            break;
        }
        case 1:
        {
     std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |       o    " << std::endl;
    std::cout <<" |       |    " << std::endl;
    std::cout <<" |     / | \\   " << std::endl;
    std::cout <<" |    /  |  \\  " << std::endl;
    std::cout <<" |      /     " << std::endl;
    std::cout <<" |     /     " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<"_____________   " << std::endl;
    if(CorrectGuess == false)
   {
       PreviousGuesses[4] = Guess;
       
   }
   // userAttempts--;
            break;
        }
        case 0:
        {
     std::cout <<"_____________   " << std::endl;
    std::cout <<" |       }    " << std::endl;
    std::cout <<" |       o    " << std::endl;
    std::cout <<" |       |    " << std::endl;
    std::cout <<" |     / | \\   " << std::endl;
    std::cout <<" |    /  |  \\  " << std::endl;
    std::cout <<" |      / \\    " << std::endl;
    std::cout <<" |     /   \\  " << std::endl;
    std::cout <<" |           " << std::endl;
    std::cout <<"_____________   " << std::endl;
    std::cout <<" \nHAHAHAAHAHAHAAHAH Game Over HEHEEHEHEH :)))))) " << std::endl;;
    std::cout <<" \nThe correct word was:  "  << Word << std::endl;;
    userAttempts=-1;
     break;

        }
        default:
        std :: cout << "There is an error(there must be), that's why this line is active.";
        }
        
    }
    return 0;
}

