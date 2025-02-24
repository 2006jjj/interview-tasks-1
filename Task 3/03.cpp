/*Задание 03
Странник пришел домой и забыл пароль для входа на двери, но у странника есть секретный документ с описанием инструкций (файл 03.txt), следуя которым, можно вспомнить пароль.

Ввод на двери выглядит таким образом:  
1 2 3
4 5 6
7 8 9

Инструкция состоит из 4 операций:
U перемещается вверх
D перемещается вниз
L перемещается влево
R перемещается вправо.

Далее в документе объясняется, что каждую кнопку, которую нужно нажать, можно найти, начав с предыдущей кнопки и двигаясь к соседним кнопкам на вводе.
Каждая строка инструкций соответствует одной кнопке, начиная с предыдущей кнопки (или, для первой строки, кнопки "5"); нажмите любую кнопку, на которой
вы находитесь, в конце каждой строки. Если ход не приводит к кнопке, игнорируйте его.

Предположим, ваши инструкции:
UL
RRDDD
LURDL
UUUUD

-Вы начинаете с "5" и двигаетесь вверх (к "2"), влево (к "1") поэтому первая кнопка - 1.
-Начиная с предыдущей кнопки ("1"), вы дважды двигаетесь вправо (к "3"), а затем три раза вниз (останавливаясь на "9" после двух ходов и игнорируя третий), заканчивая 9.
-Продолжая с "9", вы двигаетесь влево, вверх, вправо, вниз и влево, заканчивая цифрой 8.
-Наконец, вы двигаетесь вверх четыре раза (останавливаясь на "2"), затем один раз вниз, заканчивая цифрой 5.
Итак, в этом примере код ванной комнаты - 1985.
Какой код от двери в дом? */

#include <fstream> 
#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int k = 0, n = 5;
int array[5]{};
char ch;
ifstream infile("E://TEST//exam//exam3.TXT");
infile.seekg(0, ios::end);
unsigned const int sizefile = (int)infile.tellg();
cout << "size of file = " << sizefile << endl;
const int MAX = 2276;
char buffer[MAX]{};
infile.seekg(0);

while (!infile.eof())
  infile.getline(buffer, MAX, '\0');

for (int i = 0; i < MAX; i++)
{
  //cout << buffer[i];
  switch (n)
  {
    case 1: 
      switch (buffer[i]) 
      { 
        case 'U': break; 
        case 'D': n = 4; break; 
        case 'L': break;
        case 'R': n = 2; break; 
      } 
      break;
    case 2: 
      switch (buffer[i]) 
      { 
        case 'U': break;
        case 'D': n = 5; break; 
        case 'L': n = 1; break; 
        case 'R': n = 3; break; 
      } 
      break;
    case 3: 
      switch (buffer[i]) 
      { 
        case 'U': break; 
        case 'D': n = 6; break; 
        case 'L': n = 2; break; 
        case 'R': break; 
      } 
      break;
    case 4:
      switch (buffer[i])
        { 
          case 'U': n = 1; break;
          case 'D': n = 7; break; 
          case 'L': break; 
          case 'R': n = 5; break; 
        } 
      break;
    case 5: 
      switch (buffer[i])
        { 
          case 'U': n = 2; break; 
          case 'D': n = 8; break; 
          case 'L': n = 4; break; 
          case 'R': n = 6; break; 
        } 
      break;
    case 6: 
      switch (buffer[i]) 
      { 
        case 'U': n = 3; break; 
        case 'D': n = 9; break; 
        case 'L': n = 5; break; 
        case 'R': break; 
      } 
      break;
    case 7: 
      switch (buffer[i])
        { 
          case 'U': n = 4; break; 
          case 'D': break; 
          case 'L': break; 
          case 'R': n = 8; break; 
        }
      break;
    case 8: 
      switch (buffer[i]) 
      { 
        case 'U': n = 5; break; 
        case 'D': break; 
        case 'L': n = 7; break; 
        case 'R': n = 9; break; 
      } 
      break;
    case 9: 
      switch (buffer[i]) 
      { 
        case 'U': n = 6; break; 
        case 'D': break; 
        case 'L': n = 8; break; 
        case 'R': break; 
      } 
      break;
    default: 
      cout << "error!"; 
      break;
  }
  if (buffer[i + 1] == '\n')
    array[k++] = n;
}
cout << "\npin-code:";
for (int j = 0; j < 5; j++)
	cout << array[j]; 

cout << endl; system("pause"); return 0;
}
