#include <iostream>
#include <fstream>


using namespace std;

struct Sensor {
    int sensor_id;
    float sicaklik;
};

int main()
{
    long long int student_id;
    Sensor temp;
    int firstTemp=0;
    cout<< "Enter your student id:"<<student_id<<endl;
    cin<<student_id;
    int N=student_id %50;
    int E=student_id %100;

    fstream Sensor("sensors.bin", ios::in | ios::out | ios::binary);

    Sensor.seekp(N, ios::beg);
    Sensor.read(char*)&temp,sizeof(temp);
    temp.sicaklik +=E;

    Sensor.seekp(E, ios::cur);
    Sensor.read(char*)&temp,sizeof(temp);
    Sensor.close();

    fstream student(student_id + "Quiz.txt",ios::out);

    student<<"NUMBER:" +student_id<<endl;
    student<<"Sensor �ndex used in the process:" +N<<endl;
    student<<"First tempature:"<<firstTemp<< ->New tempature:<<temp.sicaklik<<endl;

}
