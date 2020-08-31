#include "scriptcall.h"

void ScriptCall::run()
{

    std::string path = "/home/najmroczniejszy/Documents/Programs/QT/3DLab/lib/bash.sh";
    callScript(path);
}

QString ScriptCall::string()
{
    return getString();
}

ScriptCall::ScriptCall(QObject *parent) : QObject(parent)
{

}

int ScriptCall::callScript(const std::string &path)
{
    FILE * stream;
    const int max_buffer = 31;
    char buffer[max_buffer];

    stream = popen(path.c_str(), "r");
    if (stream)
    {
        bashString.clear();
        while (!feof(stream))
        {
            if (fgets(buffer, max_buffer, stream) != NULL)
                bashString.append(buffer);
        }
        pclose(stream);
    }
    else
        return -1;

    emit stringChanged();
    return 0;
}

QString ScriptCall::getString()
{
    return bashString;
}
