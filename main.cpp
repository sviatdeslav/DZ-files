#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//Вариант №18(3)

/*Задача 1(с)
Реализовать чтение заголовков файлов форматов
PNG: сигнатура и IHDR Chunk*/
/*
void readPNG(string fname){
    ifstream f;//файл f
    f.open(fname);//открыте файла f
    struct PNG_IHDR{
        unsigned int length;//длина блока
        unsigned int type;//тип блока
        unsigned int width;//ширина изображения
        unsigned int height;//высота изображения
        unsigned char depth;//глубина
        unsigned char color;//тип цвета
        unsigned char compression;//метод сжатия
        unsigned char filter;//фильтр
        unsigned char interlace;//черезстрочность
        unsigned int crc;//проверочная сумма
    };
    PNG_IHDR pnih;
    unsigned char sig[];//сигнатура
    f.read((char*) &sig, sizeof(sig));//
    f.read((char*) &pnih, sizeof(pnih));//
    f.close();//закрытие файла f

    cout<<"IHDR("<<dec<<sizeof(pnih)<<" bytes)"<<endl//
    <<"len "<<pnih.length<<" (true = " <<__builtin_bswap32(pnih.length)/*возвращает байты*//*<<")"<<endl//
    << "type " << pnih.type <<  " [(char) "
                << (char)(pnih.type)
                << (char)(pnih.type >> 8)
                << (char)(pnih.type >> 16)
                << (char)(pnih.type >> 24) << "]" << endl
    << "width   " << (int) pnih.width << " (true = " << __builtin_bswap32(pnih.width) << ")" << endl
    << "height  " << (int) pnih.height << " (true = " << __builtin_bswap32(pnih.height) << ")" << endl
    << "depth   " << (int) pnih.depth << endl
    << "cType   " << (int) pnih.color << endl
    << "compr   " << (int) pnih.compression << endl
    << "filter  " << (int) pnih.filter << endl
    << "interl  " << (int) pnih.interlace << endl
    << "crc     " << (int) pnih.crc;

    cout<<endl;
}
*/
/*Задача 3(С)
Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
считывать из файла in.txt. Результат записывать в текстовый файл out.txt
y=1/2x+1/4x+...+1/Чx*/

/*float func(float a, int b){
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
*/

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
    string kom[5]{};
    int k[5]{};
    float X[5]{};
    float Y[5]{};
    std::fstream data;
    data.open("data.txt",std::ios::in);
    if(data.is_open()){
        for(int u=0;u<5;u++){
            data>>X[u]>>Y[u]>>k[u];
            kom[u]=comanda(k[u]);
            cout<<X[u]<<" "<<Y[u]<<" "<<kom[u]<<endl;
        }
    }
    return 0;
}

