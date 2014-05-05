#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QSignalMapper>
#include <QGridLayout>

namespace Ui {
class FindPair;
}

class FindPair : public QWidget
{
    Q_OBJECT

public:
    explicit FindPair(QWidget *parent = 0);
    /// Take a size of table (gSize * gSize) buttons
    explicit FindPair(int gSize, QWidget *parent = 0);
    ~FindPair();

private slots:
    /// Slot which work when user click on a button
    void wasClicked(int index);

private:
    /// Inicialize all needed vectors
    void initAr();
    /// Inicialize buttons
    void setupButtons();
    int gSize;
    /// Index of element which was clicked before
    int indexOfPrev;
    QVector<QPushButton*> buttons;
    QSignalMapper *qsm;
    Ui::FindPair *ui;
    /// Vector which associates buttons with values(0|1) by indexes
    QVector<int> valueAr;
    /// Vector which which shows clicked we on the button with this index or not
    QVector<bool> wasHere;
};
