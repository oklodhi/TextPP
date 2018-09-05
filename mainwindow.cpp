// Define all functionality for application

// Include header files
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup UI
    ui->setupUi(this);
    this->setCentralWidget(ui->mainTextEdit);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->mainTextEdit->setText(QString());

}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFile = filename;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->mainTextEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save the file");
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->mainTextEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer name");
    QPrintDialog *pDialog = new QPrintDialog(&printer, this);
    if (pDialog->exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "Cannot access printer");
        return;
    }
    ui->mainTextEdit->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->mainTextEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->mainTextEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->mainTextEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->mainTextEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->mainTextEdit->redo();
}
