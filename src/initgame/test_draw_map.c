#include "structure.h"
#include "initmap.h"

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}

void print_players(int starty, int startx){

  int x, y;

  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);
  init_pair(2,COLOR_WHITE,COLOR_RED);
  init_pair(3,COLOR_WHITE,COLOR_GREEN);
  init_pair(4,COLOR_WHITE,COLOR_YELLOW);
  init_pair(11,COLOR_WHITE,COLOR_CYAN);

  x = 1;
  y = 1;
  attron(COLOR_PAIR(1));
  mvwprintw(stdscr , y , x ,"    ");
  y++;
  mvwprintw(stdscr , y , x ,"    ");
  y--;
  attroff(COLOR_PAIR(1));

  if(startx != 0)
    x = startx-5;
  attron(COLOR_PAIR(2));
  mvwprintw(stdscr , y , x ,"    ");
  y++;
  mvwprintw(stdscr , y , x ,"    ");
  y--;
  attroff(COLOR_PAIR(2));

  if(starty != 0)
    y = starty - 3 ; x = 1;
  attron(COLOR_PAIR(3));
  mvwprintw(stdscr , y , x ,"    ");
  y++;
  mvwprintw(stdscr , y , x ,"    ");
  y--;
  attroff(COLOR_PAIR(3));

  if(startx != 0)
    x = startx-5;
  attron(COLOR_PAIR(4));
  mvwprintw(stdscr , y , x ,"    ");
  y++;
  mvwprintw(stdscr , y , x ,"    ");
  y--;
  attroff(COLOR_PAIR(4));
  
  x = COLS/2;
  
  attron(COLOR_PAIR(11));
  mvwprintw(stdscr , y , x ,"    ");
  y++;
  mvwprintw(stdscr , y , x ,"    ");
  
}

void print_map_in_middle_up(int starty,int startx,int largeur,int longeur){

  int x,y;
  int i;
  
  x = startx/8;
  y = 3 * starty/4;

  start_color();
  init_pair(9,COLOR_WHITE,COLOR_BLACK);
  init_pair(10,COLOR_BLACK,COLOR_WHITE);
  attron(COLOR_PAIR(9));
  mvprintw(1,COLS/2,"Cartagena");
  attroff(COLOR_PAIR(9));

  attron(COLOR_PAIR(10));
  for(i = 0 ; i < 2 * longeur ; i++)
      {mvwprintw(stdscr , y , x ," ");x++;}
  for(i = 0; i < largeur ; i++)
      {mvwprintw(stdscr , y , x ," ");y--;}     
  for(i = 0 ; i < longeur ; i++)
      {mvwprintw(stdscr , y , x ," ");x--;}
  y--; x++;
  for(i = 0 ; i < longeur ; i++)
      {mvwprintw(stdscr , y , x ," ");x++;}
  x--;
  for(i = 0; i < largeur ; i++)
      {mvwprintw(stdscr , y , x ," ");y--;}
  for(i = 0 ; i < longeur ; i++)
      {mvwprintw(stdscr , y , x ," ");x--;}    
  y--; x++;
  for(i = 0 ; i < 4 * longeur ; i++)
      {mvwprintw(stdscr , y , x ," ");x++;}
  y++;x--;
  for(i = 0 ; i < longeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");x--;}
  for(i = 0 ; i < largeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");y++;}
  for(i = 0 ; i < longeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");x++;}
  y++;x--;
  for(i = 0 ; i < longeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");x--;}
  x++;
  for(i = 0 ; i < largeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");y++;}
  for(i = 0 ; i < 3.3 * longeur ; i++)
      {mvwprintw(stdscr , y , x ," ");x++;}
  for(i = 0 ; i < largeur ; i++)
      {mvwprintw(stdscr , y , x ," ");y--;}
  for(i = 0 ; i < longeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");x--;}
  y--;x++;
  for(i = 0 ; i < 2 * longeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");x++;}
  y++;x--;
  for(i = 0 ; i < longeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");x--;}
  x++;
  for(i = 0 ; i < largeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");y++;}
  for(i = 0 ; i < 2.2 * longeur ; i++)
  	  {mvwprintw(stdscr , y , x ," ");x++;}
  attron(COLOR_PAIR(10));

}

void print_map_in_middle_down(int starty,int startx,int largeur, int longeur){
  int x,y;
  int i;
  
  x = startx/8;
  y = 3 * starty/4;

  y = y - largeur/2;
  
  start_color();
  attron(COLOR_PAIR(10));
  for(i = 0 ; i < 1.5 * longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x++;}
  y--;x--;
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x--;}
  for(i = 0 ; i < largeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");y--;}
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x++;}
  y--;x--;
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x--;}
  x++;
  for(i = 0 ; i < largeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");y--;}
  for(i = 0 ; i < 5.2 * longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x++;}
  for(i = 0 ; i < largeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");y++;}
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x--;}
  y++;x++;
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x++;}
  x--;
  for(i = 0 ; i < largeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");y++;}
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x--;}
  y++;x++;
  for(i = 0 ; i < 2 * longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x++;}
  y--;x--;
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x--;}
  x++;
  for(i = 0 ; i < largeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");y--;}
  for(i = 0 ; i < 3.2 * longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x++;}
  for(i = 0 ; i < largeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");y++;}
  for(i = 0 ; i < longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x--;}
  y++;x++;	
  for(i = 0 ; i < 1.5 * longeur ; i++)
  	{mvwprintw(stdscr , y , x ," ");x++;}
  attroff(COLOR_PAIR(10));
}
/*
void print_map(struct map *m,int starty, int startx){
	int x , y;
	y = starty;
	x = startx;
	
	int i;
	start_color();
	attron(COLOR_PAIR(10));
	for( i = 1 ; i < 4; i++){
		mvwprintw(stdscr, y , x , "%c", m->symbols[i]);
		x = x + 12;
	}		
	y = y - 6;
	x = x - 12;
	for (i = 4 ; i < 6 ; i++){
		mvwprintw(stdscr, y , x , "%c", m->symbols[i]);
		x = x - 12;
	}		
	attroff(COLOR_PAIR(10));	
}
*/
void print_pirate(int starty, int startx){

  int x, y;
  int i;

  start_color();
  init_pair(5,COLOR_BLUE,COLOR_BLACK);
  init_pair(6,COLOR_RED,COLOR_BLACK);
  init_pair(7,COLOR_GREEN,COLOR_BLACK);
  init_pair(8,COLOR_YELLOW,COLOR_BLACK);
  init_pair(12,COLOR_CYAN,COLOR_BLACK);

  x = startx;
  y = starty;
  for(i = 0 ; i < PIRATE ; i++)
    {
      attron(COLOR_PAIR(5));
      mvwprintw(stdscr , y , x ,"*");
      attroff(COLOR_PAIR(5));
      x = x + 2;

      attron(COLOR_PAIR(6));
      mvwprintw(stdscr , y , x ,"*");
      attroff(COLOR_PAIR(6));
      x = x + 2;
  
      attron(COLOR_PAIR(7));
      mvwprintw(stdscr , y , x ,"*");
      attroff(COLOR_PAIR(7));
      x = 2 + x;

      attron(COLOR_PAIR(8));
      mvwprintw(stdscr , y , x ,"*");
      attroff(COLOR_PAIR(8));
      x = x + 2;
      
      attron(COLOR_PAIR(12));
      mvwprintw(stdscr , y , x ,"*");
      attroff(COLOR_PAIR(12));
      
      y = 1 + y;
      x = startx;
    }
  
}

int main(void)
{	
  initscr();
  int longeur = 16;
  int largeur = 10;
  print_players(LINES,COLS);
  print_pirate(3 * LINES/4,COLS/12);
  print_map_in_middle_up(LINES,COLS,largeur,longeur);
  print_map_in_middle_down(LINES,COLS,largeur,longeur);

  /* struct map * m = NULL;
  m = random__map();
  affiche__map(m);
  assert(m != NULL);
  print_map(m,3 * LINES/4 - 2,COLS/8 +  2);*/
  refresh();		
  getch();		
  
  endwin();		

  return(EXIT_SUCCESS);
}
