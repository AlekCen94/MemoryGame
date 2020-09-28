#ifndef FIELD_H
#define FIELD_H
#include<QPushButton>
#include <QPixmap>
#include <QString>
#include <QMouseEvent>
class Table;

class Field : public QPushButton
{

protected:    

    QPixmap m_Icon; // > Slika polja

    int m_Id; // > Id polja

    int m_Value; // > Vrednost polja

    bool m_Open; // > Stanje polja

    static QSize m_Size; // > Velicina polja

    QString m_Icon_Path; // > Putanja do slike polja

    static QString m_Icon_Back_Path; // > Putanja do slike pozadine polja

    Table* m_Table; // > Table objekat na kome se nalaze polja
    
public:
    Field();
    ~Field();

protected:
    void mousePressEvent(QMouseEvent *ev) override; // > Klik event



public:

    /// > Konstruktor sa parametrima
    /// \param id id vrednost polja
    /// \param value vrednost polja
    ///  \param iconPath putanja do slke polja
    ///   \param table pokazivac na tablu u kojoj se nalaze polja
    ///
    Field(int id, int value, QString iconPath, Table* table);

    /// > Metoda koja vraca true ako je polje otvoreno
    ///
    bool isOpen();

    /// Metoda koja vraca id polja
    ///
    int getId();

    /// Metoda koja vraca vrednost polja
    ///
    int getValue();

    /// Metoda koja vraca string putanje slike polja
    ///
    QString getIconPath();

    /// Metoda koja inicijalilizuje polje
    ///
    void init();

    /// Metoda koja vraca velicinu polja
    ///
    static QSize getSize();

    /// Metoda koja definise sta se desava kada se klikne na polje
    ///
    void click();

    /// Metoda koja vraca adresu table
    ///
    Table& getTable();
};



#endif // FIELD_H
