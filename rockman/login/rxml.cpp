#include "rxml.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QCryptographicHash>
#define hash_type (QCryptographicHash::Sha512)

static const QString xml_dir = "./rr_xml";
static const QString xml_file = "./rr_xml/rr_login";

Rxml::Rxml(){
    init();
    doit();
}

void Rxml::init(){
    m_login_data.insert("admin", "roborock");
    m_login_data.insert("yangjian", "flmay");
    m_login_data.insert("cuiyi", "123");
    m_login_data.insert("traveler", "ganger");
}

void Rxml::doit(){
    this->change(m_in_data, m_login_data);
    this->write("rr_login", m_in_data);
    this->read();
    //this->show();
}

bool Rxml::add_user(const QString uname, const QString pwd){
    bool ret = false;
    auto iter = m_login_data.find(uname);
    if(iter != m_login_data.end()){
        return ret;
    }
    m_login_data.insert(uname, pwd);
    doit();
    return true;
}

void Rxml::remove_user(const QString uname){
    auto iter = m_out_data.find(uname);
    if(iter != m_out_data.end()){
        m_out_data.erase(iter);
    }
    auto it = m_login_data.find(uname);
    if (it != m_login_data.end()){
        m_login_data.erase(it);
    }
    auto ite = m_in_data.find(uname);
    if (ite != m_in_data.end()){
        m_in_data.erase(ite);
    }
    this->write("rr_login", m_in_data);
}

void Rxml::show(){
    for (auto iter=m_out_data.begin(); iter!=m_out_data.end(); ++iter){
        qDebug() << iter.key() << iter.value();
    }
}

QString Rxml::trans(QString rhs){
    QString str;
    QByteArray qb = QCryptographicHash::hash(rhs.toLatin1(), hash_type);
    str.append(qb.toHex());
    return str;
}

void Rxml::change(Loginfo &lhs, const Loginfo &rhs){
    m_in_data.clear();
    for (auto iter=rhs.begin(); iter!=rhs.end(); ++iter){
        lhs.insert(iter.key(), trans(iter.value()));
    }
}

bool Rxml::is_ok(QString uname, QString pwd){
    bool ret = false;
    auto iter = m_out_data.find(uname);
    if (iter == m_out_data.end())
        return ret;
    if (iter.value() == trans(pwd)){
        ret = true;
    }
    return ret;
}

void Rxml::write(const QString &filename, const Loginfo &rhs){
    QDomDocument doc;
    QDomProcessingInstruction instruction = doc.createProcessingInstruction("xml", "version=\"1.0\"encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement("Login");
    doc.appendChild(root);

    for (auto iter=rhs.begin(); iter!=rhs.end(); ++iter){
        QDomElement user = doc.createElement("User");
        root.appendChild(user);
        QDomElement uname = doc.createElement("Username");
        user.appendChild(uname);
        QDomElement pwd = doc.createElement("Password");
        user.appendChild(pwd);
        QDomText uname_text = doc.createTextNode(iter.key());
        uname.appendChild(uname_text);
        QDomText pwd_text = doc.createTextNode(iter.value());
        pwd.appendChild(pwd_text);
    }
    save(filename, doc);
}

void Rxml::save(const QString &filename, QDomDocument &doc){
    QDir m_dir(xml_dir);
    if(!m_dir.exists()){
        QString cmd = "sudo mkdir " + xml_dir;
        system(cmd.toStdString().c_str());
    }
    QFile file(m_dir.absolutePath() + "/" + filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
        return;
    }
    QTextStream out(&file);
    out.setCodec("UTF-8");
    doc.save(out, 4, QDomNode::EncodingFromTextStream);
    file.close();
}

void Rxml::remove(const QString &filename){
    QFile file(filename);
    if(file.exists()){
        QString cmd = "sudo rm " + filename;
        system(cmd.toStdString().c_str());
    }
}

void Rxml::read(const QString &filename){
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){
        QDomDocument doc;
        if(doc.setContent(&file)){
            QDomElement root = doc.documentElement();
            listdom(root);
        }
        file.close();
    }
}

void Rxml::read(){
    QFile file(xml_file);
    if(file.open(QIODevice::ReadOnly)){
        QDomDocument doc;
        if(doc.setContent(&file)){
            QDomElement root = doc.documentElement();
            listdom(root);
        }
        file.close();
    }
}

void Rxml::listdom(QDomElement &root){
    if (!root.hasChildNodes()){
        return;
    }
    QDomNodeList userlist = root.childNodes();
    QString uname, pwd;
    for (int i=0; i<userlist.count(); ++i){
        QDomNode user = userlist.at(i);
        QDomNodeList record = user.childNodes();
        uname = record.at(0).toElement().text();
        pwd = record.at(1).toElement().text();
        m_out_data.insert(uname, pwd);
    }
}
