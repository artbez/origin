#include "findpair.h"
#include <ctime>
#include "ui_findpair.h"

FindPair::FindPair(QWidget *parent) :
    QWidget(parent),
    gSize(2),
    buttons(QVector<QPushButton*>(2 * 2))
{
    indexOfPrev = -1;
    ui->setupUi(this);
    initAr();
    setupButtons();
}

FindPair::FindPair(int gSize, QWidget *parent):
        QWidget(parent),
        gSize(gSize),
        buttons(QVector<QPushButton*>(gSize * gSize))
{
    indexOfPrev = -1;
    ui->setupUi(this);
    initAr();
    setupButtons();
}

FindPair::~FindPair()
{
    for (int i = 0; i < buttons.size(); i++)
        delete buttons[i];
    buttons.clear();
    delete ui;
}

void FindPair::wasClicked(int index)
{
    if (wasHere.at(index) || index == indexOfPrev)
        return;

    buttons[index]->setText(QString::number(valueAr.at(index)));
    if (indexOfPrev == -1)
    {
        indexOfPrev = index;
        return;
    }
    if (valueAr.at(indexOfPrev) == valueAr.at(index))
    {
        wasHere.replace(indexOfPrev, true);
        wasHere.replace(index, true);
    }
    else
    {
        buttons[index]->setText("");
        buttons[indexOfPrev]->setText("");
    }
    indexOfPrev = -1;
}

void FindPair::initAr()
{
    srand(time(NULL));
    int numberOfZero = 0;
    for (int i = 0; i < gSize * gSize; ++i)\
    {
        int value = rand() % 2;
        if (value == 0)
            numberOfZero++;
        valueAr.append(value);
        wasHere.append(false);
    }
    if (numberOfZero % 2 != 0)
        for (int i = 0; i < gSize * gSize; ++i)
        {
            if (valueAr.at(i) == 1)
            {
                valueAr.replace(i, 0);
                break;
            }
        }
}

void FindPair::setupButtons()
{
    qsm = new QSignalMapper(this);

    QGridLayout *mainLayout = new QGridLayout(this);
    for (int i = 0; i < gSize * gSize; ++i)
    {
        QPushButton *tmp = new QPushButton(" ", this);
        buttons[i] = tmp;
        tmp->setMinimumSize(30, 30);
        QFont font = tmp->font();
        font.setPointSize(16);
        tmp->setFont(font);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        mainLayout->addWidget(tmp, i % gSize, i / gSize);
    }

    connect(qsm, SIGNAL(mapped(int)), this, SLOT(wasClicked(int)));

    setLayout(mainLayout);
}
