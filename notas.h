#ifndef NOTAS_H
#define NOTAS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Notas; }
QT_END_NAMESPACE

class Notas : public QMainWindow
{
    Q_OBJECT

public:
    Notas(QWidget *parent = nullptr);
    ~Notas();

private slots:
    void listar();
    void guardar();

private:
    Ui::Notas *ui;
    void limpiar();
};
#endif // NOTAS_H
