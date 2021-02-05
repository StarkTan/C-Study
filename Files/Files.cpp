#include <fstream>
#include <iostream>
using namespace std;
/*
* 读写文件
* 文件定位读写
    ofstream  ifstream  fstream
    void open(const char *filename, ios::openmode mode);

    ios::app	追加模式。所有写入都追加到文件末尾。
    ios::ate	文件打开后定位到文件末尾。
    ios::in	打开文件用于读取。
    ios::out	打开文件用于写入。
    ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。

    文件指针移动
    fileObject.seekg( n ); //定位到第n个
    fileObject.seekg( n, ios::beg ); //开始位置向后移动n个
    fileObject.seekg( n, ios::cur ); //当前位置向后移动n个
    fileObject.seekg( n, ios::end ); //末尾位置向后移动n个 n 可以取负值
*/



#define FILENAME "test.txt" // 不是语句不能加分号

void writeAndRead1();
void writeAndRead2();

void writeAndRead1()
{
    char data[] = "1234567890";
    // 以写模式打开文件
    ofstream outfile; 
    outfile.open(FILENAME);
    outfile << data << endl; // 写入数据
    outfile.close(); //关闭数据流

    // 以读模式打开文件
    ifstream infile;
    infile.open(FILENAME);
    cout << "Reading from the file" << endl;
    infile >> data;
    // 在屏幕上写入数据
    cout << data << endl;
    // 关闭打开的文件
    infile.close();
}


void writeAndRead2() {

    char data[] = "1234567890";

    char c1, c2, c3, c4;
    fstream file;
    file.open(FILENAME, ios::in|ios::out);
    file << data << endl; // 写入数据

    file.seekg(2);
    file >> c1;

    file.seekg(2, ios::beg);
    file >> c2;

    file.seekg(4, ios::cur);
    file >> c3;

    file.seekg(-9, ios::end);
    file >> c4;

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;

    file.close();

}

int main()
{
    writeAndRead1();
    writeAndRead2();
    return 0;
}


