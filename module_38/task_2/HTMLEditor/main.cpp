#include <QApplication>
#include <QWidget>
#include <QPlainTextEdit>
#include <QWebEngineView>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto *mainWindow = new QWidget(nullptr);
    auto *hbox = new QHBoxLayout(mainWindow);
    auto *textEdit = new QPlainTextEdit;
    auto *webView = new QWebEngineView;

    mainWindow->setWindowTitle("Редактор HTML");


    hbox->addWidget(textEdit);
    hbox->addWidget(webView);

    QSizePolicy distributor(QSizePolicy::Preferred, QSizePolicy::Preferred);
    distributor.setHorizontalStretch(1);
    textEdit->setSizePolicy(distributor);
    webView->setSizePolicy(distributor);


    QObject::connect(textEdit, &QPlainTextEdit::textChanged, [textEdit, webView]()
    {
        webView->setHtml(textEdit->toPlainText());
    });

    mainWindow->show();
    return a.exec();
}
