#include "table.h"
#include "ui_table.h"
#include "field.h"
#include <QDebug>
#include <algorithm>
#include <ctime>
#include <cstdlib>


Table::Table(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Table)
{
    ui->setupUi(this);
    init();
}

Table::~Table()
{
    for(int i = 0; i<16; i++)
    {
        delete m_Fields[i];
    }
    delete ui;

}


void Table::init()
{
    m_Number_Of_Hits = 0;
    m_Selected = false;
    m_Fields.append(new Field(1,1,":/Images/batman.png",this));
    m_Fields.append(new Field(2,2,":/Images/catwoman.jpg",this));
    m_Fields.append(new Field(3,3,":/Images/joker.jpg",this));
    m_Fields.append(new Field(4,4,":/Images/Harley Quinn.jpg",this));
    m_Fields.append(new Field(5,5,":/Images/Mad Hatter.png",this));
    m_Fields.append(new Field(6,6,":/Images/riddler.png",this));
    m_Fields.append(new Field(7,7,":/Images/talia.png",this));
    m_Fields.append(new Field(8,8,":/Images/scarecrow.png",this));

    m_Fields.append(new Field(9,1,":/Images/batman.png",this));
    m_Fields.append(new Field(10,2,":/Images/catwoman.jpg",this));
    m_Fields.append(new Field(11,3,":/Images/joker.jpg",this));
    m_Fields.append(new Field(12,4,":/Images/Harley Quinn.jpg",this));
    m_Fields.append(new Field(13,5,":/Images/Mad Hatter.png",this));
    m_Fields.append(new Field(14,6,":/Images/riddler.png",this));
    m_Fields.append(new Field(15,7,":/Images/talia.png",this));
    m_Fields.append(new Field(16,8,":/Images/scarecrow.png",this));

    shuffle();

    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
        {
             ui->gridLayout->addWidget(m_Fields.at(4*i + j),i,j);

        }

}


QVector<Field*> Table::getFields()
{
    return m_Fields;
}

Field& Table::getSelectedField()
{
    return  *m_Open_Field;
}

void Table::setSelectedField(Field *selected)
{
    m_Open_Field = selected;
    if(m_Open_Field!=nullptr)
        m_Selected = true;
    else
        m_Selected = false;
}

bool Table::isSelected()
{
    return m_Selected;
}

void Table::shuffle()
{
    std::srand ( unsigned ( std::time(0) ) );

     for(int i = 0; i<16; i++)
     {
         int rand = std::rand()%16;
         m_Fields.swapItemsAt(i,rand);
     }

}

void Table::clean()
{
    for(int i = 0; i<16; i++)
    {
        m_Fields[i]->init();
        ui->gridLayout->removeWidget(m_Fields[i]);
    }
    shuffle();

    for(int i = 0; i<16; i++)
    {
        ui->gridLayout->addWidget(m_Fields[i]);
    }
    m_Number_Of_Hits = 0;
}

void Table::update()
{
    m_Number_Of_Hits++;
    if(m_Number_Of_Hits==8)
        clean();
}

void Table::on_actionNew_play_triggered()
{
    clean();

}

void Table::on_actionExit_triggered()
{
    QApplication::quit();
}
