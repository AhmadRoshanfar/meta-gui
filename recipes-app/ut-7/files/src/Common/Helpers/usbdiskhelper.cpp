#include <cstdio>
#include <iostream>
#include <memory>
#include "usbdiskhelper.h"
#include<QDebug>
#include <QProcess>
#include <QTextCodec>
#define ROOT_PASS "pejvakrayan"



USBDiskHelper::USBDiskHelper(QObject *parent) : QObject(parent)
{
    QStringList listmedia = listMedia();
    QStringList listdev = listDev();
    for(auto dev : listmedia){
        if(dev.contains("sd")&&dev.count() == 4){
            if(!listdev.contains("/dev/"+dev)){
                runCommand((QString("echo %1|sudo -S rm -r  \"/media/%2\"").arg(ROOT_PASS).arg(dev.replace("/dev/",""))));
                qDebug()<<(QString("echo %1|sudo -S rm -r  /media/%2").arg(ROOT_PASS).arg(dev.replace("/dev/","")));
            }
        }
    }
}

QString USBDiskHelper::checkList(){
#ifdef Q_OS_WIN
    return "";
#endif
    QString str;
    QStringList listmedia = listMedia();
    QStringList listdev = listDev();
    for(auto dev : listdev){

        QString driveName =dev;
        driveName.replace("/dev/","");
        if(driveName.contains("sd")&&driveName.count() == 4){
            //             str = USBDiskHelper::exec((QString("cd /media/%1;echo \"\"> .pejvakrayan;ls .pejvakrayan").arg(driveName)));
            //             if(str == ".pejvakrayan\n"){
            //                 return driveName;
            //             }
            auto cmd = QString("pmount %1").arg(dev);
            str = USBDiskHelper::exec(cmd);
            if(str.contains("already mounted")){
                auto words = str.split(" ");
                QString mountedPath;
                if(words.count() == 8)
                    mountedPath = words.at(7);
                mountedPath.replace("\n","");
                if(mountedPath == ("/media/"+driveName))
                    return driveName;
                else{
                    QString c = QString("echo %2|sudo -S umount \"%3\"; pmount %1").arg(dev).arg(ROOT_PASS).arg(mountedPath);
                    qDebug()<<c;
                    runCommand(c);
                    return driveName;
                }
            }
            if(str.contains("empty"))
                runCommand(QString("echo %2|sudo -S rm -r  /media/%3; pmount %1").arg(dev).arg(ROOT_PASS).arg(driveName));
            //             runCommand(QString("echo %2|sudo -S umount /media/%3; pmount %1;cd /media/%3;echo \"\"> .pejvakrayan").arg(dev).arg(ROOT_PASS).arg(driveName));
            return driveName;

        }

    }

    //    for(auto dev : listmedia){
    //        if(dev.contains("sd")&&dev.count() == 4){
    //            //            std::system((QString("cd %1;echo \"\"> .pejvakrayan").arg(dev)));
    //            //            qDebug()<<(QString("cd %1;echo \"\"> .pejvakrayan;ls .pejvakrayan").arg(dev))<<"*****************";
    //            str = USBDiskHelper::exec((QString("cd /media/%1;echo \"\"> .pejvakrayan;ls .pejvakrayan").arg(dev)));
    //            //            qDebug()<<str<<"*****************";
    //            if(str == ".pejvakrayan\n" && listdev.contains("/dev/"+dev)){
    //                //                qDebug()<<dev<<"-*---------------";
    //                return dev;
    //            }
    //        }
    //    }
    //    str = USBDiskHelper::exec("ls /dev/sd*");

    //    for(auto dev : list){
    //        if(dev.contains("/dev/sd")&&dev.count() == 9){
    //            runCommand(QString("echo %2|sudo -S umount %1; pmount %1;cd /media/%3;echo \"\"> .pejvakrayan").arg(dev).arg(ROOT_PASS).arg(dev.replace("/dev/",""))/*.arg(dev.remove("/dev/sd"))*/);
    //            //            qDebug()<<(QString("echo %2|sudo -S umount %1; pmount %1;cd /media/%3;echo \"\"> .pejvakrayan").arg(dev).arg(ROOT_PASS).arg(dev.replace("/dev/",""))/*.arg(dev.remove("/dev/sd"))*/);
    //            //            qDebug()<<dev<<"++++++++++++++++";
    //            return dev;
    //        }
    //    }
    return "";

}

bool USBDiskHelper::copyFileToUSB(QString content,QString filename){
    QString usbdisk = checkList();
    qDebug()<<usbdisk;
    if(usbdisk == "")
        return false;
    QString destPath = _qmlIntegrator.applicationDirPath()+"/"+filename;
    QFile qFile(destPath);
    if (QFile::exists(destPath))
        QFile::remove(destPath);
    if (qFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&qFile); out << content;
        qFile.close();
        destPath = "/media/"+usbdisk + "/"+ filename;
        runCommand(QString("mv \"%1\" \"%2\";sync").arg(filename).arg(destPath));
        qDebug("copied");
        return true;
    }
    return true;
}

bool USBDiskHelper::copyFileToUSB(QString path){
    QString usbdisk = checkList();
    qDebug()<<usbdisk;
    if(usbdisk == "")
        return false;
    QString filename = path.split('/').last().replace("\n","");
    QString destPath = "/media/"+usbdisk + "/"+ filename;
    bool ret = QFile::copy(path,destPath);
    sync();
    return ret;
}

bool USBDiskHelper::copyDirToUSB(QString name){
    QString usbdisk = checkList();
    if(usbdisk == "")
        return false;
    QString destPath = "/media/"+usbdisk+"/"+name+"/";
    //IF FOLDER IS NOT IN PENDRIVE THEN IT WILL CREATE A FOLDER NAME REPORT
    QDir dir(destPath);
    if(!dir.exists()){
        dir.mkpath(".");
    }
    QString path1= _qmlIntegrator.applicationDirPath()+ "/" + name+"/";
    //    qDebug()<<path1;
    //    if (QFile::exists(destPath)) QFile::remove(destPath);
    QDir directory(path1);
    QStringList lst = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    for(auto filename : lst){
        QFile::copy(path1+filename,destPath+filename);
        //        qDebug()<<path1+filename<<destPath+filename;
    }
    sync();
    return true;
}

QStringList USBDiskHelper::listDev(){
    QString str = USBDiskHelper::exec("ls /dev/sd*");
    return str.split("\n");
}


QStringList USBDiskHelper::listMedia(){
    QString str = USBDiskHelper::exec("ls /media/");
    return str.split("\n");
}

int USBDiskHelper::runCommand(QString cmd){
    return std::system(cmd.toLocal8Bit().data());
}

void USBDiskHelper::sync(){
    runCommand("sync");
}

QString USBDiskHelper::exec(QString cmd){
    std::array<char,128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose) >pipe(popen((cmd+" 2>&1").toLocal8Bit(),"r"),pclose);
    if(!pipe){
        throw std::runtime_error("popen() failed!");
    }
    while(fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return QString::fromLocal8Bit(result.c_str());
}
