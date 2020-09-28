#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QVector>

class Field;

QT_BEGIN_NAMESPACE
namespace Ui { class Table; }
QT_END_NAMESPACE

class Table : public QMainWindow
{
    Q_OBJECT

public:
    Table(QWidget *parent = nullptr);
    ~Table();


private:
    Ui::Table *ui;

protected:
    QVector<Field*> m_Fields; // > Vektor polja u tabeli
    Field* m_Open_Field; // > Selektovano polje
    bool m_Selected; // > Indikator da je jedno polje selektovano
    int m_Number_Of_Hits; // > Broj pogodaka

public:
    /// Metoda koja inicijalilizuje tabelu
    ///
    void init();

    /// Metoda koja vraca vektor polja
    ///
    QVector<Field*> getFields();

    /// Metoda koja vraca selektovano polje
    ///
    Field& getSelectedField();

    /// Metoda koja postavlja selektovano polje
    /// \param selected selektovano polje
    ///
    void setSelectedField(Field* selected);

    /// Metoda koja azurira broj pogodaka
    ///
    void update();

    /// Metoda koja vraca true ako je jedno polje selektovano
    ///
    bool isSelected();

    /// Metoda koja mesa redosled elemenata
    ///
    void shuffle();

    /// Metoda koja resetuje tabelu
    ///
    void clean();

private slots:
    void on_actionNew_play_triggered();
    void on_actionExit_triggered();
};
#endif // TABLE_H
