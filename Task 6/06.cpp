/*Задание 06
Вы натыкаетесь на дверь, за которой реализуется то, что, как вы можете предположить, является реализацией двухфакторной аутентификации.
Чтобы пройти через дверь, сначала нужно провести по ней карточкой-ключом (это не проблема, она лежала на соседнем столе). Затем на маленьком
экране появляется код, который вы вводите на клавиатуре. Затем, предположительно, дверь отпирается.
К сожалению, экран был разбит. Через несколько минут вы все разобрали и поняли, как все работает.
Теперь вам осталось выяснить, что должно было отображаться на экране.
Магнитная полоса на карточке, которую вы провели, кодирует серию инструкций для экрана; эти инструкции доступны в файле 06.txt.
Экран имеет ширину 50 пикселей и высоту 6 пикселей, и способен выполнять три несколько своеобразные операции:

  -rect AxB включает все пиксели в прямоугольнике в верхнем левом углу экрана, который имеет ширину A и высоту B.
  -rotate row y=A by B сдвигает все пиксели в строке A (0 - верхняя строка) вправо на B пикселей. Пиксели, которые упадут за правый край, появятся в левом конце строки.
  -rotate column x=A by B сдвигает все пиксели в столбце A (0 - левый столбец) вниз на B пикселей. Пиксели, которые упадут снизу, появятся вверху столбца.
  
Например, вот простая последовательность на меньшем экране:
  -rect 3x2 создает небольшой прямоугольник в верхнем левом углу:
    ###....
    ###....
    .......
    
  -rotate column x=1 by 1 поворачивает второй столбец вниз на один пиксель:
    #.#....
    ###....
    .#.....
    
  -rotate row y=0 by 4 поворачивает верхнюю строку вправо на четыре пикселя:
    ....#.#
    ###....
    .#.....
    
  -rotate column x=1 by 1 снова поворачивает второй столбец на один пиксель вниз в результате чего нижний пиксель возвращается к вершине:
    .#..#.#
    #.#....
    .#.....
    
После исполнения всех инструкций, сколько пикселей на экране включены? */


#include <fstream> 
#include <iostream>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

char ch;
string str1;
string str3[200]{};
ifstream infile("E://TEST//exam//exam6.txt");
int numbers_of_strings = 0;
const unsigned int MAX = 6000;
char buffer[MAX]{};

while (!infile.eof())
  infile.getline(buffer, MAX, '\0');

int buffersize = strlen(buffer);
cout << "buffersize=" << buffersize << endl;
for (int i = 0; i < MAX; i++)
{
  if (buffer[i] == '\n')
    numbers_of_strings++;
}
cout << "numbers_of_strings=" << numbers_of_strings << endl;

for (int i = 0; i < MAX; i++)
{
  if (buffer[i] == 'r')
  {
    str1 += 'r';
    while (buffer[i] != '\n')
      str1 += buffer[++i];
  }
}


const int A = 6;
const int B = 50;
string pixels[A][B];
for (int i = 0; i < A; i++)
{
  for (int j = 0; j < B; j++)
  {
    pixels[i][j] = '.';
    cout << pixels[i][j] << ' ';
  }
  cout << endl;
}

for (int i = 0; i < A; i++)
{
  for (int j = 0; j < B; j++)
    cout << pixels[i][j] << ' ';
  cout << endl;
}

for (int i = 0; i < numbers_of_strings; i++)
{
  string ss;
  int x1 = str1.find_first_of('r');
  int x2 = str1.find_first_of('\n');
  for (int k = x1; k <= x2; k++)
    ss += str1.at(k);
  str3[i] = ss + '\0';
  ss = '\0';
  str1.erase(x1, x2 + 1);
}

cout << "str3=" << endl;
for (int i = 0; i < 6; i++)
  cout << str3[i];

for (int i = 0; i < numbers_of_strings; i++)
{
  size_t x1 = str3[i].find_first_of("1234567890");
  size_t x2 = str3[i].find_last_of("1234567890");
  int q1, q2;
  ((isdigit(str3[i][++x1]) ? q1 = atoi(str3[i].substr(--x1, 2).c_str()) : q1 = atoi(str3[i].c_str() + x1 - 1)));
  ((isdigit(str3[i][--x2]) ? q2 = atoi(str3[i].substr(x2, 2).c_str()) : q2 = atoi(str3[i].c_str() + x2 + 1)));

  int stringsize = str3[i].size();
  //cout << "q1=" << q1<<"\nq2="<<q2<<"\nstringsize="<<stringsize << endl;
  if (stringsize == 10 || stringsize == 11)
  {
    //RECT 1x1
    int r1 = q1, r2 = q2;
    for (int i = 0; i < r2; i++)
    {
      for (int j = 0; j < r1; j++)
        pixels[i][j] = '#';
    }
    
    //SORT AFTER RECT
    cout << endl;
    for (int i = 0; i < A; i++)
    {
      for (int j = 0; j < B; j++)
        cout << pixels[i][j] << ' ';
      cout << endl;
    }
  }

  if (stringsize == 21 || stringsize == 22)
  {
    //ROW
    string res1, res2;
    //1
    for (int k = 0; k < B - q2; k++)
      res1 += pixels[q1][k];
    //2
    for (int k = B - q2; k < B; k++)
      res2 += pixels[q1][k];
    cout << "res1=" << res1 << "\nres1size=" << res1.length() << endl;
    cout << "res2=" << res2 << "\nres2size=" << res2.length() << endl;

    //ROW 1 STROKA
    int n1res = -1;
    for (int k = q2; k < B; k++)
      pixels[q1][k] = res1[++n1res];
    //cout << "res1[" << n1res << "]=" << res1[n1res] << endl;

    //ROW 2 STROKA
    int n2res = -1;
    for (int k = 0; k < q2; k++)
      pixels[q1][k] = res2[++n2res];

    //SORT AFTER ROTATE RAW
    cout << endl;
    for (int i = 0; i < A; i++)
    {
      for (int j = 0; j < B; j++)
        cout << pixels[i][j] << ' ';
      cout << endl;
    }
  }

  if (stringsize == 24 || stringsize == 25)
  {
    //COLUMN
    string res3, res4;
    //1
    for (int k = 0; k < A - q2; k++)
      res3 += pixels[k][q1];
    //2
    for (int k = A - q2; k < A; k++)
      res4 += pixels[k][q1];
    cout << "res3=" << res3 << "\nres3size=" << res3.length() << endl;
    cout << "res4=" << res4 << "\nres4size=" << res4.length() << endl;
  
    //COLUMN 1 STOLBEC
    int n3res = -1;
    for (int k = q2; k < A; k++)
      pixels[k][q1] = res3[++n3res];
  
    //COLUMN 2 STOLBEC
    int n4res = -1;
    for (int k = 0; k < q2; k++)
      pixels[k][q1] = res4[++n4res];
  
    //SORT AFTER ROTATE COLUMN
    cout << endl;
    for (int i = 0; i < A; i++)
    {
      for (int j = 0; j < B; j++)
        cout << pixels[i][j] << ' ';
      cout << endl;
    }
  }
}
 
int nnn = 0;
for (int i = 0; i < A; i++)
{
  for (int j = 0; j < B; j++)
  {
    if (pixels[i][j] == "#")
      nnn++;
  }
  cout << endl;
}
 cout << "\nnnn=" << nnn << endl;

cout << endl; system("pause"); return 0;
}
