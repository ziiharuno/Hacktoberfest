<!DOCTYPE html>
<html lang="es">
    <head>
        <title>Odd/even</title>
        <style>
            h1{
                text-align:center
            }
        </style>
    </head>
    <body>
        <?php
           $rand = rand(0, 100);
           $resultado = ($rand%2==0) ? "Number $rand is odd." : "Number $rand is even.";
           echo "<h1> $resultado</h1>";
        ?>
    </body>
</html>
