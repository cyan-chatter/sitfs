#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

using namespace std;
bool gameOver;
char pName[100];
char starter = 's';
int difficulty = 3;
const int width = 20;
const int height = 20;
int x,y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};

eDirection dir;

void Setup(){
	gameOver = false;
	dir = STOP;
	x= width/2;
	y= height/2;
	fruitX = rand()%(width-1);
	fruitY = rand()%height;
	score = 0;
	cout<<endl<<"--------/--/--/--/--/--[ SNAKE IN THE FLUTTERING SHADOW ]--/--/--/--/--/--------"<<endl;
	cout<<"Controls in the match:\nW: UP\nS: DOWN\nA: LEFT\nD: RIGHT\nX: QUIT\n";
	cout<<"\nNote: This is not a game which will go easy on eyes. You wanna win? You gotta fight for it.\n The Rules are absolutely No Brainer.\n  In the Simple mode, You touch yourself and you die!\n  In the Box mode, touching the Borders will also kill you.\nI WISH YOU SUCCESS\n\n";
	cout<<"\nEnter Player Name\n";
	gets(pName);
	cout<<"\n\n Enter  S  to Play Simple Mode and Enter  B  to play Box Mode\n\n Score above 500 to earn a Title of Honour\n"<<endl;
	cout<<endl;
	cin>>starter;
}
void Draw(){
	system("cls");
	for(int j=0; j<=width; j++)
	cout<<"#";
	cout<<endl;
	
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(j == 0 || j == width - 1)
			cout<<"#";
			if(i == y && j == x)
			cout<<"O";
			else if(i == fruitY && j== fruitX)
			cout<<"F";
			else{
				bool print = false;
			for(int k=0; k<nTail; k++){
				
				if(tailX[k] == j && tailY[k] == i){
					cout<<"o";
					print = true;
				}
				
			}
			if(!print){
					cout<<" ";
				}
				
			}
			
		}
	
	cout<<endl;	
	}
	
	for(int j=0; j<=width; j++)
	cout<<"#";
	
	cout<<endl;
	cout<< "Score: "<< score <<endl;
		
}
void Input(){
	if(_kbhit()){
		switch (_getch()){
			case 'a': 
					dir = LEFT; break;
			case 'A': 
					dir = LEFT; break;
					
			case 'd':
					dir = RIGHT; break;
			case 'D': 
					dir = RIGHT; break;
						
			case 'w': 
					dir = UP; break;
			case 'W': 
					dir = UP; break;
					
			case 's':
					dir = DOWN; break;
			case 'S': 
					dir = DOWN; break;
					
			case 'x': 
					gameOver = true; break;
			case 'X': 
					gameOver = true; break;
											
		} 
	}	
}

mod1(){
	if(x >= (width-1) || x < 0 || y >= height || y < 0)
		gameOver = true;
}	

mod2(){
	if(x>=(width-1)) x=0; 
	else if(x<0) x = width-2;
	if(y>=height) y=0; 
	else if(y<0) y = height-1;
}

void Logic(){
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	
	tailX[0]=x; tailY[0]=y;
	for(int i=1; i < nTail; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		
	}
	
	switch(dir){
		case LEFT: x--;
			break;
		case RIGHT: x++;
			break;
		case UP: y--;
			break;
		case DOWN: y++;
			break;
		default:
			break;				
	}

 if(starter == 'S' || starter == 's')	
	mod2();
 else if(starter == 'B' || starter == 'b')	
	mod1();
	else mod2();

		
		for(int i=0; i<nTail; i++){
			if(tailX[i] == x && tailY[i] == y)
			gameOver = true;
		}
		
	if(x == fruitX && y == fruitY){
		score += 10;
		nTail++;
	fruitX = rand()%(width-1);
	fruitY = rand()%height;
	 
	}	
}

int main(){
	Setup();
	
		cout<<"\nSet Difficulty: \nBeginner: 1\nAmateur: 2\nRegular: 3\nHard: 4\nExpert: 5\nInsane: 6\n";
		cin>>difficulty;
		system("cls");
		
		while(!gameOver){
		Draw();
		Input();
		Logic();
		switch(difficulty){
			case 1: Sleep(50); break;
			case 2: Sleep(40); break;
			case 3: Sleep(30); break;
			case 4: Sleep(20); break;
			case 5: Sleep(10); break;
			case 6: Sleep(1); break;
			default: Sleep(30); break;
						
		
	
		}	
	}
	cout<<"\n\nFinal Score of  ";
	puts(pName);
	cout<<"  is  "<<score<<"\n\n";
	
	if(difficulty<=3){
		if(score<150) cout<<"I hate to say this but.. You totally suck at this.";
		if(score>=150 && score<250) cout<<"Hey, I know you can do better. Keep trying.";
		if(score>=250 && score<400) cout<<"Hey, I gotta admit You aren't as bad as I thought you would be.";
		if(score>=400 && score<=500) cout<<"I gotta give it to you Great Job";
		if(score>500){
		cout<<"Damn! You are totally made for this. You Rock!\n\n";
		cout<<pName<<" , you are hereby acknowledged as THE CONTENDER \n";
			}
		} 
	
  if(difficulty>=4 && difficulty<=5){
		if(score<150) cout<<"I hate to say this but.. You totally suck at this.";
		if(score>=150 && score<250) cout<<"Hey, I know you can do better than that. Keep trying!";
		if(score>=250 && score<300) cout<<"Not bad!";
		if(score>=300 && score<350) cout<<"Good job! That was a solid run.";
		if(score>=350 && score<450) cout<<"Wow! You are totally made for this. You Rock!";
		if(score>=450 && score<=500) cout<<"Damn! Are you my Ciggerate? because You are on Fire!";
		if(score>500){
		cout<<"Some say Legends are born. Some say they are made. Which one are you?";
		cout<<pName<<" , you are hereby acknowledged as THE LEGEND \n";
			} 
	}
  if(difficulty == 6){
  	if(score<120) cout<<"I hate to say this but.. You totally suck at this.";
		if(score>=120 && score<180) cout<<"Hey, I know you can do better than that. Keep trying!";
		if(score>=180 && score<250) cout<<"I see you have a prespective. Not bad!";
		if(score>=250 && score<300) cout<<"Good job! That was a solid run.";
		if(score>=300 && score<380) cout<<"Why don't you consider playing this as a profession? Because believe me! You are good.";
		if(score>=380 && score<460) cout<<"Damn! Are you my Ciggerate? because You are on Fire!";
		if(score>=460 && score<=500) cout<<"I admit it was a treat to watch you play! Can't wait to see you again!";
		if(score>500){
		cout<<cout<<"I can't comprehend you! Because You are speaking the language of Gods!";
		cout<<pName<<" , you are hereby acknowledged as THE GOD \n";
			} 
	}
	Sleep(5000);		
	return 0;
}
