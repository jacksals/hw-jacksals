#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
		   const string* team2,
		   int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;
}

// You may add additional functions here
void create_teams(string* arr_names, string* team1, string* team2, int num_players, int p_count1, int p_count2, int player)
{


	if(p_count1 == num_players/2 && p_count2 == num_players/2)
	{
		printSolution(team1, team2, num_players/2);
	}

	else
	{
		if(p_count1 < num_players/2)
		{
			team1[p_count1] = arr_names[player];
			create_teams(arr_names, team1, team2, num_players, p_count1 + 1, p_count2, player + 1);
		}
		if(p_count2 < num_players/2) 
		{
			team2[p_count2] = arr_names[player];				
			create_teams(arr_names, team1, team2, num_players, p_count1, p_count2 + 1, player + 1);
		}
		
		//put "*" in front of team1?
		
		
	}
}


int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }
  // Complete the rest of main
  ifstream infile(argv[1]);
  if(infile.fail())
  {
  	cerr << "Error" << endl;
  }
  int num_players;
  string* arr_names = NULL;
  infile >> num_players;
  if(infile.fail())
  {
  	cerr << "Error" << endl;
  }
  arr_names = new string[num_players];
  string* team1 = new string[num_players/2];
  string* team2 = new string[num_players/2];
  string name;
  int player_count = 0;
  while(infile >> arr_names[player_count]) 
  {
  	if(player_count > num_players)
  	{
  		//error file has wrong num players
  		printSolution(team1, team2, num_players/2);
  		delete [] team1;
 	    delete [] team2;
 	    delete [] arr_names;
  		return 1;
  	}
  	player_count++;
  }
  if(player_count < num_players)
  {
  	//error file wrong num players
  	printSolution(team1, team2, num_players/2);
  	delete [] team1;
  	delete [] team2;
  	delete [] arr_names;
  	return 1;
  }
  

  create_teams(arr_names, team1, team2, num_players, 0, 0, 0);
  delete [] team1;
  delete [] team2;
  delete [] arr_names;
  return 0;
}
