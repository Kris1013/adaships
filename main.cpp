#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Ship{
  private:
    char direction;
    int length;
    int hitp;
    vector<int> boatcol;
    vector<int> boatrow;
    string name;

  public:
    Ship(char dir, int len, vector<int>row, vector<int>col, int hit, string title){
        direction=dir;
        length=len;
        boatrow=row;
        boatcol=col;
        hitp=hit;
        name=title;
    }

    string getShip(int col, int row){
      for(int i=0; i<length; i++){
        if((boatcol[i]==col)&&(boatrow[i]==row)){
          return name;
        }
      }
      return "";
    }

    void setHitp(){
      hitp++;
    }

    int shipCheck(int ShipSize){
      if(hitp>=ShipSize){
        return 7;
      }else{
        return 0;
      }
    }

    void boatPlace(){
      cout << "Placement of boat "<< name << endl;
      for(int i=0; i<length; i++){
        cout << "Square ["<< boatrow[i]<< "]["<<boatcol[i]<<"]" << endl;
      }
    }
};

enum ShipSize {Submarine = 2, Destroyer = 3, Battleship = 4, Carrier = 5};
void initBoard(int board[][10]);
void boardDisplay(int board[][10]);
void gameBoardDisplay(int board[][10]);
void editBoard(int board[][10], int col, int row, int ShipSize, char dir); 
void editShip(int board[][10], int col, int row, int ShipSize, char dir, vector<Ship> &shipLineup, int name);
bool setShip(int board[][10], int ShipSize, vector<Ship> &shipLineup, int name);
char getDir(int dir);
int resetRowAndCol(int col, int &row, int ShipSize, char dir);
int spaceCheck(int board[][10], int col, int row, int size, char dir);
int playGame(int board[][10], vector<Ship> &shipLineup);
int getArea(int board[][10], int col, int row);

int main() {
  char start;
  int board[10][10];
  vector<Ship> shipLineup;
  initBoard(board);

  setShip(board, Carrier, shipLineup, 1);
  setShip(board, Battleship, shipLineup, 2);
  setShip(board, Battleship, shipLineup, 3);
  setShip(board, Destroyer, shipLineup, 4);
  setShip(board, Destroyer, shipLineup, 5);
  setShip(board, Destroyer, shipLineup, 6);
  setShip(board, Submarine, shipLineup, 7);
  setShip(board, Submarine, shipLineup, 8);
  setShip(board, Submarine, shipLineup, 9);
  setShip(board, Submarine, shipLineup, 10);

  cout << "Battleships. Press X to start"<< endl;
  cout << "8 will displayed on a hit and 7 for a miss"<< endl;
  cout << "Press X to play"<< endl;
  cin >> start;
  if(start=='x') {
    playGame(board,shipLineup);
  }
  return 0;
}

void initBoard(int board[][10]){
  for(int col=0; col<10; col++){
    for(int row=0; row<10; row++){
      board[col][row]=0;
    }
  }
}

void boardDisplay(int board[][10]){
  cout<<"   0|1|2|3|4|5|6|7|8|9"<<endl;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(j==0){
        cout<< i<< "   ";
      }
      cout<<board[i][j];
      if (j!=9){
        cout<<"|";
      }
    }
    cout<<endl;
  }
  cout<<endl;
}

void gameBoardDisplay(int board[][10]){
  cout<<"   0|1|2|3|4|5|6|7|8|9"<<endl;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(j==0){
        cout<< i<< "   ";
      }
      if(board[i][j]==8){
        cout<<8;
      } else if(board[i][j]==7){
        cout<<7;
      }else{
        cout<<0;
      }      
      if (j!=9){
        cout<<"|";
      }
    }
    cout<<endl;
  }
  cout<<endl;
}

void editBoard(int board[][10], int col, int row, int ShipSize, char dir){
  if (dir=='h'){
    for(int i=0;i<ShipSize;i++){
      board[row][col]=ShipSize;
      col++;
      cout<<endl;
    }
  } else if (dir=='v'){
    for(int i=0;i<ShipSize;i++){
      board[row][col]=ShipSize;
      row++;
      cout<<endl;
    }
  }else {cout<< "No direction"<<endl;}
    
}

void editShip(int board[][10], int col, int row, int ShipSize, char dir, vector<Ship> &shipLineup, int name){
  switch(name){
    case 1:
      if(dir=='h'){
        vector<int> row1 (5);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (5);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship carrierShip('h', 5, row1, col1, 0, "Carrier");
        shipLineup.push_back(carrierShip);
      }else if(dir=='v'){
        vector<int> row1 (5);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (5);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship carrierShip('v', 5, row1, col1, 0, "Carrier");
        shipLineup.push_back(carrierShip);
      }
    break;
  case 2:
      if(dir=='h'){
        vector<int> row1 (4);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (4);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship battleShip1('h', 4, row1, col1, 0, "Battleship1");
        shipLineup.push_back(battleShip1);
      }else if(dir=='v'){
        vector<int> row1 (4);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (4);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship battleShip1('v', 4, row1, col1, 0, "Battleship1");
        shipLineup.push_back(battleShip1);
      }
    break;
  case 3:
      if(dir=='h'){
        vector<int> row1 (4);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (4);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship battleShip2('h', 4, row1, col1, 0, "Battleship2");
        shipLineup.push_back(battleShip2);
      }else if(dir=='v'){
        vector<int> row1 (4);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (4);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship battleShip2('v', 4, row1, col1, 0, "Battleship2");
        shipLineup.push_back(battleShip2);
      }
    break;
  case 4:
      if(dir=='h'){
        vector<int> row1 (3);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (3);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship destShip1('h', 3, row1, col1, 0, "Destroyer1");
        shipLineup.push_back(destShip1);
      }else if(dir=='v'){
        vector<int> row1 (3);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (3);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship destShip1('v', 3, row1, col1, 0, "Destroyer1");
        shipLineup.push_back(destShip1);
      }
    break;
  case 5:
      if(dir=='h'){
        vector<int> row1 (3);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (3);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship destShip2('h', 3, row1, col1, 0, "Destroyer2");
        shipLineup.push_back(destShip2);
      }else if(dir=='v'){
        vector<int> row1 (3);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (3);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship destShip2('v', 3, row1, col1, 0, "Destroyer2");
        shipLineup.push_back(destShip2);
      }
    break;
  case 6:
      if(dir=='h'){
        vector<int> row1 (3);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (3);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship destShip3('h', 3, row1, col1, 0, "Destroyer3");
        shipLineup.push_back(destShip3);
      }else if(dir=='v'){
        vector<int> row1 (3);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (3);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship destShip3('v', 3, row1, col1, 0, "Destroyer3");
        shipLineup.push_back(destShip3);
      }
    break;
  case 7:
      if(dir=='h'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship subShip1('h', 2, row1, col1, 0, "Submarine1");
        shipLineup.push_back(subShip1);
      }else if(dir=='v'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship subShip1('v', 2, row1, col1, 0, "Submarine1");
        shipLineup.push_back(subShip1);
      }
    break;
  case 8:
      if(dir=='h'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship subShip2('h', 2, row1, col1, 0, "Submarine2");
        shipLineup.push_back(subShip2);
      }else if(dir=='v'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship subShip2('v', 2, row1, col1, 0, "Submarine2");
        shipLineup.push_back(subShip2);
      }
    break;
  case 9:
      if(dir=='h'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship subShip3('h', 2, row1, col1, 0, "Submarine3");
        shipLineup.push_back(subShip3);
      }else if(dir=='v'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship subShip3('v', 2, row1, col1, 0, "Submarine3");
        shipLineup.push_back(subShip3);
      }
    break;
  case 10:
      if(dir=='h'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
          col++;
        }
        Ship subShip4('h', 2, row1, col1, 0, "Submarine4");
        shipLineup.push_back(subShip4);
      }else if(dir=='v'){
        vector<int> row1 (2);
        for(int i=0;i<row1.size();++i){
          row1.at(i)=row;
          row++;
        }
        vector<int> col1 (2);
        for(int i=0;i<col1.size();++i){
          col1.at(i)=col;
        }
        Ship subShip4('v', 2, row1, col1, 0, "Submarine4");
        shipLineup.push_back(subShip4);
      }
    break;
  }
}

bool setShip(int board[][10], int ShipSize, vector<Ship> &shipLineup, int name){
  srand(time(0));
  int row=0;
  int col=0;
  int sCheck=0;
  char dir='v';
  bool placeFail=true;

  dir=getDir(rand()%10);
  col=resetRowAndCol(col, row, ShipSize, dir);
  while(placeFail){
    if(dir=='h'){
      sCheck=spaceCheck(board, col, row, ShipSize, dir);
      if(sCheck==1){
        dir=getDir(rand()%10);
        col=resetRowAndCol(col, row, ShipSize, dir);
        sCheck==0;
        continue;
      }
      editBoard(board, col, row, ShipSize, dir);
      editShip(board, col, row, ShipSize, dir, shipLineup, name);
      return 0;
    } else if (dir=='v'){
      sCheck=spaceCheck(board, col, row, ShipSize, dir);
      if(sCheck==1){
        dir=getDir(rand()%10);
        col=resetRowAndCol(col, row, ShipSize, dir);
        sCheck==0;
        continue;
      }
      editBoard(board, col, row, ShipSize, dir);
      editShip(board, col, row, ShipSize, dir, shipLineup, name);
      return 0;
    }   
  }
}

char getDir(int dir){
  if(dir>4){
    return 'h';
  }else{
    return 'v';
  }
}

int resetRowAndCol(int col, int &row, int ShipSize, char dir){
  switch(ShipSize){
    case Carrier:
      if(dir=='h'){
        row=rand()%10;
        col=rand()%5;
      }else{
        row=rand()%5;
        col=rand()%10;
      }
      break;
    case Battleship:
      if(dir=='h'){
        row=rand()%10;
        col=rand()%6;
      }else{
        row=rand()%6;
        col=rand()%10;
      }
      break;
    case Destroyer:
      if(dir=='h'){
        row=rand()%10;
        col=rand()%7;
      }else{
        row=rand()%7;
        col=rand()%10;
      }
      break;
    case Submarine:
      if(dir=='h'){
        row=rand()%10;
        col=rand()%8;
      }else{
        row=rand()%8;
        col=rand()%10;
      }
  }
  return col;
}

int spaceCheck(int board[][10], int col, int row, int size, char dir){
  int check=0;
  if(dir=='h'){
    for(int i=col;i<col+size;i++){
      check=board[row][i];
        if(check!=0){
          return 1;
        }
    }
    return 0;
  }else{
    for(int i=row;i<row+size;i++){
      check=board[i][col];
        if(check!=0){
          return 1;
        }
    }
    return 0;
  }
}

int playGame(int board[][10], vector<Ship> &shipLineup){
  int col=0;
  int row=0;
  int atk=0;
  int hit=0;
  int whiff=0;
  int area=0;
  int sunk=0;
  char dir='f';
  string shipName="";
  bool inPrgressGame=true;

  while(inPrgressGame){
    gameBoardDisplay(board);
    
    cout<<"Give lateral coordinate - ";
    cin>>row;
    cout<<"Give longitudinal coordinate - ";
    cin>>col;
    cout<<endl;
    atk++;
    area=getArea(board, col, row);

    switch(area){
      case 0:
        cout<< "Attack missed"<<endl;
        board[row][col]=7;
        whiff++;
        break;
      case 1:
        cout<< "Attacked this area previously."<<endl;
        break;
      case 2:
        board[row][col]=8;
        hit++;
        shipName=shipLineup[6].getShip(col, row);
        if(shipName=="Submarine1"){
          cout<< "Hit "<< shipName<<endl;
          shipLineup[6].setHitp();
          sunk=shipLineup[6].shipCheck(Submarine);
          if(sunk==7){
            cout<< "Submarine1 sunk."<<endl;
          }
        }else if(shipName.empty()){
          shipName=shipLineup[7].getShip(col, row);
          if(shipName=="Submarine2"){
            cout<< "Hit "<< shipName<<endl;
            shipLineup[7].setHitp();
            sunk=shipLineup[7].shipCheck(Submarine);
            if(sunk==7){
              cout<< "Submarine2 sunk."<<endl;
            }
          }else if(shipName.empty()){
            shipName=shipLineup[8].getShip(col, row);
            cout<< "Hit "<< shipName<<endl;
            shipLineup[8].setHitp();
            sunk=shipLineup[8].shipCheck(Submarine);
              if(sunk==7){
                cout<< "Submarine3 sunk."<<endl;
              }
          }else if(shipName.empty()){
            shipName=shipLineup[9].getShip(col, row);
            cout<< "Hit "<< shipName<<endl;
            shipLineup[9].setHitp();
            sunk=shipLineup[9].shipCheck(Submarine);
            if(sunk==7){
              cout<< "Submarine4 sunk."<<endl;
            }
          }
        }
        shipName.clear();
        break;
      case 3:
        board[row][col]=8;
        hit++;
        shipName=shipLineup[3].getShip(col, row);
        if(shipName=="Destroyer1"){
          cout<< "Hit "<< shipName<<endl;
          shipLineup[3].setHitp();
          sunk=shipLineup[3].shipCheck(Destroyer);
          if(sunk==7){
            cout<< "Destroyer1 sunk."<<endl;
          }
        }else if(shipName.empty()){
          shipName=shipLineup[4].getShip(col, row);
          if(shipName=="Destroyer2"){
            cout<< "Hit "<< shipName<<endl;
            shipLineup[4].setHitp();
            sunk=shipLineup[4].shipCheck(Submarine);
            if(sunk==7){
              cout<< "Destroyer2 sunk."<<endl;
            }
          }else if(shipName.empty()){
            shipName=shipLineup[5].getShip(col, row);
            cout<< "Hit "<< shipName<<endl;
            shipLineup[5].setHitp();
            sunk=shipLineup[5].shipCheck(Submarine);
              if(sunk==7){
                cout<< "Destroyer3 sunk."<<endl;
              }
          }
        } 
        shipName.clear();
        break;
      case 4:
        board[row][col]=8;
        hit++;
        shipName=shipLineup[1].getShip(col, row);
        if(shipName=="Battleship1"){
          cout<< "Hit "<< shipName<<endl;
          shipLineup[1].setHitp();
          sunk=shipLineup[1].shipCheck(Battleship);
          if(sunk==7){
            cout<< "Battleship1 sunk."<<endl;
          }
        }else if(shipName.empty()){
          shipName=shipLineup[2].getShip(col, row);
            cout<< "Hit "<< shipName<<endl;
            shipLineup[2].setHitp();
            sunk=shipLineup[2].shipCheck(Battleship);
            if(sunk==7){
              cout<< "Battleship2 sunk."<<endl;
            }
        } 
        shipName.clear();
        break;
      case 5:
        board[row][col]=8;
        hit++;
        cout<< "Hit "<< shipName<<endl;
        shipLineup[0].setHitp();
        sunk=shipLineup[0].shipCheck(Carrier);
        if(sunk==7){
          cout<< "Carrier sunk."<<endl;
        }
        break;
    }
    if(hit==30){
      inPrgressGame=false;
    }
  }
  cout<<"GG all ships sunk in"<<atk<<"attacks"<<endl;
}

int getArea(int board[][10], int col, int row){
  int area=0;
  area = board[row][col];
  return area;
}

