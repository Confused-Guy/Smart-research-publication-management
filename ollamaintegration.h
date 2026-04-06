#ifndef OLLAMAINTEGRATION_H
#define OLLAMAINTEGRATION_H

#include <QString>
#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

class OllamaIntegration : public QObject
{
    Q_OBJECT

public:
    OllamaIntegration(QObject *parent = nullptr);
    ~OllamaIntegration();

    // Check if Ollama is available
    bool isOllamaAvailable();

    // Get acceptance probability (returns 0-100)
    // This is synchronous and will block until response is received or timeout
    int checkManuscriptAcceptance(const QString &manuscriptText, const QString &model = "llama3.1:8b");

    // Get list of available models
    QStringList getAvailableModels();

    // Set Ollama server URL (default: http://localhost:11434)
    void setOllamaUrl(const QString &url);

private:
    QString ollamaUrl;
    QNetworkAccessManager *networkManager;

    // Helper to make HTTP POST requests and get response
    QString makeHttpRequest(const QString &endpoint, const QString &payload);
};

#endif // OLLAMAINTEGRATION_H
