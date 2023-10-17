#include<iostream>
#include<conio.h>
using namespace std;
void TitleScreen();
void Exit();
void WelcomeScreen();
void MainMenu();
void loading()
{
	system("cls");
	char a = 177, b = 219;
	cout << "\n\n\n\t\t\t\t\tLOADING.....";
	cout << "\n\n\n";
	cout << "\t\t\t\t\t ";
	for(int i = 0;i <= 25; i++)
	cout << a;
	Sleep(10);
	cout << "\r";
	cout << "\t\t\t\t\t ";
	for(int i = 0; i <= 25; i++)
	{
	    cout << b;
	    Sleep(20);
	}
}

void delay(unsigned int secs)
{				//Defining delay function for Windows
	clock_t goal = secs +  clock();			//Using clock to set time to delay till
	while(goal > clock());					//Waiting till that time
}

void TitleScreen()
{
	system("cls");
	cout << "\n\n\t\t----------------------------------------------------------------------------------";
	cout << "\n\t\t\t\t                     DS PROJECT         ";
	cout << "\n\t\t----------------------------------------------------------------------------------";
	delay(500);
}
void WelcomeScreen() //function for welcome screen
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t#########################################################################";
	cout << "\n\t\t#\t\t\t\tWELCOME TO\t\t\t\t#";
	cout << "\n\t\t#    BELLMAN-FORD, JOHNSONS, FLOYD WARSHALL SHORTEST PATH ALGORITHMS\t#";
	cout << "\n\t\t#########################################################################";
	cout << "\n\n\n\n\n Press any key to continue......\n";
	getch();
}

void Exit()//function to exit
{
	TitleScreen();
	Beep(1400, 500);
	cout << "\n\n\n\t\t\t\t\t\t EXITING PROGRAM";
	delay(1000);
	exit(1);
}
