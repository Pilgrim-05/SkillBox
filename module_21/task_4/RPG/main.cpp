#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct coordinate
{
  int x;
  int y;
};

struct characters
{
  string name;
  bool enemy;
  int live; //50 - 150
  int armor; //0 - 50
  int damage; //15 - 30
  coordinate point;
};

void initEnemy(vector<characters>&);
void viewEnemy(vector<characters>&);
void initPlayer(characters&, vector<characters>&);
void displayField(characters&, vector<characters>&);
void movingPlayers(characters&, vector<characters>&);
bool overlap(int, int, vector<characters>&, int, bool);
int statusCheck(characters&, vector<characters>&);
void attacks(coordinate&, characters&, characters&, vector<characters>&);
void save(characters&, vector<characters>&);
void load(characters&, vector<characters>&);

int main() {

  srand(time(0));
  const int numEnemy = 5;
  vector <characters> enemy(numEnemy);
  characters myPlayer;

  initEnemy(enemy);
  initPlayer(myPlayer, enemy);
//  myPlayer.name = "Guner";
//  myPlayer.enemy = false;
//  myPlayer.live = 150;
//  myPlayer.armor = 50;
//  myPlayer.damage = 25;
//  myPlayer.point.x = 39;
//  myPlayer.point.y = 39;
  displayField(myPlayer, enemy);
  int status = statusCheck(myPlayer, enemy);
  while(!status)
  {
      movingPlayers(myPlayer, enemy);
      displayField(myPlayer, enemy);
      status = statusCheck(myPlayer, enemy);
  }
  if(status == 1) cout<< endl << "********** You lose! **********" << endl;
  else if(status == -1) cout<< endl << "********** You won! **********" << endl;

//  viewEnemy(enemy);
}

void initEnemy(vector<characters> &enemy)
{
  for(int i = 0; i < enemy.size(); ++i)
  {
      enemy[i].name = "Enemy #" + to_string(i+1);
      enemy[i].enemy = true;
      enemy[i].live = (rand() % 101) + 50;
      enemy[i].armor = rand() % 51;
      enemy[i].damage = (rand() % 16) + 15;
      while(overlap(rand() % 40, rand() % 40, enemy, i, enemy[i].enemy)){}
  }
}
void viewEnemy(vector<characters> &enemy)
{
  for(int i = 0; i < enemy.size(); ++i)
  {
      cout << enemy[i].name << endl;
      cout << enemy[i].enemy << endl;
      cout << enemy[i].live << endl;
      cout << enemy[i].armor << endl;
      cout << enemy[i].damage << endl;
      cout << enemy[i].point.x << endl;
      cout << enemy[i].point.y << endl;
      cout << endl << "----------------------------" << endl;
  }
}
void initPlayer(characters &player, vector<characters> &enemy)
{
  cout << "fill in your player's details." << endl;
  cout << "Name: ";
  cin >> player.name;
  player.enemy = false;
  do
    {
      cout << "Live(50 - 150): ";
      cin >> player.live;
    }while(player.live < 50 || player.live > 150);
  do
    {
      cout << "Armor(0 - 50): ";
      cin >> player.armor;
    }while(player.armor < 0 || player.armor > 50);
  do
    {
      cout << "Damage(15 - 30): ";
      cin >> player.damage;
    }while(player.damage < 15 || player.damage > 30);
  int x,y;
  do
    {
      cout << "Your coordinates on the field(0 - 39): ";
      cin >> x >> y;
    }while(x < 0 || x > 39 || y < 0 || y > 39 || overlap(x, y, enemy, enemy.size(), player.enemy));
  player.point.x = x;
  player.point.y = y;
}
void displayField(characters &player, vector<characters> &enemy)
{
  const int fieldSize = 40;
  char gameMap[fieldSize][fieldSize];

  for(int i = 0; i < fieldSize; ++i)
  {
      for(int j = 0; j < fieldSize; ++j)
      {
          gameMap[i][j] = '.';
      }
  }
  for(int i = 0; i < enemy.size(); ++i)
  {
      if(enemy[i].live > 0)
      {
          gameMap[enemy[i].point.x][enemy[i].point.y] = 'E';
      }
  }
  if(player.live > 0) gameMap[player.point.x][player.point.y] = 'P';

  for(int i = 0; i < fieldSize; ++i)
  {
      for(int j = 0; j < fieldSize; ++j)
      {
          cout << gameMap[i][j];
      }
      cout << endl;
  }
}
void movingPlayers(characters &player, vector<characters> &enemy)
{
  string command;
  do
    {
      cout << "\nEnter command to move or save and load\n(left, right, top, bottom, save, load)\n";
      cin >> command;
    }while(command != "left" && command != "right" && command != "top" && command != "bottom" && command != "save" && command != "load");
  coordinate point;
  if(command == "left")
  {
      if(player.point.y > 0)
      {
          point = player.point;
          --point.y;
          attacks(point, player, player, enemy);
      }
  }else if(command == "right")
  {
      if(player.point.y < 39)
      {
          point = player.point;
          ++point.y;
          attacks(point, player, player, enemy);
      }
  }else if(command == "top")
  {
      if(player.point.x > 0)
      {
          point = player.point;
          --point.x;
          attacks(point, player, player, enemy);
      }
  }else if(command == "bottom")
  {
      if(player.point.x < 39)
      {
          point = player.point;
          ++point.x;
          attacks(point, player, player, enemy);
      }
  }else if(command == "save")
  {
      save(player, enemy);
  }else if(command == "load")
  {
      load(player, enemy);
  }

  for(int i = 0; i < enemy.size(); ++i)
  {
      int step = rand() % 4;
      switch (step) {
      case 0:
          if(enemy[i].point.y > 0 && enemy[i].live != 0)
          {
              point = enemy[i].point;
              --point.y;
              attacks(point, enemy[i], player, enemy);
          }
          break;
      case 1:
          if(enemy[i].point.y < 39 && enemy[i].live != 0)
          {
              point = enemy[i].point;
              ++point.y;
              attacks(point, enemy[i], player, enemy);
          }
          break;
      case 2:
          if(enemy[i].point.x > 0 && enemy[i].live != 0)
          {
              point = enemy[i].point;
              --point.x;
              attacks(point, enemy[i], player, enemy);
          }
          break;
      case 3:
          if(enemy[i].point.x < 39 && enemy[i].live != 0)
          {
              point = enemy[i].point;
              ++point.x;
              attacks(point, enemy[i], player, enemy);
          }
          break;
      }
  }
}
void attacks(coordinate &point, characters &attack, characters &player, vector<characters> &enemy)
{
    if(!attack.enemy)
    {
        attack.point = point;
        for(int i = 0; i < enemy.size(); ++i)
        {
            if(enemy[i].live != 0 && attack.point.x == enemy[i].point.x && attack.point.y == enemy[i].point.y)
            {
                enemy[i].armor -= attack.damage;
                if(enemy[i].armor < 0)
                {
                    enemy[i].live += enemy[i].armor;
                    enemy[i].armor = 0;
                }
                if(enemy[i].live < 0) enemy[i].live = 0;
            }
        }
    }else
    {
        if(point.x == player.point.x && point.y == player.point.y)
        {
            attack.point = point;
            player.armor -= attack.damage;
            if(player.armor < 0)
            {
                player.live += player.armor;
                player.armor = 0;
            }
            if(player.live < 0) player.live = 0;
        }else
        {
            for(int i = 0; i < enemy.size(); ++i)
            {
                if(enemy[i].live <= 0 || attack.name != enemy[i].name && (point.x != enemy[i].point.x || point.y != enemy[i].point.y))
                {
                    attack.point = point;
                }
            }
        }
    }
}
bool overlap(int x, int y, vector<characters> &person, int index, bool isEnemy)
{
    for(int i = index-1; i >= 0; --i)
    {
        if(person[i].point.x == x && person[i].point.y == y) return true;
    }
    if(isEnemy)
    {
        person[index].point.x = x;
        person[index].point.y = y;
    }
    return false;
}
int statusCheck(characters &player, vector<characters> &enemy)
{
    cout << endl << "My\tLive:  " << player.live << "\tArmor:  " << player.armor << endl;
    int summ = 0;
    for(int i = 0; i < enemy.size(); ++i)
    {
        cout << "#" << i + 1 << "\tLive:  " << enemy[i].live << "\tArmor:  " << enemy[i].armor << endl;
        summ += enemy[i].live;
    }
    if(summ <= 0) return -1;
    if(player.live <= 0) return 1;

    return 0;
}
void save(characters &player, vector<characters> &enemy)
{
    ofstream ofile("../src/gameSaves.bin", ios::binary);
    if(ofile.is_open())
    {
        int len = player.name.length();
        ofile.write((char*)&len, sizeof(len));
        ofile.write(player.name.c_str(), len);
        ofile.write((char*)&player.enemy, sizeof(player.enemy));
        ofile.write((char*)&player.live, sizeof(player.live));
        ofile.write((char*)&player.armor, sizeof(player.armor));
        ofile.write((char*)&player.damage, sizeof(player.damage));
        ofile.write((char*)&player.point.x, sizeof(player.point.x));
        ofile.write((char*)&player.point.y, sizeof(player.point.y));

        for(int i = 0; i < enemy.size(); ++i)
        {
            int len = enemy[i].name.length();
            ofile.write((char*)&len, sizeof(len));
            ofile.write(enemy[i].name.c_str(), len);
            ofile.write((char*)&enemy[i].enemy, sizeof(enemy[i].enemy));
            ofile.write((char*)&enemy[i].live, sizeof(enemy[i].live));
            ofile.write((char*)&enemy[i].armor, sizeof(enemy[i].armor));
            ofile.write((char*)&enemy[i].damage, sizeof(enemy[i].damage));
            ofile.write((char*)&enemy[i].point.x, sizeof(enemy[i].point.x));
            ofile.write((char*)&enemy[i].point.y, sizeof(enemy[i].point.y));
        }
        ofile.close();
    }else
    {
        cout << "File not found." << endl;
    }
}
void load(characters &player, vector<characters> &enemy)
{
    ifstream ifile("../src/gameSaves.bin", ios::binary);
    if(ifile.is_open())
    {
        int len;
        ifile.read((char*)&len, sizeof(len));
        player.name.resize(len);
        ifile.read((char*)player.name.c_str(), len);
        ifile.read((char*)&player.enemy, sizeof(player.enemy));
        ifile.read((char*)&player.live, sizeof(player.live));
        ifile.read((char*)&player.armor, sizeof(player.armor));
        ifile.read((char*)&player.damage, sizeof(player.damage));
        ifile.read((char*)&player.point.x, sizeof(player.point.x));
        ifile.read((char*)&player.point.y, sizeof(player.point.y));

        for(int i = 0; i < enemy.size(); ++i)
        {
            int len;
            ifile.read((char*)&len, sizeof(len));
            enemy[i].name.resize(len);
            ifile.read((char*)enemy[i].name.c_str(), len);
            ifile.read((char*)&enemy[i].enemy, sizeof(enemy[i].enemy));
            ifile.read((char*)&enemy[i].live, sizeof(enemy[i].live));
            ifile.read((char*)&enemy[i].armor, sizeof(enemy[i].armor));
            ifile.read((char*)&enemy[i].damage, sizeof(enemy[i].damage));
            ifile.read((char*)&enemy[i].point.x, sizeof(enemy[i].point.x));
            ifile.read((char*)&enemy[i].point.y, sizeof(enemy[i].point.y));
        }
        ifile.close();
        displayField(player, enemy);
    }else
    {
        cout << "File not found." << endl;
    }
}
