#include "dialog.h"
#include "ui_dialog.h"
//########################################################################################################
#include <fstream>
#include <iostream>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
using namespace std;
#include <unistd.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////
int variable_synapse_index_counter=2; 
long long variable_error;
int var ;
QString Nazvaniye_fayla_s_neyronami_i_signalom;
std::vector<unsigned long long> list_of_neurons; // сеть содержит 3 нейрона
std::vector<unsigned long long> list_of_synapses; // сеть содержит 2 синапса
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
    std::cout << "bez_1_GUI_2_iz_3_neyronov" << std::endl;    
//########################################################################################################
/// Сначала укажем какой файл с нейронами подстроить.
   Nazvaniye_fayla_s_neyronami_i_signalom="/home/viktor/my_projects_qt_2/bez_1_GUI_2_iz_3_neyronov/neyrons.txt"; 
//########################################################################################################
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор   

const QString& fileName=Nazvaniye_fayla_s_neyronami_i_signalom;
{
    std::ifstream file(fileName.toStdString().c_str());
    if (file.is_open()) {
        unsigned long long value;
        while (file >> value) {
            list_of_neurons.push_back(value);
        }
        file.close();
    } else {
        qDebug() << "Unable to open file: " << fileName;
    }
}
//########################################################################################################      
//     /home/viktor/my_projects_qt_2/bez_1_GUI_2_iz_3_neyronov/synapses.txt
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// загрузка синапсов из файла в вектор

    QFile file(  "/home/viktor/my_projects_qt_2/bez_1_GUI_2_iz_3_neyronov/synapses.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        throw std::runtime_error("Failed to open file");
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
        unsigned long long synaps = line.toULongLong(&ok);
        if (!ok) {
            throw std::runtime_error("Invalid synaps value in file");
        }
        list_of_synapses.push_back(synaps);
    }

    file.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
 qDebug()  << "нейронов: " << list_of_neurons.size();
     //  std::cout 
   qDebug()     << "нейрон 0: " << list_of_neurons[0];
 //  std::cout
  qDebug()  << "синапсов: " << list_of_synapses.size();
      qDebug() << "синапс 0: " << list_of_synapses[0];    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: решение
//////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
b: list_of_neurons[1] = (list_of_neurons[0]/ list_of_synapses[0])-list_of_neurons[1];
 list_of_neurons[2] = (list_of_neurons[1]/ list_of_synapses[1])-list_of_neurons[2];
 
  variable_error     = 1073741824-  list_of_neurons[2] ; // WARNING: изменение
//########################################################################################################      
  std::cout << "variable_error = " << variable_error<< std::endl;   
     if  ( variable_error <0)
    {
        
        std::cout << "Программа считает что это 1." << std::endl;
        
             if (list_of_synapses[variable_synapse_index_counter] < 2147483646 ) // < 2147483646 или > 1
     {
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]+1;  // +1 или -1
       goto b;   
     }
   
    }
    else {        std::cout << "Программа считает что это не 1." << std::endl;   goto d;  }
//########################################################################################################    
    d: ;;
    
    
    
    
    
}

Dialog::~Dialog()
{
    delete ui;
}

