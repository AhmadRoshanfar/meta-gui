import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


ColumnLayout {
    id: _page_basic
    width: 200
    height: 340
    spacing: 2
    property int pageNo: 0
    property var itemsList;

    Component.onCompleted: {
        setItems();
    }

    function up(){
        if(subqmlIntegrator.rightIndex<0)
            return;
        itemsList[subqmlIntegrator.rightIndex+pageNo*4].up();
    }

    function down(){
        if(subqmlIntegrator.rightIndex<0)
            return;
        itemsList[subqmlIntegrator.rightIndex+pageNo*4].down();
    }

    function nextParamStep(){
        if(subqmlIntegrator.rightIndex<0)
            return;
        var index = subqmlIntegrator.rightIndex+pageNo*4;
        if(itemsList[index].type === Enums.PARTYP_DOUBLE || itemsList[index].type === Enums.PARTYP_INT)
            itemsList[index].nextStep();
    }

    function setItems(){
        for(var  i = 0;i<itemsList.length ;i++){
            itemsList[i].visible = false;
        }
        for(i = pageNo*4;i<pageNo*4+4 && i<itemsList.length;i++){
            itemsList[i].visible = true;
        }
    }

    function longPressed(idx){

    }

    function firstPage(){
        pageNo = 0;
        setItems();
    }

    function nextPage(){

        pageNo = (pageNo+1)%(itemsList.length/4);
        setItems();
    }

    function selectParam(idx){
        for(var  i = 0;i<itemsList.length ;i++){
            itemsList[i].selected = false;
        }
        if(idx<0)
            return;
        itemsList[idx+pageNo*4].selected = true;
    }

    function onEnterPressed(){
        itemsList[subqmlIntegrator.rightIndex+pageNo*4].onEnterPressed();
    }

    function onDeletePressed(){
        itemsList[subqmlIntegrator.rightIndex+pageNo*4].onDeletePressed();
    }
//    function saveSettings(s){
//        for(var i = 0;i<itemsList.length;i++){
//            s += this.id + "," + itemsList[i].name +": "+ itemsList[i].value+"\n";
//        }
//        return s;
//    }

}
