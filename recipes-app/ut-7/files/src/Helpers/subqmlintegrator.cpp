#include "subqmlintegrator.h"

SubQMLIntegrator::SubQMLIntegrator( QObject *parent) :
    QObject(parent)
{
            }

	bool SubQMLIntegrator::topbarVisible(){
	return _topbarVisible;
}
void SubQMLIntegrator::setTopbarVisible(const 	bool &val){
	if (val == _topbarVisible)
		return;
	_topbarVisible = val;
	emit onTopbarVisibleChanged();
}
 
	bool SubQMLIntegrator::bottombarVisible(){
	return _bottombarVisible;
}
void SubQMLIntegrator::setBottombarVisible(const 	bool &val){
	if (val == _bottombarVisible)
		return;
	_bottombarVisible = val;
	emit onBottombarVisibleChanged();
}
 
	int SubQMLIntegrator::rightPage(){
	return _rightPage;
}
void SubQMLIntegrator::setRightPage(const 	int &val){
	if (val == _rightPage)
		return;
	_rightPage = val;
	emit onRightPageChanged();
}
 
	int SubQMLIntegrator::bottomPage(){
	return _bottomPage;
}
void SubQMLIntegrator::setBottomPage(const 	int &val){
	if (val == _bottomPage)
		return;
	_bottomPage = val;
	emit onBottomPageChanged();
}
 
	int SubQMLIntegrator::bottomIndex(){
	return _bottomIndex;
}
void SubQMLIntegrator::setBottomIndex(const 	int &val){
	if (val == _bottomIndex)
		return;
	_bottomIndex = val;
	emit onBottomIndexChanged();
}
 
	int SubQMLIntegrator::rightIndex(){
	return _rightIndex;
}
void SubQMLIntegrator::setRightIndex(const 	int &val){
	if (val == _rightIndex)
		return;
	_rightIndex = val;
	emit onRightIndexChanged();
}
 
	QString SubQMLIntegrator::memoryDescription(){
	return _memoryDescription;
}
void SubQMLIntegrator::setMemoryDescription(const 	QString &val){
	if (val == _memoryDescription)
		return;
	_memoryDescription = val;
	emit onMemoryDescriptionChanged();
}
 
