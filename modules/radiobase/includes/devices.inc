<?php

/**
 * @file includes/devices.inc
 * @author WebConn
 * @brief Declares devices pages callbacks
 */

/**
 * @defgroup UI Callbacks
 * @{
 */

/**
 * @function _radiobase_title_device
 *
 * Device title callback
 *
 * Describes device title by getting
 * device name from database and insert it
 * into title
 *
 * @param $device_id integer Describing device's ID
 *
 * @return string Complete title string
 */

function _radiobase_title_device($device_id)
{
    settype($device_id, "integer");
    // Common action: get device name from databae
    $dev_name = RB_Database::query("SELECT `name` FROM `devices` WHERE `id`=:id", array(":id" => $device_id))->fetchAssoc();
    $dev_name = $dev_name["name"];

    return t("Device") . ": " . $dev_name;
}

/**
 * @function _radiobase_device
 *
 * Device page callback
 *
 * Draws form contains all information about device
 * described by device_id
 *
 * @param $mode string Mode of page operating (view or edit)
 * @param $device_id integer Describing device's ID
 *
 * @return string Formatted device page
 */

function _radiobase_device($mode, $device_id)
{
    $output = "";

    // Required information:
    // - Device name
    // - Device category
    // - Device datasheet link
    // - Device basic features (get form category)
    // - Device realisation (parts filtered by this device)

    // 1. Get all required data
    // 1.1. Get device row drom 'devices'

    $device = RB_Database::query("SELECT `name`, `category`, `params`, `datasheet` FROM `devices` WHERE `id`=:id", array(":id" => $device_id))->fetchAssoc();

    switch($mode)
    {
        case "view":
            $output .= "<b>".t("Device name")."</b>: " . $device["name"] . "<br />";
            $output .= "<b>".t("Category")."</b>: " . _getCatParentsStr($device["category"], 0, "cat_view") . "<br />";
            break;
        case "edit":

            break;
    }

    return $output;
}

/**
 * @function _radiobase_page_devices
 *
 * Device actions page callback
 *
 * Generates pages with list of actions.
 * In fact, this page is index of devices/ directory
 *
 * @return string Formatted device actions page
 */

function _radiobase_page_devices()
{
    $output = "";
            
    $list[] = l(t("List devices"), "devices/list/0");
    $list[] = l(t("Search"), "devices/search");
    $list[] = l(t("Category tree"), "cats/tree");
    if(user_access("rb add items")) $list[] = l(t("Add new device"), "devices/add");
    
    $output = theme("item_list", array("items" => $list, "title" => t("Actions")));
    
    return $output;
}

/**
 * @function _radiobase_list_devices
 *
 * Device list page callback
 *
 * Generates page with table list of the devices
 * based on info stored in RadioBase database
 *
 * @param $category ID of category filter (0 for root -> all categories)
 *
 * @return string Formatted device list page
 */

function _radiobase_list_devices($category)
{
    settype($category, "integer");

    RB_Database::createCatView($category);

    $output = t("Category").": " . ($category > 0 ? _getCatParentsStr($category, 0) : t("Root category"));

    $query = "SELECT `deviceID`, `deviceName`, `caseID`, `caseName`, `manID`, `manName`, `catID`, `catName` FROM `cat_view_".$category."` WHERE ".RB_Database::getCatFilter($category);

    $result = RB_Database::query($query);

    $num = $result->rowCount();
    $table = array();

    if($num)
    {
        for($i=0; $i<$num; $i++)
        {
            $fetch = $result->fetchAssoc();
            $table[$i] = array(l($fetch["deviceName"], "device/".$fetch["deviceID"]."/view"),  l($fetch["caseName"], "case/".$fetch["caseID"]."/view"),  l($fetch["manName"], "manufacture/".$fetch["manID"]."/view"),  _getCatParentsStr($fetch["catID"], $category, "devices"));
        }
        $output .= @theme_table(array("header" => array(t("Device"), t("Case"), t("Manufacture"), t("Category")), "sticky" => true, "rows" => $table));
        //$output .= t("Category index").": ".$category;
    }
    else
        $output .= t("There are no parts in this category");

    return $output;
}

/**
 * @function _radiobase_add_device
 *
 * Generate new device description form
 * which sends information to input callback
 *
 * @return string Formatted device description form
 */

function _radiobase_add_device()
{

}

/**
 * @}
 */

/**
 * @defgroup Forms
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Input data callbacks
 * @{
 */

/**
 * @function _radiobase_add_device_submit
 *
 * Receive information from new device description form
 * and store this information into RadioBase
 *
 * @return None
 */

function _radiobase_add_device_submit()
{

}

/**
 * @}
 */

/**
 * @defgroup Private functions
 * @{
 */

function _getCatParentsStr($start, $finish, $links="parts", $delimiter="»")
{
    // Stage 1. Make category tree
    $catTree = RB_Database::getCatParentsList($start, $finish);
    $count = count($catTree);
    $output = "";
    
    switch($links)
    {
        case "parts":
            $link_format = "parts/list/by-cat/%";
            break;
        case "devices":
            $link_format = "devices/list/%";
            break;
        case "cat_view":
            $link_format = "cat/%";
            break;
        case "cat_edit":
            $link_format = "cat/%/edit";
            break;
        default:
            $link_format = "#";
    }

    for($i=$count-1; $i>=0; $i--)
    {
        $output .= l(t($catTree[$i]["name"]), str_replace("%",$catTree[$i]["id"], $link_format));
        if($i != 0) $output .= " " . $delimiter . " ";
    }

    return $output;
}

/**
 * @}
 */
