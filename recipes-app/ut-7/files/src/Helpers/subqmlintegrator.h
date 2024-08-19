#ifndef SUBQMLINTEGRATOR_H
#define SUBQMLINTEGRATOR_H

#include <QObject>
#include <QSettings>
#include "../Common/Models/enums.h"
#include <QPointF>
class SubQMLIntegrator : public QObject
{
    Q_OBJECT
SubQMLIntegrator(QObject *parent = nullptr);
Q_PROPERTY(	bool topbarVisible READ topbarVisible WRITE setTopbarVisible NOTIFY onTopbarVisibleChanged)
Q_PROPERTY(	bool bottombarVisible READ bottombarVisible WRITE setBottombarVisible NOTIFY onBottombarVisibleChanged)
Q_PROPERTY(	int rightPage READ rightPage WRITE setRightPage NOTIFY onRightPageChanged)
Q_PROPERTY(	int bottomPage READ bottomPage WRITE setBottomPage NOTIFY onBottomPageChanged)
Q_PROPERTY(	int bottomIndex READ bottomIndex WRITE setBottomIndex NOTIFY onBottomIndexChanged)
Q_PROPERTY(	int rightIndex READ rightIndex WRITE setRightIndex NOTIFY onRightIndexChanged)
Q_PROPERTY(	QString memoryDescription READ memoryDescription WRITE setMemoryDescription NOTIFY onMemoryDescriptionChanged)


	 	bool _topbarVisible = true;
	 	bool _bottombarVisible = true;
	 	int _rightPage = 0;
	 	int _bottomPage = 0;
	 	int _bottomIndex = 0;
	 	int _rightIndex = 0;
	 	QString _memoryDescription;


public:
    SubQMLIntegrator(const SubQMLIntegrator&) = delete;
    SubQMLIntegrator & operator= (const SubQMLIntegrator &) = delete;
            SubQMLIntegrator(SubQMLIntegrator &&) = delete;
            SubQMLIntegrator & operator= (SubQMLIntegrator &&) = delete;
            static auto&instance(){
                static SubQMLIntegrator test;
                return test;
            }
            	bool topbarVisible();
void setTopbarVisible(const 	bool&val); 
	bool bottombarVisible();
void setBottombarVisible(const 	bool&val); 
	int rightPage();
void setRightPage(const 	int&val); 
	int bottomPage();
void setBottomPage(const 	int&val); 
	int bottomIndex();
void setBottomIndex(const 	int&val); 
	int rightIndex();
void setRightIndex(const 	int&val); 
	QString memoryDescription();
void setMemoryDescription(const 	QString&val); 

signals:

void onTopbarVisibleChanged();
void onBottombarVisibleChanged();
void onRightPageChanged();
void onBottomPageChanged();
void onBottomIndexChanged();
void onRightIndexChanged();
void onMemoryDescriptionChanged();
};
#endif // SUBQMLINTEGRATOR_H
