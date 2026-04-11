#include "ollamaintegration.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>
#include <QRegularExpression>

OllamaIntegration::OllamaIntegration(QObject *parent)
    : QObject(parent), ollamaUrl("http://localhost:11434")
{
    networkManager = new QNetworkAccessManager(this);
}

OllamaIntegration::~OllamaIntegration()
{
}

void OllamaIntegration::setOllamaUrl(const QString &url)
{
    ollamaUrl = url;
    if (ollamaUrl.endsWith('/')) {
        ollamaUrl.chop(1);
    }
}

bool OllamaIntegration::isOllamaAvailable()
{
    // Try to reach the Ollama API
    QUrl url(ollamaUrl + "/api/tags");
    QNetworkRequest request(url);

    QNetworkReply *reply = networkManager->get(request);

    // Wait for response with timeout
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(3000); // 3 second timeout

    loop.exec();

    if (timer.isActive()) {
        timer.stop();
    }
    else {
        reply->abort();
        reply->deleteLater();
        return false;
    }

    bool available = (reply->error() == QNetworkReply::NoError);
    reply->deleteLater();

    return available;
}

int OllamaIntegration::checkManuscriptAcceptance(const QString &manuscriptText, const QString &model)
{
    // Create a prompt for checking manuscript acceptance probability
    QString prompt = QString(
        "Based on the following research manuscript/draft, provide ONLY a single number between 0 and 100 "
        "representing the probability (as a percentage) that this research would be accepted at a top-tier conference. "
        "Consider factors like clarity, methodology, novelty, and presentation. "
        "Respond with ONLY the number (e.g., '75'), nothing else.\n\n"
        "MANUSCRIPT:\n\n%1"
    ).arg(manuscriptText);

    // Create JSON request
    QJsonObject requestObj;
    requestObj["model"] = model;
    requestObj["prompt"] = prompt;
    requestObj["stream"] = false;

    QJsonDocument doc(requestObj);
    QString payload = doc.toJson(QJsonDocument::Compact);

    // Make request
    QUrl url(ollamaUrl + "/api/generate");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = networkManager->post(request, payload.toUtf8());

    // Wait for response with timeout
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(60000); // 60 second timeout

    loop.exec();

    int percentage = -1;

    if (timer.isActive()) {
        timer.stop();

        if (reply->error() == QNetworkReply::NoError) {
            // Parse response
            QByteArray responseData = reply->readAll();
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);

            if (responseDoc.isObject()) {
                QJsonObject obj = responseDoc.object();
                if (obj.contains("response")) {
                    QString responseText = obj["response"].toString().trimmed();

                    // Try to extract the percentage number
                    bool ok;
                    percentage = responseText.toInt(&ok);

                    // Validate range
                    if (!ok || percentage < 0 || percentage > 100) {
                        // Try to extract a number from the response
                        QRegularExpression rx("\\d+");
                        QRegularExpressionMatch match = rx.match(responseText);
                        if (match.hasMatch()) {
                            percentage = match.captured(0).toInt(&ok);
                            if (ok && percentage >= 0 && percentage <= 100) {
                                qDebug() << "Extracted percentage:" << percentage;
                            }
                            else {
                                percentage = -1;
                            }
                        }
                    }

                    qDebug() << "AI Response:" << responseText;
                    qDebug() << "Extracted Percentage:" << percentage;
                }
            }
        }
        else {
            qDebug() << "Network error:" << reply->errorString();
        }
    }
    else {
        qDebug() << "Request timeout";
        reply->abort();
    }

    reply->deleteLater();

    return percentage;
}

QStringList OllamaIntegration::getAvailableModels()
{
    QStringList models;

    QUrl url(ollamaUrl + "/api/tags");
    QNetworkRequest request(url);

    QNetworkReply *reply = networkManager->get(request);

    // Wait for response
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(5000); // 5 second timeout

    loop.exec();

    if (timer.isActive()) {
        timer.stop();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(responseData);

            if (doc.isObject()) {
                QJsonObject obj = doc.object();
                if (obj.contains("models")) {
                    QJsonArray modelsArray = obj["models"].toArray();
                    for (const auto &modelValue : modelsArray) {
                        if (modelValue.isObject()) {
                            QString modelName = modelValue.toObject()["name"].toString();
                            if (!modelName.isEmpty()) {
                                models.append(modelName);
                            }
                        }
                    }
                }
            }
        }
    }

    reply->deleteLater();

    return models;
}

QString OllamaIntegration::makeHttpRequest(const QString &endpoint, const QString &payload)
{
    QUrl url(ollamaUrl + endpoint);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = networkManager->post(request, payload.toUtf8());

    // Wait for response
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(30000); // 30 second timeout

    loop.exec();

    QString result;

    if (timer.isActive()) {
        timer.stop();
        if (reply->error() == QNetworkReply::NoError) {
            result = QString::fromUtf8(reply->readAll());
        }
    }

    reply->deleteLater();

    return result;
}
