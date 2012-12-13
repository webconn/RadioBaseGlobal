<?php

function _radiobase_page_devices($request)
{
    $output = "";
    
    switch($request)
    {
        case "list features":
            
            $list[] = l(t("List devices"), "devices/list");
            $list[] = l(t("Search"), "devices/search");
            $list[] = l(t("Category tree"), "cats/tree");
            if(user_access("rb add items")) $list[] = l(t("Add new device"), "devices/add");
            
            $output = theme("item_list", array("items" => $list, "title" => t("Actions")));
            
            break;
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