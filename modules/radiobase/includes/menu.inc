<?php

function _radiobase_menu()
{
    // Here the main menu is described
    
    $items["devices"] = array(
        "title" => "Devices manager",
        "description" => "Manage devices in global RadioBase",
        "page callback" => "radiobase_page_devices",
        "page arguments" => array("list features"),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );

    // List devices from database
    
    $items["devices/list"] = array(
        "title" => "List devices",
        "description" => "Show the list of the devices in global RadioBase",
        "page callback" => "radiobase_page_devices",
        "page arguments" => array("list devices"),
        "access arguments" => array("access content"),
        "type" => MENU_LOCAL_TASK
    );
    
    // Search devices in RadioBase
    
    $items["devices/search"] = array(
        "title" => "Search",
        "description" => "Search for the devices in global RadioBase",
        "page callback" => "radiobase_search_devices",
        "access arguments" => array("access content"),
        "type" => MENU_LOCAL_TASK 
    );
    
    $items["devices/add"] = array(
        "title" => "Add new device",
        "description" => "Describe new device for database",
        "page callback" => "radiobase_add_device",
        "access arguments" => array("rb add items"),
        "type" => MENU_NORMAL_ITEM
    );
    
    // Show concrete device
    
    $items["device/%/show"] = array(
        "title" => "Device: @name",
        "title callback" => "radiobase_title_devices",
        "title arguments" => array(1),
        "page callback" => "radiobase_device",
        "page arguments" => array("show", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK
    );
    
    $items["device/%/edit"] = array(
        "title" => "Device: @name",
        "title callback" => "radiobase_title_devices",
        "title arguments" => array(1),
        "page callback" => "radiobase_device",
        "page arguments" => array("show", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_DEFAULT_LOCAL_TASK
    );
    
    ##############################################################################################################
    # Categories
    
    $items["cats"] = array(
        "title" => "Category manager",
        "description" => "Manage device categories in global RadioBase",
        "page callback" => "radiobase_page_cats",
        "page arguments" => array("list features"),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );
    
    $items["cats/tree"] = array(
        "title" => "Category tree",
        "description" => "View category tree",
        "page callback" => "radiobase_page_cats",
        "page arguments" => array("tree"),
        "access arguments" => array("access content"),
        "type" => MENU_LOCAL_TASK
    );
    
    return $items;
}