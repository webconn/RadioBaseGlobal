<?php

function c_radiobase_menu()
{
    $items["cats/tree"] = array(
        "title" => "Device category tree",
        "description" => "Device category tree",
        "page callback" => "radiobase_tree_cat",
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );
    
    return $items;
}