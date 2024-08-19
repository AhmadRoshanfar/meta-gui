import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0
import SettingsWinAdaptor 1.0

import "../Views"
import "../Pages"

PageBase {
    id: _page_settings
    width:800
    itemsList: []
    SettingsWinAdaptor{
        id:_settingsWinAdaptor
    }

    property var win;
    onVisibleChanged: {
        if(visible === true){
            _settingsWinAdaptor.show();
        }
        else{
            _settingsWinAdaptor.hide();
        }
    }

    function onEnterPressed(){

    }

}
