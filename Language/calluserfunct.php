<html>
    <head>
        <title>call_user_func</title>
        <style>
            body{
                text-align:center
            }
        </style>
    </head>
    <body>
        <?php
        function program($name,$description){
            echo "$name $description<br><br>";
        }
        call_user_func("program", "Firefox", "Mozilla's browser.");
		call_user_func("program", "Mimikatz", "Open source app to manipulate Windows credentials.");
        ?>
    </body>
</html>
