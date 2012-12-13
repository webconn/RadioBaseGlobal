<?php

/**
 * @file
 * Database connection description
 */

class RB_Database extends Database
{

    private static $connection = null;

    public static function setConnection()
    {
        // Close function if connection is still initialised
        if (self::$connection)
            return null;

        // Combining databaseInfo for our service
        $databaseInfo = array(
            'driver' => 'mysql',
            'database' => 'radiobase',
            'username' => 'root',
            'password' => 'y123x842',
            'host' => 'localhost',
            'prefix' => '',
            'collation' => 'utf8_general_ci');

        self::addConnectionInfo('radiobase', 'database', $databaseInfo);

        try {
            self::$connection = self::openConnection('radiobase', 'database');
        }
        catch (exception $e) {
            var_dump($e);
            return null;
        }

        return self::$connection;
    }

    public static function listCases($pincount = 0, $start = 0, $limit = 0)
    {
        if(!self::$connection)
            self::setConnection();
            
        $query = "SELECT * FROM `cases`";

        if ($pincount > 0)
            $query .= " WHERE `pins`=:pins";

        if ($limit > 0)
            $result = self::$connection->queryRange($query, $start, $limit, array(":pins" =>
                    $pincount));
        else
            $result = self::$connection->query($query, array(":pins" => $pincount));

        return $result;
    } 
    
    public static function numParts()
    {
        if(!self::$connection)
            self::setConnection();
        return self::$connection->query("SELECT * FROM `cases`")->rowCount();
    }
    
    public static function createCatView($category, $overwrite=true)
    {
        if(!self::$connection)
            self::setConnection();

        // Steps to create view:
        // 1. Recursively collect info about features featuring in category
        // 2. Convert this info into view fields description
        // 3. Fully set the query
        // 4. Run it in database
        
        // Step 1. Collection data about features
        
        $features = array();
        $parent = $category;
        
        $query = "SELECT `features`, `parent` FROM categories WHERE `id` = :id";

        while($parent != 0)
        {
            $result = self::$connection->query($query, array(":id" => $parent))->fetchAssoc();
            $parent = $result["parent"];
            if($result["features"]) $features = array_merge(explode(",", $result["features"]), $features);
        }

        // Collect features info

        $numFeatures = count($features);
        $query = "SELECT `name`, `type`, `length`, `post-action` FROM `features` WHERE `id` = :id";
        
        $featureRows = "";
        $length = 1;

        // 2. Converting features info into query string

        for($i=0; $i<$numFeatures; $i++)
        {   

            $features[$i] = self::$connection->query($query, array(":id" => $features[$i]))->fetchAssoc();
            $featureRows .= "(CAST(SUBSTR(parts.features,".$length.",".$features[$i]["length"].") AS ".$features[$i]["type"].")".$features[$i]["post-action"].") AS ".$features[$i]["name"];
            $length += $features[$i]["length"] + 1;
            if($i != $numFeatures - 1) $featureRows .= ", ";
        }

        // 3. Combining query
        $query = "CREATE".($overwrite ? " OR REPLACE " : " ")."VIEW cat_view_:cat AS SELECT parts.id AS partID, parts.device AS deviceID, CONCAT(devices.name, parts.modification) AS deviceName, parts.case AS caseID, cases.name AS caseName, parts.manufacture AS manID, manufactures.name AS manName".($numFeatures > 0 ? ", ".$featureRows : "")." FROM parts, cases, devices, manufactures WHERE parts.manufacture = manufactures.id AND parts.device = devices.id AND parts.case = cases.id";

        return $query;
    }
}
