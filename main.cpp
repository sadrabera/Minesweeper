#include "SBDL.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
int game[30][30];
int null_check[30][30];
int game_col = 0;
int game_row = 0;
int game_fr[30][30];
const int window_width = 700;
const int window_height = 700;
int bombs;
int flag_counter;
bool flag_leader=true;
bool flag_new_flag_count=true;
int cup_leader_state=0;
void background_game(int , int);
int neighbor_bomb(int  ,int );
void menu();
void collapse (int ,int );
void square_maker();
void move(int , int);
void show_game(int );
int null_check_counter();
void load_game_menu();
void keyboard();
void bubble_sort();
void save();
void leader_board();
void chose_game();
void custom_game();
void keyboard_custom(char[]);
SDL_Rect rect[30][30];
SDL_Rect left_arrow_rect={20,10,35,30};
SDL_Rect rects_menu[5];
SDL_Rect input_rect;
SDL_Rect rect_save;
SDL_Rect rect_enter_name;
SDL_Rect flag_count_rect={370,5,40,40};
SDL_Rect num_rects[10];
SDL_Rect points_rects[10];
Texture hide_1;
Texture temp_leader_show[10];
Texture temp_leader_show_score[10];
Texture back_start;
Texture num_1_1;
Texture num_2_1;
Texture void_1;
Texture back;
Texture num_3_1;
Texture num_4_1;
Texture num_5_1;
Texture num_6_1;
Texture num_7_1;
Texture num_8_1;
Texture new_game;
Texture load_game;
Texture change_name;
Texture tx_leader_board;
Texture tx_exit;
Texture game_background;
Texture save_slot;
Texture chose_mode;
Texture hard_mode;
Texture easy_mode;
Texture normal_mode;
Texture custom_mode;
Texture selection_game;
Texture leader_board_back;
Texture conger;
Texture left_arrow;
Texture flag_count;
Texture save_quit;
Texture quit;
Texture back_to_menu;
Texture mine_game;
Texture you_lost;
Texture cup[25];
Music* menu_music;
Music* game_music;
Music* lose_music;
Music* win_music;
Sound* water_mine;
Sound* lose_rick;
SDL_Rect rectangle;
SDL_Rect cup_leader_rect;
Texture flag_game;
Font *font;
Font *font_game;
char temp_name[50];
char input_row[4] = {'\0', '\0', '\0', '\0'};
char input_cols[4] = {'\0', '\0', '\0', '\0'};
char input_bom[4] = {'\0', '\0', '\0', '\0'};
string str;
string str_score;
string dot;
string name_show;
string str_num;
SDL_Rect conger_rect;
int state=0;// 0=for start,1=for menu,2=for load page,3=for game,4=for save
int custom_game_state=0;
struct leader{
    char  name[50];
    int score=-1;
}leader_bord[10];
struct save_game{
    bool flag=false;
    char  name[50]={' '};
    int temp_game[30][30];
    int temp_null_check[30][30];
    int temp_game_col = 20;
    int temp_game_row = 20;
    int temp_game_fr[30][30];
    int flag_counter;
    int temp_boom;
}saved[4];
int player=0;
int main(int argc, char *argv[])
{
    srand(time(NULL));
    SBDL::InitEngine("Minesweeper", window_width, window_height);
    hide_1= SBDL::loadTexture("assets/hide_2_t.png");
    num_1_1= SBDL::loadTexture("assets/num_1_1.png");
    num_2_1= SBDL::loadTexture("assets/num_2_1.png");
    num_3_1= SBDL::loadTexture("assets/num_3_1.png");
    num_4_1= SBDL::loadTexture("assets/num_4_1.png");
    num_5_1= SBDL::loadTexture("assets/num_5_1.png");
    num_6_1= SBDL::loadTexture("assets/num_6_1.png");
    num_7_1= SBDL::loadTexture("assets/num_7_1.png");
    num_8_1= SBDL::loadTexture("assets/num_8_1.png");
    save_slot= SBDL::loadTexture("assets/save_slot.png");
    void_1=SBDL::loadTexture("assets/void_1.png");
    back=SBDL::loadTexture("assets/menu.jpg");
    new_game=SBDL::loadTexture("assets/new_game.png");
    load_game=SBDL::loadTexture("assets/load_game.png");
    change_name=SBDL::loadTexture("assets/change_name.png");
    tx_leader_board=SBDL::loadTexture("assets/leader_board.png");
    tx_exit=SBDL::loadTexture("assets/exit.png");
    back_start=SBDL::loadTexture("assets/start.png");
    flag_game=SBDL::loadTexture("assets/flag.png");
    game_background=SBDL::loadTexture("assets/game_background.png");
    chose_mode=SBDL::loadTexture("assets/chose_a_mode.jpg");
    hard_mode=SBDL::loadTexture("assets/hard_mode.png");
    easy_mode=SBDL::loadTexture("assets/easy_mode.png");
    normal_mode=SBDL::loadTexture("assets/normal_mode.png");
    custom_mode=SBDL::loadTexture("assets/custom_mode.png");
    selection_game=SBDL::loadTexture("assets/selection.jpg");
    leader_board_back=SBDL::loadTexture("assets/leader_board_back1.png");
    conger=SBDL::loadTexture("assets/conger1.png");
    left_arrow=SBDL::loadTexture("assets/left_arrow.png");
    flag_count=SBDL::loadTexture("assets/flag_count.png");
    save_quit=SBDL::loadTexture("assets/save and quit.png");
    save_quit=SBDL::loadTexture("assets/save and quit.png");
    back_to_menu=SBDL::loadTexture("assets/back_to_menu.png");
    quit=SBDL::loadTexture("assets/quit.png");
    mine_game=SBDL::loadTexture("assets/mine_game.png");
    you_lost=SBDL::loadTexture("assets/you_lost.png");
    cup[0]=SBDL::loadTexture("assets/cup/0.png");
    cup[1]=SBDL::loadTexture("assets/cup/1.png");
    cup[2]=SBDL::loadTexture("assets/cup/2.png");
    cup[3]=SBDL::loadTexture("assets/cup/3.png");
    cup[4]=SBDL::loadTexture("assets/cup/4.png");
    cup[5]=SBDL::loadTexture("assets/cup/5.png");
    cup[6]=SBDL::loadTexture("assets/cup/6.png");
    cup[7]=SBDL::loadTexture("assets/cup/7.png");
    cup[8]=SBDL::loadTexture("assets/cup/8.png");
    cup[9]=SBDL::loadTexture("assets/cup/9.png");
    cup[10]=SBDL::loadTexture("assets/cup/10.png");
    cup[11]=SBDL::loadTexture("assets/cup/11.png");
    cup[12]=SBDL::loadTexture("assets/cup/12.png");
    cup[13]=SBDL::loadTexture("assets/cup/13.png");
    cup[14]=SBDL::loadTexture("assets/cup/14.png");
    cup[15]=SBDL::loadTexture("assets/cup/15.png");
    cup[16]=SBDL::loadTexture("assets/cup/16.png");
    cup[17]=SBDL::loadTexture("assets/cup/17.png");
    cup[18]=SBDL::loadTexture("assets/cup/18.png");
    cup[19]=SBDL::loadTexture("assets/cup/19.png");
    cup[20]=SBDL::loadTexture("assets/cup/20.png");
    cup[21]=SBDL::loadTexture("assets/cup/21.png");
    cup[22]=SBDL::loadTexture("assets/cup/22.png");
    cup[23]=SBDL::loadTexture("assets/cup/23.png");
    cup[24]=SBDL::loadTexture("assets/cup/24.png");
    font=SBDL::loadFont("assets/Product Sans Regular.ttf",40);
    font_game=SBDL::loadFont("assets/times.ttf",70);
    menu_music=SBDL::loadMusic("assets/music/09 - The Oil.wav");
    game_music=SBDL::loadMusic("assets/music/05 Pump Room.wav");
    win_music=SBDL::loadMusic("assets/music/Beethoven  Symphony No  9 in D minor.wav");
    lose_music=SBDL::loadMusic("assets/music/Ramin-Djawadi-Goodbye-Brother-320.wav");
    water_mine=SBDL::loadSound("assets/music/mixkit-sea-mine-explosion-1184.wav");
    lose_rick=SBDL::loadSound("assets/music/lose_rick.wav");

    const int FPS = 60; //frame per second
    const int delay = 1000 / FPS; //delay we need at each frame
    bool flag_new_game=true;
    int conger_j=0;
    int lost_j=0;
    int flag_counter_check;
    SDL_Rect save_quit_rect={15,650,180,40};
    SDL_Rect quit_rect={615,650,70,40};
    SDL_Rect lost_rect={615,650,70,40};
    temp_name[0]='\0';
        rectangle.x=0;
        rectangle.y=0;
        rectangle.h=window_width;
        rectangle.w=window_height;
    square_maker();
    Texture start=SBDL::createFontTexture(font,"write your name and then press enter",0,0,0);
    Texture temp_flag_show;
    bool flag_save=true;
    ifstream in;
    in.open("files/save_slot.txt");
    {
        for(int i=0;i<4;i++)
        {
            in>>i;
            in>>saved[i].flag;
            in>>saved[i].name;
            in>>saved[i].temp_game_row;
            in>>saved[i].temp_game_col;
            for(int j=0;j<saved[i].temp_game_row;j++)
                for(int h=0;h<saved[i].temp_game_col;h++)
                    in>>saved[i].temp_game[j][h];
            for(int j=0;j<saved[i].temp_game_row;j++)
                for(int h=0;h<saved[i].temp_game_col;h++)
                    in>>saved[i].temp_game_fr[j][h];
            for(int j=0;j<saved[i].temp_game_row;j++)
            for(int h=0;h<saved[i].temp_game_col;h++)
                    in>>saved[i].temp_null_check[j][h];
            in>>saved[i].flag_counter;
            in>>saved[i].temp_boom;
        }
    }
    in.close();
    ifstream in_leader;
    in_leader.open("files/leader.txt");
    for(int i=0;i<10;i++)
    {
        in_leader>>leader_bord[i].name;
        in_leader>>leader_bord[i].score;
    }
    in_leader.close();
    SBDL::playMusic(menu_music,-1);
    while (SBDL::isRunning()) {
        int startTime = SBDL::getTime();
        SBDL::updateEvents();
        SBDL::clearRenderScreen();

        //Game logic code
        if(state==0)
        {

            SBDL::showTexture(back_start,rectangle);
            SDL_Rect name_cadre={150,270,380,50};
            SBDL::drawRectangle(name_cadre,255, 225, 222,150);
            keyboard();
            if(strnlen(temp_name,50)>0)
            {
                start = SBDL::createFontTexture(font, temp_name, 0, 0, 0);
                SBDL::showTexture(start, 160, 270);
            }
        }
        if(state==1)
        {
            {
                int i = 0;
                for (; leader_bord[i].score != -1 && i!=10; i++)
                    if (strcmp(leader_bord[i].name, temp_name)==0)
                    {
                        break;
                    }
                    if(i==10)
                        player=9;
                    else
                        player=i;
            }
            if(leader_bord[player].score==-1)
            leader_bord[player].score=0;
            strcpy(leader_bord[player].name,temp_name);
            bubble_sort();
            SBDL::showTexture(back,rectangle);
            menu();
        }
        if(state==2)
        {
            flag_new_game= false;
            load_game_menu();
            if(state==1)
                flag_new_game=true;
        }
        if(state==30)
        {
            chose_game();
        }
        if(state==31)
        {
            custom_game();
        }
        if(state==3) {
            bool flag_bug=false;
            int temp_i=0,temp_j=0;
            SBDL::showTexture(game_background,rectangle);
            SBDL::showTexture(flag_count,flag_count_rect);
            SBDL::showTexture(save_quit,save_quit_rect);
            SBDL::showTexture(quit,quit_rect);
            if(flag_new_flag_count) {
                SBDL::stopMusic();
                SBDL::playMusic(game_music,-1);
                flag_counter_check = flag_counter = bombs;
                string temp_flag_counter = to_string(flag_counter);
                temp_flag_show = SBDL::createFontTexture(font, temp_flag_counter, 245, 244, 242);
                flag_new_flag_count = false;
            }

            if(flag_new_game)
            {
               SBDL::showTexture(temp_flag_show,320,5);
                for(int i=0;i<game_row;i++)
                {
                    for(int j=0;j<game_col;j++)
                        rect[i][j]={window_width/2-game_row/2*30+i*30,window_height/2-game_col/2*30+j*30, 25, 25};
                }
                for(int i=0;i<game_row;i++)
                    for(int j=0;j<game_col;j++)
                        game_fr[i][j]=11;
                for(int i=0;i<game_row;i++)
                    for(int j=0;j<game_col;j++)
                        null_check[i][j]=1;
                for (int i = 0; i < game_row; i++)
                    for (int j = 0; j < game_col; j++) {
                        if (SBDL::keyPressed(SDL_SCANCODE_Q)) {
                            flag_new_game = true;
                            flag_new_flag_count = true;
                            state = 1;
                            SBDL::stopMusic();
                        }
                        if (SBDL::keyPressed(SDL_SCANCODE_O)) {

                            state = 4;
                            flag_new_game = true;
                            flag_new_flag_count = true;
                            SBDL::stopMusic();
                        }
                        if (SBDL::mouseInRect(rect[i][j])) {
                            if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
                                flag_save = true;
                                temp_i=i;
                                temp_j=j;
                                flag_bug= true;
                            }
                        }
                        if(SBDL::mouseInRect(quit_rect))
                            if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED))
                            {
                                flag_new_game=true;
                                flag_new_flag_count=true;
                                state=1;
                                SBDL::stopMusic();
                                SBDL::playMusic(menu_music,-1);
                            }
                    }
                if(flag_bug)
                {
                    background_game(temp_i,temp_j);
                for(int i=0;i<game_row;i++)
                    for(int j=0;j<game_col;j++)
                        game_fr[i][j]=11;
                for(int i=0;i<game_row;i++)
                    for(int j=0;j<game_col;j++)
                        null_check[i][j]=1;
                move(temp_i, temp_j);
                flag_new_game= false;
                }
            }
            if(flag_counter_check!=flag_counter)
            {
                string temp_flag_counter=to_string(flag_counter);
                temp_flag_show=SBDL::createFontTexture(font,temp_flag_counter,245, 244, 242);
                flag_counter_check=flag_counter;
            }
            SBDL::showTexture(temp_flag_show,320,5);

            show_game(0);
            if(!flag_new_game)
            for (int i = 0; i < game_row; i++)
                for (int j = 0; j < game_col; j++) {
                    if(SBDL::mouseInRect(save_quit_rect))
                        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED))
                        {
                            state=4;
                            flag_new_game=true;
                            flag_new_flag_count=true;
                            SBDL::stopMusic();
                            SBDL::playMusic(menu_music,-1);
                        }
                    if(SBDL::mouseInRect(quit_rect))
                        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED))
                        {
                            flag_new_game=true;
                            flag_new_flag_count=true;
                            state=1;
                            SBDL::stopMusic();
                            SBDL::playMusic(menu_music,-1);
                        }
                     if (SBDL::keyPressed(SDL_SCANCODE_Q))
                     {
                         flag_new_game=true;
                         flag_new_flag_count=true;
                         state=1;
                         SBDL::stopMusic();
                         SBDL::playMusic(menu_music,-1);
                     }
                     if (SBDL::keyPressed(SDL_SCANCODE_O))
                    {
                         state=4;
                        flag_new_game=true;
                        flag_new_flag_count=true;
                        SBDL::stopMusic();
                        SBDL::playMusic(menu_music,-1);

                    }
                    if (SBDL::mouseInRect(rect[i][j])) {
                        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
                            if(game_fr[i][j]!=20) {
                                flag_save = true;
                                move(i, j);
                            }
                        }
                        else if(SBDL::Mouse.clicked(SDL_BUTTON_RIGHT, 1, SDL_RELEASED))
                        {
                            flag_save = true;
                            if(game_fr[i][j]==11 && flag_counter>0)
                            {
                                game_fr[i][j]=20;
                                flag_counter--;
                            }
                            else if(game_fr[i][j]==20)
                            {
                                game_fr[i][j]=11;
                                flag_counter++;
                            }
                        }
                    }
                }
            if(null_check_counter()>=game_col*game_row-bombs)
            {
                flag_new_game = true;
                flag_new_flag_count = true;
                for(int i=0;i<10;i++)
                    if(strcmp(leader_bord[i].name,temp_name)==0)
                    {
                        leader_bord[i].score+=bombs;
                        break;
                    }
                SBDL::stopMusic();
                SBDL::delay(30);
                SBDL::playMusic(win_music,1);
                state=7;
            }
        }
        if(state==4)
        {
            save();
        }
        if(state==5)
        {
            leader_board();
        }
        if(state==6)
            break;
        else if(state==7)
        {
            SBDL::showTexture(game_background,rectangle);
            SBDL::showTexture(temp_flag_show,320,5);
            SBDL::showTexture(flag_count,flag_count_rect);
            SDL_Rect back_to_menu_rect={250,650,200,50};
            SBDL::showTexture(back_to_menu,back_to_menu_rect);
            show_game(0);
            if(conger_j<20)
            {
                conger_rect={200-10*conger_j,330-2*conger_j,300+20*conger_j,90+3*conger_j++};
                SBDL::delay(10);
            }

            SBDL::showTexture(conger,conger_rect);
            if(SBDL::mouseInRect(back_to_menu_rect))
                if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
                {
                    state=1;
                    conger_j=0;
                    SBDL::stopMusic();
                    SBDL::playMusic(menu_music,-1);
                }
        }
        else if(state==8)
        {
            SBDL::showTexture(game_background,rectangle);
            SBDL::showTexture(temp_flag_show,320,5);
            SBDL::showTexture(flag_count,flag_count_rect);
            SDL_Rect back_to_menu_rect={250,650,200,50};
            SBDL::showTexture(back_to_menu,back_to_menu_rect);
            show_game(1);
            if(SBDL::mouseInRect(back_to_menu_rect))
                if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
                {
                    state=1;
                    lost_j=0;
                    flag_new_game = true;
                    flag_new_flag_count = true;
                    SBDL::stopAllSounds();
                    SBDL::stopMusic();
                    SBDL::playMusic(menu_music,-1);
                }
            if(lost_j<20)
            {
               lost_rect={200-10*lost_j,330-2*lost_j,300+20*lost_j,90+3*lost_j++};
                SBDL::delay(10);
            }
            SBDL::showTexture(you_lost,lost_rect);
        }
        SBDL::updateRenderScreen();
        int elapsedTime = SBDL::getTime() - startTime;
        if (elapsedTime < delay)
            SBDL::delay(delay - elapsedTime);
    }
    ofstream out;
    out.open("files/save_slot.txt");
    for(int i=0;i<4;i++)
    {
        if(saved[i].flag)
          {
            out<<i<<endl;
              out<<saved[i].flag<<endl;
              out<<saved[i].name<<endl;
              out<<saved[i].temp_game_row<<endl;
              out<<saved[i].temp_game_col<<endl;
                    for(int j=0;j<saved[i].temp_game_row;j++)
                        for(int h=0;h<saved[i].temp_game_col;h++)
                            out<<saved[i].temp_game[j][h]<<' ';
                        out<<endl;
                     for(int j=0;j<saved[i].temp_game_row;j++)
                  for(int h=0;h<saved[i].temp_game_col;h++)
                            out<<saved[i].temp_game_fr[j][h]<<' ';
              out<<endl;
              for(int j=0;j<saved[i].temp_game_row;j++)
                  for(int h=0;h<saved[i].temp_game_col;h++)
                            out<<saved[i].temp_null_check[j][h]<<' ';
              out<<endl;
              out<<saved[i].flag_counter<<endl;
              out<<saved[i].temp_boom<<endl;
          }
    }
    out.close();
    ofstream out_leader;
    out_leader.open("files/leader.txt");
    for(int i=0;i<10;i++)
    {
        out_leader<<leader_bord[i].name<<endl;
        out_leader<<leader_bord[i].score<<endl;
    }
    out_leader.close();

    return 0;

}
int neighbor_bomb(int i ,int j)
{
    int counter=0;
    if(game[i-1][j-1]==10 && i>0 && j>0)
        counter++;
    if(game[i-1][j]==10 && i>0 )
        counter++;
    if(game[i-1][j+1]==10 && j<game_col-1 && i>0)
        counter++;
    if(game[i][j-1]==10 && j>0)
        counter++;
    if(game[i][j+1]==10 && j<game_col-1)
        counter++;
    if(game[i+1][j]==10 && i<game_row-1)
        counter++;
    if(game[i+1][j-1]==10 && i<game_row-1 && j>0)
        counter++;
    if(game[i+1][j+1]==10 && i<game_row-1 && j<game_col-1)
        counter++;
    return counter;
}
void background_game(int temp_i,int temp_j)
{
    for(int i=0;i<game_row;i++)
        for(int j=0;j<game_col;j++)
            game[i][j]=0;
    for(int i=0;i<bombs;i++) {
        int a = rand() % game_row;
        int b = rand() % game_col;
        if (game[a][b] != 10 && (a!=temp_i || b!=temp_j) )
            game[a][b] = 10;
        else
            i--;
    }
    for(int i=0;i<game_row;i++)
        for(int j=0;j<game_col;j++)
            if(game[i][j]!=10)
                game[i][j]=neighbor_bomb(i,j);
}
void square_maker()
{

    for(int i=0;i<5;i++) {
        if (i % 2 == 0)
            rects_menu[i] = {180, 250 + 70* i, 300, 65};
        else
            rects_menu[i] = {205, 250 + 70 * i, 300, 65};
    }
        rect_save={0,0,50,50};
    rect_enter_name={100,100,100,100};
}
void move(int i , int j)
{

    if(game[i][j]==0)
    {
        game_fr[i][j]=game[i][j];
        null_check[i][j]=0;
        collapse(i,j);
    }
    if(game[i][j]==1||game[i][j]==2||game[i][j]==3||game[i][j]==4||game[i][j]==5||game[i][j]==6||game[i][j]==7||game[i][j]==8)
    {
        game_fr[i][j]=game[i][j];
        null_check[i][j]=0;
    }
    else if (game[i][j]==10)
    {
        SBDL::stopMusic();
        SBDL::playMusic(lose_music,-1);
        SBDL::playSound(water_mine,6);
        SBDL::playSound(lose_rick,1);
        state=8;
        return;
    }
}
void show_game(int check)
{
    for(int i=0;i<game_row;i++)
    {
        for(int j=0;j<game_col;j++) {
            if (game_fr[i][j] == 11) {
                    SBDL::showTexture(hide_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 20)
            {
                SBDL::showTexture(flag_game,rect[i][j]);
            }
            else if(game_fr[i][j] == 1)
            {
                    SBDL::showTexture(num_1_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 2)
            {
                    SBDL::showTexture(num_2_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 3)
            {
                    SBDL::showTexture(num_3_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 4)
            {
                    SBDL::showTexture(num_4_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 5)
            {
                    SBDL::showTexture(num_5_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 6)
            {
                    SBDL::showTexture(num_6_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 7)
            {
                    SBDL::showTexture(num_7_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 8)
            {
                    SBDL::showTexture(num_8_1,rect[i][j]);
            }
            else if(game_fr[i][j] == 0 )
            {
                    SBDL::showTexture(void_1,rect[i][j]);
            }
             if(game[i][j]==10 &&check==1)
            {
                SBDL::showTexture(mine_game,rect[i][j]);
            }
        }
    }
}
void collapse (int y,int x)
{

    if(game[y-1][x-1]==0 && null_check[y-1][x-1]==1 && y>0 && x>0)
    {
        game_fr[y-1][x-1]=0;
        null_check[y-1][x-1]=0;
        collapse(y-1,x-1);
    }
    else if(game[y-1][x-1]!=10 && y>0 && x>0)
    {
        null_check[y-1][x-1]=0;

        game_fr[y-1][x-1]=game[y-1][x-1];

    }
    if(game[y-1][x]==0 && null_check[y-1][x]==1 && y>0 ) {
        game_fr[y-1][x]=0;
        null_check[y-1][x]=0;
        collapse(y-1,x);
    }
    else if(game[y-1][x]!=10  && y>0)
    {
        null_check[y-1][x]=0;
        game_fr[y-1][x]=game[y-1][x];
    }
    if(game[y-1][x+1]==0 && null_check[y-1][x+1]==1  && x<game_col-1 && y>0)
    {
        game_fr[y-1][x+1]=0;
        null_check[y-1][x+1]=0;
        collapse(y-1,x+1);
    }
    else if(game[y-1][x+1]!=10 && x<game_col-1 && y>0)
    {
        null_check[y-1][x+1]=0;
        game_fr[y-1][x+1]=game[y-1][x+1];
    }
    if(game[y][x-1]==0 && null_check[y][x-1]==1 && x>0)
    {
        game_fr[y][x-1]=0;
        null_check[y][x-1]=0;
        collapse(y,x-1);
    }
    else if(game[y][x-1]!=10 && x>0)
    {
        null_check[y][x-1]=0;
        game_fr[y][x-1]=game[y][x-1];
    }
    if(game[y][x+1]==0 && null_check[y][x+1]==1 && x<game_col-1)
    {
        game_fr[y][x+1]=0;
        null_check[y][x+1]=0;
        collapse(y,x+1);
    }
    else if(game[y][x+1]!=10 && x<game_col-1)
    {
        null_check[y][x+1]=0;
        game_fr[y][x+1]=game[y][x+1];
    }
    if(game[y+1][x]==0 && null_check[y+1][x]==1 && y<game_row-1)
    {
        game_fr[y+1][x]=0;
        null_check[y+1][x]=0;
        collapse(y+1,x);
    }
    else if(game[y+1][x]!=10 && y<game_row-1)
    {
        null_check[y+1][x]=0;
        game_fr[y+1][x]=game[y+1][x];
    }
    if(game[y+1][x-1]==0 && null_check[y+1][x-1]==1 && y<game_row-1 && x>0)
    {
        game_fr[y+1][x-1]=0;
        null_check[y+1][x-1]=0;
        collapse(y+1,x-1);
    }
    else if(game[y+1][x-1]!=10 && y<game_row-1 && x>0)
    {
        null_check[y+1][x-1]=0;
        game_fr[y+1][x-1]=game[y+1][x-1];
    }
    if(game[y+1][x+1]==0 && null_check[y+1][x+1]==1 && y<game_row-1 && x<game_col-1)
    {
        game_fr[y+1][x+1]=0;
        null_check[y+1][x+1]=0;
        collapse(y+1,x+1);
    }
    else if(game[y+1][x+1]!=10 && y<game_row-1 && x<game_col-1)
    {
        null_check[y+1][x+1]=0;
        game_fr[y+1][x+1]=game[y+1][x+1];
    }
}
int null_check_counter()
{
    int counter=0;
    for(int i=0;i<game_row;i++)
        for(int j=0;j<game_col;j++)
            if(null_check[i][j]==0)
                counter++;
    return counter;
}
void menu() {
    SBDL::showTexture(new_game,rects_menu[0]);
    SBDL::showTexture(load_game,rects_menu[1]);
    SBDL::showTexture(change_name,rects_menu[2]);
    SBDL::showTexture(tx_leader_board,rects_menu[3]);
    SBDL::showTexture(tx_exit,rects_menu[4]);


    if (SBDL::mouseInRect(rects_menu[0])) {
        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
            state=30;
            SBDL::updateEvents();
        }
    }
        else if (SBDL::mouseInRect(rects_menu[1])) {
        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
            state=2;
            SBDL::updateEvents();

        }
    }
        else if (SBDL::mouseInRect(rects_menu[3])) {
        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
            state = 5;
            SBDL::updateEvents();
        }
    }
        else if (SBDL::mouseInRect(rects_menu[2])) {
        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
            state = 0;
            SBDL::updateEvents();
        }
    }
        else if (SBDL::mouseInRect(rects_menu[4])) {
        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
            state=6;
        }
    }
}
void load_game_menu()
{
    SBDL::showTexture(save_slot,rectangle);
    SBDL::showTexture(left_arrow,left_arrow_rect);
    SDL_Rect here_rect[4];
    for(int i=0;i<4;i++)
        here_rect[i]={140,280+70*i,300,50};
    Texture type_save[4];
    for(int i=0;i<4;i++) {
        if (!saved[i].flag)
            type_save[i]= SBDL::createFontTexture(font ,"Empty", 250, 250, 250);
        else
            type_save[i]= SBDL::createFontTexture(font, saved[i].name, 250, 250, 250);
    }
    for(int i=0;i<4;i++)
        SBDL::drawRectangle(here_rect[i],0,0,0,100);
    for(int i=0;i<4;i++)
        SBDL::showTexture(type_save[i],140,280+70*i);

    for(int i=0;i<4;i++){
        if(SBDL::mouseInRect(left_arrow_rect))
            if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
                state=1;
                return;
            }
        if (SBDL::mouseInRect(here_rect[i])) {
            if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
                if (saved[i].flag)
                {
                    game_row=saved[i].temp_game_row;
                    game_col=saved[i].temp_game_col;
                    strcpy(temp_name,saved[i].name);
                    for(int j=0;j<game_row;j++)
                        for(int h=0;h<game_col;h++)
                    game[j][h]=saved[i].temp_game[j][h];
                    for(int j=0;j<game_row;j++)
                        for(int h=0;h<game_col;h++)
                            game_fr[j][h]=saved[i].temp_game_fr[j][h];
                    for(int j=0;j<game_row;j++)
                        for(int h=0;h<game_col;h++)
                            null_check[j][h]=saved[i].temp_null_check[j][h];
                        flag_counter=saved[i].flag_counter;
                        bombs=saved[i].temp_boom;
                    state=3;
                    for(int h=0;h<game_row;h++)
                    {
                        for(int j=0;j<game_col;j++)
                            rect[h][j]={window_width/2-game_row/2*30+h*30,window_height/2-game_col/2*30+j*30, 25, 25};
                    }
                    SBDL::updateEvents();

                    break;
                }
            }
        }
    }
}
void keyboard()
{
    int size=strnlen(temp_name,50);
    if(SBDL::keyPressed(SDL_SCANCODE_A)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='A';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_B)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='B';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_C)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='C';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_D)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='D';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_E)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='E';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_F)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='F';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_G)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='G';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_H)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='H';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_I)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='I';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_J)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='J';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_K)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='K';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_L)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='L';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_M)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='M';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_N)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='N';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_O)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='O';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_P)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='P';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_Q)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='Q';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_R)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='R';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_S)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='S';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_T)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='T';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_U)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='U';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_V)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='V';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_W)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='W';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_X)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='X';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_Y)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='Y';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_Z)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='Z';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_0)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='0';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_1)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='1';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_2)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='2';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_3)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='3';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_4)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='4';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_5)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='5';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_6)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='6';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_7)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='7';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_8)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='8';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_9)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]='9';
    }

    else if(SBDL::keyPressed(SDL_SCANCODE_BACKSPACE))
        temp_name[strnlen(temp_name,50)-1]='\0';
    else if(SBDL::keyPressed(SDL_SCANCODE_SPACE)&&size<10)
    {
        temp_name[strnlen(temp_name,50)+1]='\0';
        temp_name[strnlen(temp_name,50)]=' ';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_RETURN))
    {
        if(temp_name[0]!='\0')
        state=1;
    }
}
void bubble_sort( ) {//descending sort
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10 - i - 1; j++)
            if (leader_bord[j + 1].score > leader_bord[j].score)
                swap(leader_bord[j], leader_bord[j + 1]);
}
void save()
{
    SBDL::showTexture(save_slot,rectangle);
    SBDL::showTexture(left_arrow,left_arrow_rect);
    SDL_Rect here_rect[4];
    for(int i=0;i<4;i++)
        here_rect[i]={140,280+70*i,300,50};
        Texture type_save[4];
    for(int i=0;i<4;i++) {
        if (!saved[i].flag)
            type_save[i]= SBDL::createFontTexture(font, "Empty", 250, 250, 250);
        else
            type_save[i]= SBDL::createFontTexture(font, saved[i].name, 250, 250, 250);
    }
    for(int i=0;i<4;i++)
        SBDL::drawRectangle(here_rect[i],0,0,0,100);

        SBDL::showTexture(type_save[0],140,280);
        SBDL::showTexture(type_save[1],140,350);
        SBDL::showTexture(type_save[2],140,420);
        SBDL::showTexture(type_save[3],140,490);
    for(int i=0;i<4;i++) {
        if(SBDL::mouseInRect(left_arrow_rect))
            if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
            {
                state=1;
                SBDL::updateEvents();
            }
        if (SBDL::mouseInRect(here_rect[i])) {
            if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
                saved[i].flag = true;
                strcpy(saved[i].name, temp_name);
                for (int j = 0; j < game_row; j++)
                    for (int h = 0; h < game_col; h++)
                        saved[i].temp_game[j][h] = game[j][h];
                for (int j = 0; j < game_row; j++)
                    for (int h = 0; h < game_col; h++)
                        saved[i].temp_game_fr[j][h] = game_fr[j][h];
                for (int j = 0; j < game_row; j++)
                    for (int h = 0; h < game_col; h++)
                        saved[i].temp_null_check[j][h] = null_check[j][h];
                saved[i].temp_game_row = game_row;
                saved[i].temp_game_col = game_col;
                saved[i].flag_counter = flag_counter;
                saved[i].temp_boom=bombs;
                state = 1;
                SBDL::updateEvents();
                return;
            }
        }
    }
}
void leader_board()
{
    SBDL::showTexture(leader_board_back,rectangle);
    cup_leader_rect={305,25,100,100};
    SBDL::showTexture(cup[cup_leader_state++],cup_leader_rect);
    SBDL::showTexture(left_arrow,left_arrow_rect);
    if(cup_leader_state==25)
        cup_leader_state=0;

   if(flag_leader)
   {
       bubble_sort();
    for (int i=0;i<10;i++) {
        if (leader_bord[i].score == -1)
            continue;


        str_num = to_string(i + 1);
        str = str_num + '-';
        str_score = to_string(leader_bord[i].score);
        dot = ":";
        name_show = str + leader_bord[i].name + dot ;
        temp_leader_show[i] = SBDL::createFontTexture(font, name_show, 250, 250, 250);
        temp_leader_show_score[i]=SBDL::createFontTexture(font,str_score,250,250,250);
        flag_leader= false;
    }
   }

           for(int i=0;i<10;i++) {
               if (leader_bord[i].score == -1)
                   continue;

                   SBDL::showTexture(temp_leader_show[i], 100, 170 + 50 * i);
                   SBDL::showTexture(temp_leader_show_score[i], 530, 170 + 50 * i);
           }
    SBDL::delay(5);
           if(SBDL::mouseInRect(left_arrow_rect))
               if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
               {
                   flag_leader=true;
                   state=1;
                   SBDL::updateEvents();
               }
}
void chose_game()
{
    SBDL::showTexture(chose_mode,rectangle);
    SBDL::showTexture(left_arrow,left_arrow_rect);
    SDL_Rect here_rect[4];
    for(int i=0;i<4;i++)
        if(i%2==0)
            here_rect[i]={60,300+100*i,200,60};
    for(int i=0;i<4;i++)
        if(i%2==1)
            here_rect[i]={420,300+100*(i-1),200,60};

            SBDL::showTexture(easy_mode,here_rect[0]);
            SBDL::showTexture(normal_mode,here_rect[1]);
            SBDL::showTexture(custom_mode,here_rect[2]);
            SBDL::showTexture(hard_mode,here_rect[3]);
    for(int i=0;i<4;i++) {
        if(SBDL::mouseInRect(left_arrow_rect))
            if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
                state=1;
                SBDL::updateEvents();
                break;
            }
                if (SBDL::mouseInRect(here_rect[i])) {
            if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
                if (i == 0) {
                    game_row = 5;
                    game_col = 5;
                    bombs = 4;
                    state = 3;
                    SBDL::updateEvents();
                    return;
                } else if (i == 1) {
                    game_row = 12;
                    game_col = 12;
                    bombs = 28;
                    state = 3;
                    SBDL::updateEvents();

                    return;
                } else if (i == 2) {

                    state = 31;
                    custom_game_state = 0;
                    for (int j = 0; j < 4; j++) {
                        input_row[j] = input_cols[j] = input_bom[j] = '\0';
                    }
                    SBDL::updateEvents();
                    return;
                } else if (i == 3) {
                    game_row = 20;
                    game_col = 20;
                    bombs = 96;
                    state = 3;
                    SBDL::updateEvents();
                    return;
                }
            }
        }
    }
}
void custom_game()
{
    SBDL::showTexture(selection_game,rectangle);
    SBDL::showTexture(left_arrow,left_arrow_rect);
    SDL_Rect here_rect[3];
    here_rect[0]={350,325,100,50};
    here_rect[1]={350,410,100,50};
    here_rect[2]={350,490,100,50};
    for(int i=0;i<3;i++)
        SBDL::drawRectangle(here_rect[i],250,250,250,100);
    if(custom_game_state==0)
    {
        keyboard_custom(input_cols);
        if(strnlen(input_cols,5)>0)
        {
            Texture show_temp_cols=SBDL::createFontTexture(font,input_cols,0,0,0);
            SBDL::showTexture(show_temp_cols,375,325);
        }
        int temp_game_col=0;

        for(int i=0;input_cols[i]!='\0';i++)
        {
            temp_game_col=temp_game_col*10+(int)(input_cols[i]-48);

        }
            if(custom_game_state==1) {
                if (temp_game_col > 20 || temp_game_col==0)
                    custom_game_state--;
                else
                    game_col = temp_game_col;
            }


    }
    if(custom_game_state==1)
    {
        Texture show_temp_cols=SBDL::createFontTexture(font,input_cols,0,0,0);
        SBDL::showTexture(show_temp_cols,375,325);
        keyboard_custom(input_row);
        if(strnlen(input_row,5)>0)
        {
            Texture show_temp_row=SBDL::createFontTexture(font,input_row,0,0,0);
            SBDL::showTexture(show_temp_row,375,410);
        }
        int temp_game_row=0;
        for(int i=0;input_row[i]!='\0';i++)
        {
            temp_game_row=temp_game_row*10+(int)(input_row[i]-48);

        }
        if(custom_game_state==2) {
            if (temp_game_row > 20 || temp_game_row==0)
                custom_game_state--;
            else
                game_row = temp_game_row;
        }
    }
    if(custom_game_state==2)
    {
        Texture show_temp_cols=SBDL::createFontTexture(font,input_cols,0,0,0);
        SBDL::showTexture(show_temp_cols,375,325);
        Texture show_temp_row=SBDL::createFontTexture(font,input_row,0,0,0);
        SBDL::showTexture(show_temp_row ,375,410);
        keyboard_custom(input_bom);
        if(strnlen(input_bom,5)>0)
        {
            Texture show_temp_bom=SBDL::createFontTexture(font,input_bom,0,0,0);
            SBDL::showTexture(show_temp_bom,375,490);
        }
        int temp_game_boms=0;
        for(int i=0;input_bom[i]!='\0';i++)
        {
            temp_game_boms=temp_game_boms*10+(int)(input_bom[i]-48);

        }
        if(custom_game_state==3) {
            if (temp_game_boms > game_col*game_row/2)
                custom_game_state--;
            else
                bombs = temp_game_boms;
        }
    }
    if(SBDL::mouseInRect(left_arrow_rect))
        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED)) {
            state=30;
            SBDL::updateEvents();
        }
    if(custom_game_state==3)
    {
        state=3;
    }
}
void keyboard_custom(char number[4])
{
    int size=strnlen(number,5);
    if(custom_game_state==2)
        size--;
    if(SBDL::keyPressed(SDL_SCANCODE_0)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='0';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_1)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='1';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_2)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='2';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_3)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='3';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_4)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='4';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_5)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='5';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_6)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='6';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_7)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='7';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_8)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='8';
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_9)&&size<2)
    {
        number[strnlen(number,5)+1]='\0';
        number[strnlen(number,5)]='9';
    }
    else if(SBDL::keyReleased(SDL_SCANCODE_RETURN))
    {
        custom_game_state++;
        SBDL::updateEvents();
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_BACKSPACE))
        number[strnlen(number,5)-1]='\0';
}

