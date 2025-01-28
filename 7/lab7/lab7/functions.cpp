#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push1(int x, Stack1*& myStk1)   //���������� �������� � � ����  
{
    Stack1* e1 = new Stack1;
    cout << "->" << x << endl;//��������� ������ ��� ������ ��������
    e1->data1 = x;             //������ �������� x � ���� data 
    e1->next = myStk1;         //������� ������� �� ��������� ������� 
    myStk1 = e1;               //����� ������� �� ������� ������
}

void push2(int y, Stack2*& myStk2)   //���������� �������� y � ����  
{
    Stack2* e2 = new Stack2;
    cout << "->" << y << endl; //��������� ������ ��� ������ ��������
    e2->data2 = y;             //������ �������� y � ���� data 
    e2->next = myStk2;         //������� ������� �� ��������� ������� 
    myStk2 = e2;              //����� ������� �� ������� ������
}

void push3(Stack3*& myStk3, Stack1*& myStk1, Stack2*& myStk2)
{
    int i = 0, j = 0;
    bool flag = true;
    Stack1* e = myStk1;
    Stack2* d = myStk2;
    Stack3* c = myStk3;

    while (e != NULL) { // ������� ��������� 1 �����
        i++;
        e = e->next;
    }
    e = myStk1;

    while (d != NULL) { // ������� ��������� 2 �����
        j++;
        d = d->next;
    }
    d = myStk2;

    for (int a = 0; a < i; a++) {

        for (int b = 0; b < j; b++) {

            if (e->data1 == d->data2) {
                flag = false;
            }
        }
        if (flag == true) {
            Stack3* c = new Stack3;
            c->data3 = e->data1;
            c->next = myStk3;
            myStk3 = c;

            d = d->next;
            d = myStk2;
        }

        e = e->next;
        flag = true;
    }
    e = myStk1;
    d = myStk2;
    c = myStk3;
    while (c != NULL) { // �����
        cout << c->data3;
        cout << "->>";
        c = c->next;
    }
    c = myStk3;

}

char popStack1(Stack1*& myStk1)   //���������� �������� �� ����� �1
{
    if (myStk1 == NULL)
    {
        cout << "���� ����!" << endl;
        return -1;               //���� ���� ���� - ������� (-1) 
    }
    else
    {
        Stack1* e = myStk1;        //���������� ��� �������� ������ ��������
        char x = myStk1->data1;    //������ �������� �� ���� data � x 
        if (myStk1)
            myStk1 = myStk1->next;   //������� �������
        delete e;
        return x;
    }
}

char popStack2(Stack2*& myStk2)   //���������� �������� �� ����� �2
{
    if (myStk2 == NULL)
    {
        cout << "���� ����!" << endl;
        return -1;               //���� ���� ���� - ������� (-1) 
    }
    else
    {
        Stack2* d = myStk2;        //���������� ��� �������� ������ ��������
        char y = myStk2->data2;    //������ �������� �� ���� data � y 
        if (myStk2)
            myStk2 = myStk2->next;   //������� �������
        delete d;
        return y;
    }
}

void toFile(Stack1*& myStk1) //������ � ����
{
    Stack1* e = myStk1;
    Stack1 buf;
    ofstream frm("Stack1.txt");
    while (e)
    {
        buf = *e;
        frm.write((char*)&buf, sizeof(Stack1));
        e = e->next;
    }
    frm.close();
    cout << "���� �������\n";
}

void fromFile(Stack1*& myStk1)          //���������� �� �����
{
    Stack1 buf, * p = nullptr, * e = nullptr;
    ifstream frm("Stack1.txt");
    frm.seekg(0);
    frm.read((char*)&buf, sizeof(Stack1));
    while (!frm.eof())
    {
        push1(buf.data1, e);
        frm.read((char*)&buf, sizeof(Stack1));
    }
    frm.close();
    while (e != NULL)
    {
        buf.data1 = popStack1(e);
        push1(buf.data1, p);
        myStk1 = p;
    }
    cout << "\n���� ������\n\n";
}