<?php

function _radiobase_menu()
{
    
    /**
     * @defgroup Devices
     * @{
     */

    $items["devices"] = array(
        "title" => "Devices manager",
        "description" => "Manage devices in global RadioBase",
        "page callback" => "_radiobase_page_devices",
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/devices.inc"
    );

    $items["devices/list/%"] = array(
        "title" => "List devices",
        "description" => "Show the list of the devices in global RadioBase",
        "page callback" => "_radiobase_list_devices",
        "page arguments" => array(2),
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
    
    $items["device/%"] = array(
        "title callback" => "_radiobase_title_device",
        "title arguments" => array(1),
        "page callback" => "_radiobase_device",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/devices.inc"
    );

    $items["device/%/view"] = array(
        "title" => "View",
        "page callback" => "_radiobase_device",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK,
        "file" => "includes/devices.inc",
        "weight" => -10
    );
    
    $items["device/%/edit"] = array(
        "title" => "Edit",
        "page callback" => "_radiobase_device",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK,
        "file" => "includes/devices.inc"
    );

    /**
     * @}
     */
    
    /**
     * @defgroup Categories
     * @{
     */

    $items["cats"] = array(
        "title" => "Category manager",
        "description" => "Manage device categories in global RadioBase",
        "page callback" => "_radiobase_page_cats",
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/cats.inc"
    );
    
    $items["cats/tree"] = array(
        "title" => "Category tree",
        "description" => "View category tree",
        "page callback" => "_radiobase_list_cats",
        "page arguments" => array("tree"),
        "access arguments" => array("access content"),
        "type" => MENU_LOCAL_TASK,
        "file" => "includes/cats.inc"
    );

    $items["cat/%"] = array(
        "title callback" => "_radiobase_title_cat",
        "title arguments" => array(1),
        "page callback" => "_radiobase_cat",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/cats.inc"
    );

    $items["cat/%/view"] = array(
        "title" => "View",
        "page callback" => "_radiobase_cat",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK,
        "file" => "includes/cats.inc",
        "weight" => -10
    );
    
    $items["cat/%/edit"] = array(
        "title" => "Edit",
        "page callback" => "_radiobase_cat",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK,
        "file" => "includes/cats.inc"
    );

    /**
     * @}
     */

    /**
     * @defgroup Cases
     * @{
     */
    
    $items["cases"] = array(
        "title" => "Cases manager",
        "page callback" => "_radiobase_page_cases",
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/cases.inc"
    );

    $items["cases/list/%"] = array(
        "title" => "Cases list",
        "page callback" => "_radiobase_list_cases",
        "page arguments" => array(2),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/cases.inc"
    );
    
    $items["case/%"] = array(
        "title callback" => "_radiobase_title_case",
        "title arguments" => array(1),
        "page callback" => "_radiobase_case",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/cases.inc"
    );

    $items["case/%/view"] = array(
        "title" => "View",
        "page callback" => "_radiobase_case",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK,
        "file" => "includes/cases.inc",
        "weight" => -10
    );
    
    $items["case/%/edit"] = array(
        "title" => "Edit",
        "page callback" => "_radiobase_case",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK,
        "file" => "includes/cases.inc"
    );

    /**
     * @}
     */

    /**
     * @defgroup Parts
     * @{
     */
    
    $items["parts"] = array(
        "title" => "Parts manager",
        "page callback" => "_radiobase_page_parts",
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/parts.inc"
    );

    $items["parts/list"] = array( // list all parts in database
        "title" => "Parts list",
        "page callback" => "_radiobase_list_parts",
        "page arguments" => array("by-cat", "0"),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/parts.inc"
    );

    $items["parts/list/%"] = array( // list parts by category
        "title" => "Parts list",
        "page callback" => "_radiobase_list_parts",
        "page arguments" => array("by-cat", 2),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/parts.inc"
    );

    $items["parts/list/%/%"] = array( // selected filter type and criterium
        "title" => "Parts list",
        "page callback" => "_radiobase_list_parts",
        "page arguments" => array(2, 3),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/parts.inc"
    );

    $items["part/%"] = array(
        "title callback" => "_radiobase_title_part",
        "title arguments" => array(1),
        "page callback" => "_radiobase_part",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_NORMAL_ITEM,
        "file" => "includes/parts.inc"
    );

    $items["part/%/view"] = array(
        "title" => "View",
        "page callback" => "_radiobase_part",
        "page arguments" => array("view", 1),
        "access arguments" => array("access content"),
        "type" => MENU_DEFAULT_LOCAL_TASK,
        "file" => "includes/parts.inc",
        "weight" => -10
    );
    
    $items["part/%/edit"] = array(
        "title" => "Edit",
        "page callback" => "_radiobase_part",
        "page arguments" => array("edit", 1),
        "access arguments" => array("rb edit items"),
        "type" => MENU_LOCAL_TASK,
        "file" => "includes/parts.inc"
    );
    /**
     * @}
     */


    return $items;
}
