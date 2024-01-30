#include<iostream>
#include<cstdlib>
#include<time.h>

bool playerTurn(int compSecret, bool isWinner)
{
  int guess;
  std::cout<<"Enter your guess = ";
  std::cin>>guess;
  if(guess > compSecret)
  {
    std::cout<<"Your guess is to high\n";
    isWinner = false;
  }
  else if(guess < compSecret)
  {
    std::cout<<"Your guess is too low\n";
    isWinner = false;
  }
  else
  {
    std::cout<<"Congratulations you won";
    isWinner = true;
  }
  return isWinner;
}

void computerTurn(int playerSecret, int compSecret)
{
  bool isWinner;
  int low = 0;
  int high = 100;
  do
  {
    int guess = (low + high)/2;
    std::cout<<"Computer's guess = "<<guess<<"\n";
    if(guess == playerSecret)
    {
      std::cout<<"Computer Won !\n"
               <<"Sorry you lost\n"
               <<"Computer's guess was "<<compSecret<<"\n";
      isWinner = true;
    }
    else
    {
      if(guess > playerSecret)
      {
        std::cout<<"Guess is too high\n";
        high = guess - 1;
      }
      else if(guess < playerSecret)
      {
        std::cout<<"Guess is too low\n";
        low = guess + 1;
      }
      isWinner = playerTurn(compSecret, isWinner);
    }
  } while (isWinner == false);
}



int main()
{
  char ch;
  do
  {
    srand(time(0));
    int playerSecret;
    int compSecret = rand()%100;
    std::cout<<"Enter your secret number between 0 and 100 = ";
    std::cin>>playerSecret;
    computerTurn(playerSecret, compSecret);
    std::cout<<"Enter 'Y' to play again :- ";
    std::cin>>ch;
  } while (ch=='y' || ch=='Y');
}