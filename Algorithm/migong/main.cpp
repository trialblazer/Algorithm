#include "Maze.h"

int main()
{
    int tmpt = 0;
    Maze m;
    while (1) {
        if (tmpt == 0) m.menu();
        //menu = 0;
		char choice = getch();
    loop:m.maprand();
		switch(choice) {
		case '1':
		    m.setmpt2(1);
		    m.setmpt1(0);
		    m.findway(Entrance1, Entrance2);
            while (m.getmpt1() == 0) {
                choice = '1';
                goto loop;
            }
			m.peoplefind();
			m.setmpt2(0);
			break;
		case '2':
			m.setmpt1(0);
			m.prmap(Entrance1, Entrance2);
			m.findway(Entrance1, Entrance2);
			break;
		case '3':
			system("cls");
			break;
		case '4':
			return 0;
		default:
            tmpt = 1;
            break;
		}
	}
}
