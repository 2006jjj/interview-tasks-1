/*Задание 04
Вы налаживаете связь между вами и штабом, но что-то идет не так и сигнал передает неправильно информацию. Но на этот случай у вас есть протокол.
В этой модели одно и то же сообщение отправляется повторно. Все, что вам нужно сделать, это выяснить, какой символ реже всего встречается для каждой позиции.
Например, предположим, что вы записали следующие сообщения:
  eedadn
  drvtee
  eandsr
  raavrd
  atevrs
  tsrnev
  sdttsa
  rasrtv
  nssdts
  ntnada
  svetve
  tesnvt
  vntsnd
  vrdear
  dvrsen
  enarar
  
Наиболее реже встречающийся символ в первом столбце - а; во втором - d; и так далее. Комбинация этих символов возвращает исправленное сообщение advent.
Учитывая то что вы записали (файл 04.txt) какое сообщение вам отправили с учетом исправления ошибок?*/

#include <fstream> 
#include <iostream> 
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

char ch;
string str = "";
const unsigned int letters_of_alphabet = 26;
int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, kk = 0;
int array[letters_of_alphabet]{ a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0 };

ifstream infile("E://TEST//exam//exam4.TXT");
infile.seekg(0, ios::end);
unsigned const int sizefile = (int)infile.tellg();
cout << "size of file = " << sizefile << endl;
const unsigned int MAX = 5980;
char buffer[MAX]{};
infile.seekg(0);
int symbols_one_str = 0;

while (!infile.eof())
  infile.getline(buffer, MAX, '\0');

int strsize = strlen(buffer);
cout << "strsize=" << strsize << endl << endl;

for (int i = 0; i < MAX; i++)
{
	if (buffer[i] == '\n')
		kk++;
	//cout << buffer[i]; все содержимое файла
}
cout << "kk=" << kk << endl;
symbols_one_str = sizefile / kk-2;
cout << "symbols_one_str=" << symbols_one_str << endl<<endl;
for (int j = 0; j < symbols_one_str; j++) 
{
  for (int i = j; i < MAX - kk - 1; i += symbols_one_str + 1)
  {
    switch (buffer[i])
    {
      case 'a': array[0]++; break;
      case 'b': array[1]++; break;
      case 'c': array[2]++; break;
      case 'd': array[3]++; break;
      case 'e': array[4]++; break;
      case 'f': array[5]++; break;
      case 'g': array[6]++; break;
      case 'h': array[7]++; break;
      case 'i': array[8]++; break;
      case 'j': array[9]++; break;
      case 'k': array[10]++; break;
      case 'l': array[11]++; break;
      case 'm': array[12]++; break;
      case 'n': array[13]++; break;
      case 'o': array[14]++; break;
      case 'p': array[15]++; break;
      case 'q': array[16]++; break;
      case 'r': array[17]++; break;
      case 's': array[18]++; break;
      case 't': array[19]++; break;
      case 'u': array[20]++; break;
      case 'v': array[21]++; break;
      case 'w': array[22]++; break;
      case 'x': array[23]++; break;
      case 'y': array[24]++; break;
      case 'z': array[25]++; break;
      default:
        cout << "error1"; 
        break;
    }
  }

/* отладочная печать
for (int j = 0; j < 26; j++)
  cout << "array[" << j << "]=" << array[j] << endl;*/

int min = array[0];
int index = 0;
for (int j = 1; j < 26; ++j)
{
  if (array[j] < min)
  {
    min = array[j];
    index = j;
  }
}
cout << j+1 <<  ") Index of minimal element=" << index << " min=" << min << endl;

switch (index)
{
  case 0: str += 'a'; break;
  case 1: str += 'b'; break;
  case 2: str += 'c'; break;
  case 3: str += 'd'; break;
  case 4: str += 'e'; break;
  case 5: str += 'f'; break;
  case 6: str += 'g'; break;
  case 7: str += 'h'; break;
  case 8: str += 'i'; break;
  case 9: str += 'j'; break;
  case 10:str += 'k'; break;
  case 11:str += 'l'; break;
  case 12:str += 'm'; break;
  case 13:str += 'n'; break;
  case 14:str += 'o'; break;
  case 15:str += 'p'; break;
  case 16:str += 'q'; break;
  case 17:str += 'r'; break;
  case 18:str += 's'; break;
  case 19:str += 't'; break;
  case 20:str += 'u'; break;
  case 21:str += 'v'; break;
  case 22:str += 'w'; break;
  case 23:str += 'x'; break;
  case 24:str += 'y'; break;
  case 25:str += 'z'; break;
  default: 
    cout << "error2"; 
    break;
}

for (int j = 0; j < 26; j++)
  array[j] = 0;
}
cout << "\nОтвет:" << str << endl; 

cout << endl; system("pause"); return 0;
}
