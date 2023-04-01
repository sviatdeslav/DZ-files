#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//Вариант №18(3)

/*Задача 1(с)
Реализовать чтение заголовков файлов форматов
PNG: сигнатура и IHDR Chunk*/

int main(){
    std::ifstream png;
    png.open("sevgu1.PNG",std::ios::in);
    if (png.is_open()) {
        #pragma pack(push,1)//задает текущее значение выравнивания упаковки на 1 байт
        struct Png_str{
            unsigned int length;//длина блока
            unsigned int type;//тип блока
            unsigned int width;//ширина изображения
            unsigned int height;//высота изображения
            unsigned char depth;//глубина
            unsigned char color;//тип цвета
            unsigned char compression;//метод сжатия
            unsigned char filter;//фильтр
            unsigned char interlace;//черезстрочность
            unsigned int crc;//"контрольная" сумма
        };
        #pragma pack(pop);//удаляет запись из верхней части области временного хранения данных компилятора
        Png_str object;//объект
        unsigned char sign[8];//сигнатура
        png.read((char*)&sign,8);
        png.read((char*)&object,sizeof(object));
        png.close();
        cout<<"Signature(hex): "<<showbase<<hex
           <<+sign[0]<<" "<<+sign[1]<<" "<<+sign[2]<<" "<<+sign[3]<<" "<<+sign[4]<<" "
           <<+sign[5]<<" "<<+sign[6]<<" "<<+sign[7]<<" "<<endl;
        cout<<"Chunk IHDR("<<dec<<sizeof(object)<<" bytes)"<<endl;
        cout<<"length "<<object.length<<" (true = "<<__builtin_bswap32(object.length)<<")"<<endl;
        cout<<"type "<<object.type<<" [(char) "<<(char)(object.type)<<(char)(object.type>>8)
           <<(char)(object.type>>16)<<(char)(object.type>>24)<<"]"<<endl;
        cout<<"width "<<(int)object.width<<" (true = "<<__builtin_bswap32(object.width)<<")"<<endl;
        cout<<"height "<<(int)object.height<<" (true = "<<__builtin_bswap32(object.height)<<")"<<endl;
        cout<<"depth "<<(int)object.depth<<endl;
        cout<<"color "<<(int)object.color<<endl;
        cout<< "compression "<<(int)object.compression<<endl;
        cout<< "filter "<<(int)object.filter<<endl;
        cout<< "interl "<<(int)object.interlace<<endl;
        cout<<"crc "<<(int)object.crc;
    }
}


/*Задача 3(С)
Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
считывать из файла in.txt. Результат записывать в текстовый файл out.txt
y=1/2x+1/4x+...+1/Чx*/

float func(float a, int b){
    float c=0;
    int n=2;
    while(n<=b){
        c+=1/(n*a);
        n+=2;
    }
    return c;
}

int main(){
    float x,dx,xf;
    int Ch;
    std::fstream fin,fout;
    fin.open("in.txt",std::ios::in);
    if(fin.is_open()){
        fin>>x>>dx>>xf>>Ch;
        fin.close();
        fout.open("out.txt",std::ios::out);
        while (x<=xf){
            fout<<func(x,Ch)<<endl;
            x+=dx;
        }
        fout.close();
    }
    return 0;
}

/*Задача 6
Разработать программу для считывания полётных данных о квадрокоптерах из
файла. Одна строка содержит: Х,У,Команда, где ХУ – координаты, а Команда – это
набор чисел, характеризующих действие коптера: 10 – взлёт, 20 – посадка, 50 –
полёт, 60 – набрать высоту, 70 снизить высоту. Каждая новая строка содержит
новый набор координат и команд. Организовать переменные для хранения информации*/

string comanda(int r){
    if (r==10)
        return "Start";
    if (r==20)
        return "Finish";
    if (r==50)
        return "Fly";
    if (r==60)
        return "Up";
    if (r==70)
        return "Down";
}

int main(){
    int N;
    std::ifstream data;
    data.open("data.txt",std::ios::in);
    if(data.is_open()){
        data>>N;
        string kom[N]{};
        int k[N]{};
        float X[N]{};
        float Y[N]{};
        for(int u=0;u<5;u++){
            data>>X[u]>>Y[u]>>k[u];
            kom[u]=comanda(k[u]);
            cout<<X[u]<<" "<<Y[u]<<" "<<kom[u]<<endl;
        }
    }
    return 0;
}

