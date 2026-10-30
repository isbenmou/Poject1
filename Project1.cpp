#include <iostream>
#include <cstdlib>

using namespace std;

enum enChoice{Stone=1, Paper=2, Scissors=3};

enum enResult{Player1, Player2, Draw};

struct stResultCount
{
    short Player1WinCount;
    short Player2WinCount;
    short DrawCount;
};

struct stRoundInfo
{
    string Player1;
    string Player2;
    enResult Result;
    stResultCount ResultCount;
};

int ReadNumberInRange(string Message, int From, int To)
{

    int Number = 0;

    do
    {

        cout << Message << endl;
        cin >> Number;

    } while (Number < From || Number > To);

    return Number;
}

int RandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;

}

enResult GetRoundWinner(enChoice Player1, enChoice Player2)
{

    if((Player1 == enChoice::Stone && Player2 == enChoice::Scissors) || 
    (Player1 == enChoice::Paper && Player2 == enChoice::Stone) || 
    (Player1 == enChoice::Scissors && Player2 == enChoice::Paper))
    {
        return enResult::Player1;
    }
    else if(Player1 == Player2)
    {
        return enResult::Draw;
    }
    return enResult::Player2;

}

void PlayRound(stRoundInfo &RoundInfo, enChoice Player1, enChoice Player2)
{
    if (Player1 == enChoice::Stone && Player2 == enChoice::Scissors)
    {
        RoundInfo.Player1 = "Stone";
        RoundInfo.Player2 = "Scissors";
        RoundInfo.ResultCount.Player1WinCount++; 
        RoundInfo.Result = enResult::Player1;
    }
    else if(Player1 == enChoice::Paper && Player2 == enChoice::Stone)
    {
        RoundInfo.Player1 = "Paper";
        RoundInfo.Player2 = "Stone";
        RoundInfo.ResultCount.Player1WinCount++;
        RoundInfo.Result = enResult::Player1;
    }
    else if(Player1 == enChoice::Scissors && Player2 == enChoice::Paper)
    {
        RoundInfo.Player1 = "Scissors";
        RoundInfo.Player2 = "Paper";
        RoundInfo.ResultCount.Player1WinCount++;
        RoundInfo.Result = enResult::Player1;
    }
    else if(Player1 == Player2 && Player1 == enChoice::Stone)
    {
        RoundInfo.Player1 = "Stone";
        RoundInfo.Player2 = "Stone";
        RoundInfo.ResultCount.DrawCount++;
        RoundInfo.Result = enResult::Draw;
    }
    else if(Player1 == Player2 && Player1 == enChoice::Paper)
    {
        RoundInfo.Player1 = "Paper";
        RoundInfo.Player2 = "Paper";
        RoundInfo.ResultCount.DrawCount++;
        RoundInfo.Result = enResult::Draw;
    }
    else if(Player1 == Player2 && Player1 == enChoice::Scissors)
    {
        RoundInfo.Player1 = "Scissors";
        RoundInfo.Player1 = "Scissors";
        RoundInfo.ResultCount.DrawCount++;
        RoundInfo.Result = enResult::Draw;
    }
    else if(Player1 == enChoice::Scissors && Player2 == enChoice::Stone)
    {
        RoundInfo.Player1 = "Scissors";
        RoundInfo.Player2 = "Stone";
        RoundInfo.ResultCount.Player2WinCount++;
        RoundInfo.Result = enResult::Player2;
    }
    else if(Player1 == enChoice::Stone && Player2 == enChoice::Paper)
    {
        RoundInfo.Player1 = "Stone";
        RoundInfo.Player2 = "Paper";
        RoundInfo.ResultCount.Player2WinCount++;
        RoundInfo.Result = enResult::Player2; 
    }
    else if(Player1 == enChoice::Paper && Player2 == enChoice::Scissors)
    {
        RoundInfo.Player1 = "Paper";
        RoundInfo.Player2 = "Scissors";
        RoundInfo.ResultCount.Player2WinCount++;
        RoundInfo.Result = enResult::Player2;
    }
}

void ShowRoundInfo(stRoundInfo RoundInfo)
{

    cout << endl;
    cout << "Player1  Choice: " << RoundInfo.Player1 << endl;
    cout << "Computer Choice: " << RoundInfo.Player2 << endl;
    
    if (RoundInfo.Result == enResult::Player1)
    {
        cout << "Round Winner   : [Player]" << endl;
        system("color 2F");
    }
    else if(RoundInfo.Result == enResult::Player2)
    {
        cout << "Round Winner   : [Computer]" << endl;
        system("color E4");
    }
    else
    {
        cout << "Round Winner   : [No Winner]" << endl;
        system("color E0");
    }

    cout << "\n______________________________________________" << endl;

}

void PlayRounds()
{

    stRoundInfo Round;

    short NumberOfRounds = ReadNumberInRange("How Many Rounds 1 To 10 ?", 1, 10);
    cout << endl;

    for(short i = 0; i < NumberOfRounds; i++)
    {
        cout << "Round [" << i + 1 << "] begins:" << endl << endl;
        PlayerRound(Round, 
            ReadNumberInRange("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ", 1, 3), );
    }



}

void StartGame()
{

}

int main()
{

}
