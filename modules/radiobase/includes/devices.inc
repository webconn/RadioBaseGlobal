<?php

function _radiobase_page_devices($request, $category)
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

        case "list devices":
            
            //@$category = $_GET["cat"];
            settype($category, "integer");

            RB_Database::createCatView($category);

            $query = "SELECT `deviceID`, `deviceName`, `caseID`, `caseName`, `manID`, `manName`, `catID`, `catName` FROM `cat_view_".$category."` WHERE ".RB_Database::getCatFilter($category);

            $result = RB_Database::query($query);

            $num = $result->rowCount();
            $table = array();

            if($num)
            {
                for($i=0; $i<$num; $i++)
                {
                    $fetch = $result->fetchAssoc();
                    $table[$i] = array(l($fetch["deviceName"], "device/show/".$fetch["deviceID"]),  l($fetch["caseName"], "case/show/".$fetch["caseID"]),  l($fetch["manName"], "manufacture/show/".$fetch["manID"]),  l($fetch["catName"], "devices/list/".$fetch["catID"]));
                }
                $output = @theme_table(array("header" => array(t("Device"), t("Case"), t("Manufacture"), t("Category")), "sticky" => true, "rows" => $table));
                $output .= "Category index: ".$category;
            }
            else
                $output = "There are no parts in this category";
        
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
