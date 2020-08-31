#ifndef SCRIPTCALL_H
#define SCRIPTCALL_H

#include <QObject>
#include <string>

class ScriptCall : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString display READ getString NOTIFY stringChanged)

signals:
    void stringChanged();

public slots:
    void run();
    QString string();

public:
    explicit ScriptCall(QObject *parent = nullptr);
    QString getString();
private:
    int callScript(const std::string &path);
    QString bashString{};

};

#endif // SCRIPTCALL_H
