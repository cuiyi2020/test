#pragma once

#include <QDomDocument>
#include <QMap>
#include <QVector>

class Rxml{
public:
    Rxml();
    ~Rxml(){}
    bool add_user(const QString uname, const QString pwd);
    void remove_user(const QString uname);
    bool is_ok(const QString &uname, const QString &pwd);
    QVector<QString> get_unames();
    QStringList get_unamelist();

private:
    typedef QMap<QString, QString> Loginfo;
    void init();
    void doit();
    void write(const QString &filename, const Loginfo &rhs);
    void save(const QString &filename, QDomDocument &doc);
    void read(const QString &filename);
    void read();
    void remove(const QString &filename);
    void listdom(QDomElement &elem);
    void show();
    void change(Loginfo &lhs, const Loginfo &rhs);
    QString trans(QString rhs);

private:
    QString m_fullname;
    QString m_filename;
    Loginfo m_login_data;
    Loginfo m_in_data;
    Loginfo m_out_data;
    QVector<QString> m_unames;
    QStringList m_unamelist;
};
