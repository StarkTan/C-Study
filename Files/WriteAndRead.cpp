#include <fstream>
#include <iostream>

#include "WriteAndRead.h"

using namespace std;
/*
* ��д�ļ�
* �ļ���λ��д
    ofstream  ifstream  fstream
    void open(const char *filename, ios::openmode mode);

    ios::app	׷��ģʽ������д�붼׷�ӵ��ļ�ĩβ��
    ios::ate	�ļ��򿪺�λ���ļ�ĩβ��
    ios::in	���ļ����ڶ�ȡ��
    ios::out	���ļ�����д�롣
    ios::trunc	������ļ��Ѿ����ڣ������ݽ��ڴ��ļ�֮ǰ���ضϣ������ļ�������Ϊ 0��

    �ļ�ָ���ƶ�
    fileObject.seekg( n ); //��λ����n��
    fileObject.seekg( n, ios::beg ); //��ʼλ������ƶ�n��
    fileObject.seekg( n, ios::cur ); //��ǰλ������ƶ�n��
    fileObject.seekg( n, ios::end ); //ĩβλ������ƶ�n�� n ����ȡ��ֵ
*/

void writeAndRead1()
{
    char data[] = "1234567890";
    // ��дģʽ���ļ�
    ofstream outfile;
    outfile.open(FILENAME);
    outfile << data << endl; // д������
    outfile.close(); //�ر�������

    // �Զ�ģʽ���ļ�
    ifstream infile;
    infile.open(FILENAME);
    cout << "Reading from the file" << endl;
    infile >> data;
    // ����Ļ��д������
    cout << data << endl;
    // �رմ򿪵��ļ�
    infile.close();
}


void writeAndRead2() {

    char data[] = "1234567890";

    char c1, c2, c3, c4;
    fstream file;
    file.open(FILENAME, ios::in | ios::out);
    file << data << endl; // д������

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
