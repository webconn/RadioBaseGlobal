<?php

#############################################################
#   UI Callbacks

/**
 * Describes device title by getting
 * device name from database and insert it
 * into title
 *
 * @param $string string Default string
 * @param $params array Array, consists of 1 element with device ID
 *
 * @return string Complete title string
 */

function _radiobase_title_device($mode, $device_id)
{
    switch($mode)
    {
        case "view":
            return "Device " . $device_id;
            break;
        case "edit":
            return "Edit device " . $device_id;
            break;
    }
}

function _radiobase_device($mode, $device_id)
{
   return $mode;
}

function _radiobase_page_devices($request)
{
    $output = "";
    
    switch($request)
    {
        case "list features":
            
            $list[] = l(t("List devices"), "devices/list/0");
            $list[] = l(t("Search"), "devices/search");
            $list[] = l(t("Category tree"), "cats/tree");
            if(user_access("rb add items")) $list[] = l(t("Add new device"), "devices/add");
            
            $output = theme("item_list", array("items" => $list, "title" => t("Actions")));
            
            break;
    }
    
    return $output;
}

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
            $table[$i] = array(l($fetch["deviceName"], "device/".$fetch["deviceID"]."/view"),  l($fetch["caseName"], "case/".$fetch["caseID"]."/view"),  l($fetch["manName"], "manufacture/".$fetch["manID"]."/view"),  _getCatParentsStr($fetch["catID"], $category));
        }
        $output .= @theme_table(array("header" => array(t("Device"), t("Case"), t("Manufacture"), t("Category")), "sticky" => true, "rows" => $table));
        //$output .= t("Category index").": ".$category;
    }
    else
        $output .= t("There are no parts in this category");

    return $output;
}

function _getCatParentsStr($start, $finish)
{
    // Stage 1. Make category tree
    $catTree = RB_Database::getCatParentsList($start, $finish);
    $count = count($catTree);
    $output = "";
    
    for($i=$count-1; $i>=0; $i--)
    {
        $output .= l(t($catTree[$i]["name"]), "devices/list/".$catTree[$i]["id"]);
        if($i != 0) $output .= " » ";
    }

    return $output;
}

function _radiobase_add_device()
{
    return drupal_get_form("rb_add_device_form");   
}

function rb_add_device_form($form_state)
{
    $form['name'] = array(
        '#type' => "textfield",
        '#title' => "Device name"
    );
    
    $form['category'] = array(
        '#type' => 'submit',
        '#value' => 'Submit'
    );
    
    return $form;
}
