# include <iostream>
# include <cstdlib>
# include <string>
# include <ctime>
using namespace std;

enum choice { stone = 1, paper = 2, scissors = 3 };
enum color { red, green, yellow };
enum winner_name { player, computer, draw };

struct round_info
{
	short player_choice;
	short computer_choice;
	winner_name winner;
	string winner_name;
};

struct game_info
{
	short game_rounds_times;
	short player1_won_times;
	short computer_won_times;
	short draw_times;
	winner_name winner;
	string winner_name;
};

string num_tabs(short tabs)
{
	string tab = "";
	for (int i = 1;i <= tabs;i++)
	{
		tab += "\t";
	}
	return tab;
}

int read_num_rounds(string message)
{
	int num;
	cout << message << "\n";
	cin >> num;
	return num;
}

int random_choice(int from, int to)
{
	int random_num = rand() % (to - from + 1) + from;
	return random_num;
}

short show_round(int num)
{
	short choice = 0;

	cout << "Round [" << num << "]" << "begins:\n";
	cout << "Your choice: [1]:stone, [2]:paper, [3]:scissors ?\n";
	cin >> choice;

	return choice;

}

string choice_result(int num)
{
	switch (num)
	{
	case 1:
		return "Stone";
		break;
	case 2:
		return "paper";
		break;
	case 3:
		return "Scissors";
	}
}

void print_color(color colour)
{
	switch (colour)
	{
	case red:
		system("color 04");
		cout << "\a";
		break;
	case green:
		system("color 02");
		break;
	case yellow:
		system("color E0");

	}
}

string winner_name_string( winner_name enwinner)
{
	string array [3]= {"player","computer","draw" };
	return array[(int) enwinner];
}

winner_name who_win_round(int player_choice, int computer_choice, short& num_win_player, short& num_win_comp, short& draw_times)
{

	if (player_choice == computer_choice)
	{
		print_color(yellow);
		draw_times++;
		return draw;

	}

	switch ((choice)computer_choice)
	{
	case stone:
		if ((choice)player_choice == scissors)
		{
			print_color(red);
			num_win_comp++;
			return computer;


		}

		break;

	case paper:
		if ((choice)player_choice == stone)
		{
			print_color(red);
			num_win_comp++;
			return computer;
		}

		break; 

	case scissors:
		if ((choice)player_choice == paper)
		{
			print_color(red);
			num_win_comp++;
			return computer;

		}
	


	}

	num_win_player++;
	print_color(green);
	return player;

}

winner_name final_winner(int num_plar, int num_comp)
{
	if (num_plar == num_comp)
	{
		print_color(yellow);
	return draw;


	}

	else if (num_plar > num_comp)
	{
		print_color(green);
		return player;
	}
	else

	{
		print_color(red);
		return computer;
	}
}

game_info read_game_info(short num_win_play, short num_computer_play,short draw,int num_rounds)
{
	game_info info;
	info.player1_won_times = num_win_play;
	info.computer_won_times = num_computer_play;
	info.draw_times = draw;
	info.winner = final_winner(num_win_play, num_computer_play);
	info.winner_name = winner_name_string(info.winner);
	info.game_rounds_times = num_rounds;

	return info;




}

game_info read_rounds_info(int num_rounds)
{
	round_info info;

	short num_win_player = 0;
	short num_win_comp = 0;
	short draw_time = 0;


	for (int i = 1; i <= num_rounds; i++)
	{
		info.player_choice = show_round(i);

		info.computer_choice = random_choice(1, 3);

		info.winner =  who_win_round(info.player_choice, info.computer_choice, num_win_player, num_win_comp, draw_time);

		info.winner_name = winner_name_string(info.winner);

		

		cout << "_______________________________Round [" << i << "]_______________________________________________ \n\n";

		cout << "Player1  choice: " << choice_result(info.player_choice) << "\n";
		cout << "Computer choice: " << choice_result(info.computer_choice) << "\n";
		cout << "Winner         : " << info.winner_name << "\n";

	}


	return read_game_info(num_win_player, num_win_comp, draw_time,num_rounds);
	


	


}


void show_game_over()
{
		
		cout <<num_tabs(4)<<"_________________________________________________________________________\n";
		cout << num_tabs(8)<<"++++Game Over+++\n";
		cout << num_tabs(4)<<"___________________________________________________________________________\n\n";
		cout << num_tabs(4)<<"______________________________ [Game Results]_____________________________\n\n";

}

void print_final_result()

{
	bool again;
	do
	{
		system("cls");
		system("color 0F");
		int game_rounds = read_num_rounds("Please enter number of rounds??\n");



		game_info stinfo=read_rounds_info(game_rounds);

		

		show_game_over();

		cout << "Game Rounds       : " << stinfo.game_rounds_times << "\n";
		cout << "Player1 won times : " << stinfo.player1_won_times << "\n";
		cout << "Computer win times: " << stinfo.computer_won_times << "\n";
		cout << "Draw Times        :" << stinfo.draw_times << "\n";
		cout << "Final Wineer      :" << stinfo.winner_name << "\n";



		cout << "Do you want to play again\n";
		cin >> again;

	} while (again == 1);
}




int main()
{
	srand((unsigned)time(NULL));

	print_final_result();

}