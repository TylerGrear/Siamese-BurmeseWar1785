////////////////////////////////////////////
//// Tyler Grear - C++               ///////
////  The Siamese-Burmese War of 1785 //////
////////////////////////////////////////////

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;
string name;
char answer;
int score = 0;
int health = 4;
int choice;
int enlightenment = 0;
int dice = 0;
int rice = 0;
int game_over = 0;

enum Color
{
  DBLUE=1,GREEN,GREY,DRED,DPURP,BROWN,LGREY,DGREY,BLUE,LIMEG,TEAL,
  RED,PURPLE,YELLOW,WHITE,B_B
};
bool quit;
void col(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}
istream &operator>> ( istream &in, Color &c )
{
int tint;
cin >> tint;
if (tint==-1) quit=true;
c=(Color)tint;
}
void MaximizeWindow()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SMALL_RECT rc;
	rc.Left = rc.Top = 0;
	rc.Right = (short)(min(info.dwMaximumWindowSize.X, info.dwSize.X) - 1);
	rc.Bottom = (short)(min(info.dwMaximumWindowSize.Y, info.dwSize.Y) - 1);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
}

int RollCredits()
{
STARTUPINFO si;
PROCESS_INFORMATION pi;
LPTSTR szCmdline[] = {"C:\\Desktop\\Siam\\SiamCredits.exe"};
ZeroMemory( &si, sizeof(si) );
si.cb = sizeof(si);

system("pause");

if(CreateProcess(NULL, szCmdline[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi ))
    {
        MessageBox(NULL, "    Thank You For Playing - Please Wait For Credits", "", MB_OK);
        WaitForSingleObject( pi.hProcess, INFINITE );
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
    }
  else {
        char *errMessage;
        FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            GetLastError(),
            0,
            (LPTSTR) &errMessage,
            0,
            NULL
        );
        MessageBox(NULL, errMessage, "Not Success", MB_OK);
        LocalFree( errMessage );
    }

    return 0;

}
int Intro()
{
cout << "                                                                    " << endl;
cout << "              ====================================================  " << endl;
cout << "             //  Welcome to Vanion's Choose Your Own Adventure //   " << endl;
cout << "            ====================================================    " << endl;
cout << "                                                                    " << endl;
cout << "                     _..--**-.                 .-**--.._            " << endl;
cout << "                 _.-'         \\__...-----...__/        '-._        " << endl;
cout << "               .'      .:::...,'              ',...:::.     '.      " << endl;
cout << "              (     .'``'''::;                  ;::'''``'.    )     " << endl;
cout << "               \\             '-)             (-'           /       " << endl;
cout << "                 \\            /               \\          /        " << endl;
cout << "           ~~~     \\       .'.-.             .-.'.      /          " << endl;
cout << "        /~~   ~~\\   \\,       |\\o|           |o/ |    ,/          " << endl;
cout << "     /~~        ~~\\   \\'.    \\ '|  .-===-.  |' /   .'/           " << endl;
cout << "    {              }    \\     `/`;         ; `\\`    /     <9;/ ,__-==`     " << endl;
cout << "     \\  _-     -_ /     '.._ (_ |  .-===-. | _) _..'   ./~~( `)/``\\\\ \\\\ " << endl;
cout << "       ~  \\\   /  ~      `*`*-`//`/'       '\\`\\`-*~  ,-'_/// \\  )        " << endl;
cout << "    _- -   | | _- _          / /`;  .==.   ;`\\ \\     ~       XX\\\         " << endl;
cout << "      _ -  | |   -_    .---./ /  ;  .==.    ;`\\ \\             \\\\         " << endl;
cout << "           | |      / '.    `-.__)         |    `*                           " << endl;
cout << "           //\\     |  (`-.         '==.   ;                        " << endl;
cout << "              =-----\  . -`-.            /--------------------=     " << endl;
cout << "              //    \\_:_)    '*--.....-'  .   . .            \\\\\ " << endl;
cout << "              || .                          .              . ||     " << endl;
cout << "              []  .    =================================  .  []     " << endl;
cout << "              ||  .     The Siamese-Burmese War of 1785   .  ||     " << endl;
cout << "              [] .     =================================   . []     " << endl;
cout << "              |\\     \\                                  /    /|   " << endl;
cout << "              |\\\:::::::::::::::::::::::::::::::::::::::::::://|   " << endl;
cout << "              []:;:;:;:;:;:;:;:;:;:;:;:; By Tyler Grear :;:;:[]     " << endl;
cout << "              \\==============================================//    " << endl;
cout << "                                                                    " << endl;
system("pause");
cout << "                                                                    " << endl;
cout << "                                                                    " << endl;
cout << "                                                                    " << endl;
cout << "-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==" << endl;
cout << "==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-" << endl;
cout << "=-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-=" << endl;
cout << "-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==" << endl;
cout << "                                                                    " << endl;
cout << "                                                                    " << endl;
cout << "                                - How to Play -                     " << endl;
cout << "                                                                    " << endl;
cout << "                                                                    " << endl;
cout << "         1) Create a Character and Read the Introduction.           " << endl;
cout << "                                                                    " << endl;
cout << "         2) Enter the Kingdom of Siam.                              " << endl;
cout << "                                                                    " << endl;
cout << "         3) Make Good Decisions! Pay attention to Details and Clues." << endl;
cout << "                                                                    " << endl;
cout << "                                                                    " << endl;
cout << "                   ** Above All Else, Have Fun and Enjoy! **        " << endl;
cout << "                                                                    " << endl;
cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//" << endl;
cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
cout << "                                                                    " << endl;
cout << "                    Who Wishes to Enter the Siamese Kingdom?        " << endl;
cout << "                   ==========================================       " << endl;
cout << "                                                                    " << endl;
    cin >>name;
    cout << "                                                                          " << endl;
    cout << "                   All Hail " << name << "! Our Brave New Adventurer!     " << endl;
    cout << "                                                                          " << endl;
cout << "==============================================================================" << endl;
cout << "   Welcome to the Siamese-Burmese War of 1785, Here's a little background...  " << endl;
cout << "==============================================================================" << endl;
cout << "                                                                              " << endl;
cout << "     The Siamese-Burmese War (1785-1786), was known as the Nine Armies' War   " << endl;
cout << " in Siamese history because the Burmese came in nine armies, fought between   " << endl;
cout << " the Konbaung dynasty of Burma and the Chakri dynasty of resurgent Siam       " << endl;
cout << " (Thailand). King Bodawpaya of Burma pursued an ambitious campaign to expand  " << endl;
cout << " his dominions into the lands of the former Ayutthaya Kingdom. His armies     " << endl;
cout << " attacked Lanna in northern Siam, where the governor of Lampang managed to    " << endl;
cout << " partly halt the Burmese, waiting for the troops from Bangkok. As Phitsanulok " << endl;
cout << " was captured, Rama I, himself, led an army to the north.                     " << endl;
cout << "                                                                              " << endl;
cout << "     In the south, Bodawpaya lie waiting at Chedi Sam Ong. The Front Palace   " << endl;
cout << " (Maha Sura Singhanat) led his troops to the south to counter-attack the      " << endl;
cout << " Burmese that came from Ranong through Nakhon Si Thammarat, the engagements    " << endl;
cout << " occurred at Kanchanaburi. The Burmese also attacked Thalang (Phuket), where  " << endl;
cout << " the governor had just died. Chan, wife of the governor, and her sister Mook  " << endl;
cout << " gathered people to defend Thalang against the Burmese. Today, Chan and       " << endl;
cout << " Mook are revered as the two heroines, Thao Thepkrasattri and Thao Seesunthon." << endl;
cout << "                                                                              " << endl;
cout << "     The Burmese proceeded to capture Songkhla. Upon hearing the news, the    " << endl;
cout << " governors of Phatthalung Province fled. However, a monk named Phra Maha      " << endl;
cout << " headed a force of villagers against the Burmese.                             " << endl;
cout << "                                                                              " << endl;
cout << "     After the valiant Rama gathered his army, he challenged Bodawpaya        " << endl;
cout << " himself, the brave Siamese we're able to overwhelm the Burmese and scatter   " << endl;
cout << " their troops back into Burmese territory, northwest of the Siamese Kingdom.  " << endl;
cout << " Amidst all the chaos in the territory during this period many unexpected     " << endl;
cout << " Heroes were able to rise to the call of destiny. Do you have what it         " << endl;
cout << " takes to ride into battle atop a magnificent war-elephant? Maybe seek        " << endl;
cout << " enlightenment from the Historical Buddha, Shaka Nyorai, Or even stand        " << endl;
cout << " with the legendary Chan and Mook, sharing their glory in battle.             " << endl;
cout << "                                                       " << endl;
cout << "----------------------=| Entering the Kingdom of Siam |=-----------------------" << endl;
cout << "                                             " << endl;
system("pause");
}
int RiddleGameComplete()
{
    enlightenment++;
    cout << " The spirit of Chao Kam Nai Wen lets out a ground trembling laugh, the trees" << endl;
    cout << "shake with leaves and branches falling upon the moss spotted ground." << endl;
    cout << "" << endl;
    cout << "'You have done well and proven yourself worthy by wiping away your Karmic" << endl;
    cout << " residue with your wisdom, and shedding the crimes of your previous lives." << endl;
    cout << " Now you must continue onward to your destiny, I have heard things are afoot" << endl;
    cout << " in the city of Thalang. If this is not news to you, then perhaps you" << endl;
    cout << " should seek out the legendary elephants of Siam, I feel that Rama" << endl;
    cout << " is in dire need of someone with your wisdom. Go now! and remember :" << endl;
    cout << " If your not learning your not living, and if your not living you are not" << endl;
    cout << " learning. Farewell " << name << ", brave adventurer!'" << endl;
    cout << "" << endl;
    cout << "    Wisdom +1" << endl;
    cout << "" << endl;
    cout << ">> Enter '1' To Wake From Your Trance." << endl;
    cout << "" << endl;
    cout << "What Will You Do ? ";
}
int ThalangFightComplete()
{
    enlightenment++;
    cout << " " << endl;
    cout << " The fighting begins to subside, and a handful of remaining Burmese" << endl;
    cout << "scurry back to their boats and make a hasty retreat. Two short women" << endl;
    cout << "with yellow sashes wrapped around their short swords approach you..." << endl;
    cout << "'You stranger, I am Chan, and this is my sister Mook. You fought" << endl;
    cout << " with courage befitting that of the Siamese spirit! This is what" << endl;
    cout << " King Rama's armies need the most.'" << endl;
    cout << " " << endl;
    cout << " Although what Chan is saying is peaceful, it makes you uneasy as you" << endl;
    cout << "notice she is speaking in such a mundane manner while walking about," << endl;
    cout << "devoid of emotion, thrusting her sword into lifeless bodies along the" << endl;
    cout << "beach, ensuring that they will no longer be a problem for the kingdom." << endl;
    cout << " " << endl;
    cout << "'You must travel to the north, there is a forest, and near it are the" << endl;
    cout << " largest elephants in Siam. They will be fitting to start a war " << endl;
    cout << " elephant unit. This may be exactly what the King needs to overwhelm" << endl;
    cout << " the Burmese. Come, follow me to the entrance of the city, from there" << endl;
    cout << " you will begin your final journey north to the destiny which you have" << endl;
    cout << " already begun to fulfill.'" << endl;
    cout << " " << endl;
    cout << "    Courage +1" << endl;
    cout << "" << endl;
    cout << ">> Enter '1' to Return To The Entrance Of The City." << endl;
    cout << " " << endl;
    cout << "What Will You Do ? ";
}
int ThalangFight1()
{
cout << " You approach a group of villagers seemingly arguing over something." << endl;
cout << "just as you open your mouth to speak one of the villagers drops their" << endl;
cout << "jaw, points to the south and screams :" << endl;
cout << "                         'IT'S THE BURMESE!!'" << endl;
cout << " All of the villagers begin to scramble away, screaming for their lives!" << endl;
cout << "Suddenly a massive stone statue begins to tremble and shake. You turn to" << endl;
cout << "run, and all you can see is a growing shadow encompass the ground" << endl;
cout << "before you." << endl;
cout << " " << endl;
cout << ">> Enter '1' to Roll" << endl;
cout << " " << endl;
cout << ">> Enter '2' to Run" << endl;
cout << " " << endl;
cout << "What Will You Do ? ["<< name <<"] [HP:"<< health <<"] "; cin >> choice;
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 7");

if (choice == 1)
{
  cout << " " << endl;
  cout << "You roll away, barely managing to avoid the crashing statue." << endl;
}
else if (choice == 2)
{
  cout << " " << endl;
  cout << "You take one step, then everything goes black!" << endl;
  health--;
}
cout << " " << endl;
cout << "                   ["<< name <<"] [HP:"<< health <<"]" << endl;
cout << " " << endl;
}
int ThalangFight2()
{
cout << "" << endl;
cout << " A young inexperienced Burmese foot soldier rushes at you with a flint-lock" << endl;
cout << "musket drawn, screaming :" << endl;
cout << "                     AAAAAAAIIIIIIIIYYYYEEEEEEEEE!!" << endl;
cout << "" << endl;
cout << ">> Enter '1' to Jump" << endl;
cout << " " << endl;
cout << ">> Enter '2' to Scream" << endl;
cout << " " << endl;
cout << "What Will You Do ? ["<< name <<"] [HP:"<< health <<"] "; cin >> choice;
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 7");

if (choice == 1)
{
  cout << " " << endl;
  cout << " You jump straight in the air for no apparent reason at all. The young" << endl;
  cout << "soldier stops in his tracks completely confused, his head tilts slightly" << endl;
  cout << "as he evaluates what is going on. Just as your feet hit the ground a stray" << endl;
  cout << "arrow from inside the village hits him square in the chest, and he falls" << endl;
  cout << "to the ground dead. Your sporadic behavior seems to have paid off this time." << endl;
}
else if (choice == 2)
{
  cout << " " << endl;
  cout << " You stare intently at the young soldier and scream :" << endl;
  cout << "                  BOOONNNNZZZZZAAAAAAAAAAIIIIIIIIII!!" << endl;
  cout << " With a cocky smirk the soldier quickly halts and fires KABOOM!" << endl;
  health--;
}
cout << " " << endl;
cout << "                   ["<< name <<"] [HP:"<< health <<"]" << endl;
cout << " " << endl;
}
int ThalangFight3()
{
cout << "" << endl;
cout << " A group of Burmese soldiers begin to pour out of a little longboat, having not" << endl;
cout << "noticed you right away, you crouch behind a wooden barrel atop a small hill" << endl;
cout << "overlooking the shore." << endl;
cout << " " << endl;
cout << ">> Enter '1' to Jump Into A Barrel And Hide. " << endl;
cout << " " << endl;
cout << ">> Enter '2' to Roll The Barrel Down The Hill Towards The Soldiers." << endl;
cout << " " << endl;
cout << "What Will You Do ? ["<< name <<"] [HP:"<< health <<"] "; cin >> choice;
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 7");

if (choice == 1)
{
  cout << " " << endl;
  cout << " You jump into a barrel as fast as you can before the Burmese soldiers notice" << endl;
  cout << "you there. With a sigh of relief you peek out through a single knot hole in" << endl;
  cout << "the wood, just as you begin to form a sense of security you feel a tremendous" << endl;
  cout << "pain in your bottom! It would appear you chose the wrong barrel to be in, a" << endl;
  cout << "violently hissing snake is wriggling it's way around your body and biting " << endl;
  cout << "you all over!" << endl;
  health--;
}
else if (choice == 2)
{
  cout << " " << endl;
  cout << " You roll the barrel down the hill, it rapidly gains a high speed and crashes" << endl;
  cout << "into the soldiers, sending them flailing about." << endl;
}

cout << " " << endl;
cout << "                   ["<< name <<"] [HP:"<< health <<"]" << endl;
cout << " " << endl;
}
int ThalangFight4()
{
cout << "" << endl;
cout << " The city has turned into a full blown testament to chaos as the battle of " << endl;
cout << "Thalang rages onward. A group of villagers barrel out of a house, led by two" << endl;
cout << "short women, all screaming at the top of their lungs :" << endl;
cout << "                    RRRRRAAAAAAAAAAAAAAAAAAAAAAAAAA!!" << endl;
cout << " " << endl;
cout << ">> Enter '1' to Jump At The Head Of The Pack Charging The Burmese." << endl;
cout << " " << endl;
cout << ">> Enter '2' to Wait Like A Coward And Let Them Go Ahead Of You." << endl;
cout << " " << endl;
cout << "What Will You Do ? ["<< name <<"] [HP:"<< health <<"] "; cin >> choice;
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 7");

if (choice == 1)
{
  cout << " " << endl;
  cout << " You sprint in the direction of the group wildly charging the beach, merging " << endl;
  cout << "with them, and seemingly increasing the groups momentum. One of the women takes" << endl;
  cout << "two large strides, winds up, and twirls a sharp blade towards a Burmese troop." << endl;
  cout << "                        SSSHHHHHIIIIIIIIINNNNNKKKK!!" << endl;
  cout << " The blade strikes the upper chest of a Burmese foot soldier, from the look of" << endl;
  cout << "of the others surrounding him, fear has been struck into their hearts." << endl;
}
else if (choice == 2)
{
  cout << " " << endl;
  cout << " You let the group of villagers pass you as you tap your foot and yawn. While" << endl;
  cout << "you are waiting a flaming stray arrow sticks into your shoulder!" << endl;
  health--;
}
cout << " " << endl;
cout << "                   ["<< name <<"] [HP:"<< health <<"]" << endl;
cout << " " << endl;
}
int ThalangFight5()
{
cout << "" << endl;
cout << " You grab a sword from a fallen soldier and rush the Burmese! You come face" << endl;
cout << "to face with a soldier and lock eyes in what seems like an eternal split" << endl;
cout << "second." << endl;
cout << "" << endl;
cout << ">> Enter '1' to Swipe The Sword In A Sideways Motion." << endl;
cout << " " << endl;
cout << ">> Enter '2' to Swing The Sword In A Downward Motion." << endl;
cout << " " << endl;
cout << "What Will You Do ? ["<< name <<"] [HP:"<< health <<"] "; cin >> choice;
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 4");
  system("color 7");
  system("color 7");
  system("color 7");
  system("color 4");
  system("color 7");

if (choice == 1)
{
  cout << " " << endl;
  cout << " You take a step forward to slash at the Burmese soldier and he" << endl;
  cout << "ducks and pierces you in the rib with a small dagger." << endl;
  health--;
}
else if (choice == 2)
{
  cout << " " << endl;
  cout << " You raise a sword above your head and bring it down with all" << endl;
  cout << "your might! The Burmese soldier attempts to block the attack" << endl;
  cout << "with his sword but it shatters, and your sword strikes him" << endl;
  cout << "square in the forehead ... gross it's stuck." << endl;
}
cout << " " << endl;
cout << "                   ["<< name <<"] [HP:"<< health <<"]" << endl;
cout << " " << endl;
}
int ThalangBattle()
{
health = 4;
ThalangFight1();
system("pause");
ThalangFight2();
system("pause");
ThalangFight3();
system("pause");
ThalangFight4();
system("pause");
ThalangFight5();
system("pause");
if (health <= 0)
  {
  cout << " " << endl;
  cout << " After the adrenaline fades, the wounds you have sustained in battle" << endl;
  cout << "begin to wear you down. You begin to feel extremely lethargic and all you" << endl;
  cout << "want is to fall over, which you do, and close your eyes. You numbingly, " << endl;
  cout << "and strange enough willingly, drift into the void of blackness." << endl;
  cout << " " << endl;
  cout << "Your Adventure Is Over My Friend." << endl;
  cout << " " << endl;
  cout << ">> Enter '2' to Reincarnate Back In The Tranquility Garden." << endl;
  cout << " " << endl;
  cout << "What Will You Do? ";
  }
else if (health > 0)
  {
  ThalangFightComplete();
  }
}
int RiddleIntro()
{
    cout << "+=======================================================================+" << endl;
    cout << "|]]]]]]]]]]]]]]]]]'''''''''''''''''''''''''''''''''''''[[[[[[[[[[[[[[[[[|" << endl;
    cout << "|]]]]]]]]]]]]]]]      Welcome To The Test Of Wisdom      [[[[[[[[[[[[[[[|" << endl;
    cout << "|]]]]]]]]]]]]]]]]],,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,[[[[[[[[[[[[[[[[[|" << endl;
    cout << "+=======================================================================+" << endl;
    cout << " " << endl;
    cout << "" << endl;
    cout << " Welcome " << name << ", I will be asking you various riddles spanning" << endl;
    cout << "many places, and time periods from our history. Clear your mind and do " << endl;
    cout << "your best. In order to fully strip your Karmic residue you must answer" << endl;
    cout << "four of five questions correctly to show that you are worthy.         " << endl;
    cout << " " << endl;
    cout << " " << endl;
    system("pause");
}
int Riddle1()
{
        cout << " " << endl;
        cout << "Riddle 1 : [Ancient Greece ~ 600 B.C.]" << endl;
        cout << " " << endl;
        cout << "What has roots that nobody sees, is taller than trees." << endl;
        cout << "Up, up, it goes, and yet it never grows?" << endl;
        cout << "" << endl;
        cout << "A) A Desk" << endl;
        cout << "B) An Elephant" << endl;
        cout << "C) A Mountain" << endl;
        cout << "D) A Daisy" << endl;
        cout << " " << endl;
        cout << ">> " ; cin >> answer;
        cout << "" << endl;
        if (answer == 'c' || answer == 'C')
        {
        cout << "Correct! Knowledge + 1" << endl;
        score++;
        cout << "Current Score :" << score << endl;
        }
        else
        cout << "Unfortunately, That Is Incorrect" << endl;
        cout << endl;
        system("pause");
}
int Riddle2()
{
        cout << " " << endl;
        cout << "Riddle 2 : [Homer ~ 750 B.C.]" << endl;
        cout << " " << endl;
        cout << " During his travels around the island Ios, Homer came upon " << endl;
        cout << "some fishermen. He asked them how their day was going and " << endl;
        cout << "they responded with this riddle: 'What we caught, we " << endl;
        cout << "threw away; what we didn't catch, we kept. What did we keep?'" << endl;
        cout << "Unable to solve the riddle, Homer eventually died on the" << endl;
        cout << "island, refusing to leave until he discovered the answer." << endl;
        cout << "" << endl;
        cout << "A) A Cold" << endl;
        cout << "B) A Crab" << endl;
        cout << "C) Motivation" << endl;
        cout << "D) Lice" << endl;
        cout << " " << endl;
        cout << ">> " ; cin >> answer;
        cout << "" << endl;
        if (answer == 'd' || answer == 'D')
        {
        cout << "Correct! Knowledge + 1" << endl;
        score++;
        cout << "Current Score :" << score << endl;
        }
        else
        cout << "Unfortunately, That Is Incorrect" << endl;
        cout << endl;
        system("pause");
}
int Riddle3()
{
        cout << " " << endl;
        cout << "Riddle 3 : [Sumerian ~ 4000 B.C.]" << endl;
        cout << "" << endl;
        cout << " The earliest recorded riddle in human history from ancient Sumer :" << endl;
        cout << "'There is a house. One enters it blind and comes out seeing.'" << endl;
        cout << "" << endl;
        cout << "A) A Firehouse" << endl;
        cout << "B) A School " << endl;
        cout << "C) A Library" << endl;
        cout << "D) Xavier's School For Gifted Youngsters" << endl;
        cout << " " << endl;
        cout << ">> " ; cin >> answer;
        cout << "" << endl;
        if (answer == 'b' || answer == 'B')
        {
        cout << "Correct! Knowledge + 1" << endl;
        score++;
        cout << "Current Score :" << score << endl;
        }
        else
        cout << "Unfortunately, That Is Incorrect" << endl;
        cout << endl;
        system("pause");
}
int Riddle4()
{
        cout << " " << endl;
        cout << "Riddle 4 : [Norse ~ 700 A.D.]" << endl;
        cout << " " << endl;
        cout << " According to Norse legends, a man named Gestumblindi was about to be" << endl;
        cout << "imprisoned by the King, unless he could devise a riddle that would stump" << endl;
        cout << "him. One of these riddles is as follows : 'Four hang, four sprang, two" << endl;
        cout << "point the way, two ward off dogs, one dangles after, always rather dirty.'" << endl;
        cout << "" << endl;
        cout << "A) A Table" << endl;
        cout << "B) A Woman" << endl;
        cout << "C) A Cow" << endl;
        cout << "D) A Family Of Moles" << endl;
        cout << " " << endl;
        cout << ">> " ; cin >> answer;
        cout << "" << endl;
        if (answer == 'c' || answer == 'C')
        {
        cout << "Correct! Knowledge + 1" << endl;
        score++;
        cout << "Current Score :" << score << endl;
        }
        else
        cout << "Unfortunately, That Is Incorrect" << endl;
        cout << endl;
        system("pause");
}
int Riddle5()
{
        cout << " " << endl;
        cout << "Riddle 5 : [Anglo-Saxon ~ 900 A.D.]" << endl;
        cout << " " << endl;
        cout << "'I have heard of a something-or-other, growing in its nook," << endl;
        cout << "swelling and rising, pushing up its covering. Upon that boneless" << endl;
        cout << "thing a cocky-minded young woman took a grip with her hands;" << endl;
        cout << "with her apron a lord's daughter covered the tumescent thing.'" << endl;
        cout << "" << endl;
        cout << "A) Dough " << endl;
        cout << "B) A Bubble" << endl;
        cout << "C) A Honeycomb " << endl;
        cout << "D) The Moon " << endl;
        cout << " " << endl;
        cout << ">> " ; cin >> answer;
        cout << "" << endl;
        if (answer == 'a' || answer == 'A')
        {
        cout << "Correct! Knowledge + 1" << endl;
        score++;
        cout << "Current Score :" << score << endl;
        }
        else
        cout << "Unfortunately, That Is Incorrect" << endl;
        cout << endl;
        system("pause");
}
int Riddle6()
{
        cout << " " << endl;
        cout << "Riddle 6 : [Lewis Carroll - Alice in Wonderland - 1865 A.D.]" << endl;
        cout << " " << endl;
        cout << " Alice was sitting with the Mad Hatter and the Dormouse at the " << endl;
        cout << "famous tea party when riddles begin to be exchanged. The Mad Hatter" << endl;
        cout << "turns to Alice and says : 'When is a raven like a writing desk?'" << endl;
        cout << "" << endl;
        cout << "A) Always Blame It On The Cheshire Cat." << endl;
        cout << "B) When The Desk Is A Pelicans' Gull." << endl;
        cout << "C) Who Knows, Lewis Carroll Was On Drugs When He Wrote This." << endl;
        cout << "D) Neither The Mad Hatter Or Lewis Carroll Knew The Answer." << endl;
        cout << " " << endl;
        cout << ">> " ; cin >> answer;
        cout << "" << endl;
        if (answer == 'd' || answer == 'D')
        {
        cout << "Correct! Knowledge + 1" << endl;
        score++;
        cout << "Current Score :" << score << endl;
        }
        else
        cout << "Unfortunately, That Is Incorrect" << endl;
        cout << endl;
        system("pause");
}
int RiddleGame()
{
RiddleIntro();
Riddle1();
Riddle2();
Riddle3();
Riddle4();
Riddle5();
Riddle6();
  cout << "" << endl;
  cout << "You got " << score << " correct" << endl;
  cout << "" << endl;

  if (score >= 4)
  {
    RiddleGameComplete();
    score = 0;
  }
  else
  {
    score = 0;
    cout << "'That will not do, your wisdom will not overcome your previous" << endl;
    cout << " crimes, and fully strip your Karmic residue before attaining" << endl;
    cout << " true enlightenment. You must try again another time. Now get" << endl;
    cout << " out of my sight.'" << endl;
    cout << " " << endl;
    cout << ">> Enter '1' to Wake From Your Trance." << endl;
    cout << "" << endl;
    cout << "What Will You Do? ";
  }
}
int DeathTrap1()
{
cout << "You pick up a little stone statue of a monk smiling, hands raised in joy.     " << endl;
cout << "                                                                              " << endl;
system("pause");
cout << "                                                                              " << endl;
cout << "As if they had too many drinks, the statues that surrounded the one you       " << endl;
cout << "had taken begin to fall over...                                               " << endl;
cout << "                                                                              " << endl;
system("pause");
cout << "                                                                              " << endl;
cout << "Thump!                                                                        " << endl;
cout << "                                                                              " << endl;
system("pause");
cout << "                                                                              " << endl;
cout << "Whack!                                                                        " << endl;
cout << "                                                                              " << endl;
system("pause");
cout << "                                                                              " << endl;
cout << "Kaching!                                                                      " << endl;
cout << "                                                                              " << endl;
system("pause");
cout << "                                                                              " << endl;
cout << " You watch dozens of stone statues continue to fall in a spectacular           " << endl;
cout << "pattern like dominoes all throughout the area. Unfortunately as you take in   " << endl;
cout << "the sight one of the statues falls upon a hidden block and a low, grinding    " << endl;
cout << "sound breaks out. At this point you feel like quite the idiot, unfortunately   " << endl;
cout << "you had your chance to get away and you spent it like a dolt staring at       " << endl;
cout << "falling blocks. As the ground beneath you trembles, you take one last look    " << endl;
cout << "at the smiling statue that you had picked up, and suddenly feel his smile     " << endl;
cout << "seems much less sincere now, and a little more sinister.                      " << endl;
cout << "                                                                              " << endl;
system("pause");
cout << "                                                                              " << endl;
cout << "The ground beneath you gives way and you fall face first into a set of spikes!" << endl;
cout << "You are DEAD!!" << endl;
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 7");

cout << "                                                           " << endl;
cout << "Your Adventure Is Over My Friend.                          " << endl;
cout << "                                                           " << endl;
cout << ">> Enter '1' to Reincarnate Back In The Tranquility Garden." << endl;
cout << "                                                           " << endl;
cout << "What Will You Do? ";
    return 0;
}
int DeathTrap2()
{
cout << " You slowly approach the line of trees to the west, as you poke your head\n";
cout << "through the broadleaved thicket your heart stops and your eyes lock with a huge\n";
cout << "elephant, one tusk dripping blood upon it's latest victim. The moment seems\n";
cout << "to last an eternity until your logic sets in, 'I need to get out of here before\n";
cout << "this goes bad.' You take a few steps away from the tree line and begin hastily\n";
cout << "retreating back to the city. Nervously glancing over your shoulder you\n";
cout << "see the furious beast barrel through the trees, shattering them into splinters\n";
cout << "with ease. As you face forward and run away your foot catches a small chuckling\n";
cout << "Arhat statue and you plunge head first into a deep rushing stream.\n";
cout << "\n";
system("pause");
cout << "\n";
cout << " You struggle against the current, but cannot gain your footing...\n";
cout << "Your feet slip, you flip head over heels and violently hit your head on a rock.\n";
cout << "Everything fades to black...\n";
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 7");
cout << "                                                           " << endl;
cout << "Your Adventure Is Over My Friend.                          " << endl;
cout << "                                                           " << endl;
cout << ">> Enter '1' to Reincarnate Back In The Tranquility Garden." << endl;
cout << "                                                           " << endl;
cout << "What Will You Do? ";
    return 0;
}
int DeathTrap3()
{
    cout << " You grab a stick from the ground, and proceed to poke a Siamese" << endl;
    cout << "elephant in the hind quarter, you dummy. Unfortunately the elephants'" << endl;
    cout << "leg moves faster than you can put together that this is the apex of" << endl;
    cout << "idiocracy. The last thing your brain registers is the sound of" << endl;
    cout << "sticks breaking underfoot then everything fades to black..." << endl;
    cout << "Those were probably your ribs, not sticks, but you died before" << endl;
    cout << "the pain could arrive." << endl;
    cout << " " << endl;
    cout << "You are DEAD!!" << endl;
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 4");
    system("color 7");
    system("color 7");
    system("color 7");
    system("color 4");
    system("color 7");
cout << "                                                           " << endl;
cout << "Your Adventure Is Over My Friend.                          " << endl;
cout << "                                                           " << endl;
cout << ">> Enter '1' to Reincarnate Back In The Tranquility Garden." << endl;
cout << "                                                           " << endl;
cout << "What Will You Do? ";
}
int ShakaGuidance()
{
cout << "                                                                          " << endl;
cout << "    --------------------------------------------------------------------  " << endl;
cout << "     You slow your mind, taking in the scene, and release your thoughts.  " << endl;
cout << "    --------------------------------------------------------------------  " << endl;
cout << "                                                                          " << endl;
cout << "You are taken back in shock when an inner voice resounds within you!     " << endl;
cout << "                                                                          " << endl;
cout << "    'So you seek to become one with oneself?'                            " << endl;
cout << "                                                                          " << endl;
cout << "As a hearty laugh lets out the wind rises and the birds frightfully fly off." << endl;
cout << "                                                                            " << endl;
cout << "    'You make it sound so simple.'                                          " << endl;
cout << "                                                                            " << endl;
cout << "    'Perhaps it truly is, we only complicate life with our primal thoughts.'" << endl;
cout << "                                                                            " << endl;
cout << "Another thunderous laugh echoes through the garden, bouncing off the trees. " << endl;
cout << "                                                                          " << endl;
cout << "    'Within this garden lie the spirits of the Arhat and Bodhisattva.'    " << endl;
cout << "                                                                          " << endl;
cout << "    'seek them out, learn how they were able to attain such a goal.'      " << endl;
cout << "                                                                          " << endl;
cout << "The wind rises even more, you struggle to keep your footing...            " << endl;
cout << "                                                                          " << endl;
cout << "Your feet are plucked from the ground and you are blown to the east!...   " << endl;
cout << "                                                                          " << endl;
cout << ">> Enter '1' to Wake Up And Look Around.                 " << endl;
cout << "                                                         " << endl;
cout << "What Will You Do ? ";
}
int GiveRice()
{
     cout << " You cautiously hold a clump of rice bound in leaves upward in the elephants'" << endl;
     cout << "direction. He slowly approaches, almost appearing more nervous then you as you" << endl;
     cout << "are consumed within the shadow of the behemoth. With a tickling sniff from the" << endl;
     cout << "the trunk, the elephant quickly snatches the bundle, raises it high above his" << endl;
     cout << "head then drops it right down into his open mouth. He lets out a somewhat" << endl;
     cout << "comical, yet triumphant trumpet, seems a little dramatic over some rice but hey" << endl;
     cout << "we need all the victories we can get." << endl;
     cout << "" << endl;
     cout <<"    A violent shock wave explodes as a loud, echoing voice beigins to speak:" << endl;
     cout << "" << endl;
     cout << "'You have done well, I have observed you wiping away your Karmic residue from" << endl;
     cout << " your previous lives, and displaying true Siamese fighting spirit. Your trials" << endl;
     cout << " have been difficult but nothing compared to what you will soon face. Rama I is" << endl;
     cout << " in need of an ancient military unit that will spread the blood of his enemies" << endl;
     cout << " upon the ground. You must bring him the war elephants of Siamese myth" << endl;
     cout << " that will turn the tides of the war with the Burmese.'" << endl;
     cout << " " << endl;
     cout << "   'GO FORTH " << name << ", FULLFILL YOUR DESTINY AND BRING PEACE TO THE KINGDOM!'" << endl;
     cout << "" << endl;
     cout << " When the voice of Shaka Nyorai dwindles, the magnificent Siamese elephant" << endl;
     cout << "appears to bow in reverence to your new clarity of the world. You hop on top" << endl;
     cout << "of his back, put your hands on your hips with arms bent, and look onward over" << endl;
     cout << "the forests north and towards the war, inhaling deeply, prepared for your fate." << endl;
     cout << " " << endl;
     cout << "                Until You Return, Fare Thee Well, Adventurer" << endl;
     cout << " " << endl;
}
int GetRice()
{
    cout << " You walk up beneath the statue, even though you know it is made of" << endl;
    cout << "stone you are still uneasy while you rush and collect a bundle of rice" << endl;
    cout << "wrapped in green leaves, and scurry away." << endl;
    rice++;
    cout << " " << endl;
    cout << "    RICE +1" << endl;
    cout << " " << endl;
    cout << ">> Enter '1' to Head Back West To A Quaint Road." << endl;
    cout << " " << endl;
    cout << "What Will You Do ? ";
}
int GetDice()
{
    cout << " You Spartan kick a praying Arhat statue and it topples over, breaking in" << endl;
    cout << "many pieces, that was a little over the top don't you think? You see a set" << endl;
    cout << "of ivory dice on the ground where the statue was, pick them up and blow" << endl;
    cout << "the dirt off of them before dropping them in your pocket...good eye." << endl;
    dice++;
    cout << " " << endl;
    cout << "    DICE +1" << endl;
    cout << "                                                                            " << endl;
    cout << ">> Enter '1' to Inspect This Section Of The Garden Again.                   " << endl;
    cout << "                                                                            " << endl;
    cout << "What Will You Do ? ";
}
int GameComplete()
{
  if (enlightenment >= 2 && rice == 1)
  {
  GiveRice();
  cout << " " << endl;
  cout << "                               Roll Credits " << endl;
  cout << " " << endl;
  cout << "                            PART ONE : THE END" << endl;
  col(14);
  cout << "" << endl;
  cout << "                      Dedicated to Quimby and Natalia" << endl;
  cout << " " << endl;
  cout << " " << endl;
  col(7);
  RollCredits();
  cout << " " << endl;
  cout << ">> Enter '1' to Terminate Program. ";
  game_over++;
  }
  else
  {
  cout << " You do not have the appropriate requirements to continue with" << endl;
  cout << "your adventure. You must prove your wisdom and courage, also," << endl;
  cout << "do you even have anything the elephant wants? " << endl;
  cout << " " << endl;
  cout << ">> Enter '1' to Inspect This Area Again." << endl;
  cout << " " << endl;
  cout << "What Will You Do? ";
  }
}
struct Page
{
string text;
int options;
int nextpage[10];
};
const Page gamePages[] ={
    // Page 0: [Adventure Begins]
    {
    "                                                                           \n"
    "     A Tranquility Garden Outside of Thalang                               \n"
    " An overwhelming sense of calmness washes over your life as you stand      \n"
    " in a garden that many monks would consider an ideal state of tranquility. \n"
    " Prominently in the center of the garden is an amazingly detailed gold     \n"
    " statue of Shaka Nyorai, the Historical Buddha, sitting calmly with one    \n"
    " hand raised, palm facing outwards. Your nose picks up a slight trail      \n"
    " of burning incense that leads your eyes to a small copper bowl in front   \n"
    " of a few small statues of monks. Inside you see various offerings from    \n"
    " the locals to the enlightened one for guidance in life. The area here is  \n"
    " slightly more elevated than the rest of the garden, from here you can see \n"
    " broadleaved trees that act as a natural enclosure to the east and west.   \n"
    " Intricate streams intertwine throughout the garden linking together finely\n"
    " etched golden statues. These masterfully crafted statues of Arhat, and    \n"
    " Bodhisattva, are here to remind locals of the human embodiments that      \n"
    " upheld good qualities in man, and their paths to pure enlightenment.      \n"
    " It is said that when Shaka, the Enlightened entered Nirvana, the Arhat    \n"
    " were ordered to live in this world and protect the True Law. The subtle   \n"
    " sound of a light stream rushing, and the array of beautiful vegetation    \n"
    " gives you a sense of protection in such a violent world.                  \n"
    "                                                                           \n"
     ">> Enter '1' to Ask Shaka Nyorai For Guidance.            \n"
     "                                                          \n"
     ">> Enter '2' to Head South Towards Thalang.               \n"
     "                                                          \n"
     ">> Enter '3' to Head North Towards An Ominous Forest.     \n"
     "                                                          \n"
     ">> Enter '4' to Pick Up One Of The Arhat Statues.         \n"
     "                                                          \n"
     ">> Enter '5' to Head West Into A Group Of Solemn Statues. \n"
     "                                                          \n"
     "What Will You Do ? ",
        5,
        {20,12,8,11,7}
    },
    // Page 1: [Joyful Arhat]
    {
        "                                                                          \n"
        "     Amidst Hundreds of Joyful Arhat Statues                               \n"
        " As many small stone statues the eye can see are littered all about        \n"
        " this lush, green section of the garden. Most of them displaying poses     \n"
        " of joy and youth. From standing on one leg and balancing showing a        \n"
        " huge heartfelt beam, to a few little Arhats staring up at you smiling     \n"
        " with upturned hands under their cheeks. These happy little statues        \n"
        " inspire a younger and more simple spirit within you. Among the array      \n"
        " of smaller stone Arhat are larger golden statues which represent          \n"
        " important figures in the History of Theravada Buddhism. The garden        \n"
        " is incredibly well maintained by the locals, with the areas               \n"
        " surrounding each statue trimmed to perfection. A natural enclosure        \n"
        " of trees begins to the north and circles around you to the east,          \n"
        " then ending down south. Birds chirp and bees can be heard buzzing         \n"
        " around a nest, all in harmony with you standing in their realm.           \n"
        "                                                                           \n"

        ">> Enter '1' to Further Examine The Larger Statues.            \n"
        "                                                               \n"
        ">> Enter '2' to Push The Statue Of Buddha Under The Bodhi Tree.\n"
        "                                                               \n"
        ">> Enter '3' to Kick A Joyful Arhat Staue Near Your Feet.      \n"
        "                                                               \n"
        ">> Enter '4' to Return West To The Center Of The Garden.       \n"
        "                                                               \n"
        "What Will You Do ? ",
        4,                              // 2 options
        {2,3,4,0}                           // option 1 -> page 2
                                        // option 2 -> page 3
    },
    // Page 2: [Examine Statues]
    {
        "\n"
        " Three large golden statues are lined around the landscape here in a        \n"
        "spectacular display of the life of the historical Buddha. When he was known \n"
        "as Siddhartha Guatama, he was a young prince of the Sakya clan. A statue    \n"
        "depicting the young prince when he would showcase miraculous demonstrations \n"
        "of ancient archery is here, bow raised with arrow drawn. The second statue  \n"
        "is a depiction of Saddartha, meditating under a Bodhi tree. Under this tree \n"
        "is where Saddartha was said to have attained the level of enlightenment and \n"
        "became the Buddha. The third statue shows Buddha the enlightened, surrounded\n"
        "by people teaching what he had discovered. He was known for being quite     \n"
        "different than Brahmin priests, speaking in all dialects, to all castes, he \n"
        "was prejudice to none and chose the path of greatest compassion for all his \n"
        "fellow men and women.                                                       \n"
        "                                                                            \n"
        ">> Enter '1' to Inspect This Section Of The Garden Again.                   \n"
        "                                                                            \n"
        "What Will You Do ? ",
        1,
        {1}
    },
    // Page 3: [Push Buddha Statue]
    {
        "\n"
        " You brace yourself and push with all your might! Uh Oh... well this\n"
        "was very unexpected. The statue slides on damp moss as if it was\n"
        "on ice! You have completely and hilariously over shot the push, and\n"
        "topple over it as it crashes to the ground, and you along with it.\n"
        "You groan in pain as you tumble down a small hill and through a treeline...\n"
        "\n"
        "     Facing a Statue Trapped in the Roots of a Old Tree\n"
        " In front of you is quite an auspicious sight. An old statue has been\n"
        " grown over by a large trees' roots, only a massive Buddha head gazes at\n"
        " you intently from within the tree. The gnarled roots rise and fall\n"
        " scattered in all directions through the hard ground as if effortlessly.\n"
        " This sight leaves you with an unclean sensation spiritually. The dense\n"
        " trees surrounding the small clearing completely cover the well hidden\n"
        " area. The lack of sounds from birds and other animals seems to imply\n"
        " they are avoiding this place entirely. At the base of the statue, one of\n"
        " the few things visible near the ground is an inscription etched in Siamese\n"
        " which reads : 'Rawang Phi.' Even though you have no idea what that\n"
        " means, the overall ambiance of the statue encased in the roots of\n"
        " an ancient tree makes you very uneasy, and the scene reminds you that\n"
        " nature dominates man, we only live within it's grasp.\n"
        "\n"
        ">> Enter '1' to Climb Back South Up The Small Hill.       \n"
        "                                                          \n"
        ">> Enter '2' to Sit In Front Of The Tree And Meditate.    \n"
        "                                                          \n"
        "What Will You Do ? ",
        2,
        {1,5}
    },
    // Page 4: [Kick Arhat Statue]
    {
        "                                                                      \n"
        " You wind your leg up and kick a little smiling Arhat statue...OUCH!! \n"
        "Apparently it is stuck deeper in the ground than what is visible!     \n"
        "Your eyes well up and your blood begins to boil, you limp away in     \n"
        "defeat. You glance back at the statue you had kicked, now the statue  \n"
        "seems to be more snickering than smiling. One thing is for certain,    \n"
        "you sure do not feel any more enlightened.  \n"
        "                                                                            \n"
        ">> Enter '1' to Inspect This Section Of The Garden Again.                   \n"
        "                                                                            \n"
        "What Will You Do ? ",
        1,
        {1}
    },
    // Page 5: [Sit Tree - Riddle Game Call]
    {
        "\n"
        " You reverently fall to the ground and begin to meditate, releasing your\n"
        "thoughts, contemplating on our harmony within the natural world as you\n"
        "take in your surroundings.\n"
        "\n"
        " A little dust devil swirls in mischievously from out of nowhere, after\n"
        "a few seconds it begins to grow in size, encompassing and surrounding\n"
        "the ancient tree! As you cover your face from particles wildly raging about,\n"
        "a sinister voice emits from the dark cyclone which strikes fear at your core.\n"
        "\n"
        " 'You...Ah yes you, I have seen your deeds throughout many cycles reaping\n"
        "  havoc on the innocent. I know this for I am Chao Kam Nai Wen, and it is\n"
        "  my duty, yet even more so, my purpose, to exact revenge in the name of\n"
        "  Karma. Whether you are aware of it or not, each person is not innocent\n"
        "  of the crimes of their previous selves.\n"
        "\n"
        " 'However I am not without a sense of justice. Wisdom is the key to your\n"
        "  enlightenment, and a test of this you shall have. Prove to me you are\n"
        "  among the wise and answer my riddles of old, step outside the confines\n"
        "  of the self, and open your thoughts to the infinity of the universe.\n"
        "  Then, and only then will you strip away your Karmic residue.\n"
        "\n"
        ">> Enter '1' to Accept Chao Kam Nai Wen's Challenge.       \n"
        "                                                           \n"
        ">> Enter '2' to Return To The Center Of The Garden.        \n"
        "                                                           \n"
        "What Will You Do ? ",
        2,
        {6,0}
    },
    // Page 6: [ RIDDLE GAME CALL]
    {
        "\n",
        1,
        {15}
    },
    // Page 7: [Solemn Arhat]
    {
       "\n"
       "     Amidst Hundreds of Solemn Arhat Statues\n"
       " As many small stone statues the eye can see are littered all about this\n"
       " lush, green section of the garden. Most of them displaying poses of \n"
       " meditation and deference. A line of trees forms a natural enclosure\n"
       " here begining from the south and circling around to the west. Among\n"
       " the array of smaller stone Arhat are larger golden statues which represent\n"
       " important figures in the History of Mahayana Buddhism. The garden is \n"
       " incredibly maintained by the locals, with the areas surrounding each\n"
       " statue trimmed to perfection. The wind almost seems to dwindle in\n"
       " reverence to the many disciples who were left by Shaka, the enlightened,\n"
       " to enter Nirvana.\n"
       "\n"
       ">> Enter '1' to Return East To The Center Of The Garden.   \n"
       "                                                          \n"
       ">> Enter '2' to Kick A Little Praying Arhat Statue.   \n"
       "                                                          \n"
       "What Will You Do ? ",
        2,
        {0,10,}
    },
    // Page 8: [North Of Garden]
    {
       "\n"
       "     A Dirt Road on the Outskirts of a Forest\n"
       " The rolling hillsides of the Siamese Kingdom keep you in a constant\n"
       " state of awe as the veluptious hills seem to symmetrically align,\n"
       " overlapping as they rise towards the horizon on each side of the path.\n"
       " You notice a feeling of pleasure as your eyes take in the sweeping\n"
       " landscape. The well manicured dirt road that sprouts from the\n"
       " tranquility garden to the south tapers off into a narrow point leading\n"
       " north into a deep forest. Above the conopy of the trees are branches\n"
       " tandomly waving in the wind seemingly with an inviting gesture. You\n"
       " hear some rustling from within the wood as a massive elephant pokes\n"
       " his head out of the brush. It slowly takes a few steps out of the.\n"
       " forest scanning the area for anything edible, completely unintimidated\n"
       " by your presence.\n"
       "\n"
       ">> Enter '1' to Poke The War Elephant With A Stick.\n"
       "                                                          \n"
       ">> Enter '2' to Feed The War Elephant Rice.               \n"
       "                                                          \n"
       ">> Enter '3' to Head South Towards A Tranquility Garden.  \n"
       "                                                          \n"
       "What Will You Do ? ",
     3,
     {9,21,0}

    },
    // Page 9: [POKE ELEPHANT CALL]
    {
       "\n",
       1,
       {0}
    },
    // Page 10: [GET DICE CALL]
    {
       "\n",
       1,
       {7}
    },
     // Page 11: [Statues Fall Death Trap]
    {
        "\n",
        1,
        {0}
    },
     // Page 12: [South Of Garden]
    {
       "\n"
       "     Outside of a Siamese City\n"
       " You stroll along the quaint dirt road which is given cover by the trees\n"
       " along the edges. Above you can see small pieces of fruit dangling, and\n"
       " around them fly a plethora of insects going about their daily lives,\n"
       " completely oblivious to the troubles of man. In a very peculiar way you\n"
       " are almost jealous of their ignorant bliss. The sounds of wildlife \n"
       " however, are muffled by an overbearing sound of villagers' outbursts to\n"
       " the south. Beyond the trees to the east and west of the road are sweeping\n"
       " fields of wheat that playfully dance to the wind's music. Glimmers of\n"
       " light reflect off of magnificent statues to the north which are arranged\n"
       " almost as sentinels from evil spirits for the city. The trees that line\n"
       " the road abruptly end to the south as they are met by a relatively high\n"
       " stone wall where at the center is a stone arch leading into the city.\n"
       " Just above the tops of the moss-covered walls you see the tips of ancient\n"
       " temples rising to a point towards the grandeur of the eternal sky.\n"
       "\n"
       ">> Enter '1' to Head East Through A Small Break In The Brush.\n"
       "                                                             \n"
       ">> Enter '2' to Head South Through The Archway Of The City.  \n"
       "                                                             \n"
       ">> Enter '3' to Head North Back To A Tranquility Garden.     \n"
       "                                                             \n"
       "What Will You Do ? ",
        3,
        {13,14,0}

    },
     // Page 13: [Elephant Statue]
    {
       "\n"
       "     In Front of a Massive Stone Statue\n"
       " A huge granite elephant statue adorned with ornate cermonial head garb, and\n"
       " a beautifully carved harness hovers above you, trunk raised toward the\n"
       " sky as a symbol of empowerment. Atop the golden elephant rides an \n"
       " omnipotent being that looks down at you with a beneveloent smile, sitting\n"
       " with legs crossed, and hands pressed together in prayer. The figure atop\n"
       " the elephant is the Bodhisattva known as Samantabhadra, protector of those\n"
       " who teach Buddhist law. The area surrounding the statue is spotted by\n"
       " colorful flowers, and offerings such as bowls of water scented in\n"
       " sandalwood, with a few groups of brown rice wrapped in green leaves laying\n"
       " about. A small wooden ledge rests between you and the statue, an\n"
       " arrangemnt of candles with varying signs of use have been molded to the\n"
       " wood by the melting wax. You barely notice a small crack in the leg of the\n"
       " elephant, you hope this behemoth of a statue is stable, considering the\n"
       " size, there would not be much time to evade should it collapse.\n"
       "\n"
       ">> Enter '1' to Head Back West To A Quaint Road.\n"
       "                                                             \n"
       ">> Enter '2' to Get A Bundle Of Rice From Under The Statue.\n"
       "                                                             \n"
       "What Will You Do ? ",
        2,
        {12,22,}
    },
    // Page 14: [Thalang Entrance]
    {
       "\n"
       "     Within a Stone Archway in Thalang                                     \n"
       " Strewn along the path of the city, in sets of two, are ancient Khmer      \n"
       " structures made of weather worn stone that steeply elevate into a sharp   \n"
       " point at the top. To the north you see a stone archway leading through the\n"
       " countryside of Siam, light reflects subtly like a slow twinkling star     \n"
       " further down the path in front of a backdrop of dark trees. Elephants     \n"
       " sounding off like trumpets all about seems very foreign to you, it appears\n"
       " there are as many elephants meandering about the city as people. Being    \n"
       " the main use of transport and work, they are very prevolent here,         \n"
       " interacting with locals, carrying loads of supplies, and eagerly accepting\n"
       " food from small Siamese children. If you did not know any better you      \n"
       " would think this city is from the past. Mostly unaffected by the influence\n"
       " of the west, the Siamese boast being the only Kingdom in south Asia to    \n"
       " have never been colonized, and are a quite proud people. The ancient      \n"
       " roots of this culture make you feel like you are experiencing a place     \n"
       " lost by modern time. There is a great commotion coming from all throughout\n"
       " the city, even pouring out of the huts. An apparent disturbance is amiss  \n"
       " that is unfortunately tainting the beautiful environment before you. The  \n"
       " most prominent noises seem to be eminating from erradic villagers arguing \n"
       " further south.                                                            \n"
       "                                                                           \n"
       ">> Enter '1' to Head North Towards A Tranquility Garden.\n"
       "                                                        \n"
       ">> Enter '2' to Ask A Villager What The Commotion Is About.\n"
       "                                                             \n"
       ">> Enter '3' to Head West Towards The Docks Of Thalang.\n"
       "                                                             \n"
       "What Will You Do ? ",
        4,                              // number of options available to user
        {12,16,17}
    },
    // Page 15: [Awake From Trance]
    {
        "\n"
        "     Facing a Statue Trapped in the Roots of a Old Tree\n"
        " In front of you is quite an auspicious sight. An old statue has been\n"
        " grown over by a large trees' roots, only a massive Buddha head gazes at\n"
        " you intently from within the tree. The gnarled roots rise and fall\n"
        " scattered in all directions through the hard ground as if effortlessly.\n"
        " This sight leaves you with an unclean sensation spiritually. The dense\n"
        " trees surrounding the small clearing completely cover the well hidden\n"
        " area. The lack of sounds from birds and other animals seems to imply\n"
        " they are avoiding this place entirely. At the base of the statue, one of\n"
        " the few things visible near the ground is an inscription etched in Siamese\n"
        " which reads : 'Rawang Phi.' Even though you have no idea what that\n"
        " means, the overall ambiance of the statue encased in the roots of\n"
        " an ancient tree makes you very uneasy, and the scene reminds you that\n"
        " nature dominates man, we only live within it's grasp.\n"
        "\n"
        ">> Enter '1' to Climb Back South Up The Small Hill.       \n"
        "                                                          \n"
        ">> Enter '2' to Sit In Front Of The Tree And Meditate.    \n"
        "                                                          \n"
        "What Will You Do ? ",
        2,
        {1,5}
    },
    // Page 16: [THALANG BATTLE CALL]
    {
        "\n",
        2,
        {14,0}
    },
    // Page 17: [Docks Of Thalang]
    {
        "\n"
        "     Along the Docks of a Siamese City.\n"
        " A little network of small wooden docks interlock along the coast, small\n"
        " hulled ships bob up and down with the waves. Further off of the coast\n"
        " to the south, you can make out larger ships bearing banners of the\n"
        " Burmese Kingdom, they appear to be approaching. Opposite of the docks\n"
        " are columns of tattered wooden stalls where the locals buy and sell\n"
        " food from the sea. The fish market would look to be deserted until you\n"
        " spot one elderly man sitting in a chair puffing a pipe. A little\n"
        " further west the dock comes to an end where it meets a tall wall of\n"
        " broadleaved trees.\n"
        "                                                                \n"
        ">> Enter '1' to Head East Towards The Entrance Of Thalang.      \n"
        "                                                                \n"
        ">> Enter '2' to Walk West Along The Docks And Look In The Trees.\n"
        "                                                                \n"
        ">> Enter '3' to Approach The Elderly Man In The Fish Market.\n"
        "                                                             \n"
        "What Will You Do ? ",
        3,
        {14,18,19}
    },
    // Page 18: [DEATHTRAP 2 CALL]
    {
        "\n",
        1,
        {0}
    },
    // Page 19: [Fish Market Old Man]
    {
        "\n"
        "The old man looks up downtrodden, with a frown and says:\n"
        "\n"
        "'I would be inclined to play a game of dice with you, unfortunately\n"
        " I have lost mine, have you seen them?'"
        "                                                                \n"
        ">> Enter '1' to Head East Towards The Entrance Of Thalang.      \n"
        "                                                                \n"
        ">> Enter '2' to Walk West Along The Docks And Look In The Trees.\n"
        "                                                                \n"
        ">> Enter '3' to Approach The Elderly Man In The Fish Market.\n"
        "                                                             \n"
        "What Will You Do ? ",

        3,
        {14,18,19}
    },
    // Page 20: [SHAKA GUIDANCE CALL]
    {
     "\n",
        1,
        {1}
    },
    // Page 21: [GIVE RICE CALL]
    {
     "\n",
        1,
        {8}
    },
    // Page 22: [GET RICE CALL]
    {
     "\n",
        1,
        {12}
    },
    // Page 23: []
    {
     "\n",
        1,
        {0}
    },
};
int doPage(int page)
{
cout << gamePages[page].text;
if(gamePages[page].options <= 0)
  return -1;
if(page == 6)
  RiddleGame();
if(page == 11)
  DeathTrap1();
if(page == 18)
  DeathTrap2();
if(page == 16)
  ThalangBattle();
if(page == 20)
  ShakaGuidance();
if (page == 21)
  GameComplete();
if (page == 22)
  GetRice();
if (page == 9)
  DeathTrap3();
if (page == 10)
  GetDice();

int selection;
cin >> selection;
while(  selection < 1 || selection > gamePages[page].options )
  {
   cout << "You Are Doing It Wrong Genius! Press Only The Options Listed - Nothing Else!" << endl;
   cin >> selection;
  }
return gamePages[page].nextpage[ selection-1 ];
}

int main()
{
MaximizeWindow();
Intro();
int currentPage = 0;
while(currentPage >= 0 && game_over == 0)
  {
   currentPage = doPage(currentPage);
  }
return 0;
}
