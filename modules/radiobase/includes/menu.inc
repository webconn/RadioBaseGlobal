<?php

function _radiobase_menu()
{
    // Here the main menu is described
    
    ################################################################################
    # Devices

    $items["devices"] = array(
        "title" => "Devices manager",
        "description" => "Manage devices in global RadioBase",
        "page callback" => "_radiobase_page_devices",
        "page arguments" => array("list features"),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/devices.inc"
    );

    // List devices from database
    
    $items["devices/list/%"] = array(
        "title" => "List devices",
        "description" => "Show the list of the devices in global RadioBase",
        "page callback" => "_radiobase_list_devices",
        "page arguments" => array(2),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/devices.inc"
    );
    
    // Search devices in RadioBase
    
    $items["devices/search"] = array(
        "title" => "Search",
        "description" => "Search for the devices in global RadioBase",
        "page callback" => "_radiobase_search_devices",
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/devices.inc"
    );
    
    $items["devices/add"] = array(
        "title" => "Add new device",
        "description" => "Describe new device for database",
        "page callback" => "_radiobase_add_device",
        "access arguments" => array("rb add items"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/devices.inc"
    );
    
    // Show concrete device
    
    $items["device/%"] = array(
        "title callback" => "_radiobase_title_device",
        "title arguments" => array("view", 1),
        "page callback" => "_radiobase_device",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/devices.inc"
    );

    $items["device/%/view"] = array(
        "title callback" => "_radiobase_title_device",
        "title arguments" => array("view", 1),
        "page callback" => "_radiobase_device",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK,
        "file" => "includes/devices.inc",
        "weight" => -10
    );
    
    $items["device/%/edit"] = array(
        "title callback" => "_radiobase_title_device",
        "title arguments" => array("edit", 1),
        "page callback" => "_radiobase_device",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK,
        "file" => "includes/devices.inc"
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

    $items["cat/%"] = array(
        "title" => "Category @name: show",
        "title callback" => "radiobase_title_cat",
        "title arguments" => array(1),
        "page callback" => "radiobase_cat",
        "page arguments" => array("show", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK
    );
    
    $items["cat/%/edit"] = array(
        "title" => "Category @name: edit",
        "title callback" => "radiobase_title_cat",
        "title arguments" => array(1),
        "page callback" => "radiobase_cat",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK
    );

    ##########################################################################
    # Cases
    
    $items["cases"] = array(
        "title" => "Cases manager",
        "page callback" => "radiobase_page_cases",
        "page arguments" => array("list features"),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );

    $items["cases/list/%"] = array(
        "title" => "Cases list",
        "page callback" => "radiobase_list_cases",
        "page arguments" => array(2),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );

    $items["case/%"] = array(
        "title" => "Case @name: show",
        "title callback" => "radiobase_title_case",
        "title arguments" => array(1),
        "page callback" => "radiobase_case",
        "page arguments" => array("show", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK
    );
    
    $items["case/%/edit"] = array(
        "title" => "Case @name: edit",
        "title callback" => "radiobase_title_case",
        "title arguments" => array(1),
        "page callback" => "radiobase_case",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK
    );

    ###################################################################
    # Parts
    
    
    $items["parts"] = array(
        "title" => "Parts manager",
        "page callback" => "radiobase_page_parts",
        "page arguments" => array("list features"),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );

    $items["parts/list"] = array( // list all parts in database
        "title" => "Parts list",
        "page callback" => "radiobase_list_parts",
        "page arguments" => array("by-cat", "0"),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );

    $items["parts/list/%"] = array( // list parts by category
        "title" => "Parts list",
        "page callback" => "radiobase_list_parts",
        "page arguments" => array("by-cat", 2),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );

    $items["parts/list/%/%"] = array( // selected filter type and criterium
        "title" => "Parts list",
        "page callback" => "radiobase_list_parts",
        "page arguments" => array(2, 3),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM
    );

    $items["part/%"] = array(
        "title" => "Part @name: show",
        "title callback" => "radiobase_title_part",
        "title arguments" => array(1),
        "page callback" => "radiobase_part",
        "page arguments" => array("show", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK
    );
    
    $items["part/%/edit"] = array(
        "title" => "Part @name: edit",
        "title callback" => "radiobase_title_part",
        "title arguments" => array(1),
        "page callback" => "radiobase_part",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK
    );


    return $items;
}
