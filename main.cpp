#include <iostream>
#include <ctime>

#include <queue> // queue
#include <utility> // pair

using namespace std;

class Punkt{
	private:
		int x;
		int y;
		int type;
		
		void randPoint();
	public:
		void checkPoint();
		
		// konstruktor
		Punkt(){
			randPoint();
		}
		
		Punkt(int _x, int _y, int _t);
};

const int sizeX = 10, sizeY = 10;
int playerX = 0, playerY = 0;
int pointCount = 2;
int score = 2;
vector<vector<char>> board;
queue<pair<int, int>> tail; // first - X, second - Y
vector<Punkt> point;

void draw(){
	for(int y = 0; y < sizeY; y++){
		for(int x = 0; x < sizeX; x++){
			cout << board[x][y];
		}
		cout << '\n';
	}
	cout << "Points: " << static_cast<unsigned>(score - 2) << "\n";
}

void Punkt::randPoint(){
	do{
		x = rand() % sizeX;
		y = rand() % sizeY;
	} while(board[x][y] != '.');
	type = rand() % 4;
	if(type == 0)
		type = -2;
	if(type == -2)
		board[x][y] = '-';
	else
		board[x][y] = '0' + type;
}

void Punkt::checkPoint(){
	if(playerX == x && playerY == y){
		score += type;
		randPoint();
	}
}

Punkt::Punkt(int _x, int _y, int _t) : x(_x), y(_y), type(_t){
	if(type == -2)
		board[x][y] = '-';
	else
		board[x][y] = '0' + type;
}

int main(){
	srand(time(NULL));
	
	board.resize(sizeX, vector<char>(sizeY, '.'));
	board[playerX][playerY] = '@';
	
	point.resize(pointCount);
	
	draw();
	while(true){
		// wejście, akcje wykonane przez gracza
		char in;
		cin >> in;
		
		// interpretacja akcji/wejścia
		int newX = 0, newY = 0;
		if(in == 'w' && playerY != 0)
			newY = -1;
		else if(in == 'a' && playerX != 0)
			newX = -1;
		else if(in == 's' && playerY != sizeY - 1)
			newY = 1;
		else if(in == 'd' && playerX != sizeX - 1)
			newX = 1;
		else if(in == 'e')
			break;
		
		// update stanu świata
		if(board[playerX + newX][playerY + newY] != '#' && board[playerX + newX][playerY + newY] != '@'){
			tail.push({playerX, playerY});
			board[playerX][playerY] = '#';
			playerX += newX;
			playerY += newY;
			board[playerX][playerY] = '@';
			
			for(Punkt& p : point) // przechodzi się po wszystkich elementach point i każdy z tych elementów (po kolei) zamienia się na p
				p.checkPoint();
			
			while(tail.size() > score){
				board[tail.front().first][tail.front().second] = '.';
				tail.pop();
			}
		}
		// wyświetlenie aktualnego stanu świata
		draw();
	}
}

/*
 * ........
 * ..@.....
 * ........
 * ........
 *
 */
