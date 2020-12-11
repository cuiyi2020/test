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
    m_filename = "rr_login";
    m_login_data.insert("admin", "123");
    m_login_data.insert("yangj", "321");
    m_login_data.insert("longyue", "321");
    m_login_data.insert("xuzuzu", "2020");
    m_login_data.insert("tianhao", "2020");
    m_login_data.insert("浩哥", "2");
    m_login_data.insert("zac", "1");
    for (auto iter=m_login_data.begin(); iter!=m_login_data.end(); ++iter){
        m_unamelist.push_back(iter.key());
    }
}

QStringList Rxml::get_unamelist(){
    return m_unamelist;
}

void Rxml::doit(){
    m_in_data.clear();
    this->change(m_in_data, m_login_data);
    this->write(m_filename, m_in_data);
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
    m_unamelist.push_back(uname);
    doit();
    return true;
}

void Rxml::remove_user(const QString name){
    auto it = m_login_data.find(name);
    if (it != m_login_data.end()){
        m_login_data.erase(it);
    }
    int index = m_unamelist.indexOf(name);
    if (index >= 0 && index < m_unamelist.size())
        m_unamelist.erase(m_unamelist.begin()+index);

    QString uname = trans(name);
    auto iter = m_out_data.find(uname);
    if(iter != m_out_data.end()){
        m_out_data.erase(iter);
    }
    auto ite = m_in_data.find(uname);
    if (ite != m_in_data.end()){
        m_in_data.erase(ite);
    } 
    this->write(m_filename, m_in_data);
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
    for (auto iter=rhs.begin(); iter!=rhs.end(); ++iter){
        lhs.insert(trans(iter.key()), trans(iter.value()));
    }
}

bool Rxml::is_ok(const QString &uname, const QString &pwd){
    bool ret = false;
    auto iter = m_out_data.find(trans(uname));
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
        QString cmd = "mkdir " + xml_dir;
        system(cmd.toStdString().c_str());
    }
    m_fullname = m_dir.absolutePath() + "/" + filename;
    QFile file(m_fullname);
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
        QString cmd = "rm " + filename;
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
    QFile file(m_fullname);
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
    m_out_data.clear();
    for (int i=0; i<userlist.count(); ++i){
        QDomNode user = userlist.at(i);
        QDomNodeList record = user.childNodes();
        uname = record.at(0).toElement().text();
        pwd = record.at(1).toElement().text();
        m_out_data.insert(uname, pwd);
    }
}
