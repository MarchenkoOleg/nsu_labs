#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

#include "game.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionnew_game_triggered();
    void on_actionsave_game_triggered();
    void on_actionopen_saved_game_triggered();

    void reprintField(const std::string & key);

    void on_tableWidget_myField_cellClicked(int row, int column);
    void on_tableWidget_enemyField_cellClicked(int row, int column);
    void on_tableWidget_myField_cellDoubleClicked(int row, int column);

    void autoPlace();
    void clearField();
    void checkPlacing();
    const std::array<Cell, 100> & getFieldInstace(const std::string & key) const;
    void meAttack(int x, int y);
    void enemyAttack();
    void endGame(const QString & str);

    void on_tableWidget_myField_clicked(const QModelIndex &index);

    void on_tableWidget_myField_cellActivated(int row, int column);

private:
    Ui::MainWindow *ui;
    QIcon img_point, img_cross;

    computerPlayer comp;
    Game seaBattle;
    Field myField, enemyField;
    std::array<Cell, 100> shootedPoints;

};

#endif // MAINWINDOW_H
