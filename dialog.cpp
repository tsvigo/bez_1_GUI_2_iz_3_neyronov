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
    
    
    
    
    
    
    
    
    
    
    
    
}

Dialog::~Dialog()
{
    delete ui;
}

