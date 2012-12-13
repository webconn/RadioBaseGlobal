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
    
    public static function categoryTree()
    {
        
    }

}
