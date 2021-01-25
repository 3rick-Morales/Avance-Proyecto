#include "notas.h"
#include "ui_notas.h"

#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QMessageBox>

Notas::Notas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notas)
{
    ui->setupUi(this);
    connect(ui->cmdListar, SIGNAL(released()),
            this, SLOT(listar()));
    connect(ui->mnuListar, SIGNAL(triggered()),
            this, SLOT(listar()));
    connect(ui->mnuGuardar, SIGNAL(triggered()),
            this, SLOT(guardar()));
}

Notas::~Notas()
{
    delete ui;
}

void Notas::listar()
{
    QString nombre;
    QString apellido;
    nombre=ui->inNombre->text();
    apellido=ui->inApellido->text();
    //Impremir Nombres
    QString resultado = nombre +"  "+ apellido;
    ui->outLista->appendPlainText(resultado);
    limpiar();
}

void Notas::guardar()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Guerdar Datos", QDir::home().absolutePath(), "Archivo de texto(.txt)");
    QFile data(fileName);
    if (data.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream salida(&data);
        salida << ui->outLista->toPlainText();
        ui->statusbar->showMessage("Datos Almacenados en: " + fileName, 5000);
    }
}

void Notas::limpiar()
{
    ui->inApellido->setText(" ");
    ui->inNombre->setText(" ");
}
