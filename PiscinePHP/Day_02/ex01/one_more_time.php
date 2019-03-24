#!/usr/bin/php
<?php
    function get_month_number($month) {
        $months = array("[Jj]anvier", "[Ff]évrier", "[Mm]ars", "[Aa]vril", "[Mm]ai", "[Jj]uin", "[Jj]uillet", "[Aa]oût", "[Ss]\
eptembre", "[Oo]ctobre", "[Nn]ovembre", "[Dd]écembre");
        foreach ($months as $index => $regex) {
            if (preg_match("/$regex/", $month))
                return $index + 1;
        }
        return -1;
    }
    if ($argc >= 2) {
        if (preg_match("/^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche) [1-9]{1,2} ([Jj]anvier|[Ff][ée]vrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]o[ûu]t|[Ss]eptembre|[Oo]ctobre|[N\
n]ovembre|[Dd][ée]cembre) \d{4} \d{2}:\d{2}:\d{2}$/", $argv[1])) {
            $split = explode(' ', $argv[1]);
            $month = get_month_number($split[2]);
            setlocale(LC_TIME, "fr_FR");
            date_default_timezone_set("Europe/Paris");
            echo strtotime("$split[1]-$month-$split[3] $split[4]"), "\n";
        } else
            echo "Wrong Format\n";
    }
?>