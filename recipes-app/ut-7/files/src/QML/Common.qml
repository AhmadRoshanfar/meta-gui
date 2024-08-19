import QtQuick 2.0

Item {
    readonly property int cBTM_PAGE_CNT : 3
    readonly property int cBTM_ITEMS_PER_PAGE : 5
    function selectPage(idx){
        selectParam(-1);
        subqmlIntegrator.rightPage = 0;
        _frm_options.currentIndex = bottomPage*cBTM_ITEMS_PER_PAGE + idx;
        selectedPageIndex = idx
        firstPage();
    }

    function selectParam(idx){
        subqmlIntegrator.rightIndex = idx;
        pagesList[subqmlIntegrator.bottomIndex].selectParam(idx);
        var current = pagesList[subqmlIntegrator.bottomIndex].itemsList[idx+4*pagesList[subqmlIntegrator.bottomIndex].pageNo];
        if(!isUndefined(current))
            _lbl_step.text = current.step;
        else
            _lbl_step.text = "0";
    }
    function getLengthWithUnit(length){
        switch(qmlIntegrator.unit){
        case Enums.UNIT_MM:return length;
        case Enums.UNIT_INCH:return length/qmlIntegrator.inchToMm;
        case Enums.UNIT_US:return length/qmlIntegrator.usToMm;
        }
    }

    function getLengthMM(length){
        switch(qmlIntegrator.unit){
        case Enums.UNIT_MM:return length;
        case Enums.UNIT_INCH:return length*qmlIntegrator.inchToMm;
        case Enums.UNIT_US:return length*qmlIntegrator.usToMm;
        }
    }

    function isUndefined(obj){
        return (typeof obj === 'undefined')
    }
}
