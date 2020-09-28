#include "field.h"
#include<QDebug>
#include "table.h"



QSize Field::m_Size {QSize(200,200)};
QString Field::m_Icon_Back_Path {QString(":/Images/close.jpg")};

Field::Field()
{
    init();
}
Field::Field(int id, int value, QString iconPath, Table* table)
{
    m_Id = id;
    m_Value = value;
    m_Icon_Path = iconPath;
    m_Table = table;
    init();
}
Field::~Field()
{
    m_Table = nullptr;
}

void Field::mousePressEvent(QMouseEvent *ev)
{
    click();
}

void Field::click()
{
    if(m_Open)
    {
        m_Open = !m_Open;
        m_Icon.load(m_Icon_Back_Path);
        QIcon ButtonIcon1(m_Icon);
        setIcon(ButtonIcon1);
        setIconSize(m_Size);
        m_Table->setSelectedField(nullptr);
    }
    else
    {
        m_Open = !m_Open;
        m_Icon.load(m_Icon_Path);
        QIcon ButtonIcon1(m_Icon);
        setIcon(ButtonIcon1);
        setIconSize(m_Size);

        if(m_Table->isSelected())
        {
            if(m_Table->getSelectedField().getValue()==this->m_Value)
            {
                m_Table->getSelectedField().setEnabled(false);
                this->setEnabled(false);
                m_Table->update();
            }
            else
            {
                m_Table->getSelectedField().init();
                init();
            }
            m_Table->setSelectedField(nullptr);
        }
        else
        {
            m_Table->setSelectedField(this);
        }
    }
}

void Field::init()
{
    m_Open = false;
    m_Icon.load(m_Icon_Back_Path);
    QIcon ButtonIcon(m_Icon);
    setIcon(ButtonIcon);
    setIconSize(m_Size);
    setEnabled(true);
}

Table& Field::getTable()
{
    return *m_Table;
}

bool Field::isOpen()
{
    return m_Open;
}

int Field::getId()
{
    return m_Id;
}

int Field::getValue()
{
    return m_Value;
}

QString Field::getIconPath()
{
    return m_Icon_Path;
}

QSize Field::getSize()
{
    return m_Size;
}
